// template specialization
#include <TestBase.h>

// class template:
template <class T>
class mycontainer {
    T element;
  public:
    mycontainer (T arg) {setElement (arg);}
	void setElement (T arg) {element=arg;}
	T getElement () {return element;}
    T increase () {return ++element;}
};

// class template specialization:
template <>
class mycontainer <char> {
    char element;
  public:
    mycontainer (char arg) {setElement (arg);}
	void setElement (char arg) {element=arg;}
	char getElement () {return element;}
    char uppercase ()
    {
      if ((element>='a')&&(element<='z'))
      element+='A'-'a';
      return element;
    }
};

void testFunction ()
{
	mycontainer<int> myint (1);
	mycontainer<char> mychar ('a');
	myint.setElement (2);
	mychar.setElement ('b');
	myint.increase();
	mychar.uppercase();
	myint.getElement();
	mychar.getElement();
}

int main () {
	TestBase test (testFunction, "Class template with specialization");
	test.Exec (10);
	test.Exec (100);
	test.Exec (1000);
	test.Exec (10000);
	test.Exec (100000);
	test.Exec (1000000);
	test.Exec (10000000);
	return 0;
}