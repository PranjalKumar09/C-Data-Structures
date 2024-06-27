/* 
jaggre array is of different sizes

(1) Using static arrays
int row1[] = {1,3,4,5};
int row2[] = {2,4,7};
int *jaggred[] = {row1 , row2};


(2) using dyanmic 2d  array
int row , col;
row  = 3;
int ** arr = new int *[row];
int sizes[] = {4 ,2 , 3} ;
for (int i = 0 ; i < row ; i++)
    *(arr+1) = new int[size[i]];
int num = 1


 */

#include <iostream>
using namespace std;



    

// Display function for static jagged array
void displayStaticJaggedArray(int *jagged[], int numRows) {
    for (int i = 0; i < numRows; i++) {
        int size = sizeof(jagged[i]) / sizeof(jagged[i][0]);
        for (int j = 0; j < size; j++) {
            cout << jagged[i][j] << " ";
        }
        cout << endl;
    }
}

// Display function for dynamic 2D array
void displayDynamic2DArray(int **arr, int numRows, int *sizes) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Using static arrays
    int row1[] = {1, 3, 4, 5};
    int row2[] = {2, 4, 7};
    int *jagged[] = {row1, row2};
    int numRowsStatic = sizeof(jagged) / sizeof(jagged[0]);

    cout << "Static Jagged Array:" << endl;
    displayStaticJaggedArray(jagged, numRowsStatic);

    // Using dynamic 2D array
    int numRowsDynamic = 3;
    int sizes[] = {4, 2, 3};
    int **arr = new int *[numRowsDynamic];
    
    for (int i = 0; i < numRowsDynamic; i++)
        arr[i] = new int[sizes[i]];

    // Initialize values (you can modify this as needed)
    for (int i = 0; i < numRowsDynamic; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            arr[i][j] = i * sizes[i] + j + 1;
        }
    }

    cout << "\nDynamic 2D Array:" << endl;
    displayDynamic2DArray(arr, numRowsDynamic, sizes);

    // Free memory for dynamic array
    for (int i = 0; i < numRowsDynamic; i++)
        delete[] arr[i];
    delete[] arr;

    return 0;
}
