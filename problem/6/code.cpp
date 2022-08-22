#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5010;

int n, ans = 2e18, cnt, d[N], f[N], U[N], V[N], W[N], sz[N], fa[N], mn[N], head[N];

struct xcj{
	int to, nxt, value;
} e[N << 1];

inline int read(){
	int s = 0, w = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; w *= ch == '-' ? -1 : 1, ch = getchar());
	for (; ch >= '0' && ch <= '9'; s = s * 10 + ch - '0', ch = getchar());
	return s * w;
}

void add(int u, int v, int w){e[++cnt] = {v, head[u], w}, head[u] = cnt;}

void dfs(int x){
	sz[x] = 1, d[x] = 0;
	for (int i = head[x]; i; i = e[i].nxt){
		int y = e[i].to, z = e[i].value;
		if (y == fa[x]) continue;
		fa[y] = x, dfs(y), sz[x] += sz[y], d[x] += d[y] + sz[y] * z;
	}
}

void dp(int x, int root){
	mn[x] = f[x];
	for (int i = head[x]; i; i = e[i].nxt){
		int y = e[i].to, z = e[i].value;
		if (y == fa[x]) continue;
		f[y] = f[x] + (sz[root] - 2 * sz[y]) * z, dp(y, root), mn[x] = min(mn[x], mn[y]);
	}
}

signed main(){
	n = read();
	for (int i = 1; i < n; ++i) U[i] = read(), V[i] = read(), W[i] = read(), add(U[i], V[i], W[i]), add(V[i], U[i], W[i]);
	for (int i = 1, u, v, w, res; i < n; ++i){
		memset(mn, 0x3f, sizeof(mn));
		u = U[i], v = V[i], w = W[i], fa[u] = v, fa[v] = u, dfs(u), f[u] = d[u], dp(u, u), dfs(v), f[v] = d[v], dp(v, v), res = 0;
		for (int j = 1; j <= n; ++j) res += f[j];
		ans = min(ans, res / 2 + sz[u] * sz[v] * w + mn[u] * sz[v] + mn[v] * sz[u]);
	}
	printf("%lld\n", ans);
	return 0;
}
