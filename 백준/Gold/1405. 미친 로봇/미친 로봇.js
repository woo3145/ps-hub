const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
// dev/stdin

const [N, ...D] = input[0].split(' ').map((n) => parseInt(n));

const dy = [0, 0, 1, -1];
const dx = [1, -1, 0, 0];

let answer = 0;
const dfs = (cur, depth, cost, visited) => {
  if (N === depth) {
    answer += cost;
    return;
  }

  D.forEach((d, i) => {
    const ny = cur[0] + dy[i];
    const nx = cur[1] + dx[i];
    if (visited[ny][nx]) return;
    visited[ny][nx] = true;
    dfs([ny, nx], depth + 1, cost * (d / 100), visited);
    visited[ny][nx] = false;
  });
};
const visited = Array(N * 2 + 1)
  .fill()
  .map((n) => Array(N * 2 + 1).fill(false));
visited[N][N] = true;

dfs([N, N], 0, 1, visited);
console.log(answer);
