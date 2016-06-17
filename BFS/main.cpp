#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
    int edges,a,b;
    vector<int>nodes[1000];
    cout<<"Numero de nodos?: ";
	cin>>edges;
	for(int i=0;i<edges;i++)
    {
        cout<<"nodo?: ";
		cin>>a;
		cout<<"arista?:";
        cin>>b;
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}
	cout<<endl;

    for(int i=0;i<1000;i++)
    {
        if(!nodes[i].empty())
        {
            cout<<"[ "<<i<<" ]"<<" --> ";
            for(vector<int>::iterator it=nodes[i].begin();it!=nodes[i].end();++it)
            {
                cout<<*it<<" --> ";
            }
            cout<<" NULL "<<endl;
        }
    }

    queue<int> que;
    bool visited[1000];
    for(int i=0;i<1000;i++)
        visited[i]=false;
    int start;
    cout<<"Nodo inicial?: ";
    cin>>start;
    que.push(start);
    visited[start]=true;
	cout<<"Camino: ";

    while(!que.empty())
    {
        int front = que.front();
        cout<<front<<" ";
        que.pop();
        for(vector<int>::iterator it=nodes[front].begin();it!=nodes[front].end();++it)
        {
            if(visited[*it]==false)
            {
                visited[*it]=true;
                que.push(*it);
            }
        }
    }
	return 0;
}
