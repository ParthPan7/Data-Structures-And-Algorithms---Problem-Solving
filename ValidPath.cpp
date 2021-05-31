/*
Valid Path - InterviewBit (Graph DS)
There is a rectangle with left bottom as  (0, 0) and right up as (x, y). There are N circles such that their centers are inside the rectangle.
Radius of each circle is R. Now we need to find out if it is possible that we can move from (0, 0) to (x, y) without touching any circle.

Note : We can move from any cell to any of its 8 adjecent neighbours and we cannot move outside the boundary of the rectangle at any point of time.
*/

int xExpand[] = {-1,-1,-1,0,0,1,1,1};
int yExpand[] = {-1,0,1,-1,1,-1,0,1};
bool isSafe(int x,int y,int& finalX,int& finalY, int r, vector<int>& xCoor, vector<int>& yCoor, vector< vector<bool> >& visited)
{
		if (x < 0 || x > finalX || y < 0 || y > finalY )
		{
			return false;
		}
		if (visited[x][y] == true)
		{
			return false;
		}
		for (int i=0; i<xCoor.size(); ++i)
		{
			if (pow(x-xCoor[i],2)+pow(y-yCoor[i],2) <= r*r ) { return false; }
		}
		return true;
}
bool dfs(int x,int y,int r,int &finalX,int &finalY, vector<int>& xCoor,vector<int>& yCoor, vector< vector<bool> >& visited)
{
		if (x == finalX && y == finalY)
		{
			return true;
		}
		visited[x][y] = true;
		for (int i=0; i<8; ++i)
		{
			if (isSafe(x+xExpand[i],y+yExpand[i],finalX,finalY, r,xCoor, yCoor,visited)){ if(dfs(x+xExpand[i], y+yExpand[i],r,finalX,finalY,xCoor, yCoor, visited)) { return true; } }
		}
		return false;
}
string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) 
{
    vector< vector<bool> > vis(A+1, vector<bool>(B+1, false));

		if (dfs(0,0,D,A,B, E,F , vis))
		{
			return "YES";
		}
		return "NO";
}
