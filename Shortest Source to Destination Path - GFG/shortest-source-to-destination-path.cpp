//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int n, int m, vector<vector<int>> A, int x, int y) {
        // code here
        queue<vector<int>>q;
        vector<vector<int>>dist(n , vector<int>(m , 1e7));
        int drow[] = {-1,0,1,0};
        int dcol[] = {0 , -1 , 0,1};
        if(A[0][0] == 0) return -1;
        q.push({1 , 0 , 0});
        while(!q.empty()){
            auto node = q.front();
            int wt = node[0];
            int r = node[1];
            int c = node[2];
            q.pop();
            for(int i = 0; i < 4 ; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && A[nrow][ncol] == 1){
                    if(1 + wt < dist[nrow][ncol]){
                        dist[nrow][ncol] = wt + 1;
                        if(nrow == x && ncol == y) return wt;
                        q.push({1+wt , nrow , ncol});
                    }
                }
            }
            
        }
        return -1;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends