const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const MOD = 1000000000;
const [N, K] = input[0].split(' ').map((n) => parseInt(n));
const dp = Array.from({ length: N + 1 }, () =>
  Array.from({ length: K + 1 }, () => 0)
);

// 1을 만드는 방법은 K개의 수를 골랐을때 0 0 1, 0 1 0, 1 0 0과 같이 K개의 방법이 존재함
for (let i = 0; i <= K; ++i) {
  dp[1][i] = i;
}

for (let n = 2; n <= N; ++n) {
  for (let k = 1; k <= K; ++k) {
    dp[n][k] = dp[n - 1][k] + dp[n][k - 1];
    dp[n][k] %= MOD;
  }
}

console.log(dp[N][K]);
