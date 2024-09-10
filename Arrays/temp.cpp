#include <iostream>
using namespace std;


int arr[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,} ;



bool check_full(int arr[]){
    for (int i  = 0 ; i < 10 ; i++)
        if (arr[i] == -1)
            return false;
    return true;
}

void display(int arr[]){
    for (int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


void INSERT_START(int arr[]  , int num ){
    if (check_full(arr)){
        cout << "List is full" << endl;
        return;}
    for (int i = 9  ; i >= 1 ; i--){
        if (arr[i] == -1 && arr[i-1] != -1){
            arr[i] = num;
            return;
        }
    }
    arr[0] = num;
}

void INSERT_END(int arr[]  , int num ){
    if (check_full(arr)){
        cout << "List is full" << endl;
        return;}
    for (int i = 0  ; i < 9 ; i++){
        if (arr[i] == -1 && arr[i+1] != -1){
            arr[i] = num;
            return;
        }
    }
    arr[9] = num;
}

void DELETE_START(int arr[]){
    for (int i = 0 ; i < 9 ; i++){
        if (arr[i]!= -1){
            arr[i] = -1;
            return;
        }
    }
    cout << "List is empty" << endl;
}


void DELETE_END(int arr[]){
    for (int i = 9 ; i >= 0 ; i--){
        if (arr[i]!= -1){
            arr[i] = -1;
            return;
        }
    }
    cout << "List is empty" << endl;
}

int main(){
    cout << "Press 1 to Insert Start" << endl;
    cout << "Press 2 to Insert End" << endl;
    cout << "Press 3 to Delete Start" << endl;
    cout << "Press 4 to Delete End" << endl;
    cout << "Press 5 to Display" << endl;
    cout << "Press 6 to Exit" << endl;
    while (1){  
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
            case 1:
                int num;
                cout << "Enter the number to insert: ";
                cin >> num;
                INSERT_START(arr, num);
                break;
            case 2:
                int num2;
                cout << "Enter the number to insert: ";
                cin >> num2;
                INSERT_END(arr, num2);
                break;
            case 3:
                DELETE_START(arr);
                break;
            case 4:
                DELETE_END(arr);
                break;
            case 5:
                display(arr);
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }


    return 0;


}