#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void fin_max_cross(int* A, int low, int mid, int high)
{
    int left_sum = numeric_limits<int>::min();
    int max_left;
    int max_right;
    int sum = 0;
    for(int i = mid; i>=low;i--)
    {
        sum=sum+A[i];
        if(sum>left_sum)
        {
            left_sum=sum;
            max_left=i;
        }
    }
    int right_sum = numeric_limits<int>::min();
    sum = 0;
    for(int j=mid+1;j<=high;j++)
    {
        sum=sum+A[j];
        if(sum>right_sum)
        {
            right_sum = sum;
            max_right = j;
        }
    }
    int rpta[] = {max_left,max_right,left_sum+right_sum};
    for(int i = 0; i<3;i++)
        cout<<rpta[i]<<" ";

}

vector<int> fin_max_sub(vector<int> A,int low, int high)
{
    if(high == low)
    {
        vector<int> rpta;
        rpta.push_back(low);
        rpta.push_back(high);
        rpta.push_back(A[low]);
        return rpta;

    }
    else
    {
        int mid=(low+high)/2;
        vector<int> left;
        vector<int> right;
        left = fin_max_sub(A,low,mid);
        right = fin_max_sub(A,mid+1,high);
    }
}

int main()
{
    int A[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    fin_max_cross(A,0,8,17);

}
