/*
题目：https://www.luogu.com.cn/problem/P4017
思路：使用记忆化深搜，从最高消费者开始往下搜，直到生产者，定义dp[i]为到第i类物种的最大食物链数
注意；如果该点dp值不为0，代表已经搜过，直接加上，要记录每一个消费着的食物是什么
*/
//代码实现
#include<stdio.h>
int eat[5010][5010]={0};//记录每一个消费着的食物是什么
int sum[5010]={0};//每一个消费者有多少种食物
int h[5010]={0};//判断是否为最高消费者，是：0,，否：1
int dp[5010]={0};//第i类物种的最大食物链数
const int mod=80112002;
int dfs(int x)
{
    if(sum[x]==0)//搜到生产者返回1
    {
        dp[x]=1;
        return 1;
    }
    int r=0;
    for(int i=0;i<sum[x];i++)
    {
        int j=eat[x][i];
        if(dp[j]!=0)
        {
            r+=dp[j];//已经搜过直接使用
        }
        else
        {
            r+=dfs(j);//没搜过继续搜
        }
        r%=mod;
    }
    dp[x]=r;
    return r;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        eat[b][sum[b]++]=a;
        h[a]=1;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(h[i]==0)
        {
            ans+=dfs(i);
            ans%=mod;
        }
    }
    printf("%d",ans);
}
