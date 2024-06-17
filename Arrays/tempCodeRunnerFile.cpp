int Mountain_Element_Array_Linear_Search(int arr[], int size){
    for (int i = 1; i < size; i ++){
        if (arr[i] > arr[i + 1] && arr[i] < arr[i-1])
            return i;
    }
    return -1;
}