#include <iostream>

using namespace std;

void merg(int A[], int s, int p, int q, int r)
{
    int temp[s];
    for(int i = p; i <= r; i++)
    {
        temp[i] = A[i];
    }
    int i = p;
    int j = q+1;
    int k = p;

    while (i <= q && j <= r)
    {
        if(temp[i]<=temp[j])
        {
            A[k]= temp[i];
            i++;
        }
        else
        {
            A[k] = temp[j];
            j++;
        }
        k++;
    }
    while(i<=q)
    {
        A[k] = temp[i];
        k++;
        i++;
    }
}

void mergeSort(int A[], int s, int p, int r)
{
    if (p < r)
    {
        int q = (p + r)/2;
        mergeSort(A,s,p,q);
        mergeSort(A,s,q+1,r);
        merg(A,s,p,q,r);
    }
}

int main()
{
    int s = 8; //tamaño del array
    int A[] = {5,2,4,7,1,3,2,6};
    mergeSort(A,s,0,7);
    for(int i = 0; i < s; ++i)
    {
        cout<<A[i]<<" ";
    }
}
