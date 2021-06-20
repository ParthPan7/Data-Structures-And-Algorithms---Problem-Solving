/*
strstr - locate a substring ( needle ) in a string ( haystack ).
reference - https://www.interviewbit.com/problems/implement-strstr/
*/

int strStr(const string A, const string B) 
{
    int start = -1;
    for (int i=0; i<A.length(); ++i)
    {
        if (A[i] == B[0])
        {
            start = i;
            int bCounter = 0;
            int aCounter = i;
            while ( B[bCounter]!='\0' && A[aCounter] == B[bCounter] )
            {
                if ( aCounter > A.length() ) { return -1; }
                aCounter++;  bCounter++;
            }
            if (bCounter == B.size())
            {
                return start;
            }
            else
            {
                start = -1;
            }
        }
    }
    return start;
}
