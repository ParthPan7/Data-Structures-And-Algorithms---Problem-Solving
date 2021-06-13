/*
  Problem Description

Given an 1D integer array A of size N you have to find and return the B largest elements of the array A.

NOTE:

Return the largest B elements in any order you like.

I/P
A = [11, 3, 4]
 B = 2
 
 O/P
  [11, 4]

*/

vector<int> KLargestEle(vector<int> &A, int B) 
{
    priority_queue< int, vector<int>, greater<int> > que;
    for (int i=0; i<A.size(); ++i)
    {
        if (que.size() == B)
        {
            int top = que.top();
            if ( top < A[i] )
            {
                que.pop();
                que.push(A[i]);
            }
        }
        else 
        {
            que.push(A[i]);
        }
    }
    vector<int> vec;
    while ( que.size() > 0)
    {
        vec.push_back(que.top()); que.pop();
    }
    return vec;
}
