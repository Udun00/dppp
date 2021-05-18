/*
题目：https://vjudge.net/contest/438788#problem/E
思路：枚举摸每一张牌判断是否能胡牌，三种胡牌都要判断
注意：要判断一种牌是否超过四张
*/
//代码实现
#include<stdio.h>
#include<string.h>
int ans[1000];
int sum[50];//1-9代表m,10-18代表s,19-27代表p,28-34代表c
int Hupai1()//4x3
{
    for (int i = 1; i <= 34; i++)
    {
        int r = 0;
        if (sum[i] >= 2)
        {
            sum[i] -= 2;
            int tt[50];
            for (int j = 1; j <= 34; j++)tt[j] = sum[j];
            for (int j = 0; j <= 18; j+=9)
            {
                for (int k = 1; k <= 9; k++)
                {
                    if (tt[j  + k] >= 3)
                    {
                        tt[j  + k] -= 3;
                        r++;
                    }
                    while (k + 2 <= 9 && tt[j + k] && tt[ j + k + 1] && tt[ j + k + 2])
                    {
                        tt[ j+ k]--, tt[ j+ k + 1]--, tt[ j+ k + 2]-- ;
                            r++;
                    }
                }
            }
            for (int j = 28; j <= 34; j++)
            {
                if (tt[j] >= 3)
                {
                    r++;
                }
            }
            if (r == 4)
            {
                sum[i] += 2;
                return 1;
            }
            sum[i] += 2;
        }
    }
    return 0;
}
int Hupai2()
{
    for (int i = 1; i <= 34; i++)
    {
        if (sum[i] != 2 && sum[i] != 0)
            return 0;
    }
    return 1;
}
int Hupai3()
{
    for (int i = 28; i <= 34; i++)
    {
        if (sum[i] == 0)return 0;
    }
    for (int i = 1; i <= 19; i += 9)
    {
        if (sum[i] == 0 || sum[i + 8] == 0)return 0;
        for (int j = 1; j <= 7; j++)
        {
            if (sum[i + j] != 0)return 0;
        }
    }
    return 1;
}
int Hupai()
{
    for (int i = 1; i <= 34; i++)
    {
        if (sum[i] > 4)return 0;
    }
    if (Hupai1() || Hupai2() || Hupai3())return 1;
    else return 0;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(ans, 0, sizeof(ans));
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= 13; i++)
        {
            char x[4];
            scanf("%s", x);
            int t;
            t = x[0] - '0';
            if (x[1] == 's')t += 9;
            else if (x[1] == 'p')t += 18;
            else if (x[1] == 'c')t += 27;
            sum[t]++;
        }
        int anss = 0;
        for (int i = 1; i <= 34; i++)
        {
            sum[i]++;
            if (Hupai())
                ans[++anss] = i;
            sum[i]--;
        }
        if (anss) {
            printf("%d", anss);
            for (int i = 1; i <= anss; i++)
            {
                if (ans[i] % 9 == 0)printf(" %d", 9);
                else printf(" %d", ans[i] % 9);
                if (ans[i] >= 1 && ans[i] <= 9)printf("m");
                else if (ans[i] >= 10 && ans[i] <= 18)printf("s");
                else if (ans[i] >= 19 && ans[i] <= 27)printf("p");
                else printf("c");
            }
        }
        else printf("Nooten");
        printf("\n");
    }
}
