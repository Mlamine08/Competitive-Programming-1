#include <bits/stdc++.h>
#define MAX 16
#define EPS 1e-9
using namespace std;
typedef long double ld;

const ld PI = acos(-1.0);

int n;
ld a[MAX];

ld coefficient[MAX * 2];
ld x_low, x_high, inc;

inline void read(){
	for (int i = 0; i <= n; ++i)
		scanf("%llf", a + i);
	scanf("%llf%llf%llf", &x_low, &x_high, &inc);
}

inline void preprocess() {
	for (int i = 0; i <= 2 * n; ++i) {
			coefficient[i] = 0.0;
	}

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			coefficient[i + j] += a[i] * a[j];
		}
	}

	for (int i = 0; i <= 2 * n; ++i) {
		coefficient[i] /= ld(i + 1);
	}
}

inline ld raise(ld x, int p) {
	return pow(x, p);
}

inline ld F(const ld & x) {
	// PI * f(x) * f(x)
	ld ans = 0.0;
	for (int i = 0; i <= 2 * n; ++i) {
		ans += coefficient[i] * raise(x, i + 1);
	}
	return PI * ans;
}

inline ld volume(const ld & lo, const ld & hi) {
	return F(hi) - F(lo);
}

inline ld bisection(ld lo, ld hi, const ld target_volume) {
	while (hi - lo > EPS) {
		ld mid = (lo + hi) * 0.5;
		if (volume(x_low, mid) >= target_volume) {
			hi = mid;
		}
		else {
			lo = mid;
		}
	}

	return (lo + hi) * 0.5;
}

int main() {
	for (int tc = 1; ~scanf("%d", &n); ++tc) {
		read();
		preprocess();
		printf("Case %d: %.2llf\n", tc, volume(x_low, x_high));
		ld ans = x_low;
		for (int i = 0; i < 8; ++i) {
			ans = bisection(ans, x_high + EPS, inc * (i + 1));
			if (ans > x_high) {
				if (!i) printf("insufficient volume");
				break;
			}
			if (i) printf(" ");
			printf("%.2llf", ans - x_low);
		}
		printf("\n");
	}
	return 0;
}

