#include <iostream>
using namespace std;

int main(void)
{
    int id[1005] = {1, 2, 3, 4, 5, 6, 7, 8};
    int arr[1005] = {0,};
    int result[1005] = {0,};
    int result_id[1005] = {0,};
    int cdf[10] = {0,};
    
    int num_of_element = 8;
    
    int max_num = 0;
    
    for(int i = 0; i<num_of_element; i++)
    {
        cin >> arr[i];
        cdf[arr[i]]++;
        if(max_num < arr[i])
            max_num = arr[i];
    }
    
    for(int i = 1; i<= max_num; i++)
        cdf[i] += cdf[i-1];
    
   /* for(int i= 0; i<= max_num; i++)
        cout << cdf[i] << " ";
    cout << "\n";*/
    
    for(int i = num_of_element-1; i>=0; i--)
    {
        result[--cdf[arr[i]]] = arr[i];
        result_id[cdf[arr[i]]] = id[i];
    }
    //
    
    for(int i = 0; i<num_of_element; i++)
        cout << result_id[i] << " : " << result[i] << "\n";
    
    
}
