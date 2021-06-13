/*

Problem Description

You are given an array of N integers, A1, A2 ,..., AN and an integer B. Return the of count of distinct numbers in all windows of size B.

Formally, return an array of size N-B+1 where i'th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,..., Ai+B-1.
 
 I/P
 A = [1, 2, 1, 3, 4, 3]
 B = 3
 
 O/P
  [2, 3, 3, 2]

*/

vector<int> distinctNumberWindow(vector<int> &A, int B) 
{
        vector<int> vec;
        unordered_map<int,int> map;
        for (int i=0; i<A.size(); ++i)
        {
            map[A[i]]++;
            if (i+1-B >= 0)
            {
                vec.push_back(map.size());
                --map[A[i+1-B]];
                if (map[A[i+1-B]] == 0)
                {
                    map.erase(A[i+1-B]);
                }
            }
        }
        return vec;
}
