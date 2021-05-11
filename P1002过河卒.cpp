/*
题目：https://www.luogu.com.cn/problem/P1002
思路：由题意棋子只能往下走或往右走且不能走被马看住的点
判断更新：if(i>0)dp[i][j]+=dp[i-1][j];if(j>0)dp[i][j]+=dp[i][j-1];}
*/
//代码实现
#include<stdio.h>
typedef long long int ll;
ll dp[100][100];
int flag[100][100];
int b[2][10]= {{0,1,2,-1,2,1,-2,-1,-2},{0,2,1,2,-1,-2,1,-2,-1}};
int main()
{
    int zx,zy,mx,my;
    scanf("%d%d%d%d",&zx,&zy,&mx,&my);
    for(int i=0; i<9; i++)
    {
        if(mx+b[0][i]<=zx&&mx+b[0][i]>=0&&my+b[1][i]<=zy&&my+b[1][i]>=0)//判断是否超出棋盘边界
        {
            flag[mx+b[0][i]][my+b[1][i]]=1;
        }
    }
    dp[0][0]=1;
    for(int i=0; i<=zx; i++)
    {
        for(int j=0; j<=zy; j++)
        {
            if(flag[i][j])
            {
                continue;
            }
            else
            {
                if(i>0)//更新
                    dp[i][j]+=dp[i-1][j];
                if(j>0)
                    dp[i][j]+=dp[i][j-1];
                }
        }
    }
    printf("%lld",dp[zx][zy]);
}
