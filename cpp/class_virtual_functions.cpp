#include <TestBase.h>
#include <string>
class Animal
{
protected:
    std::string m_strName;
 
    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    Animal(std::string strName)
        : m_strName(strName)
    {
    }
 
public:
    std::string GetName() { return m_strName; }
    virtual const char* Speak() { return "???"; }
};
 
class Cat: public Animal
{
public:
    Cat(std::string strName)
        : Animal(strName)
    {
    }
 
    virtual const char* Speak() { return "Meow"; }
};
 
class Dog: public Animal
{
public:
    Dog(std::string strName)
        : Animal(strName)
    {
    }
 
    virtual const char* Speak() { return "Woof"; }
};

string Report(Animal &rAnimal)
{
	string result = rAnimal.GetName() + " says " + rAnimal.Speak();
	return result;
}
 
void testFunction ()
{
	string a, b;
	Cat cCat("Fred");
    Dog cDog("Garbo");
    a = Report(cCat);
    b = Report(cDog);
}

int main () {
	TestBase test (testFunction, "class: virtual functions");
	test.Exec (10);
	test.Exec (100);
	test.Exec (1000);
	test.Exec (10000);
	test.Exec (100000);
	test.Exec (1000000);
	test.Exec (10000000);
	return 0;
}