/*
题目：https://vjudge.net/contest/437602#problem/A
思路：这是一道树形dp模板题，，由题意选了上司就不能璇下属，定义dp[i][0]代表不选i的最大值，dp[i][1]代表选i的最大值
转态转移方程：dp[i][0]+=max(dp[d[j]].me][0],dp[d[j].me][1]);//不选上司，选下属和不选下属选大的，dp[i][1]+=dp[d[j].me][0];//选上司不选下属
*/
//代码实现
#include<stdio.h>
#include<string.h>
int dp[6005][2]={0},nextsubordinate[6005]={0},book[6005]= {0},a[6005];//邻接表
struct k
{
    int me,pre,next;//me=下属,pre=上司,next=上司的下一个下属
} d[100005];
int max(int a,int b)
{
    return a>b?a:b;
}
void dfs(int i)
{
    dp[i][1]=a[i];
    for(int j=nextsubordinate[i]; j; j=d[j].next)//遍历每一个下属
    {
        dfs(d[j].me);
        dp[i][1]+=dp[d[j].me][0];
        dp[i][0]+=max(dp[d[j].me][1],dp[d[j].me][0]);
    }
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
    memset(dp,0,sizeof(dp));
    memset(nextsubordinate,0,sizeof(nextsubordinate));
    memset(book,0,sizeof(book));
    for(int i=1; i<=n; i++)scanf("%d",&a[i]);
    int x,y;
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",&x,&y);
        if(x==0&&y==0)break;
        d[i].pre=y;
        d[i].me=x;
        d[i].next=nextsubordinate[y];
        nextsubordinate[y]=i;
        book[x]=1;
    }
    for(int i=1; i<=n; i++)
    {
        if(book[i]==0)
        {
            dfs(i);
            printf("%d\n",max(dp[i][0],dp[i][1]));
            break;
        }
    }
    }
}
