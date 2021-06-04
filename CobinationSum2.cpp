/*
InterviewBit - Backtracking
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
Example :

Given candidate set 10,1,2,7,6,1,5 and target 8,

A solution set is:

[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
*/

class CombinationSum2 {
public:
    
      void helper( vector<vector<int>>& res,vector<int>& candidates,vector<int> subres, int target, int sum, int pos  )
    {
          
       if ( sum == target )
       {    
          if (find(res.begin(),res.end(),subres) == res.end())
          {
               res.push_back(subres);
          }
           subres.clear();
           return;
       }
       if ( pos >= candidates.size() || sum > target  )
       {
           return;
       }
        if ( target == candidates[pos] )
        {
            vector<int> vec; vec.push_back(target);
            if (find(res.begin(), res.end(),vec) == res.end())
            {
                res.push_back(vec);
            }
        }
      
      
       if ( sum + candidates[pos] <= target )
       {
           subres.push_back(candidates[pos]);
           helper(res,candidates,subres,target,sum+candidates[pos],pos+1);
           subres.pop_back();
           helper(res,candidates,subres,target,sum,pos+1);
       }
       else
       {  helper(res,candidates,subres,target,sum,pos+1); }
          return;
    }
    vector<vector<int>> returnCombination(vector<int>& candidates, int target) 
    {
        vector<vector<int>> res; vector<int> subres;
        memset(visited,false,sizeof(visited));
        sort(candidates.begin(), candidates.end());
        helper(res,candidates,subres,target,0,0);
        return res;
    }
    
};
