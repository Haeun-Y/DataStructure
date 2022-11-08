#include <iostream>
using namespace std;
void printArr(int * arr, int n)
{
    for(int i = 0; i<n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
void swap_e(int * a, int * b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void insertion_sort_2(int * arr, int n)
{
    for(int i = 1; i< n; i++)
    {
        int cur = arr[i];
        int j = i-1;
        for(; j>=0; j--)
        {
            if(arr[j] > cur)
                arr[j+1] = arr[j];
            else break;
        }
        arr[j+1] = cur;
    }
}
void insertion_sort(int * arr, int n)
{
    for(int i = 1; i< n; i++)
    {
        for(int j = i-1; j >= 0; j--)
        {
            if(arr[j+1] < arr[j])
                swap_e(&arr[j+1],&arr[j]);
            else
                break;
            
            printArr(arr, n);
        }
    }
    
}
int main(void)
{
    const int arraySize = 6;
    int arr[arraySize] = {5, 3, 8, 1, 2, 7};
    cout << "input data\n";
    printArr(arr, arraySize);
    insertion_sort_2(arr, arraySize);
    cout << "sorted data\n";
    printArr(arr, arraySize);
}
