/* 
Constant Variables: There are certain rules for declaration & initialization of constant variables. They prevent specific objects/variables from being modified.
    * Can't be left uninitialized at assignment.
    * Can't be assigned at assignment.
    * Explicit value needs to be provided to a constant variable.

Syntax: const datatype name = value:
    const data_type *var_name;
    (pointer variables to const value)

    datatype *const var_name;
    (when const pointer variable points to a value)

    int x{10};
    char y{'m'};

    const int *i = &x;
    const char *j = &y;

    x = 9;  // values of x & y can be altered
    y = 'A'; // they are not constant variables

    // *i = 6; // ERROR
    // *j = 7; // ERROR
    cout << *i << " " << *j; // 9 A

    // Constant pointer pointing to a variable location
    int x2 = 5, z2 = 6; 
    char y2 = 'A', p2 = 'c'; 
    int *const i2 = &x2;  
    char *const j2 = &y2;

    // Values stored at location can be modified even if we modify the pointer itself, no compile-time error
    *i2 = 10; 
    *j2 = 'D';

    // i2 = &z2; // ERROR
    // j2 = &p2; // ERROR

    cout << *i2 << "& " << *j2 << endl; // 10 & D
    cout << i2 << "& " << j2 << endl;   // 0x7ffed2dcc & D

    In a const function, a constant function returns a constant type value.

    const int foo3(int y) {
        y--;
        return y;
    }
    const int foo4(const int y) {
        // changing y will give an error
        return y;
    }

    int main() {
        int x = 9;
        const int z = 10;
        cout << foo3(x) << " " << foo3(z); // 8 9 
        cout << foo4(x) << " " << foo4(z); // 9 10 
    }
    Here both const and non-const parameters can be passed as const parameters to a function, but it's not allowed to change the value of the passed variable because the parameter is const.

Encapsulation:
    * Process of grouping data members into a single unit 
    * Information/data hiding 
    * Wrapping up data members & functions 
    * Data members <-> properties <-> encapsulation <-> Functions <-> Methods/Behaviour

    Advantages: 
    * Data hiding -> Security
    * If we want, we can make a class "read-only"
    * Code Reversibility 
    * Encapsulation -> Better Unit Testing 

    Data hiding hides unwanted information, restricting access to only members & methods together as a whole.
    Data binding binds data members & methods together as a whole.

Inheritance (reusability): Inheriting someone's characteristics & properties
        (receiving some properties)
                HUMAN   Parent Class/Superclass
                  |
                MALE     Subclass/Child Class

    Process of creating a new class from a derived class (existing class -> base class)
    Syntax: 
        class parent_class {---};
        class child_class : public parent_class {---};

    Access Modifiers: parent, public, protected 

    Class of Parent    | Inheritance Mode | Act in child class as
    =====================================================================
    Public             | Public           | Public
    Public             | Protected        | Protected
    Public             | Private          | Private
    ----------------------------------------------------------------------
    Protected          | Public           | Protected
    Protected          | Protected        | Protected  
    Protected          | Private          | Private
    ----------------------------------------------------------------------
    Private            | Public           | NA 
    Private            | Protected        | NA
    Private            | Private          | NA

    Constructor & friend function are never accessible.

    Protected: Similar to private, accessible in classes.

    Note: child class/derived can be accessed.

Types of Inheritance 
====================
    1) Single: A -> B
    2) Multi: A -> B -> C----- (3 or more than 3)
    3) Multiple (two or more parents of the same class): class C: public A, public B {...};
    4) Hierarchical (one grad parent, it's like a family tree or binary tree)
    5) Hybrid: Combination of all

    Whenever a derived class's default constructor is called, the base class's default construction is called automatically.

    Subclass is part of inheritance, an entity which inherits from another class. Also known as a child class.

Inheritance Ambiguity 
======================
    Happens in the case of multiple inheritance, like when parents have the same function, then which function will run when called from the child class. 
    To handle it, the Scope Resultant operator `->` or `::` can be used. 
    Also, `override` can be used.
    Example: child_class.Parent_class_A::function_abc;

Polymorphism: (to be displayed in more than one form)
    * Static members can't show polymorphism.

Types 
=====
    * Compile-time polymorphism
    * Run-time polymorphism (virtual, diamond-shaped inheritance, override)

Compile-Time Polymorphism
=========================
    * At any time, this particular entity will exist.
    * Static polymorphism 
    * Function Overloading & Operation Overloading 

    Function Overloading: Write one function multiple times.

    Syntax: 
        void say()                // VALID
        void say(---)             // VALID
        int say()                 // VALID
        int say(---)              // VALID

        void hello(string s)      // NOT VALID
        int hello(string s)       // NOT VALID

        void hello(string s)      // VALID
        int hello(string s, ---)  // VALID

    This is function overloading.

    Operation Overloading 
    ======================
    Overloading is not possible in these 4 operators: ::, ", ?, ^.

    Syntax: operator <Sign>(---)

    Example:
    class B {
        public:
        int a, b; 
        void operator+(B &obj) {
            cout << "Output " << (this->a) - obj.a; 
        }
    };
        
    int main() {
        B obj1, obj2;
        obj1.a = 4;
        obj2.a = 7;
        obj1 + obj2; // Output 3
    }

Run-Time Polymorphism
======================
    (dynamic, Method Overriding)

    Rules of Method Overriding 
    * Method (function name) of the parent class & child class must have the same rule. 
    * Only possible through inheritance. 
    * When a derived class has a definition, the occurrence when a derived class has a definition for a member function.

    Example:
    class Parent {
        public:
        void show() { cout << "Parent"; }
    };

    class Son : public Parent {
        public:
        void show() {
            cout << "I am son" << endl;
        }
    };
    int main() {
        Son s;
        s.show(); // I am son 
    }

    Here the flow is main -> Son -> Parent.

Polymorphism
============
    Compile Time: Early binding 
    Run Time: Late binding

    Compile Time: C++ compiler will select the required member function.
    Run Time: Required member function to call is established at run time.

    Compile Time: Static binding
    Run Time: Dynamic binding

    Compile Time: Functional & Operator overloading 
    Run Time: Virtual & Function overriding is slower in execution.

    Compile Time: Faster in execution
    Run Time: Slower in execution.

Abstraction 
===========
    * Implementation of hiding using access modifiers 
    * In class, we can use "Private" to hide from the public
    * Showing only implementation features 
    * Only you can use code
    * Example: class
    * Increase reusability 
    * Avoid duplication of code 
    * Hiding unnecessary details & provide flexibility to change things 
    * Method Overriding feature allows a Sub-Class to provide the implementation of the method overridden in the main class.

Abstraction vs Encapsulation 
============================
    Abstraction: Classes
    Encapsulation: Private, protected

    Abstraction: Process of gaining information
    Encapsulation: Methods help wrap up data into a single module

    Abstraction: For reducing code complexity
    Encapsulation: For data protection

    Abstraction: Problem in technique are solved at interface
    Encapsulation: Problem here solved at implementation level 

    Abstraction: Hiding unwanted details/information & showing useful data only
    Encapsulation: Hiding data using a single entity or using an entity to protect information 

    Abstraction: Implement using abstract classes & interfaces 
    Encapsulation: Implement using access modifiers like public, private, and protected

    Abstraction: Complexity of hiding implementation hiding using the interface & abstract class
    Encapsulation: Data hiding using getters and setters

    Abstraction: Can be performed using an object encapsulated with a single module 
    Encapsulation: Objects encapsulated don't need to be in abstraction

    Abstraction: Focus mainly on what should be done
    Encapsulation: Focus on what should be done

Virtual Functions
=================
    * Can't be static
    * Can be a friend function of another
    * Accessed using a pointer, reference of the base class type to achieve polymorphism
    * Prototype of a virtual function should be the same in the base as well as derived class
    * Always defined in the base class & overridden in derived classes. It is not mandatory for the derived class to override in that case the base function is used.
    * Can destructor 
    * It is runtime polymorphism
    * Can't Constructor

    class base {
        public:
            void func1() { cout << "b-1"; }
            virtual void func2() { cout << "b-2"; }
            virtual void func3() { cout << "b-3"; }
            virtual void func4() { cout << "b-4"; }
    };

    class derived : public base {
        public: 
            void func1() { cout << "d-1"; }
            void func2() { cout << "d-2"; }
        
            void func4(---) { cout << "d-4"; }
    }; 

    int main() {
        base* p; // dynamically
        derived obj1; 
        p = &obj1;
        p->func1(); // b-1
        p->func2(); // d-2 
        p->func3(); // b-3
        p->func4(); // b-4
        return 0;
    }
    Pure Virtual Function:
    class base { 
        public:
            virtual void show() = 0; 
    }; 

    Limitation of Virtual Function:
        * Slower
        * Difficulty

Friend Function:
================
    * Friend - class can be declared anywhere in the base class
    * Performs a single function in 2 different classes. The friend keyword is only used in classes, not in the main program.
    * friend return type func-name(class &ref)
    * Friend of a class is allowed to access public, private, or protected in that class.
    * Friend function in that class is allowed to access to public, private, or protected data in the same class. Friendship can't be inherited, and it is not mutual.
    * Non-member function class.
    * Friend function can be declared in any section, private, public, or protected.
    * Friend function is opposed because it opposes encapsulation.

    class A1;
    class A2 {
        int money = 10;
        friend void sum(A1, A2);
    };
    class A1 {
        int money = 20;
        friend void sum(A1, A2);
    };
    void sum(A1 &a1, A2 &a2) {
        cout << a1.money + a2.money;
    }
    int main() {
        A1 a1,  A2 a2; // friend function opposed, it breaks encapsulation 
    }
    Friend class accesses private & protected members.

OOP Advantage 
=============
    * OOP is faster & easier to execute 
    * OOP provides a clear structure for a program 
    * Helps to understand software utility
    * OOP helps to keep C++ code DRY "Don't Repeat Yourself" & makes code easier to maintain, modify, and debug
    * OOP makes it possible to create fully reusable applications with less code & shorter development time
    * Procedural programming is less secure compared to OOPS. Procedural Programming doesn't offer any method for hiding. It is less secure when compared to OOP. Hiding data is possible with OOPs due to abstraction. 
  
OOP Disadvantage
================
    * Steep learning curve
    * Larger program size 
    * Slower program
    * Not suitable for all types of problems

Unified Modeling Language (UML)
===============================
    Graphical Language 
    General Purpose Modeling Language
    Specifying, Viewing, Constructing

    * Simplifies complete software 
    * Reduces thousands of words to graphical explanations
    * Communication modeling

    ___________________
    | Class Name       | 
    |-----------------|
    | 1st attribute   |  
    | 2nd attribute   |
    |-----------------|
    | 1st method()    |
    | 2nd method()    |
    |_________________|

    datatype (optional)
    ---  or  (Association)
    *   many  

    if removed, then also exist 
    public    +ve 
    private   -ve
    protected  #

        /\
       /::\
      /::::\------ Composition => Does not exist if leading   (stronger removed)
      \::::/                      its symbol is generally solid black
       \::/
        \/

        /\
       /  \
      /    \------ Aggression => If removed, then also exist   (weaker removed) 
      \    /                      its symbol is generally border black
       \  /
        \/
   
     -------- => native union 
     
Notes 
=====
 * A commonly used way to access private data member in class is to create a public member function to access those data members. 
 * Data that needs encapsulated data which is prone to change soon.
 * Constructor executed when an object is created.
 * If a constructor with parameters is written, the default constructor is removed.
 * Ambiguity is diamond-shaped Inheritance.
 * If a class is declared with two objects, then a single copy of static data member & separate copy of non-static data members will be shared by both.
 * Abstract class can have 0 instances.
 * A class may have many friends.
 * If class A is a friend of class B, it implies that class B is not automatically a friend of class A. Friendship in C++ is not a symmetric relationship; it's a one-way access privilege. 
 * Note that both classes A and B can be friends at the same time. 
 * C++ extension of C class construct feature of Simula67.
 * In OOP, a function is known as a Method.
 * An Object is an instance.
 
 
 
 
We can create default arguments by only one:  
    void hello(int a = 2, int b = 6, string c = "A")
    hello(6) // a = 6, b = 6, c = "A"
 */

#include <iostream>
#include <string>
using namespace std;

// Constant Variables
const int x = 10;
const char y = 'm';

const int *const i = &x;
const char *const j = &y;

// Encapsulation
class EncapsulationExample {
private:
    const int data;
public:
    EncapsulationExample(int d) : data(d) {}
    int getData() const {
        return data;
    }
};

// Inheritance
class Parent {
public:
    virtual void show() const { cout << "Parent" << endl; }
};

class Son : public Parent {
public:
    void show() const override {
        cout << "I am son" << endl;
    }
};

// Polymorphism
class Animal {
public:
    virtual void makeSound() const {
        cout << "Animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() const override {
        cout << "Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() const override {
        cout << "Meow!" << endl;
    }
};

// Function Overloading
void hello(int a = 2, int b = 6, string c = "A") {
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
}

// Friend Function
class A1;
class A2 {
    int money = 10;
    friend void sum(const A1&, const A2&);
};

class A1 {
    int money = 20;
    friend void sum(const A1&, const A2&);
};

void sum(const A1 &a1, const A2 &a2) {
    cout << "Sum: " << a1.money + a2.money << endl;
}

int main() {
    // Constant Variables
    cout << *i << " " << *j << endl;

    // Encapsulation
    EncapsulationExample obj(5);
    cout << "Encapsulation example: " << obj.getData() << endl;

    // Inheritance
    Son s;
    s.show();

    // Polymorphism
    Animal *ptr;
    Dog d;
    Cat c;

    ptr = &d;
    ptr->makeSound();

    ptr = &c;
    ptr->makeSound();

    // Function Overloading
    hello(6);

    // Friend Function
    A1 a1;
    A2 a2;
    sum(a1, a2);

    return 0;
}
