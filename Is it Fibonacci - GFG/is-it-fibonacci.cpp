//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
        // code here
        if(K== 1) return GeekNum[0];
        if(K > N) return GeekNum[N];
        
        long long dp[N];
        for(int i = 0 ; i < K ; i++){
            dp[i] = GeekNum[i];
        }
        
        for(int i = K ; i < N ; i++){
            long long sum = 0;
            for(int j = i-K; j < i ; j++){
                sum+= dp[j];
                // cout<<sum<<endl;
            }
            dp[i] = sum;
            // cout<<dp[K]<<" ";
        }
        return dp[N-1];
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends