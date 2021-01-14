#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "common.h"

int w[N][N] = {
  { 0, M,  M, 8, 15, M},
  {10, 0, 24, M,  8, M},
  { M, M,  0, M,  M, 6},
  { M, M,  M, 0,  5, M},
  { M, M, 12, M,  0, 7},
  { M, M,  3, M,  M, 0}};
bool S[N];
int i;
int parent[N];

int Scount = 0;                      // 頂点集合Sの要素数
int d[N];
int STACK[N];


void add(int, bool[]);
bool remain();
int dijkstra(int);
void display(char *, int *, int);
void shortest_path(int m, int n);
int push(int* STACK,int d);
int pop(int* STACK);



int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: ./main <node ID>\n");
    return 1;
  }

  int p = atoi(argv[1]);
  if (p < 0 || N <= p) {
    fprintf(stderr, "Node ID %d is out of range: [0, %d].\n", p, N);
    return 1;
  }

  for(i = 0; i < N; i++)
    S[i] = false;


  dijkstra(p);              // ダイクストラ法による最短路の計算
  display("Result", d, N);  // 結果表示
  int i;
  for (i=0;i<N;i++) 
  shortest_path(p,i);
  return 0;
}