#include <stdio.h>
#include <string.h>

struct medalCountry {
	int iPlace;
	char sName[3];
	int iMedalNum[3];
};

enum medalType { GOLDMEDAL, SILVERMEDAL, BRONZEMEDAL};
void AdjustSortTable(int aSortTable[], struct medalCountry aMedalCountry[], int iCounter, int iNo, int iMedalType);

int main(void) {
	int n, i, j, counter = 0;//当前奖牌榜上总共有的代表队数目
	struct medalCountry aMedalCountry[206] = {0};//当前奖牌数目刚刚发生变化的代表队
	struct medalCountry *pSMC;
	int aSortTable[206];
	char sNameTmp[3];
	scanf("%d", &n);

	for (i = 0; i < n; i++) {

		//Gold Medal
		scanf("%s", sNameTmp);

		for (j = 0; j < counter; j++) {

			if (!strcmp(aMedalCountry[j].sName, sNameTmp))
				//若果
			{
				aMedalCountry[j].iMedalNum[GOLDMEDAL]++;
				AdjustSortTable(aSortTable, aMedalCountry, counter, j, GOLDMEDAL);
				break;
			}
		}

		if (j == counter) {
			strcpy(aMedalCountry[j].sName, sNameTmp);
			aMedalCountry[j].iMedalNum[GOLDMEDAL]++;
			aSortTable[j] = j;
			counter++;
			AdjustSortTable(aSortTable, aMedalCountry, counter, j, GOLDMEDAL);
		}

		//Silver Medal
		scanf("%s", sNameTmp);

		for (j = 0; j < counter; j++) {

			if (!strcmp(aMedalCountry[j].sName, sNameTmp)) {
				aMedalCountry[j].iMedalNum[SILVERMEDAL]++;
				AdjustSortTable(aSortTable, aMedalCountry, counter, j, SILVERMEDAL);
				break;
			}
		}

		if (j == counter) {
			strcpy(aMedalCountry[j].sName, sNameTmp);
			aMedalCountry[j].iMedalNum[SILVERMEDAL]++;
			aSortTable[j] = j;
			counter++;
			AdjustSortTable(aSortTable, aMedalCountry, counter, j, SILVERMEDAL);
		}

		//Bronze Medal
		scanf("%s", sNameTmp);

		for (j = 0; j < counter; j++) {

			if (!strcmp(aMedalCountry[j].sName, sNameTmp)) {
				aMedalCountry[j].iMedalNum[BRONZEMEDAL]++;
				AdjustSortTable(aSortTable, aMedalCountry, counter, j, BRONZEMEDAL);
				break;
			}
		}

		if (j == counter) {
			strcpy(aMedalCountry[j].sName, sNameTmp);
			aMedalCountry[j].iMedalNum[BRONZEMEDAL]++;
			aSortTable[j] = j;
			counter++;
			AdjustSortTable(aSortTable, aMedalCountry, counter, j, BRONZEMEDAL);
		}
	}

	for (i = 0; i < counter; i++) {

		aMedalCountry[aSortTable[i]].iPlace = i;
		pSMC = aMedalCountry + aSortTable[i];
		printf("%3d %3s %3d %3d %3d\n", pSMC->iPlace + 1, pSMC->sName,
		       pSMC->iMedalNum[GOLDMEDAL], pSMC->iMedalNum[SILVERMEDAL],
		       pSMC->iMedalNum[BRONZEMEDAL]);
	}

	return 0;
}

void AdjustSortTable(int aSortTable[], struct medalCountry aMedalCountry[], int iCounter, int iNo, int iMedalType) {
	// 找到当前国家在排序数组中的位置
	int pos = -1;

	for (int i = 0; i < iCounter; i++) {

		if (aSortTable[i] == iNo) {
			pos = i;
			break;
		}
	}

	if (pos == -1)
		return;

	// 向前调整位置（冒泡排序的方式）
	while (pos > 0) {
		int prevPos = pos - 1;
		int currentCountry = aSortTable[pos];
		int prevCountry = aSortTable[prevPos];

		struct medalCountry *curr = &aMedalCountry[currentCountry];
		struct medalCountry *prev = &aMedalCountry[prevCountry];

		// 判断是否需要交换
		int swapNeeded = 0;

		// 比较金牌
		if (curr->iMedalNum[GOLDMEDAL] > prev->iMedalNum[GOLDMEDAL]) {
			swapNeeded = 1;
		} else if (curr->iMedalNum[GOLDMEDAL] == prev->iMedalNum[GOLDMEDAL]) {
			// 比较银牌
			if (curr->iMedalNum[SILVERMEDAL] > prev->iMedalNum[SILVERMEDAL]) {
				swapNeeded = 1;
			} else if (curr->iMedalNum[SILVERMEDAL] == prev->iMedalNum[SILVERMEDAL]) {
				// 比较铜牌
				if (curr->iMedalNum[BRONZEMEDAL] > prev->iMedalNum[BRONZEMEDAL]) {
					swapNeeded = 1;
				} else if (curr->iMedalNum[BRONZEMEDAL] == prev->iMedalNum[BRONZEMEDAL]) {
					// 按名称字母顺序
					if (strcmp(curr->sName, prev->sName) < 0) {
						swapNeeded = 1;
					}
				}
			}
		}

		if (swapNeeded) {
			// 交换位置
			aSortTable[pos] = prevCountry;
			aSortTable[prevPos] = currentCountry;
			pos = prevPos;
		} else {
			break;
		}
	}
}