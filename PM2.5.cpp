#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int pm;
	int sum = 0;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0, cnt5 = 0, cnt6 = 0;

	for (int i = 0; i < n; i++) {

		scanf("%d", &pm);
		sum += pm;

		if (pm <= 50)
			cnt1++;
		else if (pm <= 100)
			cnt2++;
		else if (pm <= 150)
			cnt3++;
		else if (pm <= 200)
			cnt4++;
		else if (pm <= 300)
			cnt5++;
		else
			cnt6++;
	}

	// 输出平均值，保留两位小数
	printf("%.2f\n", sum * 1.0 / n);

	// 输出各等级天数
	printf("%d %d %d %d %d %d\n", cnt1, cnt2, cnt3, cnt4, cnt5, cnt6);

	return 0;
}
