#include <bits/stdc++.h>
using namespace std;

const int N = 20, M = 1e6 + 10;
const double eps = 1e-8;

int _, n, m, f[M], bit[M], c[N][N];
double a, b, x[N], y[N];

inline int read(){
	int s = 0, w = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; w *= ch == '-' ? -1 : 1, ch = getchar());
	for (; ch >= '0' && ch <= '9'; s = s * 10 + ch - '0', ch = getchar());
	return s * w;
}

int lowbit(int x){return (x & 1) ? 1 : (lowbit(x >> 1) + 1);}

void calc(double x1, double y1, double x2, double y2){a = (x2 * y1 - x1 * y2) / x1 / x2 / (x1 - x2), b = y1 / x1 - a * x1;}

signed main(){
	for (int i = 1; i < (1 << 18); ++i) bit[i] = lowbit(i);
	for (scanf("%d", &_); _--; ){
		memset(c, 0, sizeof(c));
		memset(f, 0x3f, sizeof(f));
		scanf("%d%d", &n, &m), f[0] = 0;
		for (int i = 1; i <= n; ++i) scanf("%lf%lf", &x[i], &y[i]);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j){
				if (fabs(x[i] - x[j]) < eps) continue;
				calc(x[i], y[i], x[j], y[j]);
				if (a > -eps) continue;
				for (int k = 1; k <= n; ++k)
					if (fabs(a * x[k] * x[k] + b * x[k] - y[k]) < eps) c[i][j] |= (1 << (k - 1));
			}
		for (int i = 1; i < (1 << n); ++i){
			f[i] = min(f[i], f[i & (~(1 << (bit[i] - 1)))] + 1);
			for (int j = 1; j <= n; ++j) f[i] = min(f[i], f[i & (~c[bit[i]][j])] + 1);
		}
		printf("%d\n", f[(1 << n) - 1]);
	}
	return 0;
}
