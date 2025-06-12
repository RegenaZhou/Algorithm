/*
��С������֮��(Easy Version)

��Ŀ����
����F(i)��ʾ����i����С�����ӡ��ָ���һ��������N�����������(2->n)F(i)��

��������
��1��Ϊһ������T����ʾ��������������

��������T��ÿ�а���һ��������N��

1��T��10^6��2��N��3��10^6��

�������
�����T�У�ÿ�а���һ����������ʾ�𰸡�

�����������
ʾ�� 1
����
3
5
10
15

���
12
28
59*/
#include<iostream>
#include<vector>
using namespace std;
const int N = 3e6 + 9;
long long f[N];

vector<int> prime;
bool is_prime[N];

void Era(int n)
{
    for (int i = 1; i <= n; i++) is_prime[i] = true;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            prime.push_back(i);
            if (1ll * i * i > n) continue;
            for (int j = i * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
}

int get_minf(int x)
{
    if (is_prime[x]) return x;
    for (int i : prime)
    {
        if (x % i == 0) return i;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    Era(N - 1);
    for (int i = 2; i < N; i++)
    {
        f[i] = get_minf(i);
        f[i] += f[i - 1];
    }
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        cout << f[x] << '\n';
    }
    return 0;
}