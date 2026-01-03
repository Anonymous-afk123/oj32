#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int seats[20][5] = {0};

	while (n--) {
		int p;
		scanf("%d", &p); // 这一单买几张票

		int success = 0; // 标记：这一单是不是已经连续买好了

		// --- 尝试规则 A：找一排连续的 ---
		for (int i = 0; i < 20; i++) {

			int empty = 0;

			for (int j = 0; j < 5; j++) {

				if (seats[i][j] == 0)
					empty++;
			}

			if (empty >= p) {
				int count = 0;

				for (int j = 0; j < 5; j++) {

					if (seats[i][j] == 0 && count < p) {
						seats[i][j] = 1;
						printf("%d", i * 5 + j + 1);
						count++;

						if (count < p)
							printf(" ");
						else
							printf("\n");
					}
				}

				success = 1;
				break;
			}
		}

		if (!success) {
			int count = 0;

			for (int i = 0; i < 20; i++) {

				for (int j = 0; j < 5; j++) {

					if (seats[i][j] == 0 && count < p) {
						seats[i][j] = 1;
						printf("%d", i * 5 + j + 1);
						count++;

						if (count < p)
							printf(" ");
						else
							printf("\n");
					}
				}
			}
		}
	}

	return 0;
}