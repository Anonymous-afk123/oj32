#include <stdio.h>
#include <string.h>

typedef struct {
	int width;
	int height;
	int data[10][10];
} IMAGE;

int main(void) {
	IMAGE image;
	int rot;

	// 读取宽高
	scanf("%d %d", &image.width, &image.height);

	// 读取图像数据
	for (int i = 0; i < image.height; i++) {

		for (int j = 0; j < image.width; j++) {

			scanf("%d", &image.data[i][j]);
		}
	}

	// 读取旋转角度
	scanf("%d", &rot);

	// 根据旋转角度处理
	if (rot == 0) {
		// 0度：不旋转
		printf("%d %d\n", image.width, image.height);

		for (int i = 0; i < image.height; i++) {

			for (int j = 0; j < image.width; j++) {

				printf("%d", image.data[i][j]);

				if (j < image.width - 1)
					printf(" ");
			}

			printf("\n");
		}
	} else if (rot == 90) {
		// 顺时针90度：宽度和高度交换
		printf("%d %d\n", image.height, image.width);

		for (int j = 0; j < image.width; j++) {

			for (int i = image.height - 1; i >= 0; i--) {

				printf("%d", image.data[i][j]);

				if (i > 0)
					printf(" ");
			}

			printf("\n");
		}
	} else if (rot == 180) {
		// 顺时针180度：宽度和高度不变，全部反转
		printf("%d %d\n", image.width, image.height);

		for (int i = image.height - 1; i >= 0; i--) {

			for (int j = image.width - 1; j >= 0; j--) {

				printf("%d", image.data[i][j]);

				if (j > 0)
					printf(" ");
			}

			printf("\n");
		}
	} else if (rot == 270) {
		// 顺时针270度：宽度和高度交换
		printf("%d %d\n", image.height, image.width);

		for (int j = image.width - 1; j >= 0; j--) {

			for (int i = 0; i < image.height; i++) {

				printf("%d", image.data[i][j]);

				if (i < image.height - 1)
					printf(" ");
			}

			printf("\n");
		}
	}

	return 0;
}