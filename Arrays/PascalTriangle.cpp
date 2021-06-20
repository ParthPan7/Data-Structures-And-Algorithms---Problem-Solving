/*
Pascal's Triangle
Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]
Reference : https://www.interviewbit.com/problems/pascal-triangle/
*/

vector<vector<int> > Solution::solve(int A) 
{
    vector < vector <int> > sol;
    if (A == 0) { return sol; }
    if (A == 1) { sol.push_back( vector<int>{1} ); return sol; }
    sol.push_back( vector<int>{1} );
    sol.push_back( vector<int> {1,1});

    for (int i=2; i<A; i++)
    {
        vector<int> vec;
        vec.push_back(1);
        vector<int> prev = sol[i-1];
        for (int x = 0 ; x<prev.size()-1; ++x)
        {
            vec.push_back(prev[x]+prev[x+1]);
        }
        vec.push_back(1);
        sol.push_back(vec);
    }
    return sol;
}

