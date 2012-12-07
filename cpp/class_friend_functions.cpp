// friend functions
#include <TestBase.h>

class CRectangle {
    int width, height;
  public:
    void set_values (int, int);
    int area () {return (width * height);}
    friend CRectangle duplicate (CRectangle);
};

void CRectangle::set_values (int a, int b) {
  width = a;
  height = b;
}

CRectangle duplicate (CRectangle rectparam)
{
  CRectangle rectres;
  rectres.width = rectparam.width*2;
  rectres.height = rectparam.height*2;
  return (rectres);
}

void testFunction ()
{
	int result;
	CRectangle rect, rectb;
	rect.set_values (2,3);
	rectb = duplicate (rect);
	result = rectb.area ();
}

int main () {
	TestBase test (testFunction, "friend functions");
	test.Exec (10);
	test.Exec (100);
	test.Exec (1000);
	test.Exec (10000);
	test.Exec (100000);
	test.Exec (1000000);
	test.Exec (10000000);
	return 0;
}