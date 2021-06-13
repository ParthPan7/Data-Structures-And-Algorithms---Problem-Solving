
/*
Maximum Sum Combinations
Interview Bit : https://www.interviewbit.com/problems/maximum-sum-combinations/

Problem Description

Given two equally sized 1-D arrays A, B containing N integers each.

A sum combination is made by adding one element from array A and another element of array B.

Return the maximum C valid sum combinations from all the possible sum combinations.

I/P
 A = [3, 2]
 B = [1, 4]
 C = 2
 
 O/P
 [7, 6]
*/
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) 
{
    priority_queue<int, vector<int>, greater<int>> maxHeap;
    for (int i=0; i<A.size(); ++i)
    {
        for (int j=0; j<B.size(); ++j){
            
            
            int sum = A[i] + B[j];
            if ( maxHeap.size() == C )
            {
                int topElement = maxHeap.top();
                if ( sum > topElement)
                {
                    maxHeap.pop();
                    maxHeap.push(sum);
                }
                
            }
            else 
            {
                maxHeap.push(sum);
            }
            
        }
    }
    
    
    vector<int> vec(maxHeap.size());
    while ( maxHeap.size() > 0)
    {
        vec[maxHeap.size()-1] = maxHeap.top();
        maxHeap.pop();
    }
    return vec;
}
