//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > arr, int n)
    {
        // code here 
       
        int ans = 0 , row = 0 , col = 0 , sum = 0;
        for(int i = 0 ; i < n ; i++){
            int r = 0 , c = 0;
            for(int j = 0 ; j < n ; j++){
                sum += arr[i][j];
                r += arr[i][j];
                c += arr[j][i];
            }
           row = max(row , r);
           col = max(col , c);
        }
       
       return max(row , col)*n -sum;
    } 
    
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends