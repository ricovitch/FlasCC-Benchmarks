/*
    Copyright 2007-2008 Adobe Systems Incorporated
    Distributed under the MIT License (see accompanying file LICENSE_1_0_0.txt
    or a copy at http://stlab.adobe.com/licenses.html)
    
    Shared source file for timing, used by all the benchmarks
*/

/******************************************************************************/

//#include <time.h>
#include <sys/time.h>

/******************************************************************************/

/*  simple timer functions */
//clock_t start_time, end_time;
struct timeval start_time, end_time;
long mtime, seconds, useconds;

void start_timer() {
	//start_time = clock();
	gettimeofday(&start_time, NULL);
}

double timer() {
	/*end_time = clock();
	return (end_time - start_time)/ (double)(CLOCKS_PER_SEC);*/
	gettimeofday(&end_time, NULL);
    seconds  = end_time.tv_sec  - start_time.tv_sec;
    useconds = end_time.tv_usec - start_time.tv_usec;
    mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;
	return mtime;
}

/******************************************************************************/
