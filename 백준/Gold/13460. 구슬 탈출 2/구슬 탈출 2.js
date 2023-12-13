const fs = require('fs');
const [NM, ..._board] = fs
  .readFileSync('dev/stdin')
  .toString()
  .trim()
  .split('\n');

const [N, M] = NM.split(' ').map((n) => parseInt(n));

let blue = [0, 0];
let red = [0, 0];

const board = _board.map((line) => line.split(''));

for (let i = 0; i < N; ++i) {
  for (let j = 0; j < M; ++j) {
    if (board[i][j] === 'B') {
      blue = [i, j];
      board[i][j] = '.';
    }
    if (board[i][j] === 'R') {
      red = [i, j];
      board[i][j] = '.';
    }
  }
}

const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];

const move = (direction, ball) => {
  let resultY = ball[0];
  let resultX = ball[1];
  let count = 0;
  while (true) {
    const ny = dy[direction] + resultY;
    const nx = dx[direction] + resultX;

    if (ny < 0 || N <= ny || nx < 0 || M <= nx) break;
    if (board[ny][nx] === '#') break;

    ++count;
    resultY = ny;
    resultX = nx;

    if (board[ny][nx] === 'O') break;
  }

  return [count, resultY, resultX];
};

class Queue {
  constructor() {
    this.arr = [];
    this.head = 0;
  }

  push(val) {
    this.arr.push(val);
  }

  shift() {
    if (this.isEmpty()) return null;

    const item = this.arr[this.head];
    ++this.head;

    if (1000 < this.head) {
      this.arr = this.arr.slice(this.head);
      this.head = 0;
    }

    return item;
  }

  size() {
    return this.length - this.head;
  }

  isEmpty() {
    return this.arr.length === this.head;
  }
}
let answer = 0;
const bfs = () => {
  const queue = new Queue();

  queue.push([red, blue, 1]);

  while (!queue.isEmpty()) {
    const [curRed, curBlue, cost] = queue.shift();
    if (10 < cost) continue;
    for (let i = 0; i < 4; ++i) {
      const [rCnt, ...nextRed] = move(i, curRed);
      const [bCnt, ...nextBlue] = move(i, curBlue);
      if (rCnt === 0 && bCnt === 0) continue;
      if (nextRed[0] === nextBlue[0] && nextRed[1] === nextBlue[1]) {
        if (board[nextBlue[0]][nextBlue[1]] === 'O') continue;
        if (rCnt < bCnt) {
          nextBlue[0] -= dy[i];
          nextBlue[1] -= dx[i];
        } else {
          nextRed[0] -= dy[i];
          nextRed[1] -= dx[i];
        }
      }

      if (board[nextBlue[0]][nextBlue[1]] === 'O') continue;
      if (board[nextRed[0]][nextRed[1]] === 'O') {
        answer = cost;
        break;
      }
      queue.push([nextRed, nextBlue, cost + 1]);
    }
    if (answer) break;
  }
};
bfs();
console.log(answer === 0 ? -1 : answer);
