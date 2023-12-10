const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const board = input.map((l) => l.split('').map((n) => parseInt(n)));

const isValid = (y, x, num) => {
  for (let i = 0; i < 9; ++i) {
    if (board[i][x] === num) return false;
    if (board[y][i] === num) return false;
  }

  nY = y < 3 ? 0 : y < 6 ? 3 : 6;
  nX = x < 3 ? 0 : x < 6 ? 3 : 6;

  for (let i = nY; i < nY + 3; ++i) {
    for (let j = nX; j < nX + 3; ++j) {
      if (board[i][j] === num) return false;
    }
  }

  return true;
};

answer = null;
const dfs = (idx) => {
  if (answer) {
    return;
  }
  if (idx === 81) {
    answer = board;
    return;
  }

  const y = Math.floor(idx / 9);
  const x = idx % 9;

  if (board[y][x] !== 0) {
    dfs(idx + 1);
    return;
  }

  for (let i = 1; i <= 9; ++i) {
    if (isValid(y, x, i)) {
      board[y][x] = i;
      dfs(idx + 1);
      if (!answer) board[y][x] = 0;
    }
  }
};

dfs(0);

board.forEach((l) => console.log(l.join('')));
