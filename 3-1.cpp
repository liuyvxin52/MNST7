//这个代码实现了一个计算逆序对贡献和的算法
#include<bits/stdc++.h>
#define LL long long

using namespace std;

const int MAXN = 100005;

struct T{
    int v, id;//v存放读入元素值，id存放读入序号
} x[MAXN];
int pre[MAXN], nxt[MAXN];

int cmp(T t1, T t2) { return ti.v < t2.v; }//从小到大排序

void del(int p){
    int L = pre[p], r = nxt[p]; //L和r分别存放当前元素的前缀和后缀
    nxt[L] = r; pre[r] = L;
}

int main(){
    int m, n, i, j, k;
    scanf("%d", &n);//输入元素个数
    for(int i = 1; i <= n; i++){
        scanf("%d", &x[i]);//输入元素值
        x[i].id = /*1->*/i/*<-1*/;//存入序号i
        pre[i] = i - 1;
        nxt[i] = i + 1;
    }
    nxt[0] = 1;
    pre[n + 1] = n;
    /*2->*/sort(x + 1, x + n + 1, cmp)/*<-2*/;
    LL ans = 0;
    for(i = 1; i <= n; i++){
        
    }
}