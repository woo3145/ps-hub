const fs = require('fs');
const [_N, ..._board] = fs
  .readFileSync('dev/stdin')
  .toString()
  .trim()
  .split('\n');

const N = parseInt(_N);
const startBoard = _board.map((line) =>
  line.split(' ').map((n) => parseInt(n))
);
let answer = 0;

const moveLeft = (board) => {
  const newBoard = Array(N)
    .fill()
    .map((n) => Array(N).fill(0));

  for (let y = 0; y < N; ++y) {
    const arr = [];
    let prev = 0;
    for (let x = 0; x < N; ++x) {
      if (board[y][x] === 0) continue;
      if (prev === board[y][x]) {
        arr.push(prev * 2);
        prev = 0;
      } else {
        if (prev !== 0) arr.push(prev);
        prev = board[y][x];
      }
    }
    if (prev !== 0) arr.push(prev);

    for (let j = 0; j < arr.length; ++j) {
      if (answer < arr[j]) answer = arr[j];
      newBoard[y][j] = arr[j];
    }
  }
  return newBoard;
};
const moveRight = (board) => {
  const newBoard = Array(N)
    .fill()
    .map((n) => Array(N).fill(0));

  for (let y = 0; y < N; ++y) {
    const arr = [];
    let prev = 0;
    for (let x = N - 1; 0 <= x; --x) {
      if (board[y][x] === 0) continue;
      if (prev === board[y][x]) {
        arr.push(prev * 2);
        prev = 0;
      } else {
        if (prev !== 0) arr.push(prev);
        prev = board[y][x];
      }
    }
    if (prev !== 0) arr.push(prev);

    for (let j = 0; j < arr.length; ++j) {
      if (answer < arr[j]) answer = arr[j];
      newBoard[y][N - 1 - j] = arr[j];
    }
  }
  return newBoard;
};
const moveUp = (board) => {
  const newBoard = Array(N)
    .fill()
    .map((n) => Array(N).fill(0));

  for (let x = 0; x < N; ++x) {
    const arr = [];
    let prev = 0;
    for (let y = 0; y < N; ++y) {
      if (board[y][x] === 0) continue;
      if (prev === board[y][x]) {
        arr.push(prev * 2);
        prev = 0;
      } else {
        if (prev !== 0) arr.push(prev);
        prev = board[y][x];
      }
    }
    if (prev !== 0) arr.push(prev);

    for (let j = 0; j < arr.length; ++j) {
      if (answer < arr[j]) answer = arr[j];
      newBoard[j][x] = arr[j];
    }
  }
  return newBoard;
};
const moveDown = (board) => {
  const newBoard = Array(N)
    .fill()
    .map((n) => Array(N).fill(0));

  for (let x = 0; x < N; ++x) {
    const arr = [];
    let prev = 0;
    for (let y = N - 1; 0 <= y; --y) {
      if (board[y][x] === 0) continue;
      if (prev === board[y][x]) {
        arr.push(prev * 2);
        prev = 0;
      } else {
        if (prev !== 0) arr.push(prev);
        prev = board[y][x];
      }
    }
    if (prev !== 0) arr.push(prev);

    for (let j = 0; j < arr.length; ++j) {
      if (answer < arr[j]) answer = arr[j];
      newBoard[N - 1 - j][x] = arr[j];
    }
  }
  return newBoard;
};

const dfs = (curBoard, cnt) => {
  if (5 < cnt) {
    return;
  }

  dfs(moveLeft(curBoard), cnt + 1);
  dfs(moveRight(curBoard), cnt + 1);
  dfs(moveUp(curBoard), cnt + 1);
  dfs(moveDown(curBoard), cnt + 1);
};

dfs(startBoard, 1);

console.log(answer);
