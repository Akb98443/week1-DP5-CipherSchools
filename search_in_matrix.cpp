#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int target) {
       int n = mat.size();
       int m = mat[0].size();
       int i=0,j = m-1;
        while(i < n&&j>=0){
            if(mat[i][j] == target)
                return true;
            else if(mat[i][j] > target){
                j--;
            }
            else
                i++;
        }
        return false;
    }
int main(){

    vector<vector<int>>mat = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    if(searchMatrix(mat , 16))
    cout<<"Yes! element found in the matrix";
    else
    cout<<"No! element not found in the matrix";

}