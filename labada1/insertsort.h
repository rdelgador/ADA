#ifndef INSERTSORT_H
#define INSERTSORT_H
#include<iostream>
#include<vector>

using namespace std;

class insertsort
{
    public:
        insertsort(){};
        void isort(vector<int> a)
        {
            for(int j=1;j<a.size();++j)
            {
                int key = a[j];
                int i = j - 1;
                while(i>-1 && a[i]>key)
                {
                    a[i+1] = a[i];
                    i = i-1;
                }
                a[i+1] = key;
            }
            for(int i=0;i<a.size();i++)
            {
                cout<<a[i]<<",";
            }
        };
    protected:
    private:
};

#endif // INSERTSORT_H
