const fs = require('fs');
const input = fs.readFileSync('dev/stdin').toString().trim().split('\n');
// 

const T = parseInt(input[0]);
const [N, M] = [parseInt(input[1]), parseInt(input[3])];

const aArr = input[2].split(' ').map((n) => parseInt(n));
const bArr = input[4].split(' ').map((n) => parseInt(n));

const aSum = [];
for (let i = 0; i < N; ++i) {
  let sum = 0;
  for (let j = i; j < N; ++j) {
    sum += aArr[j];
    aSum.push(sum);
  }
}

const bSum = {};
for (let i = 0; i < M; ++i) {
  let sum = 0;
  for (let j = i; j < M; ++j) {
    sum += bArr[j];
    if (sum in bSum) bSum[sum] += 1;
    else bSum[sum] = 1;
  }
}
answer = 0;
aSum.forEach((n) => {
  const result = bSum[T - n];
  if (result) answer += result;
});

console.log(answer);
