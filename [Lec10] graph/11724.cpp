#include <bits/stdc++.h>
#define MAX_NODE_NUM 1000
using namespace std;
int visited[MAX_NODE_NUM];
typedef struct GraphType
{
  int num_of_node;
  int adj_mat[MAX_NODE_NUM][MAX_NODE_NUM];
}GraphType;

void bfs(GraphType* g, int start, int count)
{
  queue<int> q;
  visited[start] = count;
  //cout << "visit " << start << "\n";
  q.push(start);

  while(!q.empty())
    {
      int cur = q.front();
      q.pop();
      for(int i = 0; i<g->num_of_node; i++)
        {
          if(g->adj_mat[cur][i] == 1 && visited[i] == 0)
          {
            visited[i] = count;
            //cout << "visit " << i << "\n";
            q.push(i);
          }
        }
    }
  
  
}
int find_connected_component(GraphType * g)
{
  int count = 0;
  for(int i = 0; i<g->num_of_node; i++)
    {
      if(visited[i] == 0)
      {
        count++;
        //cout << "i : " << i << "  cnt : " << count << "\n";
        bfs(g, i, count);
      }
    }
  
  return count;
  
}
int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  GraphType g;
  int num_of_edge;
  cin >> g.num_of_node >> num_of_edge;

  for(int i = 0; i<num_of_edge; i++)
    {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      g.adj_mat[u][v] = g.adj_mat[v][u] = 1;
      
    }

  cout << find_connected_component(&g);

  
  
  
  

  
}
