//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        int count[26] = {0};
        for(int i = 0;i<s.size() ;i++){
        if(s[i] == 'b' || s[i] == 'a'||s[i] == 'l'||s[i] == 'o'||s[i] == 'n'){
        count[s[i]-'a']++;
    }
        }
        int ans = INT_MAX;
        count['l'-'a'] = count['l'-'a']/2;
        count['o' -'a'] = count['o' -'a']/2;
        for(int i = 0;i<26 ;i++){
           if(i == ('b'-'a') || i == ('a'-'a') || i==('l'-'a') || i == ('o'-'a') || i == ('n'-'a')) {
            
               ans = min(ans , count[i]);
           }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends