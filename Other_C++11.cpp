#include <iostream>
#include <memory>
#include <string>
#include <cstdarg>
using namespace std;
// The program to explore the functionalities of the gives things:
// 1. Final Keyword.
// 2. Lambda function.
// 3. Types of Pointers: unique_ptr, shared_ptr, weak_ptr;
// 4. Constructor Delegation
// 5. Elipses in C++

// The Final Keyword is used for the Restricted Class
// The final is used to avoid this class being inhertied by any other class.
// final Keyword implementation
// class Example final {
//     public :
//         int value;

//     // Final Keyword Restricted Method overriding -> It will not let override this function .
//     virtual void display () final {

//     }
// };

// class ExampleTemp: public Example{
//     public :
//         int value2;

//         void display(){

//         }
// };

class Test
{
public:
    int x;
    int y;

    Test(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    // This concept is known as Constructor Delegation.
    Test() : Test(10, 20)
    {
    }

    void display()
    {
        cout << "The values initialised with the constructor delegations is = " << x << "  " << y << " " << endl;
    }
};

// The Sum function to under stand the concept of elipses in c++.

int sum(int n, ...)
{
    auto x = 0;
    va_list list;

    // cout << "List" << list << endl;
    va_start(list, n); // -> This is used to initialise the list.
    cout << "List" << list << endl;

    for ( auto i : {2,1,0}){
        cout << va_arg(list, int);
    }

    return x;
}

int main()
{

    int z = 10;
    string hello = "Ankit Jangra";

    // 1. Lambda function with no capture list;

    auto val = [](int x) -> int
    {
        return x * 2;
    }(10);

    cout << "The first Lambda value is - " << val << endl;

    // 2. The lambda function with a capture list and update the variables inside the capture list.
    auto val2 = [&z](int x) -> int
    {
        z++;
        return x * 10;
    };

    cout << "The Second lamda function value is = " << val2(10) << " The value of Z is = " << z << endl;

    auto val3 = [&](int x) -> int
    {
        z++;
        hello = "Hello Ankit Jangra.";
        return x * 10;
    };

    cout << "The Three lamda function value is = " << val3(10) << " The value of Z is = " << z << endl
         << hello << endl;

    Test test;

    test.display();

    cout << "The sum values are as follows  =  " << sum(3, 1, 2, 3);
    return 0;
}
