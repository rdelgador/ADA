#include <iostream>
#define fA 2
#define cA 2
#define fB 2
#define cB 2

using namespace std;

void square_matrix(int A[fA][fA],int B[fA][fA])
{
    int n =  fA;
    int C[n][n];
    for(int i = 0; i<n; ++i)
    {
        for(int j=0;j<n; ++j)
        {
            C[i][j]=0;
            for(int k =0;k<n;++k)
                C[i][j]= C[i][j] + (A[i][k])*(B[i][k]);
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
            cout<<C[i][j]<<'\t';
        cout<<endl;
    }
}

int main()
{
    int A[fA][cA];
    int B[fA][cA];
    int a=1;
    for(int i=0;i<fA;i++)
    {
        for(int j=0;j<fA;j++)
        {
            A[i][j] = a;
            a++;
        }
    }
    a=1;
    for(int i=0;i<fA;i++)
    {
        for(int j=0;j<fA;j++)
        {
            B[i][j] = a;
            a++;
        }
    }

    square_matrix(A,B);
}
