const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const N = parseInt(input[0]);
const arr = input.slice(1).map((n) => parseInt(n));
const dp = Array.from({ length: N + 1 }, () => 0);

dp[0] = 0;
dp[1] = arr[0];
dp[2] = arr[0] + arr[1];
dp[3] = Math.max(arr[0] + arr[2], arr[1] + arr[2]);

for (let i = 4; i <= N; ++i) {
  // 두칸전에서 오는경우 vs 세칸전과 직전칸을 밟고오는 경우
  dp[i] = Math.max(dp[i - 2] + arr[i - 1], dp[i - 3] + arr[i - 2] + arr[i - 1]);
}

console.log(dp[N]);
