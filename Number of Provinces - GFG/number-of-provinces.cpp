//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void dfs(vector<int>adj[] , int strt , vector<int>&vis){
      vis[strt]  = 1;
      for(auto it : adj[strt]){
          if(vis[it] != 1){
              vis[it] = 1;
              dfs(adj , it , vis);
          }
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int n = adj.size();
        vector<int>grph[n];
        for(int i = 0 ; i <n; i++){
            for(int j = 0 ; j < n ; j++){
                if(adj[i][j]) grph[i].push_back(j);
            }
        }
        
        int count = 0;
        vector<int>vis(n , 0);
        for(int i = 0 ; i <n ; i++){
            if(vis[i] != 1){
                count++;
                dfs(grph , i , vis);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends