//这段代码是用动态规划求解旅行商问题，实现了计算一组点之间的最短路径，并输出最短路径的长度。
#include<bits/stdc++.h>

using namespace std;

int n;                          //点的数量
double a[16][3];                //存储每个点的坐标
double dp[1 << 16][16], ans;    //dp数组用于存储最短路径的长度
//ans用于存储最终的最短路径长度

double dis(int x, int y){//计算两个点之间的距离
    return sqrt((a[x][1] - a[y][1]) * (a[x][1] - a[y][1]) + (a[x][2] - a[y][2]) * (a[x][2] - a[y][2]));
}

int main(){
    cin >> n;//输入点的数量
    for(int i = 1; i <= n; i++)
        cin >> a[i][1] >> a[i][2];//输入每个点的坐标
    n++;//点数增加1，因为需要包含起点
    memset(dp, 127, sizeof(dp));//初始化dp为一个较大的数，默认值为无穷大
    dp[1][0] = 0;//起点到自身的距离为0
    for(int s = 0; s <= (1 << n) - 1; s++){//状态压缩遍历所有可能的路径
        for(int i = 1; i <= n - 1; i++){
            if((s & (1 << i)) == 0) continue;//如果状态s中不包含点i，则跳过当前循环

            int x = s - (1 << i);//移除点i后的新状态
            for(int j = 0; j <= n - 1; j++){
                if((s & (1 << j)) == 0) continue;//如果状态s中不包含点j，则跳过当前循环
                dp[s][i] = min(dp[s][i], dp[x][j] + dis(j, i));//更新最短路径长度
            }
        }
    }
    int x = (1 << n) - 1;//最终的状态表示所有点都已经访问过
    ans = dp[x][1];//初始化最短路径长度为从起点出发经过所有点的距离
    for(int i = 2; i < n; i++)
        ans = min(dp[x][i], ans);//找到经过所有点的最短路径
    printf("%2lf", ans);
}