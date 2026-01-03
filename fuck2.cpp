#include <stdio.h>

#define MAXN 200005

// 定义全局数组，防止栈溢出
long long a[MAXN];
long long s1[MAXN]; // 普通前缀和
long long s2[MAXN]; // 带权前缀和 (i * a[i])

int main() {
	int n, q;

	if (scanf("%d %d", &n, &q) != 2)
		return 0;

	s1[0] = 0;
	s2[0] = 0;

	for (int i = 1; i <= n; i++) {

		scanf("%lld", &a[i]);
		// 预处理前缀和
		s1[i] = s1[i - 1] + a[i];
		s2[i] = s2[i - 1] + (long long)i * a[i];
	}

	while (q--) {
		int l, r;
		scanf("%d %d", &l, &r);

		// 使用推导出的公式计算结果
		// Result = sum(i*a[i]) - (l-1)*sum(a[i])
		long long part2 = s2[r] - s2[l - 1];
		long long part1 = (long long)(l - 1) * (s1[r] - s1[l - 1]);

		printf("%lld\n", part2 - part1);
	}

	return 0;
}