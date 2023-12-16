const fs = require('fs');
const input = fs.readFileSync('dev/stdin').toString().trim().split('\n');

const [N, P, Q, X, Y] = input[0].split(' ').map((n) => parseInt(n));

const cache = new Map();

const getNum = (num) => {
  if (num <= 0) return 1;
  if (cache.has(num)) return cache.get(num);

  const t = getNum(Math.floor(num / P) - X) + getNum(Math.floor(num / Q) - Y);
  cache.set(num, t);
  return t;
};

console.log(getNum(N));
