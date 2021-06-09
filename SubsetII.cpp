/*
  Interview Bit SubsetII (Backtracking algorithm)
  https://www.interviewbit.com/problems/subsets-ii/
  
  Given a collection of integers that might contain duplicates, S, return all possible subsets.

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
The subsets must be sorted lexicographically.

xample :
If S = [1,2,2], the solution is:

[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 2]
]
*/

bool compare (vector<int> a, vector<int> b)
{
    if (lexicographical_compare(a.begin(),a.end(),b.begin(),b.end()))
    {
        return true;
    }
    return false;
}
void generateSubset(vector<int> &A,vector<int> res, vector< vector<int> >& ans, int pos)
{
    if (pos == A.size() ) 
    { 
        sort(res.begin(), res.end());
        if (find(ans.begin(), ans.end(), res) == ans.end())
        {
            ans.push_back(res);     
        }
        return; 
    }
    
    res.push_back(A[pos]);
    generateSubset(A,res,ans,pos+1);
    res.pop_back();
    generateSubset(A,res,ans,pos+1); 
}
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) 
{
    vector< vector<int> > ans;
    vector<int> res;
    generateSubset(A,res,ans,0);
    sort(ans.begin(), ans.end(), compare);
    return ans;
}
