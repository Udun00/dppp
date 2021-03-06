/*
 数字三角形
 题意：给你一个数字三角形，每层遍历一个，问从上到下路径之和的最大值
 思路：定义一个二维数组dp[i][j]，代表着遍历到第i层第j个时的路径之和最大值，转态转移方程：dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]);
 */
//代码实现
#include<stdio.h>
int a[1005][1005]={0};
int f[1004][1004]={0};
int max(int a,int b)
{
    if(a>b)return a;
    else return b;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            scanf("%d",&a[i][j]);
            f[i][j]=a[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            f[i][j]+=max(f[i-1][j],f[i-1][j-1]);
            ans=max(ans,f[i][j]);
        }
    }
    printf("%d",ans);
    return 0;
}
