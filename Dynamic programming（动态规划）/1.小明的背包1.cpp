/*
小明的背包1
题目描述
小明有一个容量为V的背包。
这天他去商场购物，商场一共有N件物品，第i件物品的体积为wi，价值为vi​。
小明想知道在购买的物品总体积不超过V的情况下所能获得的最大价值为多少，请你帮他算算。

输入描述
输入第1行包含两个正整数N,V，表示商场物品的数量和小明的背包容量。
第2∼N+1 行包含2 个正整数w,v，表示物品的体积和价值。

1≤N≤10^2，1≤V≤10^3，1≤wi,vi​≤10^3。

输出描述
输出一行整数表示小明所能获得的最大价值。*/
#include <iostream>
using namespace std;
using ll = long long;
const int N = 105, M = 1010;
ll dp[M];

int main()
{
    int n, V;
    cin >> n >> V;
    for (int i = 1; i <= n; i++)
    {
        ll w, v;
        cin >> w >> v;
        for (int j = V; j >= w; j--)
        {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    cout << dp[V] << '\n';
    return 0;
}