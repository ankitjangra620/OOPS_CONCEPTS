#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// A template type of struct which will be used inside the class to declare its member variables.
template <typename X, typename Y>
struct Comp
{
    X real;
    Y img;
};

// Illustrations using the class example of the complex numbers to implement all the concepts.

// Class Declarations
class Complex
{
private:
    string name;
    struct Comp<float, int> complex;
    static const int stat = 200;

public:
    Complex()
    {
        // This is the defailt constructor object.
    }

    Complex(string name, auto real, auto img)
    {
        cout << "Default constructor values  =  " << name << " " << real << "  " << img << endl;
        this->name = name;
        this->complex.real = real;
        this->complex.img = img;
    }

    // iF WE use Complex(Complex c) -> it will cause recusrsion as c will call another constructor and it will cause a infinite calls of functions.
    Complex(Complex &c)
    {
        // This is the Copy constructor..
        this->name = c.name;
        this->complex = c.complex;
    }

    void printObject();

    // We also has the functionality of friend operator overloaded functions.
    friend Complex operator+(Complex obj1, Complex obj2);

    // Friend function declarations for the << operator
    friend ostream &operator<<(ostream &os, Complex &r);

    // Let us understand the overloading of ++ and -- operator which are the Increament and Decreament operator.
    // Pre increament
    Complex &operator++()
    {
        name = "Ankit";
        complex.real += 1;
        complex.img += 1;
    }

    // Post increament
    Complex &operator++(int)
    {
    }

    // The destructor function of the Complex class.
    ~Complex()
    {
        cout << "Destructor called";
    }
};

Complex operator+(Complex obj1, Complex obj2)
{
    Complex c1;

    c1.name = obj1.name + obj2.name;
    c1.complex.real = obj1.complex.real + obj2.complex.real;
    c1.complex.img = obj1.complex.img + obj2.complex.img;

    return c1;
}

void Complex::printObject()
{
    cout << "The object initialise values are as = " << this->name << " " << this->complex.real << " " << this->complex.img << endl;
}

// ostream and istream operator overloading using friend functions..
ostream &operator<<(ostream &os, Complex &r)
{
    os << "The values output using the ostream output operator  =  " << r.name << endl;
    return os;
}

int main()
{

    Complex obj1("first", 10, 20);
    obj1.printObject();

    Complex obj2 = obj1;

    Complex temp;
    temp = obj1 + obj2;
    Complex obj3(temp);

    obj3.printObject();

    cout << obj3;

    return 0;
}