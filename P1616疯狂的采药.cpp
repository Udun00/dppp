/*
 疯狂的采药
 题目：https://www.luogu.com.cn/problem/P1616
 思路：完全被背包的模板，只需要将dp的第二循环倒序
*/
//代码实现
#include<stdio.h>
int v[1000],w[1000],dp[1000]={0};
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int t,m;
    scanf("%d%d",&t,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&w[i],&v[i]);
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=t;j>=w[i];j--)
        {
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    printf("%d",dp[t]);
}

