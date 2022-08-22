#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m, L, R, cl, cr, cnt, tot, a[N], fa[N], rk[N], sz[N], dep[N], dfn[N], son[N], top[N], head[N];
char op[2];

struct xcj{
	int to, nxt;
} e[N << 1];

struct xcx{
	int l, r, tag, l_col, r_col, all_col;
	#define lp p << 1
	#define rp p << 1 | 1
	#define l(p) t[p].l
	#define r(p) t[p].r
	#define tag(p) t[p].tag
	#define lc(p) t[p].l_col
	#define rc(p) t[p].r_col
	#define ac(p) t[p].all_col
} t[N << 2];

inline int read(){
	int s = 0, w = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; w *= ch == '-' ? -1 : 1, ch = getchar());
	for (; ch >= '0' && ch <= '9'; s = s * 10 + ch - '0', ch = getchar());
	return s * w;
}

void add(int u, int v){e[++cnt] = {v, head[u]}, head[u] = cnt;}

void index(int p){
	ac(p) = ac(lp) + ac(rp), lc(p) = lc(lp), rc(p) = rc(rp);
	if (rc(lp) == lc(rp)) --ac(p);
}

void build(int p, int l, int r){
	l(p) = l, r(p) = r;
	if (l == r){
		lc(p) = rc(p) = a[rk[l]], ac(p) = 1;
		return ;
	}
	int mid = (l + r) >> 1;
	build(lp, l, mid), build(rp, mid + 1, r), index(p);
}

void spread(int p){
	if (!tag(p)) return ;
	lc(lp) = lc(rp) = rc(lp) = rc(rp) = tag(lp) = tag(rp) = tag(p), ac(lp) = ac(rp) = 1, tag(p) = 0;
}

void change(int p, int l, int r, int col){
	if (l <= l(p) && r(p) <= r){
		lc(p) = rc(p) = tag(p) = col, ac(p) = 1;
		return ;
	}
	spread(p);
	int mid = (l(p) + r(p)) >> 1;
	if (l <= mid) change(lp, l, r, col);
	if (r > mid) change(rp, l, r, col);
	index(p);
}

int ask(int p, int l, int r){
	if (l(p) == L) cl = lc(p);
	if (r(p) == R) cr = rc(p);
	if (l == l(p) && r(p) == r) return ac(p);
	spread(p);
	int mid = (l(p) + r(p)) >> 1, res = 0, col1 = -1, col2 = 0;
	if (r <= mid) res = ask(lp, l, r);
	else if (l > mid) res = ask(rp, l, r);
	else {
		res = ask(lp, l, mid) + ask(rp, mid + 1, r);
		if (rc(lp) == lc(rp)) --res;
	}
	return res;
}

void dfs1(int x){
	sz[x] = 1, son[x] = -1;
	for (int i = head[x]; i; i = e[i].nxt){
		int y = e[i].to;
		if (dep[y]) continue;
		dep[y] = dep[x] + 1, fa[y] = x, dfs1(y), sz[x] += sz[y];
		if (!~son[x] || sz[y] > sz[son[x]]) son[x] = y;
	}
}

void dfs2(int x, int top_x){
	top[x] = top_x, rk[dfn[x] = ++tot] = x;
	if (!~son[x]) return ;
	dfs2(son[x], top_x);
	for (int i = head[x]; i; i = e[i].nxt){
		int y = e[i].to;
		if (y != fa[x] && y != son[x]) dfs2(y, y);
	}
}

void change1(int x, int y, int z){
	while (top[x] != top[y]){
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		change(1, dfn[top[x]], dfn[x], z), x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	change(1, dfn[x], dfn[y], z);
}

int ask1(int x, int y, int res = 0, int col1 = -1, int col2 = -1){
	while (top[x] != top[y]){
		if (dep[top[x]] < dep[top[y]]) swap(x, y), swap(col1, col2);
		L = dfn[top[x]], R = dfn[x], res += ask(1, dfn[top[x]], dfn[x]), x = fa[top[x]];
		if (cr == col1) --res;
		col1 = cl;
	}
	if (dep[x] > dep[y]) swap(x, y), swap(col1, col2);
	L = dfn[x], R = dfn[y], res += ask(1, dfn[x], dfn[y]);
	if (cl == col1) --res;
	if (cr == col2) --res;
	return res;
}

signed main(){
	n = read(), m = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	for (int i = 1, u, v; i < n; ++i) u = read(), v = read(), add(u, v), add(v, u);
	dep[1] = 1, dfs1(1), dfs2(1, 1), build(1, 1, n);
	for (int x, y, z; m--; ){
		scanf("%s", op), x = read(), y = read();
		if (op[0] == 'C') z = read(), change1(x, y, z);
		else printf("%d\n", ask1(x, y));
	}
	return 0;
}
