const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

let [N, M] = input[0].split(' ').map((a) => Number(a));

let address = {};
let answer = [];

for (let i = 0; i < N; i++) {
  let [id, pw] = input[i + 1].split(' ');
  address[id] = pw;
}

for (let i = 0; i < M; i++) {
  let site = input[i + 1 + N];
  answer.push(address[site]);
}

console.log(answer.join('\n'));
