#include <iostream>
using namespace std;
void print_arr(int * arr, int n)
{
    for(int i = 0; i<n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
void swap(int * a, int * b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void bubble_sort(int * arr, int n)
{
    for(int i = n-1; i> 0; i--)
    {
        for(int j = 0; j<i; j++)
        {
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
            //이건 뒤에서부터 정렬하는 거라 앞에서 대소비교해서 종료해버리면 안됨
            //else break;
        }
        cout << "intermediate result : i = " << i << "\n";
        print_arr(arr, n);
        
    }
    
}
int main(void)
{
    const int array_size = 6;
    int arr[array_size] = {5, 3, 8, 1, 2, 7};
    
    cout << "input data\n";
    print_arr(arr, array_size);
    
    bubble_sort(arr, array_size);
    cout << "bubble_sort\n";
    print_arr(arr, array_size);
    
    
}
