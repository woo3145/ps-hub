const fs = require('fs');
const input = fs.readFileSync('dev/stdin').toString().trim().split('\n');

const N = parseInt(input[0]);
const dp = Array(N + 1).fill(Infinity);

for (let i = 0; i <= N; ++i) {
  dp[i] = i;
  for (let j = 2; j * j <= i; ++j) {
    dp[i] = Math.min(dp[i], dp[i - j * j] + 1);
  }
}

console.log(dp[N]);
