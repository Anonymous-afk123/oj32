#include <stdio.h>

typedef struct {
	int id;   // 存储学生编号
	int time; // 总时间（分钟）
} Student;

int main() {
	int n;

	if (scanf("%d", &n) != 1)
		return 0;

	Student records[n];

	// 初始化数组
	for (int i = 0; i < n; i++) {

		records[i].id = 0;
		records[i].time = 0;
	}

	int count = 0; // 记录实际有多少个不同的学生

	for (int i = 0; i < n; i++) {

		int num, h1, m1, h2, m2;
		scanf("%d %d:%d %d:%d", &num, &h1, &m1, &h2, &m2);

		int duration = (h2 - h1) * 60 + (m2 - m1);

		// 查找该学生是否已经在记录中
		int found = -1;

		for (int j = 0; j < count; j++) {

			if (records[j].id == num) {
				found = j;
				break;
			}
		}

		if (found != -1) {
			records[found].time += duration;
		} else {
			records[count].id = num;
			records[count].time = duration;
			count++;
		}
	}

	// 冒泡排序：按时间降序，时间相同按ID升序
	for (int i = 0; i < count - 1; i++) {

		for (int j = 0; j < count - 1 - i; j++) {

			int needSwap = 0;

			if (records[j].time < records[j + 1].time) {
				needSwap = 1;
			} else if (records[j].time == records[j + 1].time && records[j].id > records[j + 1].id) {
				needSwap = 1;
			}

			if (needSwap) {
				Student temp = records[j];
				records[j] = records[j + 1];
				records[j + 1] = temp;
			}
		}
	}

	// 输出
	for (int i = 0; i < count; i++) {

		printf("%d %d\n", records[i].id, records[i].time);
	}

	return 0;
}