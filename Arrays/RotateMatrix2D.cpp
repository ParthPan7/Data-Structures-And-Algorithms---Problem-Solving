/*
Question reference: https://www.interviewbit.com/problems/rotate-matrix/
Rotating Matrix 90 degree clockwise
*/

void rotateMatrix(vector<vector<int> > &A) 
{
    for (int i=0; i<A.size(); ++i)
    {
        for (int j=i; j<A[i].size(); ++j)
        {
            int temp = A[i][j];
            A[i][j]  = A[j][i];
            A[j][i]  = temp;
        }
        reverse(A[i].begin(), A[i].end());
    }
    return;
}
