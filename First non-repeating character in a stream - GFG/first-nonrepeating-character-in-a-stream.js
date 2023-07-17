//{ Driver Code Starts
//Initial Template for javascript

"use strict";

process.stdin.resume();
process.stdin.setEncoding("utf-8");

let inputString = "";
let currentLine = 0;



process.stdin.on("data", (inputStdin) => {
  inputString += inputStdin;
});

process.stdin.on("end", (_) => {
  inputString = inputString
    .trim()
    .split("\n")
    .map((string) => {
      return string.trim();
    });

  main();
});

function readLine() {
  return inputString[currentLine++];
}


function main() {
  let t = parseInt(readLine());
  let i = 0;
 
  for (; i < t; i++) {
    let A = readLine().trim();
    let obj = new Solution();
    let res = obj.FirstNonRepeating(A);
    console.log(res);
  }

}

// } Driver Code Ends


//User function Template for javascript

/**
 * @param {string} A
 * @return {string}
*/

class Solution {
  FirstNonRepeating(A){
    //code here
    let count = new Array(26).fill(0);
    let q = [];
    let res = '';
    for(let i = 0 ; i < A.length ; i++){
        
        count[A[i].charCodeAt() - 'a'.charCodeAt()]++;
        q.push(A[i]);
        while(q.length > 0 && count[q[0].charCodeAt() - 'a'.charCodeAt()] > 1){
            q.shift();
        }
        if(q.length > 0) res += q[0];
        else res += '#';
    }
    return res;
  }
}
