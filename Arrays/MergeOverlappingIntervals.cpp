/*
Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].
*/
 struct Interval 
 {
     int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
bool compare(Interval one, Interval two)
{
    return one.start < two.start; 
}
vector<Interval> Solution::merge(vector<Interval> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(A.begin(), A.end(),compare);
    vector<Interval> ans;
    Interval temp = A[0]; 
    for ( auto ele:A)
    {
       if (temp.end >= ele.start)
       {
           temp.end = max(temp.end, ele.end);
       }
       else
       {
           ans.push_back(temp);
           temp = ele;
       }
    }
    ans.push_back(temp);
    return ans;
}
