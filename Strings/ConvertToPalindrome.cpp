/*
Input 1:

 A = "abcba"
Input 2:

 A = "abecbea"


Example Output
Output 1:

 1
Output 2:

 0
 Reference : https://www.interviewbit.com/problems/convert-to-palindrome/
*/

int convertToPalindrome(string A) 
{
    int front = 0; 
    int back = A.size()-1;
    int shift = 0;
    while (back >= front)
    {
        if (A[back] != A[front])
        {
            shift++;
            if (A[back-1] == A[front])
            {
                back--;
            }
            else if (A[back] == A[front+1])
            {
                front++;
            }
            else 
            {
                shift++;
            }
        }
        back--;
        front++;
    }
    if (shift > 1) { return 0; }
    return 1;
}
