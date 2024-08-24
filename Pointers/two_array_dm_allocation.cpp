/* 
int **arr = new *[n];
//rest same as taking memory to array 

Note: After memory use when  heap  work over then clear memory 

for (int i = 0; i<row  ; i++)
delet when arr -> delete [ ]arr
// delete column -> delete []arr[i];  // delete allocate column



 */

#include <iostream>

using namespace std;

// Function to create a 2D array dynamically
int **create2DArray(int rows, int cols) {
    int **arr = new int *[rows]; // Allocate memory for rows

    // Allocate memory for each column in each row
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    return arr;
}

// Function to delete a 2D array
void delete2DArray(int **arr, int rows) {
    // Free memory for each column in each row
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }

    // Free memory for rows
    delete[] arr;
}

int main() {
    int rows = 3;
    int cols = 4;

    // Create a 2D array
    int **arr = create2DArray(rows, cols);

    // Initialize elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = i * cols + j;
        }
    }

    // Print the array
    cout << "2D Array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Delete the array
    delete2DArray(arr, rows);

    return 0;
}
