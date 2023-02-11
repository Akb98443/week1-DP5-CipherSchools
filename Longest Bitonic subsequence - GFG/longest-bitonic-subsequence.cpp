//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>arr)
	{
	    int n = arr.size();
	    // code here
	  int dp1[n];
	  int dp2[n];
	  
	  //////for dp1
	  for(int i = 0 ; i < n ; i++){
	      dp1[i] = 1;
	      for(int j = 0 ; j < i ; j++){
	          if(arr[j] < arr[i]){
	              dp1[i] = max(dp1[i] , dp1[j]+1);
	          }
	      }
	  }
	  
	  //////for dp2
	  
	  for(int i = n-1 ; i >= 0 ; i--){
	      dp2[i] = 1;
	      for(int j = n-1 ; j > i ; j--){
	          if(arr[j] < arr[i]){
	              dp2[i] = max(dp2[i] , dp2[j]+1);
	          }
	      }
	  }
	  int mx1 = dp1[0];
// 	  int mx2 = dp2[0];
	  for(int i = 0 ; i<n ; i++){
	      mx1 = max(dp1[i]+dp2[i]-1 , mx1);
	   //   mx2 = max(dp2[i] , mx2);
	  }
	  
	  return mx1;//+mx2-1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends