#include <bits/stdc++.h>
using namespace std;
int heap[100005];
int heap_size;
void swap_e(int * a, int * b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
} 
int delete_heap()
{
  int min_element = heap[1];
  heap[1] = heap[heap_size--];
  int cur_idx = 1;
  int child = cur_idx * 2;
  while(child <= heap_size)
    {
      if(child < heap_size)
        child = (heap[child] > heap[child+1])? child+1 : child;
      if(heap[child] < heap[cur_idx])
      {
         swap_e(&heap[child], &heap[cur_idx]);
         cur_idx = child;
         child = child * 2;
      } 
      else break;
    }
  return min_element;
}
void insert_heap(int key)
{
  heap[++heap_size] = key;
  int cur_idx = heap_size;
  int parent = heap_size/2;

  while(parent >= 1)
    {
      if(heap[parent] > heap[cur_idx])
      {
        swap_e(&heap[parent], &heap[cur_idx]);
        cur_idx = parent;
        parent = parent/2;
      }  
      else break;
    }
}
void print_heap()
{
  for(int i =1; i<= heap_size; i++)
    cout << i << " : " << heap[i] << "\n";
  cout << "\n";
}
void init_heap()
{
  heap_size = 0;
}


int compare_card()
{
  int result = 0;
  int group_a, group_b;
  if(heap_size == 1) return 0;
  
  while(heap_size > 1)
    {
      group_a = delete_heap();
      group_b = delete_heap();

      result += group_a;
      result += group_b;
      
      insert_heap(group_a + group_b);
      //print_heap();
    }

  return result;
  
}
int main(void)
{
  //ios::sync_with_stdio(false);
  //cin.tie(NULL);
  int total_card_group;
  cin >> total_card_group;

  for(int i = 0; i<total_card_group; i++)
    {
      int card_num = 0;
      cin >> card_num;
      insert_heap(card_num);
    }

  cout << compare_card();
  
  
  
  
}
