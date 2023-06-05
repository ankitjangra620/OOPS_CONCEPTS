#include <iostream>
#include <cmath>

#include <string>

using namespace std;
class B;

class A {
    private: 
        int val;
    public: 
        A(){

        }

        A(int v){
            val = v;
        }

        A doubleValue (){
            A x(val*2);

            return x;
        } 

        friend void printVal(A x, B y);
};

class B {
    private : 
        int name;
    public: 
        B(){

        }

        B(int v){
            name= v;
        }

        friend A A::doubleValue();
        friend void printVal(A x, B y);

        // To make all the functions of the class A as the friend functions of class B
        friend class A;
};


void printVal(A x, B y){
    cout << x.val << "   " <<  y.name << endl;
}

int main(){
    A obj1(10);
    B obj2(20);

    printVal(obj1, obj2);

    obj1.doubleValue();

    printVal(obj1, obj2);

    obj1.doubleValue();
    return 0;
}