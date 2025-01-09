### **Asymptotic Notation 

Asymptotic Notation is used to mathematically represent the time complexity (TC) of algorithms. It provides a way to compare the efficiency of algorithms by focusing on their growth rates rather than specific time measures. It helps answer *how good* one algorithm is compared to another, particularly for large input sizes.

---

#### **Key Notations**
1. **Big-O Notation (O)**:
   - **Purpose**: Describes the *asymptotic upper bound* of an algorithm’s running time.
   - **Definition**: \( f(x) \) is \( O(g(x)) \) if there exist constants \( c > 0 \) and \( n_0 \geq 0 \) such that:
     \[
     f(x) \leq c \cdot g(x) \quad \text{for all} \quad x \geq n_0
     \]
   - **Usage**: Ensures the algorithm's runtime will not exceed \( c \cdot g(x) \) for sufficiently large \( x \).
   - Example: If a function is \( O(n) \), it is also \( O(n^2) \), as \( n \) grows slower than \( n^2 \).

---

2. **Big-Omega Notation (\( \Omega \))**:
   - **Purpose**: Describes the *asymptotic lower bound* of an algorithm’s running time.
   - **Definition**: \( f(x) \) is \( \Omega(g(x)) \) if there exist constants \( c > 0 \) and \( n_0 \geq 0 \) such that:
     \[
     f(x) \geq c \cdot g(x) \quad \text{for all} \quad x \geq n_0
     \]
   - **Usage**: Ensures the algorithm's runtime will always be at least \( c \cdot g(x) \) for large \( x \).
   - Example: If a function is \( \Omega(n^2) \), it is also \( \Omega(n) \), as \( n^2 \) grows faster than \( n \).

---

3. **Big-Theta Notation (\( \Theta \))**:
   - **Purpose**: Describes the *tight bound* (both upper and lower) of an algorithm’s running time.
   - **Definition**: \( f(x) \) is \( \Theta(g(x)) \) if there exist constants \( c_1, c_2 > 0 \) and \( n_0 \geq 0 \) such that:
     \[
     c_2 \cdot g(x) \leq f(x) \leq c_1 \cdot g(x) \quad \text{for all} \quad x \geq n_0
     \]
   - **Meaning**: \( f(x) \) is sandwiched between \( c_2 \cdot g(x) \) (lower bound) and \( c_1 \cdot g(x) \) (upper bound).
   - **Usage**: Provides the most accurate description of the algorithm's runtime and is typically expected during interviews when asked for the "order of" a function.

---

#### **Summary**
- **Big-O**: Upper bound (worst-case scenario).
- **Big-Omega**: Lower bound (best-case scenario).
- **Big-Theta**: Tight bound (most realistic picture).

For large problems, asymptotic notation helps analyze algorithms’ scalability, ensuring better time complexity and efficiency.