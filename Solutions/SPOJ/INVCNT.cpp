#include<stdio.h>
#include<string.h>
#include<vector>
#define MAX 200005
#define avg(a, b) ((a + b) >> 1)
using namespace std;
typedef long long int ll;
int n;
int a[MAX];
ll ans;
void sort(int l, int r){
	if (l == r) return;
	int m = avg(l, r);
	sort(l, m);
	sort(m + 1, r);
	vector<int>v;
	v.reserve(r - l + 1);
	int i = l, j = m + 1;
	while (i <= m && j <= r){
		if (a[i] <= a[j])v.push_back(a[i++]);
		else ans += (m - i + 1), v.push_back(a[j++]);
	}
	while(i <= m)
		v.push_back(a[i++]);
	while(j <= r)
		v.push_back(a[j++]);
	memcpy(a + l, &v[0], v.size()*sizeof(int));
}
int main(void){
	freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	while(TC--){
		ans = 0LL;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", a + i);
		sort(0, n-1);
		printf("%lld\n", ans);
	}
	return 0;
}

