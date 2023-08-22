//这段代码是用动态规划求解旅行商问题，实现了计算一组点之间的最短路径，并输出最短路径的长度。
#include<bits/stdc++.h>

using namespace std;

int n;                          //点的数量
double a[16][3];                //存储每个点的坐标
double dp[1 << 16][16], ans;    //dp数组用于存储最短路径的长度
//ans用于存储最终的最短路径长度

double dis(int x, int y){
    return sqrt((a[x][1] - a[y][1]) * (a[x][1] - a[y][1]) + (a[x][2] - a[y][2]) * (a[x][2] - a[y][2]));
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i][1] >> a[i][2];
    n++;
    memset(dp, 127, sizeof(dp));
    dp[1][0] = 0;
    for(int s = 0; s <= (1 << n) - 1; s++){
        for(int i = 1; i <= n - 1; i++){
            if((s & (1 << i)) == 0) continue;

            int x = s - (1 << i);
            for(int j = 0; j <= n - 1; j++){
                if((s & (1 << j)) == 0) continue;
                dp[s][i] = min(dp[s][i], dp[x][j] + dis(j, i));
            }
        }
    }
    int x = (1 << n) - 1;
    ans = dp[x][1];
    for(int i = 2; i < n; i++)
        ans = min(dp[x][i], ans);
    printf("%2lf", ans);
}