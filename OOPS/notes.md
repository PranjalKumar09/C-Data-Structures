 ### **Overloading Friend Functions**
1. **Scenarios of Overloading:**  
   - **`c1 = c2 + c3;`**  
     - Works with or without friend functions because the addition operator can access both `c2` and `c3`.  
   - **`c1 = c2 + 5;`**  
     - Works only with friend functions since `5` is not an object and cannot access class internals without a friend function.  
   - **`c1 = 5 + c3;`**  
     - Only possible with a friend function because `5` is not an object of the class and cannot invoke member functions.

---

### **Class vs. Object**
| **Class**                               | **Object**                                   |
|-----------------------------------------|---------------------------------------------|
| Blueprint or template for creating data | Instance of a class, occupying memory       |
| Logical entity                          | Physical entity                             |
| Declared using the `class` keyword      | Created dynamically using `new` or statically |
| Does not occupy memory                  | Occupies memory when instantiated          |
| Declared once                           | Multiple objects can exist simultaneously  |

---

### **Procedural Oriented Programming vs. Object-Oriented Programming**
| **POP (Procedural-Oriented Programming)** | **OOP (Object-Oriented Programming)**       |
|-------------------------------------------|---------------------------------------------|
| Focuses on algorithms                     | Focuses on data and its encapsulation       |
| Programs divided into functions           | Programs divided into objects               |
| Requires less memory                      | Generally requires more memory             |
| Uses a top-down approach                  | Uses a bottom-up approach                  |
| No access specifiers                      | Supports public, private, and protected specifiers |
| Function and operator overloading not supported | Supports overloading                     |
| Low data security                         | High data security                         |
| No data binding                           | Supports data binding                      |

---

### **Avoiding Ambiguity in Inheritance**

#### **Using Scope Resolution Operator**
- Example:  
  ```cpp
  Obj.ClassB::a = 10;
  Obj.ClassC::a = 100;
  ```

#### **Using Virtual Base Classes (Diamond Problem Resolution)**

```cpp
class ClassA {
public:
    int a;
};

class ClassB : virtual public ClassA {
public:
    int b;
};

class ClassC : virtual public ClassA {
public:
    int c;
};

class ClassD : public ClassB, public ClassC {
public:
    int d;
};

int main() {
    ClassD obj;
    obj.a = 100;  // Resolves ambiguity
    obj.b = 20;
    obj.c = 30;
    obj.d = 40;

    cout << obj.a; // 100
    cout << obj.b; // 20
    cout << obj.c; // 30
    cout << obj.d; // 40

    return 0;
}
```

---

### **Return by Reference**
1. **Purpose:** Allows modification of the returned value as if it's an alias to the original variable.  
2. **Syntax:**
   ```cpp
   datatype& functionName(parameters);
   ```

3. **Example:**
   ```cpp
   int& returnValue(int& x) {
       cout << "x = " << x << ", Address of x = " << &x << endl;
       return x;
   }

   int main() {
       int a = 20;
       int& b = returnValue(a); // b becomes an alias of a
       cout << "a = " << a << ", Address of a = " << &a << endl;
       cout << "b = " << b << ", Address of b = " << &b << endl;

       returnValue(a) = 13; // Changes the value of a via alias
       cout << "a = " << a << ", Address of a = " << &a << endl;

       return 0;
   }
   ```

4. **Output:**
   ```
   x = 20, Address of x = 0x7ff...
   a = 20, Address of a = 0x7ff...
   b = 20, Address of b = 0x7ff...
   x = 13, Address of x = 0x7ff...
   a = 13, Address of a = 0x7ff...
   ```

5. **Key Takeaways:**
   - References are aliases to variables.
   - They do not occupy new memory.
   - Returning a reference allows modifications to the original variable through the returned value.  

--- 

### **Additional Notes**
- **References vs. Pointers:** References are simpler but less flexible; pointers allow for dynamic memory manipulation


---

### **Why Not Return a Local Variable by Reference?**
- **Reason:**  
  Local variables exist in the stack memory and are destroyed once the function exits. Returning a reference to such a variable leads to undefined behavior because the reference points to a memory location that no longer holds valid data.
  
- **Security Concern:**  
  Returning a dangling reference could lead to accidental data manipulation, or in some cases, malicious exploitation.

---

### **Call by Value vs. Call by Reference**

| **Call by Value**                 | **Call by Reference**                |
|-----------------------------------|--------------------------------------|
| Passes a copy of the value         | Passes the address of the variable   |
| Modifications do not affect original value | Modifications directly affect the original value |
| Simple to implement               | Requires pointers or references      |
| Suitable for small data sets      | Suitable for large data sets         |

---

### **Examples**

#### **Pass by Reference**
```cpp
void work(int &x) { 
    x++; 
    cout << x << endl; 
}

int main() {
    int a = 10;
    work(a); // Modifies 'a' directly
    cout << a; // Output: 11
    return 0;
}
```
- **Output:**  
  ```
  11
  11
  ```

---

#### **Pass by Pointer**
```cpp
void work(int *x) {
    (*x)++; 
    cout << *x << endl;
}

int main() {
    int a = 10;
    work(&a); // Pass address of 'a'
    cout << a; // Output: 11
    return 0;
}
```
- **Output:**  
  ```
  11
  11
  ```

---

### **Key Differences Between Pointers and References**

| **References**                             | **Pointers**                               |
|-------------------------------------------|-------------------------------------------|
| Acts as an alias for another variable      | Stores the memory address of a variable   |
| Cannot be null                             | Can be null                               |
| Once initialized, cannot change what it refers to | Can point to different variables       |
| Automatically dereferenced                 | Requires explicit dereferencing           |
| More abstract and safer                    | Offers more control, but riskier          |

---

### **Example: Pass by Reference**
```cpp
void modifyValue(int &x) {
    x = x * 2;
}

int main() {
    int num = 5;
    modifyValue(num); // Directly modifies 'num'
    cout << num; // Output: 10
    return 0;
}
```

---

### **Example: Pass by Pointer**
```cpp
void modifyValue(int *ptr) {
    *ptr = *ptr * 2;
}

int main() {
    int num = 5;
    modifyValue(&num); // Pass address of 'num'
    cout << num; // Output: 10
    return 0;
}
```

---

### **Dynamic Object Management**
1. **Pointer to Object**
   ```cpp
   class ClassName {
   public:
       void show() { cout << "Object created dynamically!" << endl; }
   };

   int main() {
       ClassName *ptr_obj = new ClassName(); // Dynamic object creation
       ptr_obj->show(); // Access members using pointer
       delete ptr_obj;  // Free allocated memory
       return 0;
   }
   ```

2. **Reference to Dynamic Object**
   ```cpp
   class ClassName {
   public:
       void show() { cout << "Dynamic object referenced!" << endl; }
   };

   int main() {
       ClassName &ref = *(new ClassName()); // Reference to dynamic object
       ref.show(); // Access members directly
       delete &ref; // Free allocated memory
       return 0;
   }
   ```

---

### **Access Specifiers: Class vs. Structure**

| **Class**                                  | **Structure**                              |
|-------------------------------------------|-------------------------------------------|
| Mutable reference type                     | Immutable value type                      |
| Supports inheritance                       | Does not support inheritance              |
| Managed by ARC (Automatic Reference Counting) | Stack allocated                          |
| Shared references (copy semantics)         | Copies on assignment                      |
| Slightly less performant due to reference counting | More performant for simple data        |
| Best for shared, mutable state and inheritance | Best for simple, immutable data types    |

---

### **Friend Function**
1. **Definition:**  
   A **friend function** is a non-member function that can access private and protected members of a class. It can be a:
   - **Global Function**
   - **Member Function of Another Class**

2. **Syntax:**
   - **Global Friend Function:**
     ```cpp
     class ClassName {
         friend void functionName(ClassName &obj);
     };
     ```
   - **Friend Function in Another Class:**
     ```cpp
     class ClassA {
         friend void ClassB::functionName(ClassA &obj);
     };
     ```

3. **Example:**
   ```cpp
   class FriendExample {
   private:
       int data;

   public:
       FriendExample() : data(0) {}
       friend void showData(FriendExample &obj);
   };

   void showData(FriendExample &obj) {
       cout << "Data: " << obj.data << endl;
   }

   int main() {
       FriendExample obj;
       showData(obj);
       return 0;
   }
   ```

   - **Output:**  
     ```
     Data: 0
     ```




### **Array of Class Objects in C++**

In C++, we can create arrays of objects of a class just like we can with basic data types like `int`, `char`, etc. Here's how:

```cpp
int main() {
    ClassName variable_abc[100];  // Array of ClassName objects with 100 elements
}
```

- **Constructor for Class Array Elements:**
    ```cpp
    ClassName xyz[100];  // Array of 100 ClassName objects
    // Constructor for each element will be called, one by one.
    ```

  - You can explicitly call a constructor while initializing each object in the array (like using a constructor with arguments), but you cannot use array initialization syntax with constructors that have parameters directly.

- **Accessing Object Data at a Different Index:**
    ```cpp
    xyz[0].someMemberFunction();  // Call member function of the first object
    xyz[1].someMemberFunction();  // Call member function of the second object
    ```

### **Global Variables and Local Scope**

```cpp
int c = 9;  // Global variable

int main() {
    int c = 8;  // Local variable
    cout << "Global c is " << ::c;  // Output: Global c is 9
    return 0;
}
```
- **Explanation:**
  - `::c` refers to the global `c`, while the local variable `c` is accessed without the `::`.
  
### **Static and Const in C++**

Both `static` and `const` can be used together, but they serve different purposes:

- **Static:**
  - **Global Static Variables:** A `static` variable at the global level means it has internal linkage, i.e., it can only be accessed within the same translation unit (source file).
  - **Local Static Variables:** A static local variable maintains its value across multiple function calls (retains the last modified value).
  
- **Const:**
  - A `const` variable is a read-only variable, meaning it cannot be modified after initialization.
  - You can use `const` in combination with `static` for variables that remain constant across calls but are limited to the scope of the file or function.

- **Example of Static and Const Together:**
  ```cpp
  static const int MAX_SIZE = 100;  // 'MAX_SIZE' is constant and static within the file
  ```

### **Accessing Global Variables When Local Variables Have the Same Name**

If both a global and a local variable share the same name, the local variable will "shadow" the global one within the scope of the function. To access the global variable, you use the `::` scope resolution operator.

```cpp
int c = 9;  // Global variable

int main() {
    int c = 8;  // Local variable
    cout << "Local c is " << c << endl;  // Output: Local c is 8
    cout << "Global c is " << ::c << endl;  // Output: Global c is 9
    return 0;
}
```

### **Default Data Type for Decimal Values**

In C++, by default, decimal literals are treated as `double` unless specified otherwise. If you want to store a decimal value in a `float` or `long double`, you need to suffix the number appropriately:

- **`float`**: Use `f` or `F` suffix.
  ```cpp
  float f = 35.4f;  // 'f' indicates it's a float
  ```
  
- **`long double`**: Use `l` or `L` suffix.
  ```cpp
  long double ld = 35.4l;  // 'l' indicates it's a long double
  ```

### **Type Casting in C++**

In C++, type casting allows you to explicitly convert one data type to another. There are two types:

- **Implicit Type Casting**: Automatically performed by the compiler when it finds it safe.
  ```cpp
  int num1 = 7, num2 = 3;
  float result = num1 / num2;  // Implicit conversion of 7/3 to float (2.0)
  ```

- **Explicit Type Casting**: You can explicitly cast one type to another using the `(type)` syntax.
  ```cpp
  int num1 = 7, num2 = 3;
  float result = (float) num1 / num2;  // Explicit conversion to float, result = 2.33
  ```

  - **Explanation:**
    - In the example above, `num1 / num2` is an integer division, which results in `2`. By casting `num1` to `float`, we get the result `2.33`.

---



### Data Type Hierarchy  
`bool < char < short int < int < unsigned int < long int < unsigned long int < long long int < float < double < long double`

---

### Explicit Type Conversion  
**Syntax:** `(type) expression`  
- Allows explicit conversion of a data type to another.  

```cpp
int num1 = 7, num2 = 3;
float result;
result = (float) num1 / num2;  // Converts num1 to float for the operation
```  
- **Implicit Conversion:** `num1 / num2` → `2`  
- **Explicit Conversion:** `(float)num1 / num2` → `2.33`

---

### Static Cast  
- **Efficient compile-time type casting.**  
- **Syntax:** `static_cast<new_data_type>(expression)`  
- Performs conversions possible by implicit cast but is safer and more explicit.  

Example:  
```cpp
double multiplication = 3.5 * 1.31;
int result = static_cast<int>(multiplication);  // Converts double to int
```

---

### Dynamic Cast  
- **Runtime cast** for **class pointers and references.**  
- Validates the cast at runtime, returning `NULL` if it fails.  
- **Syntax:** `dynamic_cast<new_data_type>(expression)`  

Example:  
```cpp
BaseClass *basePtr;
DerivedClass *derivedPtr = dynamic_cast<DerivedClass*>(basePtr);
if (derivedPtr != nullptr) {
    // Cast successful
}
```

---

### Reinterpret Cast  
- Converts pointers of one type into another, even if they are unrelated.  
- Does not validate the type compatibility.  
- **Syntax:** `reinterpret_cast<new_data_type>(expression)`  

Example:  
```cpp
int *ptr = new int(65);
char *ch = reinterpret_cast<char*>(ptr);
```

---

### Const Cast  
- Alters or removes the `const` qualifier of a variable.  
- **Syntax:** `const_cast<new_data_type>(expression)`  

Example:  
```cpp
const int num = 10;
int *ptr = const_cast<int*>(&num);
*ptr = 20;  // Modifies value despite being const
```