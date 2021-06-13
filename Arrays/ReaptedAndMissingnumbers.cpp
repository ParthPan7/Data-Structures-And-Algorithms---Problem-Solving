/*
Interview Bit : https://www.interviewbit.com/problems/repeat-and-missing-number-array/
Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4

*/

vector<int> repeatedNumber(const vector<int> &A) 
{
    vector vec(1000005,0);
    vector<int> res;
    for (int i=1; i<=A.size(); ++i)
    {
        vec[i] = 0;
    }
    
    for (int i=0; i<A.size(); ++i)
    {
        vec[A[i]]++;
        if (vec[A[i]] > 1)
        {
            res.push_back(A[i]);
        }
    }
    
    for (int i=1; i<=A.size(); ++i)
    {
        if (vec[i] == 0)
        {
            res.push_back(i);
        }
    }
    return res;
}
