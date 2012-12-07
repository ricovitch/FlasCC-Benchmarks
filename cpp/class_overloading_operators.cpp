// vectors: overloading operators example
#include <TestBase.h>

class CVector {
  public:
    int x,y;
    CVector () {};
    CVector (int,int);
    CVector operator + (CVector);
};

CVector::CVector (int a, int b) {
  x = a;
  y = b;
}

CVector CVector::operator+ (CVector param) {
  CVector temp;
  temp.x = x + param.x;
  temp.y = y + param.y;
  return (temp);
}

void testFunction ()
{
	CVector a (3,1);
	CVector b (1,2);
	CVector c;
	c = a + b;
}

int main () {
	TestBase test (testFunction, "vectors: overloading operators example");
	test.Exec (10);
	test.Exec (100);
	test.Exec (1000);
	test.Exec (10000);
	test.Exec (100000);
	test.Exec (1000000);
	test.Exec (10000000);
	return 0;
}