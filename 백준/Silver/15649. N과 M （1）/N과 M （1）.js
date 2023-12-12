
const fs = require('fs');
const [N, M] = fs
  .readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split(' ')
  .map((n) => parseInt(n));
// dev/stdin

const answer = [];
const arr = [];
const recur = (cnt) => {
  if (arr.length === M) {
    answer.push([...arr]);
    return;
  }
  for (let i = 1; i <= N; ++i) {
    if (arr.includes(i)) continue;
    arr.push(i);
    recur(cnt + 1);
    arr.pop();
  }
};

recur(1);

console.log(answer.map((n) => n.join(' ')).join('\n'));
