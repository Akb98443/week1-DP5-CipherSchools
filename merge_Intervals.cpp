#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& itrvl) {
        vector<vector<int>>vt;
        int n = itrvl.size();
        sort(itrvl.begin() , itrvl.end());
        for(int i = 0; i < n ; i++) {
          if(vt.size() ==0){
              vt.push_back(itrvl[i]);

          }  
          else{
              int sz = vt.size();
              if(max(itrvl[i][0] , itrvl[i][1]) < vt[sz-1][1]){
                  continue;
              }else if(vt[sz-1][1] >= itrvl[i][0] && vt[sz-1][1] <= itrvl[i][1]){
                  vt[sz-1][1] = itrvl[i][1];
              }
              else{
                  vt.push_back(itrvl[i]);
              }
              
          }
            
        }
        
        return vt;
    }

int main() {
vector<vector<int>>v = { {1,3},{2,6},{8,10},{15,18}};

vector<vector<int>>ans = merge(v);

for(auto row :ans){
    for(auto ele:row){
        cout << ele <<" ";
    }
    cout<<endl;
}

}