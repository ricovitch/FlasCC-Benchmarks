// using namespace example
#include <TestBase.h>

namespace first
{
  int x = 5;
}

namespace second
{
  double x = 3.1416;
}

void testFunction ()
{
	int a;
	double b;
	{
		using namespace first;
		a = x;
	}
	{
		using namespace second;
		b = x;
	}
}

int main () {
	TestBase test (testFunction, "using namespace example");
	test.Exec (10);
	test.Exec (100);
	test.Exec (1000);
	test.Exec (10000);
	test.Exec (100000);
	test.Exec (1000000);
	test.Exec (10000000);
	return 0;
}