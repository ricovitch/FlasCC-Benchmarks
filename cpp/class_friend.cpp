// friend class
#include <TestBase.h>

class CSquare;

class CRectangle {
    int width, height;
  public:
    int area ()
      {return (width * height);}
    void convert (CSquare a);
};

class CSquare {
  private:
    int side;
  public:
    void set_side (int a)
      {side=a;}
    friend class CRectangle;
};

void CRectangle::convert (CSquare a) {
  width = a.side;
  height = a.side;
}

void testFunction ()
{
	int result;
	CSquare sqr;
	CRectangle rect;
	sqr.set_side(4);
	rect.convert(sqr);
	result = rect.area();
}

int main () {
	TestBase test (testFunction, "friend class");
	test.Exec (10);
	test.Exec (100);
	test.Exec (1000);
	test.Exec (10000);
	test.Exec (100000);
	test.Exec (1000000);
	test.Exec (10000000);
	return 0;
}