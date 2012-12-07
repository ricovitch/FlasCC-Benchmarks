// virtual members
#include <TestBase.h>

class CPolygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
    virtual int area ()
      { return (0); }
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
	int a,b,c;
	CRectangle rect;
	CTriangle trgl;
	CPolygon poly;
	CPolygon * ppoly1 = &rect;
	CPolygon * ppoly2 = &trgl;
	CPolygon * ppoly3 = &poly;
	ppoly1->set_values (4,5);
	ppoly2->set_values (4,5);
	ppoly3->set_values (4,5);
	a = ppoly1->area();
	b = ppoly2->area();
	c = ppoly3->area();
}

int main () {
	TestBase test (testFunction, "class: virtual members");
	test.Exec (10);
	test.Exec (100);
	test.Exec (1000);
	test.Exec (10000);
	test.Exec (100000);
	test.Exec (1000000);
	test.Exec (10000000);
	return 0;
}