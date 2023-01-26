#include<bits/stdc++.h>
using namespace std;
void setZeroes(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        for(int i=0;i<n;i++) {
            for(int j = 0 ; j< m;j++){
if((i<n-1 && mat[i+1][j] == 0) || (j>0 && mat[i][j-1] == 0)|| (i>0&& mat[i-1][j] == 0)||(j<m-1 && mat[i][j+1] == 0)){
                        mat[i][j] = 0;
                }
            }
        }

        
    }
int main(){
vector<vector<int>> mat = {{1,1,1},{1,0,1},{1,1,1}};
setZeroes(mat);

for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
        }

}