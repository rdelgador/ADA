#include <iostream>
#include <vector>

using namespace std;

vector<int> grafo[50];
int time;
int start[100], finish[100], path[100], color[100];

void DFS_Visit(int u)
{
    color[u] = 0;
    time = time + 1;
    start[u] = time;
    for(int i=0; i<grafo[u].size(); i++)
    {
        int v = grafo[u][i];
        if(color[v]==-1)
        {
            path[v] = u;
            DFS_Visit(v);
        }
    }
    color[u] = 1;
    time = time + 1;
    finish[u] = time;
}

int main()
{
    int nodes, edges, u, v;
    cout<<"Numero de nodos?: ";
    cin>>nodes;
    cout<<"Numero de aristas?: ";
    cin>>edges;
    for(int i=0; i<=edges; i++)
    {
        cout<<"nodo?: ";
        cin>>u;
        cout<<"arista?: ";
        cin>>v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }
    for(int i=1; i<=nodes; i++)
    {
        color[i] = -1;
        path[i] = -1;
    }
    time = 0;
    for(int i=1; i<=nodes; i++)
    {
        if(color[i]==-1)
        {
            DFS_Visit(i);
        }
    }
    for(int i=1; i<=nodes; i++)
    {
        cout<<"Nodo: "<<i<<" Tiempo: "<<start[i]<<" Tiempo Final: "<<finish[i]<<endl;
    }
    return 0;
}
