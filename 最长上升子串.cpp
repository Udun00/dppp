/*
题目：https://vjudge.net/contest/437602#problem/I
思路：利用二分查找和贪心优化dp，防止TL
*/
//代码实现
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e5+6;
int a[maxn],b[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    b[1]=a[1];
    int sum=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]>b[sum])
        {
            b[++sum]=a[i];//如果是上升的就加在后面
        }
        else
        {
            int k=lower_bound(b+1,b+sum+1,a[i])-b;//否则在b中找到第一个大于a[i]的数，用a[i]替换这个数，贪心：数越小，上升的可能就越大
            b[k]=a[i];
        }
    }
    printf("%d",sum);
}
