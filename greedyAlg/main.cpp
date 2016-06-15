#include <iostream>

using namespace std;

////////Algoritmos Greedy/////////

//1. Recursive-Activity-Selector (Cormen, pag. 419)
void recur_act_select(int s[], int f[],int k, int n)
{
    int m = k + 1;
    while(m<=n && s[m-1]<f[k])
    {
        m = m+1;
    }
    if(m<=n)
    {
        cout<<m-1<<" ";
        recur_act_select(s,f,m,n);
    }
    else
        cout<<"  fin";
}

//2. Greedy-Activity-Selector (Cormen, pag. 421)
void gree_act_select(int s[], int f[], int n)
{
    int a = 0;
    int k = 0;
    cout<<a;
    for(int m = 1;m<n;m++)
    {
        if(s[m]>=f[k])
        {
            cout<<m<<" ";
            k = m;
        }
    }
    cout<<"  fin";
}

int main()
{
    int s[] = {1,3,0,5,3,5,6,8,8,2,12};
    int f[] = {0,3,5,6,7,9,9,10,11,12,14,16};
    int n = sizeof(s)/sizeof(s[0]);
    recur_act_select(s,f,0,n);
    //gree_act_select(s,f,n);
}
