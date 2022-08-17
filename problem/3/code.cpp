#include <bits/stdc++.h>
using namespace std;

const int N = 20, M = 1040;

int n, m, f[M], a[M][N];

inline int read(){
	int s = 0, w = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; w *= ch == '-' ? -1 : 1, ch = getchar());
	for (; ch >= '0' && ch <= '9'; s = s * 10 + ch - '0', ch = getchar());
	return s * w;
}

signed main(){
	memset(f, 0x3f, sizeof(f));
	n = read(), m = read(), f[(1 << n) - 1] = 0;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j) a[i][j] = read();
	for (int i = (1 << n) - 1; ~i; --i)
		for (int j = 1, kk; j <= m; ++j){
			kk = i;//记得初始化 
			for (int k = 1; k <= n; ++k)
				if ((a[j][k] > 0 && (i & (1 << (k - 1)))) || (a[j][k] < 0 && !(i & (1 << (k - 1))))) kk ^= (1 << (k - 1));
			f[kk] = min(f[kk], f[i] + 1);
		}
	printf("%d\n", f[0] > 1e9 ? -1 : f[0]);
	return 0;
}
