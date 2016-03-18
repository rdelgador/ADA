#include <iostream>
#include <vector>
#include "insertsort.h"

using namespace std;

int main()
{
    insertsort x;
    vector<int> y;
    y.push_back(31);
    y.push_back(3000000);
    y.push_back(59);
    y.push_back(26);
    y.push_back(41);
    y.push_back(58);

    x.isort(y);
    return 0;
}
