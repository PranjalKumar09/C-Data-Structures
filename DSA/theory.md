
### Data Structure
- **Definition**: A structured way to organize data for efficient access and modification.
- **Memory Usage**: Optimizes data management in memory, critical for efficient storage and retrieval (e.g., managing large files in RAM).
- **Examples**: Arrays, linked lists, stacks, queues, trees, graphs.

### Data Type
- **Definition**: Specifies the type of values a variable can store and the operations it supports.
- **Categories**:
  - **Primitive Types**: `int`, `float`, `char`, `double`, etc.
  - **Derived Types**: Arrays, pointers, structures, unions.
  - **Abstract Data Types (ADTs)**: Lists, stacks, queues, trees, graphs.

### Variable Types
- **Static Variable**: Retains its value across function calls; stored in the data segment.
- **Global Variable**: Declared outside any function; accessible globally within the same or across files.
- **Local Variable**: Declared within a function or block, accessible only within its scope.

### Character Data Type
- **Size and Representation**:
  - Usually occupies 1 byte (8 bits).
  - **ASCII Values**: Represents 128 characters using 7 bits; 8 bits support extended characters (total 256).



| **Aspect**              | **Struct**                                                                                      | **Union**                                                                                     |
|-------------------------|-------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------|
| **Memory Allocation**   | Each member has its own memory space; total size = sum of all members (+ padding).              | All members share the same memory space; total size = size of the largest member.            |
| **Data Storage**        | Stores and accesses all members simultaneously; each retains independent values.               | Only one member can store a value at any time; updating one affects others.                  |
| **Access**              | All members are accessible independently at any time.                                          | Only the last written member holds meaningful data; accessing others may return garbage.     |
| **Initialization**      | All members can be initialized at once.                                                        | Only the first member can be reliably initialized.                                           |
| **Use Case**            | Ideal for grouping related data with multiple attributes that are used together.               | Useful when storing different types of data in the same location, but only one at a time.    |
| **Padding & Alignment** | Padding may be added to align members, which can increase total memory usage.                  | No extra padding is added beyond the largest member, making it more memory-efficient.        |
| **Example**             | ```struct Person { char name[50]; int age; float height; };```                                 | ```union Data { int integer; float floating_point; char character; };```                    |

---

| **Criteria**            | **Advantages of Struct**                                                                          | **Advantages of Union**                                                                        |
|-------------------------|---------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------|
| **Memory Efficiency**   | Allows simultaneous storage of multiple data types independently.                                 | More memory-efficient when only one data type is used at a time.                               |
| **Data Safety**         | Each member’s value is stored independently, ensuring data integrity.                             | Suitable for memory-constrained scenarios when only one type is needed at a time.              |

---
| **Criteria**            | **Disadvantages of Struct**                                                                       | **Disadvantages of Union**                                                                     |
|-------------------------|---------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------|
| **Memory Consumption**  | Consumes more memory due to separate storage for each member.                                     | Only one member can store meaningful data at any time; others may hold garbage values.         |
| **Access Complexity**   | Requires more memory alignment, which may increase overall size due to padding.                   | Updating one member’s value affects all other members, risking unintentional data overwrite.   | 



