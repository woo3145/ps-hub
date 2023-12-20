const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const N = parseInt(input[0]);
const arr = input[1].split(' ').map((n) => parseInt(n));
const dp = Array.from({ length: N + 1 }, () => -Infinity);

dp[0] = 0;
for (let i = 1; i <= N; ++i) {
  for (let j = 1; j <= i; ++j) {
    dp[i] = Math.max(dp[i], dp[i - j] + arr[j - 1]);
  }
}

console.log(dp[N]);
