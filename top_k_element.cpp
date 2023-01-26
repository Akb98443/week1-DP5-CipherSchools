#include<bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {

         priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;
        unordered_map<int,int>mp;
        for(auto x : nums)
        mp[x]++;
        for(auto x : mp){
            pq.push({x.second , x.first});
            if(pq.size() > k)
            pq.pop();
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }

int main() {

vector<int>  nums = {1,1,1,2,2,3};

vector<int>ans = topKFrequent(ans , 2);

// cout<<"top " << 2<<" element : "<<endl;
for(int i = 0; i < ans.size(); i++){
    cout<<ans[i]<<" ";
}


}