//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        // Code here
        // vector<int>dist(v , INT_MAX);
        // vector<bool>find(v , false);
        // dist[s] = 0;
        
        // for(int cnt = 0; cnt<v-1;cnt++) {
        //     int u = -1;
        //     for(int i = 0;i<v;i++){
        //         if(!find[i] && (u==-1 || dist[i] < dist[u])){
        //             u = i;
        //         }
        //     }
        //     find[u] = true;
            
            
        //     for(auto v1: adj[u]) {
        //         if(find[v1[0]] == false){
        //             dist[v1[0]] = min(dist[v1[0]] , dist[u]+v1[1]);
        //         }
        //     }
        // }
        
        // return dist; 
        
        
    ///using priority queue
    
    priority_queue<pair<int,int>,vector<pair<int ,int>> , greater<pair<int,int>>>pq;
    vector<int>dist(v , 10e9);
    dist[s] =0;
    pq.push({0,s});
    while(!pq.empty()){
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();
    
    for(auto it : adj[node]){
        int adjwt = it[1];
        int adjnode = it[0];
        
        if(wt+ adjwt < dist[adjnode] ){
            dist[adjnode] = wt + adjwt;
            pq.push({dist[adjnode] , adjnode});
        }
    }
    }
        return dist;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends