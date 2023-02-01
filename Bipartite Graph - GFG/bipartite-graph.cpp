//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private : 
    bool dfs(int curr ,int color ,  vector<int>adj[] , vector<int>&mark){
        mark[curr] = color;
        
        for(auto it : adj[curr])
        {
            if(mark[it] == -1){
                if(!dfs(it , !color , adj , mark)) return false;
            }
            else if(mark[it] == color) return false;
        }
        return true;
    }
public:
	bool isBipartite(int v, vector<int>adj[]){
	    // Code here
	    vector<int>mark(v , -1);
	    for(int i = 0 ; i< v ; i++){
	        if(mark[i] == -1){
	            if(!dfs(i ,0 ,  adj , mark))
	            return false;
	        }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends