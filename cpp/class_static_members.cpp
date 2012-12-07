// static members in classes
#include <TestBase.h>

class CDummy {
  public:
    static int n;
    CDummy () { n++; };
    ~CDummy () { n--; };
};

int CDummy::n=0;

void testFunction ()
{
	CDummy a;
	CDummy b[5];
	CDummy * c = new CDummy;
	delete c;
}

int main () {
	TestBase test (testFunction, "static members in classes");
	test.Exec (10);
	test.Exec (100);
	test.Exec (1000);
	test.Exec (10000);
	test.Exec (100000);
	test.Exec (1000000);
	test.Exec (10000000);
	return 0;
}