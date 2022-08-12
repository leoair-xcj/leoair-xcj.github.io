#include <bits/stdc++.h>
using namespace std;

const int N = 110, M = 510;

int n, m, cnt, num, scc, top, a[N], b[N], c[N], d[N], aa[N], bb[N], in[N], dfn[N], low[N], sta[N], head[N], f[N][M];
bool ins[N];

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

void add(int u, int v){e[++cnt] = {v, head[u]}, head[u] = cnt;}

void tarjan(int x){
	dfn[x] = low[x] = ++num, sta[++top] = x, ins[x] = 1;
	for (int i = head[x]; i; i = e[i].nxt){
		int y = e[i].to;
		if (!dfn[y]) tarjan(y), low[x] = min(low[x], low[y]);
		else if (ins[y]) low[x] = min(low[x], dfn[y]);
	}
	if (dfn[x] == low[x]){
		++scc;
		int y;
		do {
			y = sta[top--], aa[scc] += a[y], bb[scc] += b[y], ins[y] = 0, c[y] = scc;
		} while (x != y);
	}
}

void dp(int x){
	for (int i = aa[x]; i <= m; ++i) f[x][i] = bb[x];
	for (int i = head[x]; i; i = e[i].nxt){
		int y = e[i].to;
		dp(y);
		for (int j = m; j >= aa[x]; --j)
			for (int k = 0; k <= j - aa[x]; ++k) f[x][j] = max(f[x][j], f[x][j - k] + f[y][k]);
	}
}

signed main(){
	n = read(), m = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	for (int i = 1; i <= n; ++i) b[i] = read();
	for (int i = 1; i <= n; ++i) d[i] = read(), add(d[i], i);
	for (int i = 1; i <= n; ++i)
		if (!dfn[i]) tarjan(i);
	cnt = 0;
	for (int i = 0; i <= n; ++i) head[i] = 0;
	for (int i = 1; i <= n; ++i)
		if (c[i] != c[d[i]]) add(c[d[i]], c[i]), ++in[c[i]];
	for (int i = 1; i <= scc; ++i)
		if (!in[i]) add(0, i);
	dp(0), printf("%d\n", f[0][m]);
	return 0;
}
