#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
        stack<char>stk;
        for(int i=0;i<s.size();i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                stk.push(s[i]);
            }
            char x ;
            if(stk.empty()){
                return false;
            }
            switch(s[i]){
                case ')':
                    x = stk.top();
                    stk.pop();
                    if(x == '{' || x == '[')
                        return false;
                    break;
                  case '}':
                    x = stk.top();
                    stk.pop();
                    if(x == '(' || x == '[')
                        return false;
                    break;  
                 case ']':
                    x = stk.top();
                    stk.pop();
                    if(x == '(' || x == '{')
                        return false;
                    break;   
            }
        }
        return stk.empty();
        
    }

int main(){
    string s = "{{}}()][][]{{}}()";
    if(isValid(s)){
        cout<<"Paranthesis are balanced";
    }
    else
    cout<<"Paranthesis are not valid";
}