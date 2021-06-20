/*
Reference : https://www.interviewbit.com/problems/largest-number/
Given [3, 30, 34, 5, 9], the largest formed number is 9534330.
*/

bool compare(string& a,string& b)
{
    return a+b > b+a;
}
string largestNumber(const vector<int> &A) 
{
    vector<string> sol;
    int zeros = 0;
    for (int i=0; i<A.size(); ++i)
    {
        if (A[i] == 0) {zeros++; }
        else { sol.push_back(to_string(A[i])); }
    }
    if (zeros == A.size()) { return "0"; }
    sort(sol.begin(), sol.end(), compare);
    string ans = "";
    for (auto ele:sol)
    {
        ans += ele; 
    }
    return ans;
}
