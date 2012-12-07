// function template
#include <TestBase.h>

template <class T>
T GetMax (T a, T b) {
	T result;
	result = (a>b)? a : b;
	return (result);
}

void testFunction ()
{
	int i=5, j=6, k;
	long l=10, m=5, n;
	k = GetMax<int> (i,j);
	n = GetMax<long> (l,m);
}

int main () {
	TestBase test (testFunction, "Function Template");
	test.Exec (10);
	test.Exec (100);
	test.Exec (1000);
	test.Exec (10000);
	test.Exec (100000);
	test.Exec (1000000);
	test.Exec (10000000);
	
	return 0;
}