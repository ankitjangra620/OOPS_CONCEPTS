#include <iostream>
#include <fstream>
#include <vector>
#include <string >
#include <typeinfo>

// This is a complete program you need to undetrstans the concepts of : 
// 1. Operator Overloading.
// 2. Friend function.
// 3. Constructors and The types of constructors.
// 4. File handling in c++.
// 5. getting input from the files and its functions.
// 6. Exceptions handling.
// 7. Vector Concepts.
// 8. Concepts of Pass By Reference and Pass By value.

using namespace std;

class Student
{
private:
    int roll;
    string className;
    vector<string> name;

public:
    Student()
    {
    }

    // Parameterised constructor :

    Student(int x, string y, string *arr, int size)
    {
        this->roll = x;
        this->className = y;
        for (int i = 0; i < size; i++)
        {
            // cout << arr[i] << "  ";
            name.push_back(arr[i]);
        }
    }

    void display()
    {

        cout << this->roll << "  " << this->className << "  ";

        for (auto it : this->name)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    // Overloading the operator << to write tpo file the data of the object
    friend ofstream &operator<<(ofstream &of, Student obj);

    friend ifstream &operator>>(ifstream &ifs, Student &obj);
};

ofstream &operator<<(ofstream &of, Student obj)
{
    of << obj.roll << "     " << obj.className << "    ";
    for (auto x : obj.name)
    {
        of << x << "   ";
    }

    of << endl;

    return of;
}

ifstream &operator>>(ifstream &ifs, Student &obj)
{
    if (ifs.is_open() && !ifs.eof())
    {
        string data;
        string x;
        ifs >> obj.roll >> obj.className;

        // // cout << data << " "<< x;

        for (int i = 0; i < 3; i++)
        {

            ifs >> data;
            obj.name.push_back(data);
        }

        // obj.display();
        return ifs;
    }
    else
    {
        throw "File is not open";
    }
}

int main()
{

    // Program regarding the File handling to provide the input and output to the files in c++.
    string arr[3] = {"Ankit", "Kumar", "Jangra"};
    // cout << typeid(&arr).name();
    cout << sizeof(arr) / sizeof(arr[0]);
    Student std1(5, "CSE", arr, sizeof(arr) / sizeof(arr[0]));
    Student std2(5, "CSE", arr, sizeof(arr) / sizeof(arr[0]));
    Student std3(5, "CSE", arr, sizeof(arr) / sizeof(arr[0]));
    Student std4(5, "CSE", arr, sizeof(arr) / sizeof(arr[0]));
    Student std5(5, "CSE", arr, sizeof(arr) / sizeof(arr[0]));
    try
    {
        // for (int i = 0; i < 3; i++)
        // {
        //     cout << arr[i] << " v ";
        // }
    }
    catch (string e)
    {
        cout << e;
    }

    ofstream outfile("my.txt", ios::trunc);

    // for (auto x : {0, 1, 2, 3, 4, 5})
    // {
    //     outfile << std1
    // }
    outfile << std1;
    outfile << std2;
    outfile << std3;
    outfile << std4;
    outfile << std5;

    // Now we have to read the content from the files.
    // eof function is used to show the end of file.

    // vector <Student*> obj;

    // This is just the object declations.
    Student x;

    // This is the object initialisation at the later on steps.
    // With the help of the Copy constructor;
    x = Student(42, "TEs", arr, sizeof(arr) / sizeof(arr[0]));
    outfile << x;
    ifstream iffile("my.txt");

    vector <Student > vect;
    int m = 0;
    while (!iffile.eof()) 
    {
        vect.resize(m+1);
        Student obj1;
        iffile >> obj1;
        vect[m] = obj1; // Or simply you can do Vect.push_back(obj1);
        m++;
    }

    for (auto x : vect){
        x.display();
    }

    cout <<vect.size();
    
    // obj1.display();
    outfile.eof();
    return 0;
}