#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10;

int n, ans, cnt, root, a[N], b[N], head[N], f[N][2];
bool v[N];

struct xcj{
	int to, nxt;
} e[N];

inline int read(){
	int s = 0, w = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; w *= ch == '-' ? -1 : 1, ch = getchar());
	for (; ch >= '0' && ch <= '9'; s = s * 10 + ch - '0', ch = getchar());
	return s * w;
}

void add(int u, int v){
	e[++cnt] = {v, head[u]};
	head[u] = cnt;
}

void find_loop(int x){
	v[x] = 1;
	if (v[b[x]]) root = x;
	else find_loop(b[x]);
}

void dp(int x){
	v[x] = 1;
	f[x][0] = 0;
	f[x][1] = a[x];
	for (int i = head[x]; i; i = e[i].nxt){
		int y = e[i].to;
		if (y == root) f[y][1] = -2e9;
		else {
			dp(y);
			f[x][1] += f[y][0];
			f[x][0] += max(f[y][0], f[y][1]);
		}
	}
}

signed main(){
	n = read();
	for (int i = 1; i <= n; ++i){
		a[i] = read();
		b[i] = read();
		add(b[i], i);
	}
	for (int i = 1, val; i <= n; ++i)
		if (!v[i]){
			find_loop(i);
			dp(root);
			val = max(f[root][0], f[root][1]);
			root = b[root];
			dp(root);
			ans += max(val, max(f[root][0], f[root][1]));
		}
	printf("%lld\n", ans);
	return 0;
}
