#include <iostream>
#include <chrono>
using namespace std;

void embaralha(int[], int);
void troca(int*, int*);
void display(int[], int);


// Driver Code 
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    embaralha(arr, n);
    display(arr, n);

    return 0;
} //fim do main  

// A utility function to troca to integers  
void troca(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// A utility function to print an array  
void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// A function to generate a random  
// permutation of arr[]  
void embaralha(int arr[], int n) {
    // Use a different seed value so that  
    // we don't get same result each time 
    // we run this program  
    srand(clock());

    // Start from the last element and troca  
    // one by one. We don't need to run for  
    // the first element that's why i > 0  
    for (int i = n - 1; i > 0; i--)
    {
        // Pick a random index from 0 to i  
        int j = rand() % (i + 1);

        // troca arr[i] with the element  
        // at random index  
        troca(&arr[i], &arr[j]);
    }
}
