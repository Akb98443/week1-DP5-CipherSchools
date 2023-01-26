#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
       vector<int>ans;
       int n = matrix.size();
       int m = matrix[0].size();
       int top = 0 , bottom = n-1 , left = 0 , ryt = m-1;
       while(top <= bottom && left <= ryt){
           
           //top row
           for(int i =left;i<= ryt;i++){
               ans.push_back(matrix[top][i]);
           }
           top++;

           //right column

           for(int i=top; i<= bottom;i++){
               ans.push_back(matrix[i][ryt]);
           }
           ryt--;


        
           //bottom row
        if(top <= bottom){
           for(int i =ryt; i>= left ;i--){
               ans.push_back(matrix[bottom][i]);
           }
           bottom--;
        }

           //left column
if(left <= ryt){
           for(int i = bottom ; i>= top;i--){
               ans.push_back(matrix[i][left]);
           }
           left++;
        }
       }

       return ans;    

       }
    
int main(){
    vector<vector<int>>matrix = {{1,2,3} , {4,5,6} ,{7,8 ,9}};
     vector<int>ans = spiralOrder(matrix);
     for(int i=0;i<ans.size();i++){
       cout<<ans[i]<<" ";
        }


}