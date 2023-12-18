const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const N = parseInt(input[0]);
const arr = input[1].split(' ').map((n) => parseInt(n));

const lowerBound = (_arr, val) => {
  let left = 0;
  let right = _arr.length;

  while (left < right) {
    const mid = Math.floor((left + right) / 2);

    if (val <= _arr[mid]) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  return left;
};

const lis = [];

lis.push(arr[0]);

for (let i = 1; i < N; ++i) {
  if (lis[lis.length - 1] < arr[i]) {
    lis.push(arr[i]);
  } else {
    const idx = lowerBound(lis, arr[i]);
    lis[idx] = arr[i];
  }
}

console.log(lis.length);
