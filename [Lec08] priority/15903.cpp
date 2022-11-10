#include <bits/stdc++.h>
using namespace std;
int min_heap[10000];
int heap_size;
void swap_e(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void insert_heap(int key)
{
    min_heap[++heap_size] = key;
    int curIdx = heap_size;
    int parentIdx = heap_size/2;
    while(parentIdx >= 1)
    {
        if(min_heap[parentIdx] > min_heap[curIdx])
        {
            swap_e(&min_heap[parentIdx], &min_heap[curIdx]);
            curIdx = parentIdx;
            parentIdx = parentIdx/2;
        }
        else break;
    }
    
}
int delete_heap()
{
    int result = min_heap[1];
    min_heap[1] = min_heap[heap_size--];
    int curIdx = 1;
    int childIdx = curIdx * 2;
    while(childIdx <= heap_size)
    {
        if(childIdx < heap_size)
            childIdx = (min_heap[childIdx] < min_heap[childIdx+1]) ? childIdx : childIdx+1;
        if(min_heap[childIdx] < min_heap[curIdx])
        {    
            swap_e(&min_heap[childIdx], &min_heap[curIdx]);
            curIdx = childIdx;
            childIdx = childIdx * 2;
        }
        else break;
    }
    return result;
    
}
void print_heap()
{
    for(int i = 1; i<=heap_size; i++)
        cout << i << " : " << min_heap[i] << "\n";
    cout << "\n";
        
}
int sum_heap()
{
    int result = 0;
    while(heap_size > 0)
        result += delete_heap();
    
    return result;
}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i<n; i++)
    {
        int num;
        cin >> num;
        insert_heap(num);
    }
    
    //print_heap();
    
    for(int i = 0; i<m; i++)
    {
        int numA = delete_heap();
        int numB = delete_heap();
        //print_heap();
        insert_heap(numA+numB);
        insert_heap(numA+numB);
    }
    
    //print_heap();
    
    cout << sum_heap();
    
    
    
    
}
