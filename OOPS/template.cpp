#include <bits/stdc++.h>
using namespace std;

/*
    Template Datatype

        template <typename T>
        T fn (--) --


    In class Ex-

        template <typename T> class  Array{
            T* ptr;
            int size;

        public:
            Array(T arr(), int s){
                T[s];
                ---
            }
            void print();}
        template <typename T> void Array<T>::print(){
            for(int i = 0; i < size; i++)
                cout << " " << i * (ptr+i)
            cout << endl;
        }

    Eariler it was usen as template <class T>
    there can also be template<class T, class S>
    or in new
    template <typename T, typename S>
 */

template <typename T>
class Array {
    T* ptr; // Pointer to array of type T
    int size;

public:
    // Constructor
    Array(T arr[], int s) {
        ptr = new T[s];  // Dynamically allocate memory for array
        size = s;
        for (int i = 0; i < size; i++) {
            ptr[i] = arr[i];  // Copy array elements
        }
    }
    
    // Function to print array elements
    void print() const;

    void fn(){
        cout << "I am sample function" << endl;
    }

    // Destructor to free allocated memory
    ~Array() {
        delete[] ptr;
    }
};

// Template class function definition outside the class
template <typename T>
void Array<T>::print() const {
    for (int i = 0; i < size; i++) {
        cout << " " << ptr[i];
    }
    cout << endl;
}

// When defining member functions outside the class, use `template <class T>` and specify `Class_name<T>::` before the function definition.

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {

    cout << add(10, 20);       // Works for integers
    cout << add(5.5, 6.7);     // Works for floats



    int arr[] = {1, 2, 3, 4, 5};  // Sample array
    Array<int> myArray(arr, 5);   // Create Array object for integers
    myArray.print();              // Print array elements

    myArray.fn();               // Call sample function
    
    return 0;

}

