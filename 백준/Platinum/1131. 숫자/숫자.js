const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [A, B, K] = input[0].split(' ').map((n) => parseInt(n));
const pows = {};

for (let i = 0; i < 10; ++i) {
  pows[i] = Math.pow(i, K);
}

const calc = (num) => {
  let sum = 0;
  while (num) {
    sum += pows[num % 10];
    num = Math.floor(num / 10);
  }
  return sum;
};

const dp = Array(1000001);
const dfs = (cur) => {
  if (dp[cur] !== undefined && dp[cur] !== -1) {
    return dp[cur];
  }

  // 첫 방문
  if (dp[cur] === undefined) {
    dp[cur] = -1; // 방문 표시
    const next = dfs(calc(cur));
    // dfs를 돌면서 다음 순환수의 min값을 찾음

    return (dp[cur] = Math.min(next, cur));
  } else {
    // 사이클 발견
    let min = cur;
    // 사이클 중 가장 최솟값 찾기
    for (let i = calc(cur); i !== cur; i = calc(i)) min = Math.min(min, i);

    // dp에 최솟값 저장
    for (let i = calc(cur); i !== cur; i = calc(i)) dp[i] = min;

    return (dp[cur] = min);
  }
};

let answer = 0;
for (let i = A; i <= B; ++i) {
  answer += dfs(i);
}

console.log(answer);
