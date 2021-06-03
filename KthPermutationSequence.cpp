
/*
K-th Permutation InterviewBit
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3 ) :

1. "123"
2. "132"
3. "213"
4. "231"
5. "312"
6. "321"
Given n and k, return the kth permutation sequence.

For example, given n = 3, k = 4, ans = "231"
*/

class KPermutation 
{
public:
    set<int> s;
    void solutionSet(vector<string> &vec, string& str, int n, int k, int& count)
    {
        if (str.length() == n)
        {
            count++;
            if (count == k) {  vec.push_back(str); return;}
            return;
        }
        
        for (int i=1; i<=n; ++i)
        {
            if ( s.find(i)==s.end() && count!=k )
            {
                s.insert(i);
                str += (char)i+'0';
                solutionSet(vec,str,n,k,count);
                str.pop_back();
                s.erase(i);
            }
        }
        return;
    }
    string kthPermutation(int n, int k) 
    {
        vector<string> solSet;
        string str = ""; int count = 0;
        solutionSet(solSet,str,n,k,count);
        return solSet[0];
    }
};
