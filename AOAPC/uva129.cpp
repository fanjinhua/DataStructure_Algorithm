/** /
#include <iostream>
using std::cout;
using std::endl;
int n, L, cnt;
int S[100];

int dfs(int cur)
{
	if (cnt++ == n)
	{
		for (int i = 0; i < cur; ++i)
			cout << static_cast<char>('A' + S[i]);
		cout << endl;
		return 0;
	}
	for (int i = 0; i < L; ++i)
	{
		S[cur] = i;
		int ok = 1;
		for (int j = 1; j * 2 <= cur + 1; j++)
		{
			int equal = 1;
			for (int k = 0; k < j; ++k)
				if (S[cur - k] != S[cur - k - j])
				{
					equal = 0;
					break;
				}
			if (equal)
			{
				ok = 0;
				break;
			}
		}
		if (ok)
			if (!dfs(cur + 1))
				return 0;
	}
	return 1;
}

int main()
{
	//while (std::cin >> n >> L && n > 0)
	{
		n = 7;
		L = 3;
		cnt = 0;
		dfs(0);
	}
	return 0;
}
/**/