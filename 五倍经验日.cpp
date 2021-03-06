/*
 五倍经验日
 题目：https://www.luogu.com.cn/problem/P1802
 思路：01背包的变形版，只是输了也有价值，且每个人都会挑战，dp[i]代表有i瓶药的最大价值，要用long long!!!
*/
#include<stdio.h>
long long int w[1100],l[1100],dp[1100],u[1100];
long long int max(long long int a,long long int b)
{
    return a>b?a:b;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld%lld",&l[i],&w[i],&u[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=u[i];j--)
        {
            dp[j]=max(dp[j]+l[i],dp[j-u[i]]+w[i]);//判断输掉好还是赢了好
        }
        for(int j=u[i]-1;j>=0;j--)
        {
            dp[j]+=l[i];//小于use[i]的情况肯定打不过,直接加上输掉的经验
        }
    }
    printf("%lld",5*dp[m]);
}
