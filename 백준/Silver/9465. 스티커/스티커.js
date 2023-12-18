const fs = require('fs');
const input = fs.readFileSync('dev/stdin').toString().trim().split('\n');

const T = parseInt(input[0]);
const answer = [];

for (let t = 0; t < T; ++t) {
  const N = parseInt(input[t * 3 + 1]);
  const arr = [];
  arr.push(input[t * 3 + 2].split(' ').map((n) => parseInt(n)));
  arr.push(input[t * 3 + 3].split(' ').map((n) => parseInt(n)));

  if (0 < N) {
    arr[0][1] = Math.max(arr[0][0], arr[1][0] + arr[0][1]);
    arr[1][1] = Math.max(arr[1][0], arr[1][1] + arr[0][0]);
  }
  for (let i = 2; i < N; ++i) {
    arr[0][i] = Math.max(arr[1][i - 1], arr[1][i - 2]) + arr[0][i];
    arr[1][i] = Math.max(arr[0][i - 1], arr[0][i - 2]) + arr[1][i];
  }
  answer.push(Math.max(arr[0][N - 1], arr[1][N - 1]));
}
console.log(answer.join('\n'));
