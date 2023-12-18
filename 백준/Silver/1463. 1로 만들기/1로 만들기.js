const fs = require('fs');
const input = fs.readFileSync('dev/stdin').toString().trim().split('\n');

const N = parseInt(input[0]);
const dp = Array(N + 1).fill(Infinity);

dp[1] = 0;

for (let i = 2; i <= N; ++i) {
  const nums = [dp[i - 1]];
  if (i % 3 === 0) nums.push(dp[i / 3]);
  if (i % 2 === 0) nums.push(dp[i / 2]);
  dp[i] = Math.min(...nums) + 1;
}

console.log(dp[N]);
