//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int>adj[N];
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<long>dist(N , INT_MAX);
        queue<int>q;
        dist[src] = 0;
        q.push(src);
        while(!q.empty()){
            auto nd = q.front();
            q.pop();
            for(auto it : adj[nd]){
                
                if(dist[nd]+1 < dist[it]){
                    dist[it] = dist[nd]+1;
                    q.push(it);
                }
            }
        }
        vector<int>ans(N,-1);
        for(int i = 0; i<N;i++){
            if(dist[i] != INT_MAX)
            ans[i] = dist[i];
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends