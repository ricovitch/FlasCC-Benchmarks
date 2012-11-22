/*

Alchemy CPP Wrapper
@author Eric Hélier

*/

#include "AS3.h"
#include "benchmark_stdint.hpp"
#include <stddef.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "alchemy_benchmark_results.h"
#include "alchemy_benchmark_timer.h"

/******************************************************************************/

// this constant may need to be adjusted to give reasonable minimum times
// For best results, times should be about 1.0 seconds for the minimum test run
int iterations = 300000;

// 8000 items, or between 8k and 64k of data
// this is intended to remain within the L2 cache of most common CPUs
#define SIZE 	8000

// initial value for filling our arrays, may be changed from the command line
double init_value = 1.0;

/******************************************************************************/

#include "benchmark_shared_tests.h"

/******************************************************************************/
/******************************************************************************/

template <typename T>
T hash_func2(T seed) {
	return (914237 * (seed + 12345)) - 13;
}

template <typename T>
T complete_hash_func(T seed) {
	return hash_func2( hash_func2( hash_func2( seed ) ) );
}

/******************************************************************************/

template <typename T>
inline void check_sum(T result) {
  T temp = (T)SIZE * complete_hash_func( (T)init_value );
  if (!tolerance_equal<T>(result,temp)) printf("test %i failed\n", current_test);
}

/******************************************************************************/

// this is the heart of our loop unrolling - a class that unrolls itself to generate the inner loop code
// at least as long as we keep F < 50 (or some compilers won't compile it)
template< int F, typename T >
struct loop_inner_body {
	inline static void do_work(T &result, const T *first, int n) {
		loop_inner_body<F-1,T>::do_work(result, first, n);
		T temp = first[ n + (F-1) ];
		temp = complete_hash_func( temp );
		result += temp;
	}
};

template< typename T >
struct loop_inner_body<0,T> {
	inline static void do_work(T &, const T *, int) {
	}
};

/******************************************************************************/
/******************************************************************************/

// F is the unrolling factor
template <int F, typename T >
void test_for_loop_unroll_factor(const T* first, int count, const char *label) {
  int i;
  
  start_timer();
  
  for(i = 0; i < iterations; ++i) {
    T result = 0;
	int n = 0;
	
    for (; n < (count - (F-1)); n += F) {
		loop_inner_body<F,T>::do_work(result,first, n);
	}
	
    for (; n < count; ++n) {
		result += complete_hash_func( first[n] );
	}
	
    check_sum<T>(result);
  }
  
  record_result( timer(), label );
}

/******************************************************************************/

// F is the unrolling factor
template <int F, typename T >
void test_while_loop_unroll_factor(const T* first, int count, const char *label) {
  int i;
  
  start_timer();
  
  for(i = 0; i < iterations; ++i) {
    T result = 0;
	int n = 0;
	
    while ( n < (count - (F-1)) ) {
		loop_inner_body<F,T>::do_work(result,first, n);
		n += F;
	}
	
    while ( n < count ) {
		result += complete_hash_func( first[n] );
		++n;
	}
	
    check_sum<T>(result);
  }
  
  record_result( timer(), label );
}

/******************************************************************************/

// F is the unrolling factor
template <int F, typename T >
void test_do_loop_unroll_factor(const T* first, int count, const char *label) {
  int i;
  
  start_timer();
  
  for(i = 0; i < iterations; ++i) {
    T result = 0;
	int n = 0;
	
	if ((count - n) >= F)
		do {
			loop_inner_body<F,T>::do_work(result,first, n);
			n += F;
		} while (n < (count - (F-1)));
	
	if (n < count)
		do {
			result += complete_hash_func( first[n] );
			++n;
		} while (n != count);
	
    check_sum<T>(result);
  }
  
  record_result( timer(), label );
}

/******************************************************************************/

// F is the unrolling factor
template <int F, typename T >
void test_goto_loop_unroll_factor(const T* first, int count, const char *label) {
  int i;
  
  start_timer();
  
  for(i = 0; i < iterations; ++i) {
    T result = 0;
	int n = 0;
	
	if ((count - n) >= F) {
loop2_start:
		loop_inner_body<F,T>::do_work(result,first, n);
		n += F;
		
		if (n < (count - (F-1)))
			goto loop2_start;
	}

	if (n < count) {
loop_start:
		result += complete_hash_func( first[n] );
		++n;
		
		if (n != count)
			goto loop_start;
	}
	
    check_sum<T>(result);
  }
  
  record_result( timer(), label );
}

/******************************************************************************/
/******************************************************************************/

// our global arrays of numbers to be operated upon

double dataDouble[SIZE];

int32_t data32[SIZE];

// not elegant, but I need strings to hang around until we print the results
// and I don't want to pull in STL
const int UnrollLimit = 32;
char temp_string[UnrollLimit][100];

/******************************************************************************/
/******************************************************************************/

// another unrolled loop to create all of our tests
template< int N, typename T >
struct for_loop_tests {
	static void do_test( const T *data, const char *label_base ) {
		for_loop_tests<N-1, T>::do_test(data, label_base);
		sprintf( temp_string[N-1], "%s %d", label_base, N );
		test_for_loop_unroll_factor<N>( data, SIZE, temp_string[N-1] );
	}
};

template<typename T>
struct for_loop_tests<0,T> {
	static void do_test( const T *, const char * ) {
	}
};

/******************************************************************************/

template< int N, typename T >
struct while_loop_tests {
	static void do_test( const T *data, const char *label_base ) {
		while_loop_tests<N-1, T>::do_test(data, label_base);
		sprintf( temp_string[N-1], "%s %d", label_base, N );
		test_while_loop_unroll_factor<N>( data, SIZE, temp_string[N-1] );
	}
};

template<typename T>
struct while_loop_tests<0,T> {
	static void do_test( const T *, const char * ) {
	}
};

/******************************************************************************/

template< int N, typename T >
struct do_loop_tests {
	static void do_test( const T *data, const char *label_base ) {
		do_loop_tests<N-1, T>::do_test(data, label_base);
		sprintf( temp_string[N-1], "%s %d", label_base, N );
		test_do_loop_unroll_factor<N>( data, SIZE, temp_string[N-1] );
	}
};

template<typename T>
struct do_loop_tests<0,T> {
	static void do_test( const T *, const char * ) {
	}
};

/******************************************************************************/

template< int N, typename T >
struct goto_loop_tests {
	static void do_test( const T *data, const char *label_base ) {
		goto_loop_tests<N-1, T>::do_test(data, label_base);
		sprintf( temp_string[N-1], "%s %d", label_base, N );
		test_goto_loop_unroll_factor<N>( data, SIZE, temp_string[N-1] );
	}
};

template<typename T>
struct goto_loop_tests<0,T> {
	static void do_test( const T *, const char * ) {
	}
};

/******************************************************************************/
/******************************************************************************/

static AS3_Val benchmark(void* self, AS3_Val args)
{
	// output command for documentation:
	int i;
	AS3_ArrayValue(args,"IntType, FloatType", &iterations, &init_value);
	printf("C++ benchmarks 'functionobjects' with args : %d - %d\n", iterations, init_value);

// int32_t
	::fill(data32, data32+SIZE, int32_t(init_value));
	
	for_loop_tests<UnrollLimit, int32_t>::do_test( data32, "int32_t for loop unroll" );
	summarize("int32_t for loop unrolling", SIZE, iterations, kDontShowGMeans, kDontShowPenalty );
	
	while_loop_tests<UnrollLimit, int32_t>::do_test( data32, "int32_t while loop unroll" );
	summarize("int32_t while loop unrolling", SIZE, iterations, kDontShowGMeans, kDontShowPenalty );

	do_loop_tests<UnrollLimit, int32_t>::do_test( data32, "int32_t do loop unroll" );
	summarize("int32_t do loop unrolling", SIZE, iterations, kDontShowGMeans, kDontShowPenalty );

	goto_loop_tests<UnrollLimit, int32_t>::do_test( data32, "int32_t goto loop unroll" );	
	summarize("int32_t goto loop unrolling", SIZE, iterations, kDontShowGMeans, kDontShowPenalty );


// double
	iterations /= 4;

	::fill(dataDouble, dataDouble+SIZE, double(init_value));
	
	for_loop_tests<UnrollLimit, double>::do_test( dataDouble, "double for loop unroll" );
	summarize("double for loop unrolling", SIZE, iterations, kDontShowGMeans, kDontShowPenalty );
	
	while_loop_tests<UnrollLimit, double>::do_test( dataDouble, "double while loop unroll" );
	summarize("double while loop unrolling", SIZE, iterations, kDontShowGMeans, kDontShowPenalty );

	do_loop_tests<UnrollLimit, double>::do_test( dataDouble, "double do loop unroll" );
	summarize("double do loop unrolling", SIZE, iterations, kDontShowGMeans, kDontShowPenalty );

	goto_loop_tests<UnrollLimit, double>::do_test( dataDouble, "double goto loop unroll" );	
	summarize("double goto loop unrolling", SIZE, iterations, kDontShowGMeans, kDontShowPenalty );


	return 0;
}

// the end
/******************************************************************************/
/******************************************************************************/

// Alchemy entry point
int main()
{
	AS3_Val benchmarkMethod = AS3_Function(NULL, benchmark);
	AS3_Val result = AS3_Object("benchmark: AS3ValType", benchmarkMethod);
	AS3_Release (benchmarkMethod);
	AS3_LibInit (result);
	return 0;
}