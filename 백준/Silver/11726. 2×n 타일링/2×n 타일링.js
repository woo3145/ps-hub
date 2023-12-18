const fs = require('fs');
const input = fs.readFileSync('dev/stdin').toString().trim().split('\n');

const N = parseInt(input[0]);
const dp = Array(N + 1).fill(0);
const MOD = 10007;
dp[1] = 1;
dp[2] = 2;

for (let i = 3; i <= N; ++i) {
  dp[i] = dp[i - 1] + dp[i - 2];
  dp[i] %= MOD;
}

console.log(dp[N]);