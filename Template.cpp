#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// Function Template : Program Name : BasicOOPS.cpp
// Class Templtae :
class A
{
public:
    int myVal = 10;

    A(auto val)
    {   
        this->myVal = val;
        cout << "The A default constructor called." << endl;
    }

    A (A &val){
        cout << "The A copy constructor is called - "<<endl;
        this->myVal = val.myVal;
    }
};

template <class T>
class B
{
public:
    T val;

    B (int x) {
        T obj(x);
        this = obj;
    }

    void display()
    {
        cout << "The B class Display function is called - " << val.myVal << endl;
    }
};

int main () {

    // Creating a valriable or object of class B with template of class A

    B <class A> obj(30);
}