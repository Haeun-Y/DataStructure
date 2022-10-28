#include <iostream>
using namespace std;
#define ROWS 3 
#define COLS 3 
#define MAX_TERMS 10 
typedef struct {
       int row;
       int col;
       int value;
} element;
typedef struct SparseMatrix {
element data[MAX_TERMS];
       int rows;
       int cols;
       int terms;
} SparseMatrix;
void printMatrix(SparseMatrix a)
{
  int tmp[6][6] = {0,};
  for(int i =0; i<a.terms; i++)
    {
      element cur = a.data[i];
      tmp[cur.row][cur.col] = cur.value;
      
    }

  for(int i =0; i<a.rows; i++)
    {
      for(int j =0; j<a.cols; j++)
        cout << tmp[i][j] << " ";
      cout << "\n";
    }
    
    cout << "\n";
    
}
void printSparseMatrix(SparseMatrix a)
{
    for(int i = 0; i<a.terms; i++)
        cout << a.data[i].row << " " << a.data[i].col << " " << a.data[i].value << "\n";
    cout << "\n";
    
}
SparseMatrix transpose(SparseMatrix a)
{
  SparseMatrix at = a;
  
  //transpose
  for(int i = 0; i< at.terms; i++)
    {
      
      int tmp = at.data[i].row;
      at.data[i].row = at.data[i].col;
      at.data[i].col = tmp;
    }
    
    //sorting
  for(int i = 0; i<at.terms-1; i++)
  {
      int tmpIdx = i;
      for(int j = i+1; j<at.terms; j++)
      {
          if(at.data[tmpIdx].row > at.data[j].row)
            tmpIdx = j;
          else if(at.data[tmpIdx].row == at.data[j].row)
          {
              if(at.data[tmpIdx].col > at.data[j].col)
                tmpIdx = j;
          }
          
      }
      
      element tmpElement = at.data[tmpIdx];
      at.data[tmpIdx] = at.data[i];
      at.data[i] = tmpElement;
      
  }
  return at;
}
int main() {
    
    //Add B as an input. Use your own example freely.
    SparseMatrix B = {{{0,3,7}, {1,0,9}, {1,5,8}, {3,0,6}, {3,1,5}, {4,5,1}, {5,2,2}}, 6, 6, 7};
    
    //Perform the transpose operation
    SparseMatrix Bt = transpose(B);
    
    //check the transpose matrix 
    //whether the transposed matrix Bt is saved in a row-wise manner
    //printSparseMatrix(Bt);
    
    //Print out B and B^T in a dense matrix form to check
    //whether the operation works correctly.
    printMatrix(B);
    printMatrix(Bt);
    
  
}
