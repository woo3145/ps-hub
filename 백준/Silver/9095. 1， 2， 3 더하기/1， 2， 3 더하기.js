const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const T = parseInt(input[0]);
const arr = input.slice(1).map((n) => parseInt(n));
const MAX_N = 11;
const dp = Array.from({ length: MAX_N + 1 }, () => 0);
dp[1] = 1;
dp[2] = 2; // 1 1, 2
dp[3] = 4; // 1 1 1, 1 2, 2 1, 3
const recursive = (sum) => {
  if (dp[sum]) {
    return dp[sum];
  }

  for (let i = 1; i <= 3; ++i) {
    dp[sum] += recursive(sum - i);
  }
  return dp[sum];
};

recursive(MAX_N);

let answer = '';
for (i = 0; i < T; ++i) {
  answer += `${dp[arr[i]]}\n`;
}

console.log(answer.trim());
