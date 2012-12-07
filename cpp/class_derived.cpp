// derived classes
#include <TestBase.h>

class CPolygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b;}
  };

class CRectangle: public CPolygon {
  public:
    int area ()
      { return (width * height); }
  };

class CTriangle: public CPolygon {
  public:
    int area ()
      { return (width * height / 2); }
  };

void testFunction ()
{
	int a,b;
	CRectangle rect;
	CTriangle trgl;
	rect.set_values (4,5);
	trgl.set_values (4,5);
	a = rect.area();
	b = trgl.area();
}

int main () {
	TestBase test (testFunction, "derived classes");
	test.Exec (10);
	test.Exec (100);
	test.Exec (1000);
	test.Exec (10000);
	test.Exec (100000);
	test.Exec (1000000);
	test.Exec (10000000);
	return 0;
}