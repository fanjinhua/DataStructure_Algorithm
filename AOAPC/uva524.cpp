/** /
#include <iostream>
using namespace std;

int is_prime(int x)
{
	for (int i = 2; i*i <= x; ++i)
		if (x % i == 0)
			return 0;
	return 1;
}

int n, A[50], isp[50], vis[50];
void dfs(int cur)
{
	if (cur == n && isp[A[0] + A[n - 1]])
	{
		for (int i = 0; i < n; ++i)
			cout << A[i] << " ";
		cout << endl;
	}
	for (int i = 2; i <= n; ++i)
	{
		if (!vis[i] && isp[i + A[cur - 1]])
		{
			A[cur] = i;
			vis[i] = 1;
			dfs(cur + 1);
			vis[i] = 0;
		}
	}
}

int main()
{
	int n, kase = 0;
	while (cin >> n)
	{
		cout << "Case " << kase << ":\n";
		for (int i = 2; i <= n * 2; ++i)
			isp[i] = is_prime(i);
		memset(vis, 0, sizeof(vis));
		A[0] = 1;
		dfs(1);
	}
	return 0;
}
/**/