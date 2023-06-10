#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class MyExceptionsClass
{
public:
    int myException = 10;

    MyExceptionsClass()
    {
    }
};

ostream &operator<<(ostream &os ,MyExceptionsClass x)
{
    os << " - This is consoled using the  << operator overloading - " << x.myException;

    return os;
}


// Inherting from the Exceptions class.

class ExtendedExceptionsClass : public exception{
    char *what(auto val){
        cout << "In My Custom Extended Exception class extended from the noraml exception class " << val <<endl;
    }
};


// Let us understand the concept of try and catch block statements

void throwExceptions(int a)
{
    // We can do this only of we have extended the class
    throw ExtendedExceptionsClass();
    if (a == 0)
    {
        MyExceptionsClass val;
        throw val;
    }
    if (a < 5)
    {
        throw 5;
    }
    if (a < 10)
    {
        string z = "10";
        throw z;
    }
    if (a < 15)
    {
        throw true;
    }
    throw '1';
}

int main()
{

    try
    {
        // Multiple Throw catch statemnets
        try
        {
            throwExceptions(0);
            // throwExceptions(4);
            // throwExceptions(7);
            throwExceptions(12);
            // throwExceptions(17);
        }
        // This time this inner catch statements will fire.
        catch (bool e)
        {
            cout << "5. The Exception occured during the function call is = " << e << endl;
        }
    }
    // The catch statement for the user defined class to be used for the Exceptions throwing.
    catch (MyExceptionsClass e)
    {
        cout << "3. The Exception occured during the function call is = " << e << endl;
    }
    // We can have different type of the catch parameters according to the exceptions whichh has been throws.
    // Here the bool type is above the int type because otherwise the int will take the bool as 0 or 1 ans will fire its statements.
    catch (bool e)
    {
        cout << "3. The Exception occured during the function call is = " << e << endl;
    }
    catch (int e)
    {
        cout << "1. The Exception occured during the function call is = " << e << endl;
    }
    catch (string e)
    {
        cout << "2. The Exception occured during the function call is = " << e << endl;
    }
    // There is also a general exceptions if any of the catch statements doesn't matcg
    catch (...)
    {
        cout << "4. The Exception occured during the function call can't be consoled." << endl;
    }

    return 0;
}