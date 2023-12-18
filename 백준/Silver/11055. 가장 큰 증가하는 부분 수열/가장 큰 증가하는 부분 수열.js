const fs = require('fs');
const input = fs.readFileSync('dev/stdin').toString().trim().split('\n');

const N = parseInt(input[0]);
const arr = input[1].split(' ').map((n) => parseInt(n));
const dp = Array(N).fill(0);
let answer = 0;

for (let i = 0; i < N; ++i) {
  dp[i] = arr[i];

  for (let j = 0; j <= i; ++j) {
    if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i]) dp[i] = dp[j] + arr[i];
  }
  if (answer < dp[i]) answer = dp[i];
}

console.log(answer);
