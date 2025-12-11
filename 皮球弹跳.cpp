#include <stdio.h>

int main() {
	long h, n;

	// 读取输入
	if (scanf("%ld %ld", &h, &n) != 2) {
		printf("输入格式错误\n");
		return 1;
	}

	// 输入验证
	if (h < 0 || n < 0) {
		printf("输入必须是非负整数\n");
		return 1;
	}

	// 处理特殊情况
	if (n == 0) {
		printf("0.0 %.1f\n", (double)h);
		return 0;
	}

	// 初始化
	double total_distance = (double)h;  // 第一次下落的距离
	double current_height = (double)h;  // 当前高度

	// 处理 n >= 1 的情况
	for (long i = 1; i < n; i++) {

		current_height /= 2.0;              // 反弹到一半高度
		total_distance += 2 * current_height; // 上升 + 下落
	}

	// 输出结果
	printf("%.1f %.1f\n", total_distance, current_height / 2.0);
	return 0;
}