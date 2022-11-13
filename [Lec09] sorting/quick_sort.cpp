#include <iostream>
#define NUM_OF_ELEMENT 6
using namespace std;
void swap_e(int * a, int * b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int partition(int *list, int left, int right)
{
    
  int pivot = list[left];
  int low = left+1;
  int high = right;
  cout << "pivot left right : " << pivot << " " << list[left] << " " << list[right] << "\n";

//low와 high가 같지 않을거라는 보장 -> 하나의 원소가 pivot보다 크면서 작을 수는 없기 때문에??
// 1 2 가 주어진 경우 -> low == high임 
// low와 high가 같은 경우
  while(low < high)
    {
      while(low < right && list[low] < pivot) low++;
      cout << "list[high] : " << list[high] << "  pivot : " << pivot << "\n";
      while(high > left && list[high] > pivot) high--;
      if(low < high)
        swap_e(&list[low], &list[high]);
        //swap_e(&list[low++], &list[high--]); 이게 틀렸음 조건도 없이 무조건 ++, -- 하면 위험함
        //예를 들어 3, 1, 5, 9, 3, 7 일경우 5와 3을 swap한 후 바로 low, high모두 9를 가리키게 됨 
        //그럼 swap_e(&list[high], &list[left]); 에 의해 최종적으로 
        //9, 1, 5, 3, 3, 7 이 되므로 정상적으로 동작 x 
        // 3, 1, 3, 9, 5, 7
        //만약 같은 경우에 ++ -- 를 하지 않는다면 low는 3 가리키고, high는 3 가리킴

    }
    cout << "swap " << list[high] << " and " << list[left] << "\n";
  swap_e(&list[high], &list[left]);

  //print
  for(int i = 0; i<high; i++)
    cout << list[i] << " ";
  cout << "\npivot : " << list[high] << "\n";
  for(int i = high+1; i< NUM_OF_ELEMENT; i++)
    cout << list[i] << " ";
  cout << "\n";

  return high;
  
}
void quick_sort(int * list, int left, int right)
{
  if(left < right)
  {
    int q = partition(list, left, right);
    quick_sort(list, left, q-1);
    quick_sort(list, q+1, right);
  }
}
int main(void) {
  
  int arr[6]= {3, 4, 7, 1, 2, 5};
  quick_sort(arr, 0, NUM_OF_ELEMENT-1);

  
    
}
