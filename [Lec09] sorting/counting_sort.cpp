#include <iostream>
using namespace std;
void counting_sort(int* list, int n, int* result, int range_of_num)
{
    int cdf[1005] = {0,};
    
    for(int i = 0; i<n; i++)
        cdf[list[i]]++;
    
    //calculate cdf from pdf 
    for(int i = 1; i <= range_of_num; i++)
        cdf[i] += cdf[i-1];
    
    for(int i = n-1; i>= 0; i--)
        result[--cdf[list[i]]] = list[i];
    
}
void print_arr(int * list, int n)
{
    for(int i = 0; i<n; i++)
        cout << list[i] << " ";
    cout << "\n";
}
int main(void)
{
    int arr[1005] = {2, 5, 3, 0, 2, 3, 0, 3};
    int max_num = 5;
    int result[1005] = {0,};
    int n = 8;
    
    cout << "input data\n";
    print_arr(arr, n);
    
    counting_sort(arr, n, result, max_num);
    
    cout << "sorted data\n";
    print_arr(result, n);
    
    
}
