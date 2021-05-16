/*
题目：https://vjudge.net/contest/437602#problem/C
思路：简单dp,定义dp[i]为前i个字符的最长相同字符子串
状态转移方程
 if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1]+1;
  else    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
*/
//代码实现
#include<stdio.h>
#include<string.h>
int dp[1100][1100]= {0};
int max(int x,int y)
{
    return x>y?x:y;
}
int main()
{
    char s1[1100],s2[1100];
    while(scanf("%s",s1)!=EOF)
    {
        scanf("%s",s2);
        int len1=strlen(s1),len2=strlen(s2);
        for(int i=0;i<=len1;i++)
        {
            for(int j=0;j<=len2;j++)
            {
                dp[i][j]=0;
            }
        }
        for(int i=1; i<=len1; i++)
        {
            for(int j=1; j<=len2; j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        printf("%d\n",dp[len1][len2]);
    }
}
