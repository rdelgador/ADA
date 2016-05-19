#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void subsec(int X[], int tam)
{
    int P[tam];
    int M[tam];
    int L = 1;
    int j;

    M[0] = 0;

    for(int i=1;i<tam;++i)
    {
        int lo = 0;
        int hi = L;
        if(X[M[hi-1]]<X[i])
            j = hi;
        else
        {
            while(hi-lo > 1)
            {
                int mid = (lo+hi)/2;
                if(X[M[mid-1]]<X[i])
                    lo = mid;
                else
                    hi = mid;
            }
            j = lo;
        }

        P[i] = M[j-1];

        if(j==L || X[i]<X[M[j]])
        {
            M[j] = i;
            L = max(L,j+1);
        }
    }
    vector<int> result;
    int pos = M[L-1];
    for(int i=L;i>0;--i)
    {
        result.push_back(X[pos]);
        pos = P[pos];
    }

    reverse(result.begin(),result.end());
    for(int i=0;i<result.size();++i)
    {
        cout<<result[i]<<" ";
    }
}

int main()
{
    int X[] = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
    subsec(X,16);

}
