/*
BackTracking Problems:

Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

To elaborate,

Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
Entries should be sorted within themselves.
Example :
If n = 4 and k = 2, a solution is:

[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]
https://www.interviewbit.com/problems/combinations/

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Helper(vector< vector<int> > &res, vector<int> subSol, int n, int k, int row)
{
    if (  k == subSol.size() )
    {
        res.push_back(subSol);
        return;
    }
    for (int i=row; i<=n; ++i)
    {
        subSol.push_back(i);
        Helper(res, subSol, n, k, i+1);
        subSol.pop_back();
    }
}
vector<vector<int> > combine(int A, int B) 
{
        vector< vector<int> > res;
        vector<int> subSol;
        Helper(res, subSol, A, B, 1);  
        
        return res;
}

int main()
{
    vector < vector<int> > sol = combine(4,2);
    sort( sol.begin(), sol.end() );
    for (auto vec : sol )
    {
        for (auto ele: vec)
        { cout << ele << " "; }
        cout << endl ;
    }

    return 0;
}
