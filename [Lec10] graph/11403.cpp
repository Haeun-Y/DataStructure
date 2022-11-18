#include <bits/stdc++.h>
using namespace std;
int graph[105][105];
int result[105][105];
void print_result(int node_num)
{
  for(int i = 0; i<node_num; i++)
    {
      for(int j = 0; j<node_num; j++)
        cout << result[i][j] << " ";
      cout << "\n";
    }
  
}
void bfs(int start, int node_num)
{
  queue<int> q;
  bool is_visit[105] = {false, };
  q.push(start);
  while(!q.empty())
    {
      int cur = q.front();
      q.pop();
      for(int i = 0; i<node_num; i++)
        {
          if(!is_visit[i] && graph[cur][i] == 1)
          {
            result[start][i] = 1;
            is_visit[i] = true;
            q.push(i);
            
          }
        }
    }
  
}
int main(void)
{
  //ios::sync_with_stdio(false);
  //cin.tie(NULL);

  int node_num;
  cin >> node_num;


  for(int i =0; i < node_num; i++)
    {
      for(int j = 0; j < node_num; j++)
        cin >> graph[i][j];
    }

  for(int i = 0; i<node_num; i++)
    bfs(i, node_num);

  print_result(node_num);


  
}
