#include <bits/stdc++.h>
using namespace std;
int max_heap[500005];
int heap_size;
void init_heap()
{
  heap_size = 0;
}
void swap_nodes(int* a, int* b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
void print_heap()
{
  for(int i =1; i<=heap_size; i++)
    cout << i <<" : " << max_heap[i] << "\n";
  cout << "\n";
}
void insert_heap(int key)
{
  max_heap[++heap_size] = key;
  int cur_idx = heap_size;
  int parent_idx = cur_idx/2;

  while(parent_idx >= 1)
    {
      if(max_heap[parent_idx] < max_heap[cur_idx])
      {
        swap_nodes(&max_heap[parent_idx], &max_heap[cur_idx]);
        cur_idx = parent_idx;
        parent_idx = parent_idx/2;
      }
      else break;
    }
  
}
int delete_heap()
{
  int result = max_heap[1];
  max_heap[1] = max_heap[heap_size--];
  int cur_idx = 1;
  int child_idx = cur_idx * 2;
  while(child_idx <= heap_size)
    {
      //two children
      if(child_idx < heap_size)
        child_idx = (max_heap[child_idx] < max_heap[child_idx+1]) ? child_idx+1 : child_idx;
      
      if(max_heap[cur_idx] < max_heap[child_idx])
      {
        swap_nodes(&max_heap[cur_idx], &max_heap[child_idx]);
        
        cur_idx = child_idx;
        child_idx = child_idx * 2;
      }
      else break;
    }

  return result;

  
}
int main() {
    ios::sync_with_stdio(false);
  cin.tie(NULL);

  int visit_num = 0;
  cin >> visit_num;

  for(int i = 0; i<visit_num; i++)
    {
      int num =0;
      cin >> num;

      //아이들 방문
      if(num == 0)
      {
        if(heap_size == 0)
          cout << "-1\n";
        else
          cout << delete_heap() << "\n";
        //print_heap();
            
      }
      //거점지 방문
      else
      {
        for(int j = 0; j<num; j++)
          {
            int value = 0;
            cin >> value;
            insert_heap(value);
            //print_heap();
          }
      }
    }
  

  
}
