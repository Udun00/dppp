/*
题意：
辰辰是个天资聪颖的孩子，他的梦想是成为世界上最伟大的医师。
为此，他想拜附近最有威望的医师为师。医师为了判断他的资质，给他出了一个难题。
医师把他带到一个到处都是草药的山洞里对他说：“孩子，这个山洞里有一些不同的草药，采每一株都需要一些时间，每一株也有它自身的价值。我会给你一段时间，在这段时间里，你可以采到一些草药。
如果你是一个聪明的孩子，你应该可以让采到的草药的总价值最大。”
如果你是辰辰，你能完成这个任务吗？
输入格式
第一行有 22 个整数 TT（1 \le T \le 10001≤T≤1000）和 MM（1 \le M \le 1001≤M≤100），用一个空格隔开，TT 代表总共能够用来采药的时间，MM 代表山洞里的草药的数目。
接下来的 MM 行每行包括两个在 11 到 100100 之间（包括 11 和 100100）的整数，分别表示采摘某株草药的时间和这株草药的价值。
输出格式
输出在规定的时间内可以采到的草药的最大总价值。
输入输出样例
输入 #
70 3
71 100
69 1
1 2
输出 
3
说明/提示
【数据范围】
对于 30\%30% 的数据，M \le 10M≤10；
对于全部的数据，M \le 100M≤100。
思路：01背包模板题,状态转移方程dp[j]=max(dp[j],dp[j-w[i]]+v[i])
*/
**代码实现**
```
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
    return 0;
}
```
