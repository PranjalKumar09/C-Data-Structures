#include <iostream>
#include <string>
using namespace std;

class Person
{
    string name;
    int age;

public:
    // Default constructor
    Person()
    {
        name = "NoName";
        age = 0;
    }

    // Friend functions to allow access to private members
    friend ostream &operator<<(ostream &output, const Person &p);
    friend istream &operator>>(istream &input, Person &p);
};

// Overloading << operator for output
ostream &operator<<(ostream &output, const Person &p)
{
    output << "Name: " << p.name << endl
           << "Age: " << p.age << endl;
    return output; // Return the stream for chaining
}

// Overloading >> operator for input
istream &operator>>(istream &input, Person &p)
{
    input >> p.name >> p.age;
    return input; // Return the stream for chaining
}

int main()
{
    Person p;

    cout << "Enter Name and Age: " << endl;
    cin >> p;

    cout << "Person Details: " << endl;
    cout << p;

    return 0;
}

/*
Notes:
- `cin` is an object of `istream`, while `cout` is an object of `ostream`.
- `>>` and `<<` cannot be member functions of the `Person` class because `cin` and `cout` belong to other classes.
- Friend functions allow access to private members and enable operator overloading for custom behavior.
*/
