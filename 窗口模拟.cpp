#include <stdio.h>

typedef struct {
	int x1;
	int y1;
	int x2;
	int y2;
	int id;
} Coord;

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	Coord loc[N];

	for (int i = 0; i < N; i++) {

		scanf("%d %d %d %d", &loc[i].x1, &loc[i].y1, &loc[i].x2, &loc[i].y2);
		loc[i].id = i + 1;
	}

	int x, y;

	for (int i = 0; i < M; i++) {

		scanf("%d %d", &x, &y);
		int found = 0;

		for (int j = N - 1; j >= 0; j--) {


			if (x >= loc[j].x1 && x <= loc[j].x2 && y >= loc[j].y1 && y <= loc[j].y2) {
				Coord temp = loc[j];

				for (int k = j; k < N - 1; k++) {

					loc[k] = loc[k + 1];
				}

				loc[N - 1] = temp;
				printf("%d\n", temp.id);
				found = 1;
				break;
			}

		}

		if (!found)
			printf("IGNORED\n");
	}

	return 0;
}