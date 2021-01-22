#include <stdlib.h>

int *snail(size_t *outsz, const int **mx, size_t rows, size_t cols) {
  // the numbers of rows and cols are passed separately for historical reasons
  *outsz = rows*cols;
  size_t sz = rows * cols;
  int *arr = malloc(sizeof(int) * sz);
  int flags[rows][cols];
  for(size_t i=0; i<rows; i++)
    memset(flags[i], 0, sizeof(int)*cols);
  int dirx[4] = {0, 1, 0, -1};
  int diry[4] = {1, 0, -1, 0};
  size_t n = 0, x = 0, y = 0;
  int dir = 0;
  while(n<rows*cols){
    arr[n] = mx[x][y];
    flags[x][y] = 1;
    size_t tmpx = x + dirx[dir];
    size_t tmpy = y + diry[dir];
    if(flags[tmpx][tmpy]==1 || tmpx<0 || tmpx>=rows || tmpy<0 || tmpy>=cols) {
      dir = (dir+1)%4;
    }
    x = x + dirx[dir];
    y = y + diry[dir];
    n++;
  }
  return arr;
}
