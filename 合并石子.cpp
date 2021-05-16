/*
题目：https://vjudge.net/contest/437602#problem/B
优化：定义b[i]为前缀和数组
思路：定义dp[i][j]为i到j的最优解，那么dp[i][j]由两部分组成,可以从中间选一个点k
状态转移方程
dp[i][j]=max(dp[i][j],dp[i][k]+dp[k][j]+b[j]-b[i-1])
dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+b[j]-b[i-1])
*/
#include<stdio.h>
int a[110],b[110],mi[110][110]= {0},ma[110][110]= {0};
int min(int x,int y)
{
    return x<y?x:y;
}
int max(int x,int y)
{
    return x>y?x:y;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            b[i]=b[i-1]+a[i];
        }
        for(int i=n-1; i>=1; i--)
        {
            for(int j=i+1; j<=n; j++)
            {
                mi[i][j]=0x3f3f3f3f;
                ma[i][j]=0;
                for(int k=i; k<=j-1; k++)
                {
                    mi[i][j]=min(mi[i][j],mi[i][k]+mi[k+1][j]+b[j]-b[i-1]);
                    ma[i][j]=max(ma[i][j],ma[i][k]+ma[k+1][j]+b[j]-b[i-1]);
                }
            }
        }
        printf("%d %d\n",mi[1][n],ma[1][n]);
    }
}
https://vjudge.net/contest/437602#problem[dp[i][j]=max(dp[i][k])
