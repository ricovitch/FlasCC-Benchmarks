#include <iostream>
#include <time.h>

int intGetMax (int a, int b)
{
	int result;
	result = (a>b)? a : b;
	return (result);
}

long longGetMax (long a, long b)
{
	long result;
	result = (a>b)? a : b;
	return (result);
}

int main () {
	int i=5, j=6, k;
	long l=10, m=5, n;
	int inc, inc2;
	
	printf ("computing...\n");
	clock_t t = clock();
	for (inc=0; inc<10000; inc++) {
		for (inc2=0; inc2<10000; inc2++) {
			k = intGetMax (i,j);
			n = longGetMax (l,m);
		}
	}
	t = clock() - t;
	printf ("%fsec\n", ((float)t)/CLOCKS_PER_SEC);
	
	return 0;
}