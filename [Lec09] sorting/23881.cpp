#include <bits/stdc++.h>
using namespace std;
void swap_num(int * a, int * b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void selection_sort(int* list, int n, int k)
{
    int total = 0;
    for(int i = n-1; i>0; i--)
    {
        int max_idx = i;
        for(int j = 0; j < i; j++)
        {    
            if(list[j] > list[max_idx])
                max_idx = j;
        }    
        if(max_idx != i)
        {
            swap_num(&list[max_idx], &list[i]);
            if(++total == k)
            {
                cout << list[max_idx] << " " << list[i];
                return;
            }
        }
    }
    if(total < k)
        cout << -1;
    
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int arr[10005] = {0,};
    
    int n,k;
    cin >> n >> k;
    
    
    for(int i = 0; i<n; i++)
        cin >> arr[i];
        
    selection_sort(arr, n, k);
    
    
    
}
