#include<bits/stdc++.h>
using namespace std ;
vector<int> mergeTwoSortedArr(vector<int>& a, vector<int>& b){
    int n1 = a.size()-1, n2 = b.size()-1 ;
    vector<int>ans;
    int i = 0,j = 0;
    while(i<=n1 ||j<=n2){
        if(i<=n1 && a[i] <= b[j]){
            ans.push_back(a[i]);
            i++;
        }
        else if(j <= n2 && b[j] < a[i]){
            ans.push_back(b[j]);
            j++;
        }
    }
    return ans;
}

int main() {
    vector<int>arr1 = {1,2,3,4,5,};
    vector<int>arr2 = {30,40,89,90};
    vector<int>ans = mergeTwoSortedArr(arr1 , arr2);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}

