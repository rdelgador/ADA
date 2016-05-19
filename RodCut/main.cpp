#include <iostream>
#include <limits>

using namespace std;

int cut_rod(int p[],int n)
{
    if(n<=0)
        return 0;
    int q = std::numeric_limits<int>::min();
    for(int i=0;i<n;i++)
        q = max(q,p[i]+cut_rod(p,n-i-1));
    return q;
}

int memoized_cut_rod_aux(int p[], int n, int r[])
{
    if(r[n]>=0)
        return r[n];
    int q;
    if(n==0)
        q = 0;
    else
    {
        q = std::numeric_limits<int>::min();
        for(int i=1;i<n;++i)
            q = max(q,p[i]+memoized_cut_rod_aux(p,n-i,r));
    }
    r[n] = q;
    return q;
}
int memoized_cut_rod(int p[], int n)
{
    int r[n];
    for(int i=0;i<n;++i)
        r[i] = std::numeric_limits<int>::min();
    return memoized_cut_rod_aux(p,n,r);
}

int bottom_up_cut_rod(int p[],int n)
{
    int r[n+1];
    r[0] = 0;
    for(int j=1;j<=n;++j)
    {
        int q = std::numeric_limits<int>::min();
        for(int i = 0; i<j;++i)
            q = max(q, p[i]+r[j-i-1]);
        r[j]=q;
    }
    return r[n];
}

int main()
{
    int p[] = {1,5,8,10,13,17,18,22,25,30};
    int n = sizeof(p)/sizeof(p[0]);
    cout<<memoized_cut_rod(p,n);
}
