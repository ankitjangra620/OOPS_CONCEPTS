#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

// Concept of Polymorphism

// Abstract class will be the abstract class.

class Abstract {
    public :
        // The Pure Virutal Fucntion of the class.
        virtual void Function() = 0;
};


class Person {
    protected : 
        int age;
    public : 
        Person (int y){
            this -> age = y;
        }

        Person(){

        }

        // Making this function virtual for the purpose of late binding 
        virtual void printAge(){
            cout << "Person Class Age Function  -  " << "The age of the Person is  =  " << this->age <<endl;
        }  

        // To illustrate the Data Hiding Part, This function will not be accessible by the object of the derived class/
        void hideThisFunction(){
            cout << "Hided this functions." << endl;
        }
};

class Employee: public Person, public Abstract {
    private : 
        int  salery;
    public: 
        Employee() {

        }

        Employee(int x, int y) : Person(x){
            this->salery = y;
        }
        // Concept of Function overriding.
        void printAge(){
            cout << "Employee Class Age Function  -  " << "The Age of the Employee is = " << this -> age << endl;
        }

        void printSalery(){
            cout << "Employee Class Salery Function  -  " << "The Salery of the Employee is = " << this -> salery << endl;
        }

        void hideThisFunction (int x){
            cout<<"Hided this functions in derived class" << endl;
        }

        // We have to override the function of the abstract class otherwise this will also work as the Abstract class.
        void Function () {
            cout << "The Abstract Class Functions in Employee class."<<endl;
        }
};

class Husband: public Person {
    private : 
        string wifeName;
    public: 
    
      static int x;

        Husband(int x, string y) : Person(x){
            this->wifeName = y;
        }

        void printAge(){
            cout << "Husband Class Age Function  -  " << "The Age of the Husband is = " << this -> age << endl;
        }

        void printWifeName(){
            cout << "Husband Class Salery Function  -  " << "The WifeName of the Husband is = " << this -> wifeName << endl;
        }
        
    // Concept of inner class: 
        class Son {
            public: 
                int val;

                Son(){

                }

                Son(int m){
                    this -> val = m;
                }

                void printX(){
                    x = 2003;
                    cout << "The value of the static Data member in Inner class is as = " << x << endl;
                }

        };

        Son obj1;

        void printInner(){
            obj1.val = 200;
            cout << "The inner class val is  =  " << obj1.val << endl;

            obj1.printX();
        }

        // The static function to change the values of the static functions
        static void ChangeX(int val) {
            x= val;
        }


};

int Husband :: x = 2001;

int main () {

    Employee obj1(10, 10000);

    Person * p;

    p =  new Employee(20, 20000);

    obj1.printAge();

    p -> printAge();

    // Which function will these two call as the function of the base class has been hided from here.
    obj1.hideThisFunction(10);

    // This can only call the function in the base class as this is the pointer of the base class.
    p -> hideThisFunction();

    Husband obj3(30, "Neha");
    
    obj3.printAge();
    obj3.printWifeName();

    cout << "The static member of class Husband before change is = " << Husband :: x <<endl;

    Husband::ChangeX(2002);

    cout << "The static member of class Husband after change is = " << Husband :: x <<endl;

    obj3.printInner();


    cout << "The static member of inner class Son after change is = " << Husband :: x <<endl;



    return 0;
}