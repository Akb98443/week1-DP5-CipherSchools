//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        // code here
        // vector<bool>mset(v,false);
        // vector<int>key(v ,INT_MAX);
        // key[0] = 0;
        // int res = 0;
        // for(int ct = 0;ct < v; ct++){
            
        //     int u = -1;
        //     for(int i=0;i<v;i++){
        //         if(mset[i] == false && (u==-1 || key[i] < key[u])){
        //             u = i;
        //         }
        //     }
        //     mset[u] = true;
        //     res += key[u];
            
        //     for(auto it : adj[u]){
        //         if(!mset[it[0]]){
        //             key[it[0]] = min(key[it[0]] , it[1]);
        //         }
        //     }
        // }
        
        // return res;
        
        
        ///METHOD2 Priority Queue
priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int>vis(v , 0);
        pq.push({0 , 0});
    
        int sum = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            
            int node = it.second;
            if(vis[node] == 1) continue;
                vis[node] = 1;
            sum += wt;
            for(auto nd : adj[node]){
                int adjNode = nd[0];
                int edw = nd[1];
                if(!vis[adjNode])
                pq.push({edw , adjNode});
                
            
            }
            
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends