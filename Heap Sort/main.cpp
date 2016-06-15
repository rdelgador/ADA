#include <iostream>

using namespace std;

////////////HEAP SORT////////////////////

/////MANTENIENDO LA PROPIEDAD DEL HEAP//////
void max_heapify(int A[],int n,int i) //n -> tamaño de heap
{
    int largest=i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l<n && A[r]>A[largest])
        largest=l;
    if(r<n && A[r]>A[largest])
        largest=r;
    if(largest!=i)
    {
        swap(A[i],A[largest]);
        max_heapify(A,n,largest);
    }

}

void build_max_heap(int A[], int n)
{
    for(int i=n/2 - 1; i>=0; i--)
        max_heapify(A,n,i);

    for(int i=n-1; i>=0;i--)
    {
        swap(A[0],A[i]);
        max_heapify(A,i,0);
    }
    swap(A[0],A[1]);
}

void printA(int A[], int n)
{
    for(int i=0; i<n; ++i)
        cout<<A[i]<<" ";
    cout<<endl;
}

int heap_extract_max(int A[])
{
    int n = sizeof(A)/sizeof(A[0]);
    if(n<1)
        return -1;
    int m=A[1];
    A[1] = A[n];
    n=n-1;
    max_heapify(A,n,1);
    return m;
}

int main()
{
    int A[] = {4,1,3,2,16,9,10,14,8,7};
    int n = sizeof(A)/sizeof(A[0]);

    build_max_heap(A,n);

    printA(A,n);
}
