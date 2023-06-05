#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Hybrid Inheritance
// With the solutions of Diamond Problem using virtual keyword.

class Base{
    // this can be private but then it will not be accessible for the Child Classes
    // Child classes can't access the private memeber variabled in any of the conditions.
    protected: 
        int bprivate;
    public: 
        int bpublic;
        void printVal(){
            cout << "4  " << bprivate << " " << bpublic << endl;
            cout<< "End to print object."<<endl;
        }

    // Base () {
    //     cout<<"The Base Construcotr called" <<endl;
    // }

    Base(int a, int b){
        cout<<"The Base Construcotr called" <<endl;
        bprivate = a;
        bpublic = b;
    }

     ~Base(){
        cout<<"Base Destructor called" << endl;
    }
};

// Virtual will be used to solve the Diamond problem in inheritance.
class Derived11: virtual private Base{
      private: 
        int d11private;
    public: 
        int d11public;
        void printVal(){
            cout << "3  " << d11private << " " << d11public << endl;
        }

    Derived11(int a, int b, int c, int d): Base (c, d){
        cout << "The Derived 11 Constructor called"<< endl;
        d11private = a;
        d11public = b;
    }

     ~Derived11(){
        cout<<"Derived 11 Destructor called" << endl;
    }

};

class Derived12 : virtual public Base{
      protected: 
        int d12private;
    public: 
        int d12public;
        void printVal(){
            cout << "2  " << d12private << " " << d12public << endl;
        }

    Derived12(int a, int b, int c, int d): Base (c, d){
        cout<< "Derived 12 constructor called"<<endl;
        d12private = a;
        d12public  = b;
    }
    
     ~Derived12(){
        cout<<"Derived 12 Destructor called" << endl;
    }

};

class Derived2 : public Derived11, public Derived12{
      private: 
        int d2private;
    public: 
        int d2public;
        void printVal(){
            cout << "Start to print object " << endl;
            cout << "1  " << d2private << " " << d2public << endl;
            cout << "2  " << d12private << " " << d12public << endl;
            cout << "3  " << "Private" << " " << d11public << endl;
            cout << "4  " << bprivate << " " << bpublic << endl;
        }

    // Let us write the constructor to initialise all the values.
  
    // We have to pass all the constriuctor here only rather than it will not call all the constructors.
    // very important and complex mechanism
    Derived2(int a,int b,int c,int d,int e,int f,int g,int h): Derived12(c,d,g,h), Derived11(e,f,g,h), Base(g,h){
        cout << "The Derived 2 constructor called" << endl;
        d2private = a;
        d2public = b;
    }

    ~Derived2(){
        cout<<"Derived 2 Destructor called" << endl;
    }
};

int main(){
    
    Derived2 obj1(8,7,6,5,4,3,2,1);

    obj1.printVal();

    // Let us see the way and sequence of calling the destructor.

    // Concepts of Base pointer class to the Derived class;

    Base *p, *q;

    p = new Derived12(1,2,3,4);

    p->printVal();
    // It will access to the Base class print val

    // cout << p-> d12public;  THis gives error as no member available.

    // This will give error as this is private inheritance
    // p = new Derived11(1,2,3,4);

    q = new Derived2(8,7,6,5,4,3,2,1);
    q->printVal();


    return 0;
}