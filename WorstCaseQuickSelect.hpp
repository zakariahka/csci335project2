#include <iostream>
#include<cmath>
#include <vector>
using namespace std;

vector<int> worstCaseQuickSelect (void)
{
    vector<int> values;

    for (int i = 20000; i > 0;i--){
        values.push_back(i);
    }

    return values;
}