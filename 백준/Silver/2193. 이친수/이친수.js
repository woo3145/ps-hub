const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const N = parseInt(input[0]);

const dp = Array.from({ length: N + 1 }, () => 0);

dp[1] = BigInt(1); // 1
dp[2] = BigInt(1); // 10

for (let i = 3; i <= N; ++i) {
  dp[i] = dp[i - 1] + dp[i - 2];
}

console.log(dp[N].toString());
