/*
题目：https://www.luogu.com.cn/problem/P2196
思路：以每个地窖为起点用dfs一直搜到不能往下搜为止，每搜完一次更新最大值和路径;
注意：题目给的链接是单向的
*/
//代码实现
#include<stdio.h>
int map[100][100] = { 0 };
int book[100] = { 0 };
int p[100], c[100];
int ans = 0;
int sum[100];
int max = 0;
int n;
void dfs(int x, int s, int step,int d)
{
    int flag = 0;
    for (int i = x + 1; i <= d; i++)
    {
        if (map[x][i] == 1 && book[i] == 0)//判断是否不能在搜了
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)//搜完更新最大值和路径
    {
        if (max < s)
        {
            max = s;
            ans = step;
            for (int i = 1; i <= step; i++)
            {
                c[i] = p[i];
            }
        }
        return;
    }
    else
    {
        for (int i = x + 1; i <= d; i++)
        {
            if (map[x][i] == 1 && book[i] == 0)
            {
                book[i] = 1;//标记走过
                p[step + 1] = i;//记录路径
                dfs(i, s + sum[i], step + 1,d);
                book[i] = 0;//回溯
            }
        }

    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)scanf("%d", &sum[i]);
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        book[i] = 1;
        p[1] = i;
        dfs(i, sum[i], 1,n);
        book[i] = 0;
    }
    for (int i = 1; i <= ans; i++)printf("%d ", c[i]);
    printf("\n%d", max);
}
