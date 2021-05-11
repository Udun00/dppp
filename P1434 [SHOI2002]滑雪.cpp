/*
题目：https://www.luogu.com.cn/problem/P1434
思路：滑雪只能从高往低滑，定义dp[i][j]为坐标为（i,j）的最优解，并且从最小高度往最大高度开始dp（因为低高度的变化不会影响高高度）
判断：如果上下左右未出边界且高度比该点高度低，更新dp数组
更新代码
if(high[u.x-1][u.y]<u.h)dp[u.x][u.y]=max(dp[u.x][u.y],dp[u.x-1][u.y]+1);//找出从上下左右下来的最优解
if(high[u.x+1][u.y]<u.h)dp[u.x][u.y]=max(dp[u.x][u.y],dp[u.x+1][u.y]+1);
if(high[u.x][u.y-1]<u.h)dp[u.x][u.y]=max(dp[u.x][u.y],dp[u.x][u.y-1]+1);
if(high[u.x][u.y+1]<u.h)dp[u.x][u.y]=max(dp[u.x][u.y],dp[u.x][u.y+1]+1);
*/
//代码实现
#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
typedef struct k
{
    int x,y,h;
} k;
struct cmp//定义容器
{
    bool operator()(k x1,k x2)
    {
        return x1.h>x2.h;
    }
};
int dp[110][110],high[110][110];
int main()
{
    priority_queue<k,vector<k>,cmp> pp;
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            scanf("%d",&high[i][j]);
            k l;
            l.x=i,l.y=j,l.h=high[i][j];
            pp.push(l);
            dp[i][j]=1;
        }
    }
    int ans=0;
    while(!pp.empty())
    {
        k u=pp.top();
        if(high[u.x-1][u.y]<u.h)dp[u.x][u.y]=max(dp[u.x][u.y],dp[u.x-1][u.y]+1);//找出从上下左右下来的最优解
        if(high[u.x+1][u.y]<u.h)dp[u.x][u.y]=max(dp[u.x][u.y],dp[u.x+1][u.y]+1);
        if(high[u.x][u.y-1]<u.h)dp[u.x][u.y]=max(dp[u.x][u.y],dp[u.x][u.y-1]+1);
        if(high[u.x][u.y+1]<u.h)dp[u.x][u.y]=max(dp[u.x][u.y],dp[u.x][u.y+1]+1);
        pp.pop();
        ans=max(ans,dp[u.x][u.y]);
    }
    printf("%d",ans);
}
