/* QUESTION {minimize the maximum pages }
    -> Maximum element in Mininum number of pages form N books to M students. Given that there are N books and M students. Also given are the number of pages in each book in ascending order. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum, with the condition that every student is assigned to read some consecutive books. Print that minimum number of pages.
 
SOLUTION->

is_possible function taking four arguments, array , array_size as the number of books(N), number of students (M), and mid to check it can potential answer or not
firstly we are intilazing StudentCount = 0, PageSum = 0
Now (FOR) while we iterating through array   (IF) we checking wheter  PageSum+arr[i] is less than or equal to mid then if this possible do PageSum = PageSum + arr[i] ,ELSE else we are increasing studentCount then checking if studentCount more than M or array element more than mid ans we know that if any of condtion occur then mid is wrong so RETURN false
after checking all if we iterated all loop then outside we will return true




Book_Allocation taking three arguments array , array_size as the number of books(N), number of students (M)
we intilazing start = 0 , end = Total_Sum of all element of array
runnig WHILE loop  (start <= end)
    set mid , check IF possible , set ans = mid, then decrease end  (we have to find minimizing  the maximum pages, decreasing end for minimizing   a)
    ELSE increase start
return ans

If you use only the < condition (start < end), it may lead to missing the correct solution in certain cases. Consider the scenario where there are only two elements left in the search range (start and end are adjacent). If the condition is start < end, the loop will exit without checking the case where start equals end. This can lead to missing the correct answer.

By using start <= end, you ensure that the loop continues until the start and end pointers meet, allowing you to consider the case where start equals end. This ensures that the algorithm explores the entire search space, including the potential solution at the point where start and end converge.

 */
#include<iostream>

using namespace std;

// Function to check if it's possible to allocate books to students with a maximum page limit
// Parameters:
//   - arr: Array representing the pages of books
//   - N: Number of books
//   - M: Total number of students
//   - mid: The current maximum page limit for a student
// Returns:
//   - True if it's possible to allocate books with the given maximum page limit, false otherwise
bool is_possible(int arr[] , int N , int M , int mid) {
    int StudentCount = 1;   // Keeps track of the number of students
    int PageSum = 0;       // Accumulates the pages assigned to the current student

    for (int i = 0; i < N; i++) {
        // If adding the current book's pages to PageSum keeps it below or equal to mid, it means the current student can take this book.
        if (PageSum + arr[i] <= mid) {
            PageSum += arr[i];
        } else {
            StudentCount++;  // Increment StudentCount as the current student cannot take more pages
            // Check if the number of students exceeds the total allowed (M) or if the pages of a single book exceed mid
            if (StudentCount > M || arr[i] > mid) {
                return false;  // If either condition is true, return false as it's not possible to allocate books within the specified limit
            }
            PageSum = arr[i];  // Reset PageSum to the pages of the current book for the new student
        }
    }
    return true;  // If the loop completes, it means it's possible to allocate books within the specified limit, so return true
}

int Book_Allocation(int arr[], int N, int M){
    int start = 0 ,end ,  sum = 0 ;
    for( int i = 0 ; i < N ; i++){
        sum += arr[i];
        // start = max(start, arr[i]); //
    }
    end = sum;
    while(start <= end){
        
        int mid = start + (end - start)/2;
        if (is_possible(arr ,N , M ,mid)){ 
            end = mid-1;
        } 
        else start = mid+1;
        }
    return end;
}

int main(){
    cout << endl;
    
    int arr[] = {12, 34, 67, 90}, M = 4; // M is total students
    int N = sizeof(arr) / sizeof(arr[0]); // N is number of students

    cout << Book_Allocation(arr, N, M) << endl;


    cout << endl;
    return 0;
}