#include<bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
        double ans = 1.00;
        long long nn  = n;
        if(n < 0) nn = -1*nn;

        while(nn){
            if(nn%2){
                ans = ans*x;
                nn = nn-1;
            }
            else{
                x = x*x;
                nn = nn/2;
            }
        }
        if(n < 0) ans = (double)1.00/(double)ans;
        return ans;
}

int main(){
   double x = 2.00000;
   int n = 10;
   double ans = myPow(x , n);
   cout<<"power of the given number to n : "<<ans;

}