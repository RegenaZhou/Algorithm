/*
问题描述
求2^(3^(4^(...^2023))的值对2023 取模的结果。

注: 上式都是指数，可写为2∗∗(3∗∗(4∗∗(...2023...)) 其中∗∗ 表示指数。

答案提交
这是一道结果填空的题，你只需要算出结果后提交即可。
本题的结果为一个整数，
在提交答案时只填写这个整数，填写多余的内容将无法得分。*/
#include <bits/stdc++.h>
using namespace std;

int get_phi(int x)//取得欧拉函数，朴素枚举法
{
    int cnt = 0;
    for (int i = 1; i <= x; i++)
    {
        if (__gcd(i, x) == 1) cnt++;
    }
    return cnt;
}

int g(int x, int p)//(x^(x+1)^(x+2)^...)%p
{
    if (x == 2023)
    {
        if (x > p) return x % p + p;
        else return x;
    }
    int b = g(x + 1, get_phi(p));
    int res = 1;
    int add = 0;
    for (int i = 1; i <= b; i++)
    {
        res = res * x;
        if (res > p) add = p;
        res %= p;
    }
    return res + add;
}
int main()
{
    cout << g(2, 2023) % 2023 << endl;
    return 0;
}