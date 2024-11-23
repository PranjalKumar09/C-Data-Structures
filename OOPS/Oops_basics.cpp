/* 
    OOP - revolves around data or objects rather than functions and logic.

    Things revolve around Object, Entity, and State. Objects generally have properties and behavior.

    By default, class members are private. (Group object is private).

    Class: Consider a class of cars. They have wheels, names, and designs. It is a user-defined data type that has data members and member functions.
    Data members: These are data variables and member variables, and together these define the properties and behaviors of objects in a class. A class is a way to bind data and its associated function together.

    Object: An instance of a class containing instances of members and behavior defined in class templates.

    To access properties and functions of data members, use dot (.) => .property_name.

    Mention the name of the file in the header.
    #include "Test.cpp" // to include a class from another file 




    Test.cpp file:
     __________________
    |class ----{       |
    |                  |
    |                  |
    |_};_______________|

    In the case of an empty class, only one memory is allocated, and the size of that class is 1; otherwise, the size is equal to that of the data size.

    'public': All will be publicly accessible below the 'public' keyword in the class.

    From the beginning, it is private, so no need to specify that.

    To access private members, we use getter, setter, or print function.

    void print(){
        cout << ----;
    }

    datatype get(){
        return ----;
    }

    void set(datatype value){
        ---- = value;
    }

    These three must be declared in public.

    Static allocation: class_name random_name;

    Dynamic allocation: class_name *random_name = new class_name;

    Four building blocks of OOP:
        Encapsulation        Polymorphism        Inheritance         Abstraction 

    We can also see the size of the included class by 'size ("test.cpp")'.

    class ab{
        int a1, a2;
        public:
            ---
    };

    ab b1, b2;

    //  accessing elements 
    b2.a1;
    b2.a1;

    // all are equal 
    size_of(ab);
    size_of(b1);
    size_of(b2);

    In dynamic: *---                          &--- 
                  |                            |
            value is an address              is an address
 
    We can also use "->" instead of (*a).b in dynamic (a->b).


    Constructor: Special methods involved automatically at the time of object creation.
        Properties:
            * Object Creation
            * No input needed (for default constructor) 
            * No return type
            * When we create our own constructor, then the private one vanishes.
                                                   Parameter 
            -> Default     |                        None 
            -> Parameterized    |-> constructor      One or more arguments
            -> Copy         |                   Object of the same class as the constructor's class    
             

             Parameterized: Using the "this" keyword 
                'this' => Store the current object's address in the word address in the current object.

            Example -> class Hero{
                    public : int health;
                    Hero(int health){
                        this->health = health;
                    }
                };

            Constructor calling: ClassName ab1, ab2(, );

            The address of a particular 'this' is the same as a particular '&ab'.

                cout << this; // inside class 
                cout << &ab; 


            Characteristics of OOPs 

            * Dynamic bonding     * Encapsulation   * Polymorphism      * Dynamic Bonding   * Abstraction   * Inheritance


            Printing class_name or &class_name gives an Error 


            Copy constructor: * Deep copy   * Shallow copy (default copy)   
                                For copying an existing object 
                Hero ( Hero &temp){
                    // if "Hero temp" is written, then it will get stuck in its loop 
                    this -> health = temp.health ;
                    this -> level = temp.level ;
                } 
                The process if members of an object through copy construction is known as copy initialization. Also called member-wise initialization. 


                Hero Copied(OldHero) // it is the same class as the functional argument

                
                Default copy: No copy function needed in the default copy in class. It is auto. (No function needed like above)

                Syntax: Class_name  New_class(old_class)  // already built 

                If we change the values of others also change here, address copy not valued copy in default 




    Static Functions: Object creation does not need the "this" keyword. They only access static members.

                class Ram {
                    public:
                    char *name;
                    int health;
                    char level; 
                    static int time;
                    // here time will start

                } 

                static int random()
                    cout << time;
                    // only access static member


            // Deep copy: entirely different memory created & value copied, not the address. If one changes, the other does not change.

                Ram (Ram &temp){
                    char *ch = new char[str_len(temp.name)++]
                    strcpy(ch, temp_name)
                    this->name=ch;
                    this->health = temp.health;
                    this->level = temp.level;
                }

            Destructor can be virtual. 
                Automatically created when an object goes out of scope. 
                It's not possible to make more than one destructor. 
                It can be virtual. 
                No return type. 
                No input type. 
                The same as constructor just has a "~" sign.
                For static allocation, the destructor is automatically created.
                For dynamic allocation, the destructor is automatically not created (by using delete).
                Can't access address. 
                ~Ram(){
                    cout << "Destructor launched" << endl;
                    
                }

            // to initialize the static datatype syntax
               <data_type> <Classname> :: <field_name> = value;
                    };

            We should initialize static outside the class.
            int Ram :: time = 5;

            int main() {
                -----
                -----
                Ram t_static;  // it will delete automatically
                Ram *t_dynamic = new Ram;
                delete t_dynamic;// we have to delete 
                cout << Ram :: time; // recommended
                Ram Hanuman;
                cout << Hanuman.time; // not recommended 
                // in both cases, the answer is 5


                // but in the below case it comes 1 
                cout << Ram :: randome;
                }



B child classes of A
and C child classes of B

Constructor order => A=>B=>C
Destructor order => C=>B=>A


 */
#include <iostream>
#include <cstring>

using namespace std;

class Ram;

class ab {
    int a1, a2;
public:
};

// Class definition for class Hero
class Hero {
public:
    int health;

    // Parameterized constructor
    Hero(int health) {
        this->health = health;
    }

    // Copy constructor
    Hero(const Hero &temp) {
        this->health = temp.health;
    }
};

// Class definition for class Ram
class Ram {
public:
    char *name;
    int health;
    char level;
    static int time;

    // Constructor
    Ram(const char *name, int health, char level) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->health = health;
        this->level = level;
    }

    // Destructor
    ~Ram() {
        cout << "Destructor launched" << endl;
        delete[] name;
    }

    // Static function
    static int random() {
        return time;
    }
};

int Ram::time = 5;



// Virtual function
class Base {
public:
    void func1() { cout << "Base func1\n"; }
    virtual void func2() { cout << "Base func2\n"; }
    virtual void func3() { cout << "Base func3\n"; }
    virtual void func4(int x) { cout << "Base func4 with int: " << x << "\n"; }
};
class Derived1 : public Base {
public:
    void func1() { cout << "Derived func1\n"; } // Hides Base func1
    void func2() override { cout << "Derived func2\n"; } // Overrides Base func2
    // Not overriding func3, Base func3 will be called
    void func4(int x) override { cout << "Derived func4 with int: " << x << "\n"; } // Overrides Base func4
};
class Derived2 : public Base {
public:
    // Not overriding func1, func2, func3, func4
};
class Derived3 : public Base {
public:
    void func1() { cout << "Derived3 func1\n"; } // Hides Base func1
    void func2(int x) { cout << "Derived3 func2 with int: " << x << "\n"; } // Overloads func2, not overrides
    void func4() { cout << "Derived3 func4 without parameters\n"; } // Overloads func4, not overrides
};
void callFunctions(Base* p) {
    p->func1();
    p->func2();
    p->func3();
    p->func4(10);
}





int main() {
    ab b1, b2;
    Hero Hanuman(100);
    Ram t_static("Static Ram", 100, 'A');
    Ram *t_dynamic = new Ram("Dynamic Ram", 100, 'B');

    delete t_dynamic;

    // Accessing static member using class name
    cout << "Static time: " << Ram::time << endl;

    // Accessing static member using object
    cout << "Static time from object: " << t_static.time << endl;

    // Accessing static member function
    cout << "Random time: " << Ram::random() << endl;

    // Accessing dynamic member of Ram
    cout << "Dynamic Ram name: " << t_static.name << endl;





    // Virtual
    Base base;
    Derived1 derived1;
    Derived2 derived2;
    Derived3 derived3;

    cout << endl << endl<<  "Calling functions on Base object:\n";
    callFunctions(&base);
    
    cout << "\nCalling functions on Derived object:\n";
    callFunctions(&derived1);

    cout << "\nCalling functions on Derived2 object:\n";
    callFunctions(&derived2);

    cout << "\nCalling functions on Derived3 object:\n";
    callFunctions(&derived3);

    return 0;
}
