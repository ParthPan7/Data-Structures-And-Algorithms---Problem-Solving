/*
Interview Bit : https://www.interviewbit.com/problems/set-matrix-zeros/
Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.

Input 2:
    [   [1, 0, 1],
        [1, 1, 1],
        [1, 0, 1]   ]

Output 2:
    [   [0, 0, 0],
        [1, 0, 1],
        [0, 0, 0]   ]
*/

void setMatrixZeroes(vector<vector<int> > &A) 
{
  
    int col[A[0].size()];
    int row[A.size()];
    memset(col, 0 ,sizeof(col));
    memset(row, 0 ,sizeof(row));
    for (int i=0; i<A.size(); ++i)
    {
        for (int j=0; j<A[0].size(); ++j)
        {
            if (A[i][j] == 0)
            {
                row[i] = 1; col[j] = 1;
            }
        }
    }
    
    for (int i=0; i<A.size(); ++i)
    {
        for (int j=0; j<A[0].size(); ++j)
        {
            if (col[j]  || row[i]) { A[i][j] = 0; }
            
        }
    }
}
