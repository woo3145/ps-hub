const fs = require('fs');
const input = fs.readFileSync('dev/stdin').toString().trim().split('\n');
// dev/stdin

const [N, M] = [input[0], input[2]].map((n) => parseInt(n));

const aArr = input[1].split(' ');
const bArr = input[3].split(' ');

const cache = {};

aArr.forEach((n) => (cache[n] = 1));

const answer = [];

bArr.forEach((n) => {
  if (cache[n] === 1) {
    answer.push(1);
  } else {
    answer.push(0);
  }
});

console.log(answer.join(' '));

