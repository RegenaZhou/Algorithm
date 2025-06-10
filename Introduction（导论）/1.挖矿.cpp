/*问题描述
小蓝正在数轴上挖矿，数轴上一共有n个矿洞，第i个矿洞的坐标为ai。
小蓝从0出发，每次可以向左或向右移动1的距离，
当路过一个矿洞时，就会进行挖矿作业，获得1单位矿石，
但一个矿洞不能被多次挖掘。小蓝想知道在移动距离不超过m的前提下，
最多能获得多少单位矿石?

输入格式
输入的第一行包含两个正整数n,m，用一个空格分隔。
第二行包含n个整数a1,a2,⋯,an，相邻整数之间使用一个空格分隔。

输出格式
输出一行包含一个整数表示答案。*/
#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int sum[N * 2];
int bs(int l, int r)
{
    return sum[N + r] - sum[N + l - 1];
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, num;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        sum[num+N] = 1;
    }
    for (int i = 1; i < N * 2; i++)
    {
        sum[i] += sum[i - 1];
    }
    int ans = 0;
    ans = max(bs(-m, 0), bs(0, m));
    for (int i = 1; i <= m; i++)
    {
        int r = i;
        int l = i - (m - i);
        l = min(0, l);
        ans = max(ans, bs(l, r));
    }
    for (int i = 1; i <= m; i++)
    {
        int l = i * (-1);
        int r = m - 2 * i;
        r = max(0, r);
        ans = max(ans, bs(l, r));
    }
    cout << ans << '\n';
    return 0;
}