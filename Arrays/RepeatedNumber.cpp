/*
Interview Bit reference: https://www.interviewbit.com/problems/find-duplicate-in-array/
[3 4 1 4 1]
op: 4
*/

int repeatedNumber(const vector<int> &A) 
{
    vector vec(A.size(),0);
    for (int i=0; i<A.size(); ++i)
    {
        vec[A[i]]++;
        if (vec[A[i]] > 1) { return A[i]; }
    }
    return -1;
}
