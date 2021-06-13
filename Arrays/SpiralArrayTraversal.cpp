/*
Interview bit : https://www.interviewbit.com/problems/spiral-order-matrix-i/
Example:

Given the following matrix:

[
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
]
You should return

[1, 2, 3, 6, 9, 8, 7, 4, 5]

*/

vector<int> spiralOrder(const vector<vector<int> > &A) 
{
    vector<int> vec;
    int T = 0, B = A.size()-1; 
    int L = 0, R = A[0].size()-1;
    int direction = 0;
    
    while ( T<=B && L<=R )
    {
        if (direction == 0)
        {
            for (int i=L; i<=R; i++)
            {
                vec.push_back(A[T][i]);
            }
            T++;
            
        }
        
        else if (direction == 1)
        {
            for (int i=T; i<=B; ++i)
            {
                vec.push_back(A[i][R]);
            }
            R--;
            
        }
        
        else if (direction == 2)
        {
            for (int i=R; i>=L; i--)
            {
                vec.push_back(A[B][i]);
            }
            --B;
           
        }
        
        else if ( direction == 3 )
        {
            for (int i=B; i>=T; i-- )
            {
                vec.push_back(A[i][L]);
            }
            L++;
           
        }
        direction = (direction+1)%4;
    }
    return vec;
}

