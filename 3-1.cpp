//这个代码实现了一个计算逆序对贡献和的算法
#include<bits/stdc++.h>
#define LL long long

using namespace std;

const int MAXN = 100005;

struct T{
    int v, id;//v存放读入元素值，id存放读入序号
} x[MAXN];
int pre[MAXN], nxt[MAXN];

int cmp(T t1, T t2) { return t1.v < t2.v; }//从小到大排序

void del(int p){
    int L = pre[p], r = nxt[p]; //L和r分别存放当前元素的前缀和后缀
    nxt[L] = r; pre[r] = L;
}

int main(){
    int m, n, i, j, k;
    scanf("%d", &n);//输入元素个数
    for(i = 1; i <= n; i++){
        scanf("%d", &x[i].v);//输入元素值
        x[i].id = /*1->*/i/*<-1*/;//存入序号i
        pre[i] = i - 1;
        nxt[i] = i + 1;
    }
    nxt[0] = 1;
    pre[n + 1] = n;
    /*2->*/sort(x + 1, x + n + 1, cmp)/*<-2*/;//按照元素值对序列进行排序
    LL ans = 0;//初始化结果为0
    for(i = 1; i <= n; i++){
        LL L1, L2, r1, r2;
        L1 = pre[x[i].id];//当前元素的前驱
        if(L1) L2 = pre[L1];//当前元素的前驱的前驱
        L2 = -1;
        r1 = nxt[x[i].id];//当前元素的后继
        if(r1 != n + 1) r2 = nxt[r1];//当前元素的后继的后继
        else r2 = -1;
        if(L2 != -1) ans += (L1 - L2) * (r1 - x[i].id) * i;//计算左边逆序对的贡献
        if(r2 != -1) ans += (r2 - r1) * (x[i].id - L1) * i;//计算右边逆序对的贡献
        del(x[i].id);//删除当前元素，保证下次循环不再考虑
    }
    printf("%lld", ans);
}