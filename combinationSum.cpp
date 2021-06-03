/*

Combination Sum (LeetCode) BackTracking Algorithm.

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]

*/

class CalculateCombinationSum {
public:
    void helper(vector<vector<int>> &ans,vector<int>& candidates,vector<int> res, int target,int pos, int sum)
    {
        if ( pos >= candidates.size() || sum > target) { return; }
        if (sum == target)
        {
            ans.push_back(res);
            res.clear();
            return;
        }
        else 
        {
            res.push_back(candidates[pos]);
            helper(ans,candidates, res, target,pos,sum+candidates[pos]);
            res.pop_back();
            helper(ans,candidates, res, target,pos+1, sum);
        }
        return;
    }
    vector<vector<int>> computeSum(vector<int>& candidates, int target) 
    {
             vector<vector<int>> ans;
             vector<int> vec;
             helper(ans,candidates,vec,target,0,0);
             return ans;
    }
};
