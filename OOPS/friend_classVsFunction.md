### **Friend Function vs Friend Class**
---

#### **Friend Function**:
- **Usage**: Typically used for **operator overloading** or when you need a **non-member function** to access private/protected members of a class.
- **Declaration**: Declared inside the class using the `friend` keyword.
- **Access**: Allows the function (global or in another class) to access **private** and **protected** members of the class.
- **When to Declare**: Must be declared inside the class before it is used.
- It can called without object like -> NOT obj.display(X)   but directly display(X)
  
**Example**:
```cpp
class MyClass {
private:
    int x;
public:
    MyClass(int val) : x(val) {}
    
    // Friend function declaration
    friend void display(MyClass obj);
};

// Friend function definition
void display(MyClass obj) {
    std::cout << obj.x << std::endl;  // Access private member
}
```

---

#### **Friend Class**:
- **Usage**: A **class** is declared as a friend of another class to access its **private** and **protected** members.
- **Declaration**: Declared inside the class using the `friend` keyword.
- **Access**: Allows a whole class (or another class) to access private and protected members of the class.
- **Inheritance**: Not required to declare before use. If a class inherits from a friend class, it automatically has access to private/protected members of the base class.

**Example**:
```cpp
class ClassB;  // Forward declaration

class ClassA {
private:
    int secret;
public:
    ClassA(int val) : secret(val) {}

    // Declaring ClassB as a friend class
    friend class ClassB;
};

class ClassB {
public:
    void showSecret(ClassA& obj) {
        std::cout << obj.secret << std::endl;  // Access private member of ClassA
    }
};
```

---

### **Key Differences**:
- **Friend Function**:
  - External function (global or in another class).
  - Declared before usage inside the class.
  - Commonly used for operator overloading.

- **Friend Class**:
  - Entire class is given access to private/protected members.
  - Can be declared at any point in the class.
  - Used when one class needs access to another class’s private/protected data, especially in the context of inheritance.

---
