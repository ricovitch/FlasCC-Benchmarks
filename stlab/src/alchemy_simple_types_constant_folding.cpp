/*

Alchemy CPP Wrapper
@author Eric H�lier

*/

/******************************************************************************/

#include "AS3.h"
#include "benchmark_stdint.hpp"
#include <cstddef>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "alchemy_benchmark_results.h"
#include "alchemy_benchmark_timer.h"

/******************************************************************************/

// this constant may need to be adjusted to give reasonable minimum times
// For best results, times should be about 1.0 seconds for the minimum test run
int base_iterations = 2000000;
int iterations = base_iterations;


// 8000 items, or between 8k and 64k of data
// this is intended to remain within the L2 cache of most common CPUs
const int SIZE 	= 8000;


// initial value for filling our arrays, may be changed from the command line
double init_value = 1.0;

/******************************************************************************/

// our global arrays of numbers to be operated upon

double dataDouble[SIZE];
float dataFloat[SIZE];

uint64_t data64unsigned[SIZE];
int64_t data64[SIZE];

uint32_t data32unsigned[SIZE];
int32_t data32[SIZE];

uint16_t data16unsigned[SIZE];
int16_t data16[SIZE];

uint8_t data8unsigned[SIZE];
int8_t data8[SIZE];

/******************************************************************************/

#include "benchmark_shared_tests.h"

/******************************************************************************/


static AS3_Val bench_int8_t(void* self, AS3_Val args)
{	
	// output command for documentation:
	int i;
	AS3_ArrayValue(args,"IntType, FloatType", &base_iterations, &init_value);
	printf("C++ benchmarks 'simple_types_constant_folding (bench_int8_t)' with args : %d - %d\n", base_iterations, init_value);

// int8_t
	::fill(data8, data8+SIZE, int8_t(init_value));
	
	iterations = base_iterations;
	test_constant<int8_t, custom_two<int8_t> >(data8,SIZE,"int8_t constant");
	test_constant<int8_t, custom_add_constants<int8_t> >(data8,SIZE,"int8_t add constants");
	test_constant<int8_t, custom_sub_constants<int8_t> >(data8,SIZE,"int8_t subtract constants");
	test_constant<int8_t, custom_multiply_constants<int8_t> >(data8,SIZE,"int8_t multiply constants");
	test_constant<int8_t, custom_divide_constants<int8_t> >(data8,SIZE,"int8_t divide constants");
	test_constant<int8_t, custom_mod_constants<int8_t> >(data8,SIZE,"int8_t mod constants");
	test_constant<int8_t, custom_equal_constants<int8_t> >(data8,SIZE,"int8_t equal constants");
	test_constant<int8_t, custom_notequal_constants<int8_t> >(data8,SIZE,"int8_t notequal constants");
	test_constant<int8_t, custom_greaterthan_constants<int8_t> >(data8,SIZE,"int8_t greater than constants");
	test_constant<int8_t, custom_lessthan_constants<int8_t> >(data8,SIZE,"int8_t less than constants");
	test_constant<int8_t, custom_greaterthanequal_constants<int8_t> >(data8,SIZE,"int8_t greater than equal constants");
	test_constant<int8_t, custom_lessthanequal_constants<int8_t> >(data8,SIZE,"int8_t less than equal constants");
	test_constant<int8_t, custom_and_constants<int8_t> >(data8,SIZE,"int8_t and constants");
	test_constant<int8_t, custom_or_constants<int8_t> >(data8,SIZE,"int8_t or constants");
	test_constant<int8_t, custom_xor_constants<int8_t> >(data8,SIZE,"int8_t xor constants");
	
	summarize("int8_t simple constant folding", SIZE, iterations, kDontShowGMeans, kDontShowPenalty );
	
	
	iterations = base_iterations / 10;
	test_constant<int8_t, custom_constant_add<int8_t> >(data8,SIZE,"int8_t constant add");
	test_constant<int8_t, custom_multiple_constant_add<int8_t> >(data8,SIZE,"int8_t multiple constant adds");

	test_constant<int8_t, custom_constant_sub<int8_t> >(data8,SIZE,"int8_t constant subtract");
	test_constant<int8_t, custom_multiple_constant_sub<int8_t> >(data8,SIZE,"int8_t multiple constant subtracts");

	test_constant<int8_t, custom_constant_multiply<int8_t> >(data8,SIZE,"int8_t constant multiply");
	test_constant<int8_t, custom_multiple_constant_multiply<int8_t> >(data8,SIZE,"int8_t multiple constant multiplies");
	test_constant<int8_t, custom_multiple_constant_multiply2<int8_t> >(data8,SIZE,"int8_t multiple constant multiply2");

	test_constant<int8_t, custom_constant_divide<int8_t> >(data8,SIZE,"int8_t constant divide");
	test_constant<int8_t, custom_multiple_constant_divide<int8_t> >(data8,SIZE,"int8_t multiple constant divides");
	test_constant<int8_t, custom_multiple_constant_divide2<int8_t> >(data8,SIZE,"int8_t multiple constant divide2");
	
	test_constant<int8_t, custom_multiple_constant_mixed<int8_t> >(data8,SIZE,"int8_t multiple constant mixed");

	test_constant<int8_t, custom_constant_and<int8_t> >(data8,SIZE,"int8_t constant and");
	test_constant<int8_t, custom_multiple_constant_and<int8_t> >(data8,SIZE,"int8_t multiple constant and");

	test_constant<int8_t, custom_constant_or<int8_t> >(data8,SIZE,"int8_t constant or");
	test_constant<int8_t, custom_multiple_constant_or<int8_t> >(data8,SIZE,"int8_t multiple constant or");

	test_constant<int8_t, custom_constant_xor<int8_t> >(data8,SIZE,"int8_t constant xor");
	test_constant<int8_t, custom_multiple_constant_xor<int8_t> >(data8,SIZE,"int8_t multiple constant xor");

	summarize("int8_t constant folding", SIZE, iterations, kDontShowGMeans, kDontShowPenalty );

	return 0;
}

static AS3_Val bench_uint8_t(void* self, AS3_Val args)
{	
	// output command for documentation:
	int i;
	AS3_ArrayValue(args,"IntType, FloatType", &base_iterations, &init_value);
	printf("C++ benchmarks 'simple_types_constant_folding (bench_uint8_t)' with args : %d - %d\n", base_iterations, init_value);

// unsigned8
	::fill(data8unsigned, data8unsigned+SIZE, uint8_t(init_value));
	
	iterations = base_iterations;
	test_constant<uint8_t, custom_two<uint8_t> >(data8unsigned,SIZE,"uint8_t constant");
	test_constant<uint8_t, custom_add_constants<uint8_t> >(data8unsigned,SIZE,"uint8_t add constants");
	test_constant<uint8_t, custom_sub_constants<uint8_t> >(data8unsigned,SIZE,"uint8_t subtract constants");
	test_constant<uint8_t, custom_multiply_constants<uint8_t> >(data8unsigned,SIZE,"uint8_t multiply constants");
	test_constant<uint8_t, custom_divide_constants<uint8_t> >(data8unsigned,SIZE,"uint8_t divide constants");
	test_constant<uint8_t, custom_mod_constants<uint8_t> >(data8unsigned,SIZE,"uint8_t mod constants");
	test_constant<uint8_t, custom_equal_constants<uint8_t> >(data8unsigned,SIZE,"uint8_t equal constants");
	test_constant<uint8_t, custom_notequal_constants<uint8_t> >(data8unsigned,SIZE,"uint8_t notequal constants");
	test_constant<uint8_t, custom_greaterthan_constants<uint8_t> >(data8unsigned,SIZE,"uint8_t greater than constants");
	test_constant<uint8_t, custom_lessthan_constants<uint8_t> >(data8unsigned,SIZE,"uint8_t less than constants");
	test_constant<uint8_t, custom_greaterthanequal_constants<uint8_t> >(data8unsigned,SIZE,"uint8_t greater than equal constants");
	test_constant<uint8_t, custom_lessthanequal_constants<uint8_t> >(data8unsigned,SIZE,"uint8_t less than equal constants");
	test_constant<uint8_t, custom_and_constants<uint8_t> >(data8unsigned,SIZE,"uint8_t and constants");
	test_constant<uint8_t, custom_or_constants<uint8_t> >(data8unsigned,SIZE,"uint8_t or constants");
	test_constant<uint8_t, custom_xor_constants<uint8_t> >(data8unsigned,SIZE,"uint8_t xor constants");
	
	summarize("uint8_t simple constant folding", SIZE, iterations, kDontShowGMeans, kDontShowPenalty );
	
	
	iterations = base_iterations / 10;
	test_constant<uint8_t, custom_constant_add<uint8_t> >(data8unsigned,SIZE,"uint8_t constant add");
	test_constant<uint8_t, custom_multiple_constant_add<uint8_t> >(data8unsigned,SIZE,"uint8_t multiple constant adds");

	test_constant<uint8_t, custom_constant_sub<uint8_t> >(data8unsigned,SIZE,"uint8_t constant subtract");
	test_constant<uint8_t, custom_multiple_constant_sub<uint8_t> >(data8unsigned,SIZE,"uint8_t multiple constant subtracts");

	test_constant<uint8_t, custom_constant_multiply<uint8_t> >(data8unsigned,SIZE,"uint8_t constant multiply");
	test_constant<uint8_t, custom_multiple_constant_multiply<uint8_t> >(data8unsigned,SIZE,"uint8_t multiple constant multiplies");
	test_constant<uint8_t, custom_multiple_constant_multiply2<uint8_t> >(data8unsigned,SIZE,"uint8_t multiple constant multiply2");

	test_constant<uint8_t, custom_constant_divide<uint8_t> >(data8unsigned,SIZE,"uint8_t constant divide");
	test_constant<uint8_t, custom_multiple_constant_divide<uint8_t> >(data8unsigned,SIZE,"uint8_t multiple constant divides");
	test_constant<uint8_t, custom_multiple_constant_divide2<uint8_t> >(data8unsigned,SIZE,"uint8_t multiple constant divide2");
	
	test_constant<uint8_t, custom_multiple_constant_mixed<uint8_t> >(data8unsigned,SIZE,"uint8_t multiple constant mixed");

	test_constant<uint8_t, custom_constant_and<uint8_t> >(data8unsigned,SIZE,"uint8_t constant and");
	test_constant<uint8_t, custom_multiple_constant_and<uint8_t> >(data8unsigned,SIZE,"uint8_t multiple constant and");

	test_constant<uint8_t, custom_constant_or<uint8_t> >(data8unsigned,SIZE,"uint8_t constant or");
	test_constant<uint8_t, custom_multiple_constant_or<uint8_t> >(data8unsigned,SIZE,"uint8_t multiple constant or");

	test_constant<uint8_t, custom_constant_xor<uint8_t> >(data8unsigned,SIZE,"uint8_t constant xor");
	test_constant<uint8_t, custom_multiple_constant_xor<uint8_t> >(data8unsigned,SIZE,"uint8_t multiple constant xor");

	summarize("uint8_t constant folding", SIZE, iterations, kDontShowGMeans, kDontShowPenalty );

	return 0;
}

static AS3_Val bench_int16_t(void* self, AS3_Val args)
{	
	// output command for documentation:
	int i;
	AS3_ArrayValue(args,"IntType, FloatType", &base_iterations, &init_value);
	printf("C++ benchmarks 'simple_types_constant_folding (bench_int16_t)' with args : %d - %d\n", base_iterations, init_value);

// int16_t
	::fill(data16, data16+SIZE, int16_t(init_value));
	
	iterations = base_iterations;
	test_constant<int16_t, custom_two<int16_t> >(data16,SIZE,"int16_t constant");
	test_constant<int16_t, custom_add_constants<int16_t> >(data16,SIZE,"int16_t add constants");
	test_constant<int16_t, custom_sub_constants<int16_t> >(data16,SIZE,"int16_t subtract constants");
	test_constant<int16_t, custom_multiply_constants<int16_t> >(data16,SIZE,"int16_t multiply constants");
	test_constant<int16_t, custom_divide_constants<int16_t> >(data16,SIZE,"int16_t divide constants");
	test_constant<int16_t, custom_mod_constants<int16_t> >(data16,SIZE,"int16_t mod constants");
	test_constant<int16_t, custom_equal_constants<int16_t> >(data16,SIZE,"int16_t equal constants");
	test_constant<int16_t, custom_notequal_constants<int16_t> >(data16,SIZE,"int16_t notequal constants");
	test_constant<int16_t, custom_greaterthan_constants<int16_t> >(data16,SIZE,"int16_t greater than constants");
	test_constant<int16_t, custom_lessthan_constants<int16_t> >(data16,SIZE,"int16_t less than constants");
	test_constant<int16_t, custom_greaterthanequal_constants<int16_t> >(data16,SIZE,"int16_t greater than equal constants");
	test_constant<int16_t, custom_lessthanequal_constants<int16_t> >(data16,SIZE,"int16_t less than equal constants");
	test_constant<int16_t, custom_and_constants<int16_t> >(data16,SIZE,"int16_t and constants");
	test_constant<int16_t, custom_or_constants<int16_t> >(data16,SIZE,"int16_t or constants");
	test_constant<int16_t, custom_xor_constants<int16_t> >(data16,SIZE,"int16_t xor constants");
	
	summarize("int16_t simple constant folding", SIZE, iterations, kDontShowGMeans, kDontShowPenalty );
	
	
	iterations = base_iterations / 10;
	test_constant<int16_t, custom_constant_add<int16_t> >(data16,SIZE,"int16_t constant add");
	test_constant<int16_t, custom_multiple_constant_add<int16_t> >(data16,SIZE,"int16_t multiple constant adds");

	test_constant<int16_t, custom_constant_sub<int16_t> >(data16,SIZE,"int16_t constant subtract");
	test_constant<int16_t, custom_multiple_constant_sub<int16_t> >(data16,SIZE,"int16_t multiple constant subtracts");

	test_constant<int16_t, custom_constant_multiply<int16_t> >(data16,SIZE,"int16_t constant multiply");
	test_constant<int16_t, custom_multiple_constant_multiply<int16_t> >(data16,SIZE,"int16_t multiple constant multiplies");
	test_constant<int16_t, custom_multiple_constant_multiply2<int16_t> >(data16,SIZE,"int16_t multiple constant multiply2");

	test_constant<int16_t, custom_constant_divide<int16_t> >(data16,SIZE,"int16_t constant divide");
	test_constant<int16_t, custom_multiple_constant_divide<int16_t> >(data16,SIZE,"int16_t multiple constant divides");
	test_constant<int16_t, custom_multiple_constant_divide2<int16_t> >(data16,SIZE,"int16_t multiple constant divide2");
	
	test_constant<int16_t, custom_multiple_constant_mixed<int16_t> >(data16,SIZE,"int16_t multiple constant mixed");

	test_constant<int16_t, custom_constant_and<int16_t> >(data16,SIZE,"int16_t constant and");
	test_constant<int16_t, custom_multiple_constant_and<int16_t> >(data16,SIZE,"int16_t multiple constant and");

	test_constant<int16_t, custom_constant_or<int16_t> >(data16,SIZE,"int16_t constant or");
	test_constant<int16_t, custom_multiple_constant_or<int16_t> >(data16,SIZE,"int16_t multiple constant or");

	test_constant<int16_t, custom_constant_xor<int16_t> >(data16,SIZE,"int16_t constant xor");
	test_constant<int16_t, custom_multiple_constant_xor<int16_t> >(data16,SIZE,"int16_t multiple constant xor");

	summarize("int16_t constant folding", SIZE, iterations, kDontShowGMeans, kDontShowPenalty );

	return 0;
}

static AS3_Val bench_uint16_t(void* self, AS3_Val args)
{
	// output command for documentation:
	int i;
	AS3_ArrayValue(args,"IntType, FloatType", &base_iterations, &init_value);
	printf("C++ benchmarks 'simple_types_constant_folding (bench_uint16_t)' with args : %d - %d\n", base_iterations, init_value);

// unsigned16
	::fill(data16unsigned, data16unsigned+SIZE, uint16_t(init_value));
	
	iterations = base_iterations;
	test_constant<uint16_t, custom_two<uint16_t> >(data16unsigned,SIZE,"uint16_t constant");
	test_constant<uint16_t, custom_add_constants<uint16_t> >(data16unsigned,SIZE,"uint16_t add constants");
	test_constant<uint16_t, custom_sub_constants<uint16_t> >(data16unsigned,SIZE,"uint16_t subtract constants");
	test_constant<uint16_t, custom_multiply_constants<uint16_t> >(data16unsigned,SIZE,"uint16_t multiply constants");
	test_constant<uint16_t, custom_divide_constants<uint16_t> >(data16unsigned,SIZE,"uint16_t divide constants");
	test_constant<uint16_t, custom_mod_constants<uint16_t> >(data16unsigned,SIZE,"uint16_t mod constants");
	test_constant<uint16_t, custom_equal_constants<uint16_t> >(data16unsigned,SIZE,"uint16_t equal constants");
	test_constant<uint16_t, custom_notequal_constants<uint16_t> >(data16unsigned,SIZE,"uint16_t notequal constants");
	test_constant<uint16_t, custom_greaterthan_constants<uint16_t> >(data16unsigned,SIZE,"uint16_t greater than constants");
	test_constant<uint16_t, custom_lessthan_constants<uint16_t> >(data16unsigned,SIZE,"uint16_t less than constants");
	test_constant<uint16_t, custom_greaterthanequal_constants<uint16_t> >(data16unsigned,SIZE,"uint16_t greater than equal constants");
	test_constant<uint16_t, custom_lessthanequal_constants<uint16_t> >(data16unsigned,SIZE,"uint16_t less than equal constants");
	test_constant<uint16_t, custom_and_constants<uint16_t> >(data16unsigned,SIZE,"uint16_t and constants");
	test_constant<uint16_t, custom_or_constants<uint16_t> >(data16unsigned,SIZE,"uint16_t or constants");
	test_constant<uint16_t, custom_xor_constants<uint16_t> >(data16unsigned,SIZE,"uint16_t xor constants");
	
	summarize("uint16_t simple constant folding", SIZE, iterations, kDontShowGMeans, kDontShowPenalty );
	
	
	iterations = base_iterations / 10;
	test_constant<uint16_t, custom_constant_add<uint16_t> >(data16unsigned,SIZE,"uint16_t constant add");
	test_constant<uint16_t, custom_multiple_constant_add<uint16_t> >(data16unsigned,SIZE,"uint16_t multiple constant adds");

	test_constant<uint16_t, custom_constant_sub<uint16_t> >(data16unsigned,SIZE,"uint16_t constant subtract");
	test_constant<uint16_t, custom_multiple_constant_sub<uint16_t> >(data16unsigned,SIZE,"uint16_t multiple constant subtracts");

	test_constant<uint16_t, custom_constant_multiply<uint16_t> >(data16unsigned,SIZE,"uint16_t constant multiply");
	test_constant<uint16_t, custom_multiple_constant_multiply<uint16_t> >(data16unsigned,SIZE,"uint16_t multiple constant multiplies");
	test_constant<uint16_t, custom_multiple_constant_multiply2<uint16_t> >(data16unsigned,SIZE,"uint16_t multiple constant multiply2");

	test_constant<uint16_t, custom_constant_divide<uint16_t> >(data16unsigned,SIZE,"uint16_t constant divide");
	test_constant<uint16_t, custom_multiple_constant_divide<uint16_t> >(data16unsigned,SIZE,"uint16_t multiple constant divides");
	test_constant<uint16_t, custom_multiple_constant_divide2<uint16_t> >(data16unsigned,SIZE,"uint16_t multiple constant divide2");
	
	test_constant<uint16_t, custom_multiple_constant_mixed<uint16_t> >(data16unsigned,SIZE,"uint16_t multiple constant mixed");

	test_constant<uint16_t, custom_constant_and<uint16_t> >(data16unsigned,SIZE,"uint16_t constant and");
	test_constant<uint16_t, custom_multiple_constant_and<uint16_t> >(data16unsigned,SIZE,"uint16_t multiple constant and");

	test_constant<uint16_t, custom_constant_or<uint16_t> >(data16unsigned,SIZE,"uint16_t constant or");
	test_constant<uint16_t, custom_multiple_constant_or<uint16_t> >(data16unsigned,SIZE,"uint16_t multiple constant or");

	test_constant<uint16_t, custom_constant_xor<uint16_t> >(data16unsigned,SIZE,"uint16_t constant xor");
	test_constant<uint16_t, custom_multiple_constant_xor<uint16_t> >(data16unsigned,SIZE,"uint16_t multiple constant xor");

	summarize("uint16_t constant folding", SIZE, iterations, kDontShowGMeans, kDontShowPenalty );

	return 0;
}

static AS3_Val bench_int32_t(void* self, AS3_Val args)
{
	// output command for documentation:
	int i;
	AS3_ArrayValue(args,"IntType, FloatType", &base_iterations, &init_value);
	printf("C++ benchmarks 'simple_types_constant_folding (bench_int32_t)' with args : %d - %d\n", base_iterations, init_value);

// int32_t
	::fill(data32, data32+SIZE, int32_t(init_value));

	iterations = base_iterations;
	test_constant<int32_t, custom_two<int32_t> >(data32,SIZE,"int32_t constant");
	test_constant<int32_t, custom_add_constants<int32_t> >(data32,SIZE,"int32_t add constants");
	test_constant<int32_t, custom_sub_constants<int32_t> >(data32,SIZE,"int32_t subtract constants");
	test_constant<int32_t, custom_multiply_constants<int32_t> >(data32,SIZE,"int32_t multiply constants");
	test_constant<int32_t, custom_divide_constants<int32_t> >(data32,SIZE,"int32_t divide constants");
	test_constant<int32_t, custom_mod_constants<int32_t> >(data32,SIZE,"int32_t mod constants");
	test_constant<int32_t, custom_equal_constants<int32_t> >(data32,SIZE,"int32_t equal constants");
	test_constant<int32_t, custom_notequal_constants<int32_t> >(data32,SIZE,"int32_t notequal constants");
	test_constant<int32_t, custom_greaterthan_constants<int32_t> >(data32,SIZE,"int32_t greater than constants");
	test_constant<int32_t, custom_lessthan_constants<int32_t> >(data32,SIZE,"int32_t less than constants");
	test_constant<int32_t, custom_greaterthanequal_constants<int32_t> >(data32,SIZE,"int32_t greater than equal constants");
	test_constant<int32_t, custom_lessthanequal_constants<int32_t> >(data32,SIZE,"int32_t less than equal constants");
	test_constant<int32_t, custom_and_constants<int32_t> >(data32,SIZE,"int32_t and constants");
	test_constant<int32_t, custom_or_constants<int32_t> >(data32,SIZE,"int32_t or constants");
	test_constant<int32_t, custom_xor_constants<int32_t> >(data32,SIZE,"int32_t xor constants");
	
	summarize("int32_t simple constant folding", SIZE, iterations, kDontShowGMeans, kDontShowPenalty );
	
	
	iterations = base_iterations / 10;
	test_constant<int32_t, custom_constant_add<int32_t> >(data32,SIZE,"int32_t constant add");
	test_constant<int32_t, custom_multiple_constant_add<int32_t> >(data32,SIZE,"int32_t multiple constant adds");

	test_constant<int32_t, custom_constant_sub<int32_t> >(data32,SIZE,"int32_t constant subtract");
	test_constant<int32_t, custom_multiple_constant_sub<int32_t> >(data32,SIZE,"int32_t multiple constant subtracts");

	test_constant<int32_t, custom_constant_multiply<int32_t> >(data32,SIZE,"int32_t constant multiply");
	test_constant<int32_t, custom_multiple_constant_multiply<int32_t> >(data32,SIZE,"int32_t multiple constant multiplies");
	test_constant<int32_t, custom_multiple_constant_multiply2<int32_t> >(data32,SIZE,"int32_t multiple constant multiply2");

	test_constant<int32_t, custom_constant_divide<int32_t> >(data32,SIZE,"int32_t constant divide");
	test_constant<int32_t, custom_multiple_constant_divide<int32_t> >(data32,SIZE,"int32_t multiple constant divides");
	test_constant<int32_t, custom_multiple_constant_divide2<int32_t> >(data32,SIZE,"int32_t multiple constant divide2");
	
	test_constant<int32_t, custom_multiple_constant_mixed<int32_t> >(data32,SIZE,"int32_t multiple constant mixed");

	test_constant<int32_t, custom_constant_and<int32_t> >(data32,SIZE,"int32_t constant and");
	test_constant<int32_t, custom_multiple_constant_and<int32_t> >(data32,SIZE,"int32_t multiple constant and");

	test_constant<int32_t, custom_constant_or<int32_t> >(data32,SIZE,"int32_t constant or");
	test_constant<int32_t, custom_multiple_constant_or<int32_t> >(data32,SIZE,"int32_t multiple constant or");

	test_constant<int32_t, custom_constant_xor<int32_t> >(data32,SIZE,"int32_t constant xor");
	test_constant<int32_t, custom_multiple_constant_xor<int32_t> >(data32,SIZE,"int32_t multiple constant xor");

	summarize("int32_t constant folding", SIZE, iterations, kDontShowGMeans, kDontShowPenalty );

	return 0;
}

static AS3_Val bench_uint32_t(void* self, AS3_Val args)
{
	// output command for documentation:
	int i;
	AS3_ArrayValue(args,"IntType, FloatType", &base_iterations, &init_value);
	printf("C++ benchmarks 'simple_types_constant_folding (bench_uint32_t)' with args : %d - %d\n", base_iterations, init_value);


// unsigned32
	::fill(data32unsigned, data32unsigned+SIZE, uint32_t(init_value));

	iterations = base_iterations;
	test_constant<uint32_t, custom_two<uint32_t> >(data32unsigned,SIZE,"uint32_t constant");
	test_constant<uint32_t, custom_add_constants<uint32_t> >(data32unsigned,SIZE,"uint32_t add constants");
	test_constant<uint32_t, custom_sub_constants<uint32_t> >(data32unsigned,SIZE,"uint32_t subtract constants");
	test_constant<uint32_t, custom_multiply_constants<uint32_t> >(data32unsigned,SIZE,"uint32_t multiply constants");
	test_constant<uint32_t, custom_divide_constants<uint32_t> >(data32unsigned,SIZE,"uint32_t divide constants");
	test_constant<uint32_t, custom_mod_constants<uint32_t> >(data32unsigned,SIZE,"uint32_t mod constants");
	test_constant<uint32_t, custom_equal_constants<uint32_t> >(data32unsigned,SIZE,"uint32_t equal constants");
	test_constant<uint32_t, custom_notequal_constants<uint32_t> >(data32unsigned,SIZE,"uint32_t notequal constants");
	test_constant<uint32_t, custom_greaterthan_constants<uint32_t> >(data32unsigned,SIZE,"uint32_t greater than constants");
	test_constant<uint32_t, custom_lessthan_constants<uint32_t> >(data32unsigned,SIZE,"uint32_t less than constants");
	test_constant<uint32_t, custom_greaterthanequal_constants<uint32_t> >(data32unsigned,SIZE,"uint32_t greater than equal constants");
	test_constant<uint32_t, custom_lessthanequal_constants<uint32_t> >(data32unsigned,SIZE,"uint32_t less than equal constants");
	test_constant<uint32_t, custom_and_constants<uint32_t> >(data32unsigned,SIZE,"uint32_t and constants");
	test_constant<uint32_t, custom_or_constants<uint32_t> >(data32unsigned,SIZE,"uint32_t or constants");
	test_constant<uint32_t, custom_xor_constants<uint32_t> >(data32unsigned,SIZE,"uint32_t xor constants");
	
	summarize("uint32_t simple constant folding", SIZE, iterations, kDontShowGMeans, kDontShowPenalty );
	
	
	iterations = base_iterations / 10;
	test_constant<uint32_t, custom_constant_add<uint32_t> >(data32unsigned,SIZE,"uint32_t constant add");
	test_constant<uint32_t, custom_multiple_constant_add<uint32_t> >(data32unsigned,SIZE,"uint32_t multiple constant adds");

	test_constant<uint32_t, custom_constant_sub<uint32_t> >(data32unsigned,SIZE,"uint32_t constant subtract");
	test_constant<uint32_t, custom_multiple_constant_sub<uint32_t> >(data32unsigned,SIZE,"uint32_t multiple constant subtracts");

	test_constant<uint32_t, custom_constant_multiply<uint32_t> >(data32unsigned,SIZE,"uint32_t constant multiply");
	test_constant<uint32_t, custom_multiple_constant_multiply<uint32_t> >(data32unsigned,SIZE,"uint32_t multiple constant multiplies");
	test_constant<uint32_t, custom_multiple_constant_multiply2<uint32_t> >(data32unsigned,SIZE,"uint32_t multiple constant multiply2");

	test_constant<uint32_t, custom_constant_divide<uint32_t> >(data32unsigned,SIZE,"uint32_t constant divide");
	test_constant<uint32_t, custom_multiple_constant_divide<uint32_t> >(data32unsigned,SIZE,"uint32_t multiple constant divides");
	test_constant<uint32_t, custom_multiple_constant_divide2<uint32_t> >(data32unsigned,SIZE,"uint32_t multiple constant divide2");
	
	test_constant<uint32_t, custom_multiple_constant_mixed<uint32_t> >(data32unsigned,SIZE,"uint32_t multiple constant mixed");

	test_constant<uint32_t, custom_constant_and<uint32_t> >(data32unsigned,SIZE,"uint32_t constant and");
	test_constant<uint32_t, custom_multiple_constant_and<uint32_t> >(data32unsigned,SIZE,"uint32_t multiple constant and");

	test_constant<uint32_t, custom_constant_or<uint32_t> >(data32unsigned,SIZE,"uint32_t constant or");
	test_constant<uint32_t, custom_multiple_constant_or<uint32_t> >(data32unsigned,SIZE,"uint32_t multiple constant or");

	test_constant<uint32_t, custom_constant_xor<uint32_t> >(data32unsigned,SIZE,"uint32_t constant xor");
	test_constant<uint32_t, custom_multiple_constant_xor<uint32_t> >(data32unsigned,SIZE,"uint32_t multiple constant xor");

	summarize("uint32_t constant folding", SIZE, iterations, kDontShowGMeans, kDontShowPenalty );

	return 0;
}

static AS3_Val bench_int64_t(void* self, AS3_Val args)
{
	// output command for documentation:
	int i;
	AS3_ArrayValue(args,"IntType, FloatType", &base_iterations, &init_value);
	printf("C++ benchmarks 'simple_types_constant_folding (bench_int64_t)' with args : %d - %d\n", base_iterations, init_value);
	

// int64_t
	::fill(data64, data64+SIZE, int64_t(init_value));

	iterations = base_iterations;
	test_constant<int64_t, custom_two<int64_t> >(data64,SIZE,"int64_t constant");
	test_constant<int64_t, custom_add_constants<int64_t> >(data64,SIZE,"int64_t add constants");
	test_constant<int64_t, custom_sub_constants<int64_t> >(data64,SIZE,"int64_t subtract constants");
	test_constant<int64_t, custom_multiply_constants<int64_t> >(data64,SIZE,"int64_t multiply constants");
	test_constant<int64_t, custom_divide_constants<int64_t> >(data64,SIZE,"int64_t divide constants");
	test_constant<int64_t, custom_mod_constants<int64_t> >(data64,SIZE,"int64_t mod constants");
	test_constant<int64_t, custom_equal_constants<int64_t> >(data64,SIZE,"int64_t equal constants");
	test_constant<int64_t, custom_notequal_constants<int64_t> >(data64,SIZE,"int64_t notequal constants");
	test_constant<int64_t, custom_greaterthan_constants<int64_t> >(data64,SIZE,"int64_t greater than constants");
	test_constant<int64_t, custom_lessthan_constants<int64_t> >(data64,SIZE,"int64_t less than constants");
	test_constant<int64_t, custom_greaterthanequal_constants<int64_t> >(data64,SIZE,"int64_t greater than equal constants");
	test_constant<int64_t, custom_lessthanequal_constants<int64_t> >(data64,SIZE,"int64_t less than equal constants");
	test_constant<int64_t, custom_and_constants<int64_t> >(data64,SIZE,"int64_t and constants");
	test_constant<int64_t, custom_or_constants<int64_t> >(data64,SIZE,"int64_t or constants");
	test_constant<int64_t, custom_xor_constants<int64_t> >(data64,SIZE,"int64_t xor constants");
	
	summarize("int64_t simple constant folding", SIZE, iterations, kDontShowGMeans, kDontShowPenalty );
	
	
	iterations = base_iterations / 10;
	test_constant<int64_t, custom_constant_add<int64_t> >(data64,SIZE,"int64_t constant add");
	test_constant<int64_t, custom_multiple_constant_add<int64_t> >(data64,SIZE,"int64_t multiple constant adds");

	test_constant<int64_t, custom_constant_sub<int64_t> >(data64,SIZE,"int64_t constant subtract");
	test_constant<int64_t, custom_multiple_constant_sub<int64_t> >(data64,SIZE,"int64_t multiple constant subtracts");

	test_constant<int64_t, custom_constant_multiply<int64_t> >(data64,SIZE,"int64_t constant multiply");
	test_constant<int64_t, custom_multiple_constant_multiply<int64_t> >(data64,SIZE,"int64_t multiple constant multiplies");
	test_constant<int64_t, custom_multiple_constant_multiply2<int64_t> >(data64,SIZE,"int64_t multiple constant multiply2");

	test_constant<int64_t, custom_constant_divide<int64_t> >(data64,SIZE,"int64_t constant divide");
	test_constant<int64_t, custom_multiple_constant_divide<int64_t> >(data64,SIZE,"int64_t multiple constant divides");
	test_constant<int64_t, custom_multiple_constant_divide2<int64_t> >(data64,SIZE,"int64_t multiple constant divide2");
	
	test_constant<int64_t, custom_multiple_constant_mixed<int64_t> >(data64,SIZE,"int64_t multiple constant mixed");

	test_constant<int64_t, custom_constant_and<int64_t> >(data64,SIZE,"int64_t constant and");
	test_constant<int64_t, custom_multiple_constant_and<int64_t> >(data64,SIZE,"int64_t multiple constant and");

	test_constant<int64_t, custom_constant_or<int64_t> >(data64,SIZE,"int64_t constant or");
	test_constant<int64_t, custom_multiple_constant_or<int64_t> >(data64,SIZE,"int64_t multiple constant or");

	test_constant<int64_t, custom_constant_xor<int64_t> >(data64,SIZE,"int64_t constant xor");
	test_constant<int64_t, custom_multiple_constant_xor<int64_t> >(data64,SIZE,"int64_t multiple constant xor");

	summarize("int64_t constant folding", SIZE, iterations, kDontShowGMeans, kDontShowPenalty );

	return 0;
}

static AS3_Val bench_uint64_t(void* self, AS3_Val args)
{
	// output command for documentation:
	int i;
	AS3_ArrayValue(args,"IntType, FloatType", &base_iterations, &init_value);
	printf("C++ benchmarks 'simple_types_constant_folding (bench_uint64_t)' with args : %d - %d\n", base_iterations, init_value);

// unsigned64
	::fill(data64unsigned, data64unsigned+SIZE, uint64_t(init_value));
	
	iterations = base_iterations;
	test_constant<uint64_t, custom_two<uint64_t> >(data64unsigned,SIZE,"uint64_t constant");
	test_constant<uint64_t, custom_add_constants<uint64_t> >(data64unsigned,SIZE,"uint64_t add constants");
	test_constant<uint64_t, custom_sub_constants<uint64_t> >(data64unsigned,SIZE,"uint64_t subtract constants");
	test_constant<uint64_t, custom_multiply_constants<uint64_t> >(data64unsigned,SIZE,"uint64_t multiply constants");
	test_constant<uint64_t, custom_divide_constants<uint64_t> >(data64unsigned,SIZE,"uint64_t divide constants");
	test_constant<uint64_t, custom_mod_constants<uint64_t> >(data64unsigned,SIZE,"uint64_t mod constants");
	test_constant<uint64_t, custom_equal_constants<uint64_t> >(data64unsigned,SIZE,"uint64_t equal constants");
	test_constant<uint64_t, custom_notequal_constants<uint64_t> >(data64unsigned,SIZE,"uint64_t notequal constants");
	test_constant<uint64_t, custom_greaterthan_constants<uint64_t> >(data64unsigned,SIZE,"uint64_t greater than constants");
	test_constant<uint64_t, custom_lessthan_constants<uint64_t> >(data64unsigned,SIZE,"uint64_t less than constants");
	test_constant<uint64_t, custom_greaterthanequal_constants<uint64_t> >(data64unsigned,SIZE,"uint64_t greater than equal constants");
	test_constant<uint64_t, custom_lessthanequal_constants<uint64_t> >(data64unsigned,SIZE,"uint64_t less than equal constants");
	test_constant<uint64_t, custom_and_constants<uint64_t> >(data64unsigned,SIZE,"uint64_t and constants");
	test_constant<uint64_t, custom_or_constants<uint64_t> >(data64unsigned,SIZE,"uint64_t or constants");
	test_constant<uint64_t, custom_xor_constants<uint64_t> >(data64unsigned,SIZE,"uint64_t xor constants");
	
	summarize("uint64_t simple constant folding", SIZE, iterations, kDontShowGMeans, kDontShowPenalty );
	
	
	iterations = base_iterations / 10;
	test_constant<uint64_t, custom_constant_add<uint64_t> >(data64unsigned,SIZE,"uint64_t constant add");
	test_constant<uint64_t, custom_multiple_constant_add<uint64_t> >(data64unsigned,SIZE,"uint64_t multiple constant adds");

	test_constant<uint64_t, custom_constant_sub<uint64_t> >(data64unsigned,SIZE,"uint64_t constant subtract");
	test_constant<uint64_t, custom_multiple_constant_sub<uint64_t> >(data64unsigned,SIZE,"uint64_t multiple constant subtracts");

	test_constant<uint64_t, custom_constant_multiply<uint64_t> >(data64unsigned,SIZE,"uint64_t constant multiply");
	test_constant<uint64_t, custom_multiple_constant_multiply<uint64_t> >(data64unsigned,SIZE,"uint64_t multiple constant multiplies");
	test_constant<uint64_t, custom_multiple_constant_multiply2<uint64_t> >(data64unsigned,SIZE,"uint64_t multiple constant multiply2");

	test_constant<uint64_t, custom_constant_divide<uint64_t> >(data64unsigned,SIZE,"uint64_t constant divide");
	test_constant<uint64_t, custom_multiple_constant_divide<uint64_t> >(data64unsigned,SIZE,"uint64_t multiple constant divides");
	test_constant<uint64_t, custom_multiple_constant_divide2<uint64_t> >(data64unsigned,SIZE,"uint64_t multiple constant divide2");
	
	test_constant<uint64_t, custom_multiple_constant_mixed<uint64_t> >(data64unsigned,SIZE,"uint64_t multiple constant mixed");

	test_constant<uint64_t, custom_constant_and<uint64_t> >(data64unsigned,SIZE,"uint64_t constant and");
	test_constant<uint64_t, custom_multiple_constant_and<uint64_t> >(data64unsigned,SIZE,"uint64_t multiple constant and");

	test_constant<uint64_t, custom_constant_or<uint64_t> >(data64unsigned,SIZE,"uint64_t constant or");
	test_constant<uint64_t, custom_multiple_constant_or<uint64_t> >(data64unsigned,SIZE,"uint64_t multiple constant or");

	test_constant<uint64_t, custom_constant_xor<uint64_t> >(data64unsigned,SIZE,"uint64_t constant xor");
	test_constant<uint64_t, custom_multiple_constant_xor<uint64_t> >(data64unsigned,SIZE,"uint64_t multiple constant xor");

	summarize("uint64_t constant folding", SIZE, iterations, kDontShowGMeans, kDontShowPenalty );

	return 0;
}

static AS3_Val bench_float(void* self, AS3_Val args)
{
	// output command for documentation:
	int i;
	AS3_ArrayValue(args,"IntType, FloatType", &base_iterations, &init_value);
	printf("C++ benchmarks 'simple_types_constant_folding (bench_float)' with args : %d - %d\n", base_iterations, init_value);


// float
	::fill(dataFloat, dataFloat+SIZE, float(init_value));

	iterations = base_iterations;
	test_constant<float, custom_two<float> >(dataFloat,SIZE,"float constant");
	test_constant<float, custom_add_constants<float> >(dataFloat,SIZE,"float add constants");
	test_constant<float, custom_sub_constants<float> >(dataFloat,SIZE,"float subtract constants");
	test_constant<float, custom_multiply_constants<float> >(dataFloat,SIZE,"float multiply constants");
	test_constant<float, custom_divide_constants<float> >(dataFloat,SIZE,"float divide constants");
	
	summarize("float simple constant folding", SIZE, iterations, kDontShowGMeans, kDontShowPenalty );
	
	
	iterations = base_iterations / 10;
	test_constant<float, custom_constant_add<float> >(dataFloat,SIZE,"float constant add");
	test_constant<float, custom_multiple_constant_add<float> >(dataFloat,SIZE,"float multiple constant adds");

	test_constant<float, custom_constant_sub<float> >(dataFloat,SIZE,"float constant subtract");
	test_constant<float, custom_multiple_constant_sub<float> >(dataFloat,SIZE,"float multiple constant subtracts");

	test_constant<float, custom_constant_multiply<float> >(dataFloat,SIZE,"float constant multiply");
	test_constant<float, custom_multiple_constant_multiply<float> >(dataFloat,SIZE,"float multiple constant multiplies");
	test_constant<float, custom_multiple_constant_multiply2<float> >(dataFloat,SIZE,"float multiple constant multiply2");

	test_constant<float, custom_constant_divide<float> >(dataFloat,SIZE,"float constant divide");
	test_constant<float, custom_multiple_constant_divide<float> >(dataFloat,SIZE,"float multiple constant divides");
	test_constant<float, custom_multiple_constant_divide2<float> >(dataFloat,SIZE,"float multiple constant divide2");
	
	test_constant<float, custom_multiple_constant_mixed<float> >(dataFloat,SIZE,"float multiple constant mixed");

	summarize("float constant folding", SIZE, iterations, kDontShowGMeans, kDontShowPenalty );

	return 0;
}

static AS3_Val bench_double(void* self, AS3_Val args)
{
	// output command for documentation:
	int i;
	AS3_ArrayValue(args,"IntType, FloatType", &base_iterations, &init_value);
	printf("C++ benchmarks 'simple_types_constant_folding (bench_double)' with args : %d - %d\n", base_iterations, init_value);

// double
	::fill(dataDouble, dataDouble+SIZE, double(init_value));

	iterations = base_iterations;
	test_constant<double, custom_two<double> >(dataDouble,SIZE,"double constant");
	test_constant<double, custom_add_constants<double> >(dataDouble,SIZE,"double add constants");
	test_constant<double, custom_sub_constants<double> >(dataDouble,SIZE,"double subtract constants");
	test_constant<double, custom_multiply_constants<double> >(dataDouble,SIZE,"double multiply constants");
	test_constant<double, custom_divide_constants<double> >(dataDouble,SIZE,"double divide constants");
	
	summarize("double simple constant folding", SIZE, iterations, kDontShowGMeans, kDontShowPenalty );

	
	iterations = base_iterations / 10;
	test_constant<double, custom_constant_add<double> >(dataDouble,SIZE,"double constant add");
	test_constant<double, custom_multiple_constant_add<double> >(dataDouble,SIZE,"double multiple constant adds");

	test_constant<double, custom_constant_sub<double> >(dataDouble,SIZE,"double constant subtract");
	test_constant<double, custom_multiple_constant_sub<double> >(dataDouble,SIZE,"double multiple constant subtracts");

	test_constant<double, custom_constant_multiply<double> >(dataDouble,SIZE,"double constant multiply");
	test_constant<double, custom_multiple_constant_multiply<double> >(dataDouble,SIZE,"double multiple constant multiplies");
	test_constant<double, custom_multiple_constant_multiply2<double> >(dataDouble,SIZE,"double multiple constant multiply2");

	test_constant<double, custom_constant_divide<double> >(dataDouble,SIZE,"double constant divide");
	test_constant<double, custom_multiple_constant_divide<double> >(dataDouble,SIZE,"double multiple constant divides");
	test_constant<double, custom_multiple_constant_divide2<double> >(dataDouble,SIZE,"double multiple constant divide2");
	
	test_constant<double, custom_multiple_constant_mixed<double> >(dataDouble,SIZE,"double multiple constant mixed");

	summarize("double constant folding", SIZE, iterations, kDontShowGMeans, kDontShowPenalty );
	
	return 0;
}

// the end
/******************************************************************************/
/******************************************************************************/

// Alchemy entry point
int main()
{
	AS3_Val bench_int8_tMethod = AS3_Function(NULL, bench_int8_t);
	AS3_Val bench_uint8_tMethod = AS3_Function(NULL, bench_uint8_t);
	AS3_Val bench_int16_tMethod = AS3_Function(NULL, bench_int16_t);
	AS3_Val bench_uint16_tMethod = AS3_Function(NULL, bench_uint16_t);
	AS3_Val bench_int32_tMethod = AS3_Function(NULL, bench_int32_t);
	AS3_Val bench_uint32_tMethod = AS3_Function(NULL, bench_uint32_t);
	AS3_Val bench_int64_tMethod = AS3_Function(NULL, bench_int64_t);
	AS3_Val bench_uint64_tMethod = AS3_Function(NULL, bench_uint64_t);
	AS3_Val bench_floatMethod = AS3_Function(NULL, bench_float);
	AS3_Val bench_doubleMethod = AS3_Function(NULL, bench_double);
	
	AS3_Val result = AS3_Object("bench_int8_t: AS3ValType,\
				bench_uint8_t: AS3ValType,\
				bench_int16_t: AS3ValType,\
				bench_uint16_t: AS3ValType,\
				bench_int32_t: AS3ValType,\
				bench_uint32_t: AS3ValType,\
				bench_int64_t: AS3ValType,\
				bench_uint64_t: AS3ValType,\
				bench_float: AS3ValType,\
				bench_double: AS3ValType",
				bench_int8_tMethod, bench_uint8_tMethod, bench_int16_tMethod, bench_uint16_tMethod,
				bench_int32_tMethod, bench_uint32_tMethod, bench_int64_tMethod, bench_uint64_tMethod,
				bench_floatMethod, bench_doubleMethod);
				
	AS3_Release (bench_int8_tMethod);
	AS3_Release (bench_uint8_tMethod);
	AS3_Release (bench_int16_tMethod);
	AS3_Release (bench_uint16_tMethod);
	AS3_Release (bench_int32_tMethod);
	AS3_Release (bench_uint32_tMethod);
	AS3_Release (bench_int64_tMethod);
	AS3_Release (bench_uint64_tMethod);
	AS3_Release (bench_floatMethod);
	AS3_Release (bench_doubleMethod);
	
	AS3_LibInit (result);
	return 0;
}