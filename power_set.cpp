#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> all_subsets(vector<int>& nums) {
        vector<vector<int>>v = {{}};
        for(int num : nums){
            int n = v.size();
            for(int i=0;i<n;i++){
            v.push_back(v[i]);
            v.back().push_back(num);
            }
        }
return v;
    }


int main() {
    vector<int>v = {1,2,3};
    vector<vector<int>> subsets = all_subsets(v);

    for(int i = 0; i < subsets.size();i++){
        for(int j = 0; j < subsets[i].size();j++){
            cout << subsets[i][j] <<" ";
        }
        cout<<endl;
    }



}