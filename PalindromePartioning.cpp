/*

refer : https://www.interviewbit.com/problems/palindrome-partitioning/ ( Question)
Backtracking Algorithms
Given a string s, partition s such that every string of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["a","a","b"]
    ["aa","b"],
  ]
  
*/
class PalindromePartition {
public:
    bool IsPalindrome(string s, int start, int end)
    {
        while ( start <= end )
        {
            if ( s[start] != s[end] ) { return false; }
            start++; end--;
        }
        return true;
    }
    
    void helper(string s, int pos, vector<string> &vec, vector< vector<string> >& sol)
    {
               if (pos == s.length())
               {
                   sol.push_back(vec);
                   return;
               }
        
        for (int i=pos; i<s.length(); ++i)
        {
            if (IsPalindrome(s,pos,i))
            {
                vec.push_back(s.substr(pos,i-pos+1));
                helper(s,i+1,vec,sol);
                vec.pop_back();
            }
        }
        return;
        
    }
    vector<vector<string>> partitionStringToPalindrome(string s) 
    {
        vector<string> vec;
        vector< vector<string> > sol;
        helper(s,0,vec,sol);
        return sol;
    }
};
