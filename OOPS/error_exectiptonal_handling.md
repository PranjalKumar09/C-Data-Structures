### **Enhanced Notes on Error and Exception Handling**

#### **Error Types**
1. **Runtime Error**  
   - Errors during program execution (e.g., division by zero, accessing invalid memory).
   
2. **Logical Error**  
   - Errors in program logic producing incorrect results without crashing (e.g., wrong calculations).

3. **Semantic Error**  
   - Syntax appears correct, but code doesn't perform intended function.

---

#### **Exception Handling Overview**
**Exception:** A condition that disrupts the flow of the program, requiring special handling.  
**Types of Exceptions:**  
1. **Synchronous:**  
   - Controlled exceptions (e.g., invalid inputs).  
2. **Asynchronous:**  
   - Beyond program control (e.g., hardware failures, keyboard interrupts).  

---

#### **Key Exception Handling Constructs**
1. **`try` Block:**  
   - Encapsulates code that might throw exceptions.  
   - Purpose: Test for errors.

2. **`catch` Block:**  
   - Executes when a specific exception is thrown.  
   - **Preconditions:** Catch must match or exist; otherwise, the exception propagates.

3. **`throw`:**  
   - Triggers an exception when an error is detected.  
   - Can list exceptions a function might throw (but does not handle them).  
   - Allows custom error creation.

---

#### **Traditional Error Handling Flow**
1. **Trigger the Exception:** Detect error in the program.  
2. **Throw the Exception:** Use `throw` to flag the issue.  
3. **Catch the Exception:** Handle the flagged error in a `catch` block.  
4. **Perform Corrective Action:** Resolve or log the issue.

---

#### **Exception Handling Notes**
- Functions may handle **some exceptions** while allowing others to propagate.  
- Unhandled exceptions are managed by the caller or the program terminates.  

---

#### **Grouping Exceptions**
- Both basic types (e.g., `int`) and objects can be thrown as exceptions.  
- **Exception Hierarchies:** Organize exceptions into namespaces or classes for better categorization.

---

#### **Code Execution Notes**
- **Code after `throw`:** Does not execute; control transfers to the `catch` block.  
- **Code after `catch`:** Executes if exception is handled.

---

#### **Examples**

**Example 1: Basic Exception Flow**  
```cpp
int x = -1;
cout << "Before try" << endl;

try {
    cout << "Inside try" << endl;
    if (x < 0) {
        throw x; // Throws exception
        cout << "After throw"; // Skipped
    }
}
catch (int n) {
    cout << "After catch" << endl;
}
cout << "Last";
```
**Output:**  
```
Before try  
Inside try  
After catch  
Last
```

---

**Example 2: Default Catch Block**  
```cpp
try {
    throw 10; // Throws int exception
}
catch (char *except) {
    cout << "Caught";
}
catch (...) { // Default handler
    cout << "Default type Exception";
}
```
**Output:**  
```
Default type Exception
```

---

**Example 3: Handling Multiple Exceptions**
```cpp
void fun(int *ptr, int x) throw (int *, int) {
    if (ptr == NULL) throw ptr;  // Dynamic exception
    if (x == 0) throw x;        // Static exception
}

try {
    fun(NULL, 5); // Throws dynamic exception
} catch (int *p) {
    cout << "Pointer Exception";
} catch (int n) {
    cout << "Integer Exception";
}
```

---

#### **Classes as Exceptions**
```cpp
class Exception {
    // Custom exception class
};

try {
    throw Exception(); // Throwing custom exception
}
catch (Exception e) {
    cout << "Custom Exception Caught";
}
```

