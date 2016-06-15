#include <iostream>
#include <vector>
#include <limits>

using namespace std;

///////////PREGUNTA 4.1.3 ////////////////////////

/////////// El vector result tiene como argumentos:
////////// result[0]  es left
////////// result[1]  es right
////////// result[2]  es sum

//////// FUERZA BRUTA //////////////
vector<int> find_max_subB(vector<int> A, int low, int high)
{
    int m = std::numeric_limits<int>::min();
    vector<int> result;
    result.push_back(0);
    result.push_back(0);
    result.push_back(m);
    int result_sum = result[0]+result[1]+result[2];
    for(int i=low;i<high;i++)
    {
        int sum = 0;
        for(int j=i;j<high;j++)
        {
            sum = sum + A[j];
            if(result_sum < sum)
            {
                result[0] = i;
                result[1] = j+1;
                result[2] = sum;
            }
        }
    }
    return result;
}

//////// RECURSIVO //////////////

vector<int> find_max_cross_sub(vector<int> A, int low, int mid, int high)
{
    vector<int> result;
    int m = std::numeric_limits<int>::min();
    result.push_back(-1);
    result.push_back(-1);
    result.push_back(0);
    int sum = 0;
    int left_sum = std::numeric_limits<int>::min();
    int right_sum = std::numeric_limits<int>::min();

    for (int i=mid -1;i>= low;i--)
    {
        sum = sum + A[i];
        if(sum>left_sum)
        {
            left_sum=sum;
            result[0]=i;
        }
    }
    sum = 0;

    for(int j= mid; j<high;j++)
    {
        sum=sum+A[j];
        if(sum>right_sum)
        {
            right_sum = sum;
            result[1]=j+1;
        }
    }
    result[2]=left_sum+right_sum;
    return result;


}

vector<int> find_max_subR(vector<int> A, int low, int high)
{
    if(high== low +1)
    {
        vector<int> result;
        result.push_back(low);
        result.push_back(high);
        result.push_back(A[low]);
        return result;
    }
    else
    {
        int mid = (low + high)/2;
        vector<int> left = find_max_subR(A,low,mid);
        vector<int> right = find_max_subR(A,mid,high);
        vector<int> cross = find_max_cross_sub(A,low,mid,high);

        if(left[2]>=right[2] && left[2]>= cross[2])
            return left;
        else
        {
            if(right[2]>=left[2] && right[2] >= cross[2])
                return right;
            else
                return cross;
        }
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

