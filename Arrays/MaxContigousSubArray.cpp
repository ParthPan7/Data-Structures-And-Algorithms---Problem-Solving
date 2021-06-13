/*
 Max Sum Contiguous Subarray
 Input:
    A = [1, 2, 3, 4, -10]
 Output:
     10
     
 InterviewBit : https://www.interviewbit.com/problems/max-sum-contiguous-subarray/
*/

int maxSubArray(const vector<int> &A) 
{
  int currMax = A[0];
  int maxTillNow = A[0];
  for (int i=1; i<A.size(); ++i)
  {
      currMax = max(A[i],currMax+A[i]);
      maxTillNow = max(maxTillNow,currMax);
  }
  return maxTillNow;
}
