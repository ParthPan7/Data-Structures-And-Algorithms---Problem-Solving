/*
Given an integer n, return all distinct solutions to the n-queens puzzle. (Backtracking Algorithm)

Each solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/
#include <iostream>
#include <vector>
using namespace std;
bool isSafe(int row, int col,  vector< vector<string> > &copyBoard, int N)
{
    for (int i=0; i<col; ++i)
    {
        if (copyBoard[row][i] == "Q") { return false; }
    }
    for (int i=row ,j=col; i >-1 && j > -1; --i,--j)
    {
        if (copyBoard[i][j] == "Q") { return false; }
    }
    for (int i=row ,j=col; i < N && j > -1; ++i,--j)
    {
        if (copyBoard[i][j] == "Q") { return false; }
    }
}

bool backtracking ( vector< vector<string> > &copyBoard, vector< vector<string> > &res, int N, int col )
{
    if (col == N)
    {
        for (auto row:copyBoard)
        {
            res.push_back(row);
        }
        return false;
    }
    for (int i=0; i<N; ++i)
    {
        if (isSafe(i,col,copyBoard,N))
        {
            copyBoard[i][col] = "Q";
            if (backtracking(copyBoard,res, N, col+1))
            { return true; }
            else {
                copyBoard[i][col] = ".";
            }
        }
    }
    return false;
}

vector< vector<string> > solveNQueens(int A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector< vector<string> > copyBoard,resultboard;
    if (A == 2|| A == 3) { return resultboard; }
    vector<string> row(A,".");
    
    for (int i=0; i<A; ++i)
    {
        copyBoard.push_back(row);
    }
    backtracking(copyBoard, resultboard, A, 0);
    return resultboard;
}

int main()
{
   vector< vector<string> > res = solveNQueens(4);
   for (auto vec:res) 
   { 
       for (auto row: vec) { cout << row << " "; } 
        cout << endl;
   }

    return 0;
}
