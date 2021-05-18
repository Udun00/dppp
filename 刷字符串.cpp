/*
题目：https://vjudge.net/contest/438788#problem/D
思路：定义dp[i][j]为从空字符串到b字符串i~j的最小粉刷次数，f[i]为a字符串0~i-1的最优解
dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
 f[i]=min(f[i],f[k]+dp[k+1][i]);
*/
//代码实现
#include<stdio.h>
#include<string.h>
int dp[110][110];
int f[110];
int min(int a,int b)
{
    return a<b?a:b;
}
int main()
{
    char s1[110],s2[110];
    while(scanf("%s",s1)!=EOF)
    {
        scanf("%s",s2);
        memset(dp,0x3f,sizeof(dp));
        memset(f,0x3f,sizeof(f));
        int len=strlen(s1);
        for(int i=0;i<len;i++)dp[i][i]=1;
        for(int i=2;i<=len;i++)//区间长度
        {
            int l=0,r=l+i-1;
            for(;r<len;r++,l++)
            {
                dp[l][r]=dp[l][r-1]+1;
                for(int k=l;k<r;k++)
                {
                    dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
                }
                if(s2[l]==s2[r])//首尾相同可以少刷一次
                    dp[l][r]--;
            }
        }
        if(s2[0]==s1[0])
        f[0]=0;
        else f[0]=1;
        for(int i=0;i<len;i++)
        {
            f[i]=dp[0][i];
            if(s2[i]==s1[i])
            {
                if(i==0)f[i]=0;//第一个字符相等粉刷次数为0
                f[i]=f[i-1];
            }
            else
            {
                for(int k=0;k<i;k++)
                {
                    f[i]=min(f[i],f[k]+dp[k+1][i]);
                }
            }
        }
        printf("%d\n",f[len-1]);
    }
}
