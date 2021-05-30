/** InterviewBit -- Graph DS **/
/ * N- islands and M-cost connected Bridges (minimum cost path between every islands) */
/ * Approach : Greedy - Prims Algorithm */

#include <iostream>
#include <vector>
#include<set>
#include<algorithm>
#define INT_MAX 9999
using namespace std;
bool compare(vector<int> A, vector<int> B)
{
    return A[2] < B[2];
}
int extractMin(int keys[], bool MST[], int A)
{
    int min = INT_MAX; int index = -1;
    for (int i=1; i<=A; ++i)
    {
        if (keys[i] < min && MST[i] == false ) 
        {  
            min = keys[i];
            index = i;
        }
    }
    return index;
}
int primsMST(int A, vector<vector<int> > &B)
{
    bool MST[A+1];
    int parent[A+1];
    int keys[A+1];
    int cost = 0;
    for (int i=1; i<=A; ++i)
    {
        MST[i] = false; keys[i] = INT_MAX;
    }
    
    sort(B.begin(), B.end(), compare);
    
    keys[B[0][0]] = 0;
    
    for (int i=0; i<A-1; ++i )
    {
        
        int u = extractMin(keys,MST,A);
        if ( u == -1 ) { continue; }
        //cout << u <<endl;
        MST[u] = true;
        for (int j=0; j<B.size(); ++j)
        {
                if (B[j][0] == u && MST[B[j][1]] == false && B[j][2] < keys[B[j][1]]  )
                {
                    keys[B[j][1]] = B[j][2];
                    parent[B[j][1]] = B[j][0];
                }
        }
        
    }
    
    for (int i=1; i<=A; ++i)
    {
        if (keys[i]>=0 && keys[i] <= 1000) {  cost += keys[i]; }
       
    }
    return cost;
}
int solve(int A, vector<vector<int>> &B) 
{
    set<int> s;
    vector<vector<int>> remainingMappings;
    if (A >= B.size())
    {
        for ( int i=1; i<B.size(); ++i )
        {
            s.insert(B[i][0]);
        }
        
        for (int i=1; i<=A; ++i)
        {
            if (s.find(i) == s.end())
            {
                for (int j=0; j<B.size(); ++j)
                {
                 if (B[j][1] == i)
                 {
                    vector<int> v{B[j][1], B[j][0], B[j][2]};
                    remainingMappings.push_back(v);
                 }
                }
            }
        }
        
        
    }
  
    for (auto ele:B )
    {
        remainingMappings.push_back(ele);
    }
    return primsMST(A,remainingMappings);
}

int main()
{
    int graph[4][3] = {
                        {1, 2, 1},
                        {2, 3, 2},
                        {3, 4, 4},
                        {1, 4, 3} 
                      };
    vector<vector<int>> B;
    
    for (int i=0; i<4; ++i)
    {
        vector<int> v{graph[i],graph[i]+3};
        B.push_back(v);
    }
    cout << solve(4,B);
    return 0;
}
