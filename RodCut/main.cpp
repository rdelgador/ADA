#include <iostream>
#include <limits>
#include <ctime>

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
    {
        return r[n];
    }
    int q;
    if(n==0)
        q = 0;
    else
    {
        q = std::numeric_limits<int>::min();
        for(int i=0;i<n;++i)
            q = max(q,p[i]+memoized_cut_rod_aux(p,n-i-1,r));
    }
    r[n] = q;
    return q;
}
int memoized_cut_rod(int p[], int n)
{
    int r[n+1];
    for(int i=0;i<n+1;++i)
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
    //int p[] = {1,5,8,10,13,17,18,22,25,30,35,41,456,565,674};
    //int p[] = {1,5,8,10,13,17,18,22,25,30,35,41,456,565,674,701,722,783,825,847};
    //int p[] = {1,5,8,10,13,17,18,22,25,30,35,41,456,565,674,701,722,783,825,847,989,1023,1134,1256,1367};
    //int p[] = {1,5,8,10,13,17,18,22,25,30,35,41,456,565,674,701,722,783,825,847,989,1023,1134,1256,1367,1654,2123,2567,2789,3456};
    //int p[] = {1,5,8,10,13,17,18,22,25,30,35,41,456,565,674,701,722,783,825,847,989,1023,1134,1256,1367,1654,2123,2567,2789,3456,4321,4678,5678,6789,8797};
    int n = sizeof(p)/sizeof(p[0]);
    cout<<bottom_up_cut_rod(p,n);
}
