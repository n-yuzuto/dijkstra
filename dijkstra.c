#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // stdbool.hヘッダーファイルをインクルード
#include <limits.h>
#include "common.h"

extern int w[N][N];
extern bool S[N];
extern int Scount;                      // 頂点集合Sの要素数
extern int d[N];
extern int parent[N];
int STACK[N];

/**
 * 頂点集合 S に頂点 u を追加する．
 * @param u 追加する頂点
 * @param S 頂点集合
 * @return なし
 */
void add(int u, bool S[]) {
  S[u] = true;
}

/**
 * 頂点集合のうち S に追加されていない頂点があるかどうか確認する．
 * @return S に追加されていない頂点が存在すれば true，それ以外は false
 */
static bool remain() {
  // 関数を完成させる．
  int count = 0;
  int i;
  for(i=0;i<N;i++){
    if(S[i] == false) count++;
  }
  if(count >= 1){
    return true;
  }
  else return false;
}

/**
 * p からの最短距離が確定していない頂点のうち，d[] が最小の頂点を
 * 返す．
 * @param なし
 * @return 未確定の d[] が最小の頂点
 */
int select_min() {
  // 関数を完成させる．
int i;
int target = -1;
int distance = 99999;
for(i=0;i<N;i++){
  if(S[i] == false){
    if(d[i] != M){
      if(d[i] < distance){
      distance = d[i];
      target = i;
      }
    }
  }
}
return target;
}

/**
 * 頂点 u から頂点 x に接続する辺が存在すれば true, それ以外は
 * false を返す.
 * @param u 頂点
 * @param x 頂点
 * @return 辺が存在すれば true, それ以外は false
 */
bool member(int u, int x) {
  // 関数を完成させる．
if (w[u][x] != M) return true;
else return false;
}

/**
 * ダイクストラ法で，頂点 p から各頂点への最短路の重みを計算する．
 * @param p 開始点
 * @return なし
 */
void dijkstra(int p) {
  int i;
  add(p, S);
  for(i = 0; i < N; i++) {
    d[i] = w[p][i];
    // (A)
    parent[i] = p;
  }
  
  while (remain()) {
    int u = select_min();
    if (u == -1)
      break;
    else
      add(u, S);
  int x;
    for(x = 0; x < N; x++) {
      if (member(u, x) == true) {
        int k = d[u] + w[u][x];
        if (k < d[x]){
          d[x] = k;
          // (B)
          parent[x] = u;
        }
      }
    }
  }
  printf("\n");
}

/**
 * 配列の中身を標準出力に表示．結果出力およびデバッグ用．
 * @param name ラベル（変数名など）
 * @param ary 配列
 * @return なし
 */
void display(char* name, int* ary, int length) {
  printf("%s: [", name);
  int i;
  for(i = 0; i < length; i++) {
    if (ary[i] == M)
      printf(" M");
    else
      printf(" %d", ary[i]);
  }
  printf(" ]\n");
}

int top = 0;
int push(int* STACK,int d){
    if(top > N-1){
        printf("Overflow stack");
        return EXIT_FAILURE;
    }
    STACK[top]=d;
    top+=1;
}


int pop(int* STACK){
    if(top == 0){
        printf("Underflow stack");
        return EXIT_FAILURE;
    }
    top-=1;
    return STACK[top];
}

void shortest_path(int m,int n){
    if(d[n]==M){
        printf("there is no path.\n");
    }
    else{
        int x;
        x = n;
        push(STACK,x);
        while(x != m){
            x = parent[x];
            push(STACK,x);
        }
        while(top > 1){
            printf("%d -> ",pop(STACK));
        }
        printf("%d\n",pop(STACK));
    }
}

