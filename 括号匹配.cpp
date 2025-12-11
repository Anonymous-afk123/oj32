#include <stdio.h>

int main() {
	char s[51];
	scanf("%s", s);

	char desk[51]; // 桌子，放左括号
	int top = -1;  // 桌子上盒子数

	for (int i = 0; s[i]; i++) {

		char c = s[i];

		if (c == '(' || c == '[' || c == '{') {
			desk[++top] = c;   // 放盒子
		} else if (c == ')' || c == ']' || c == '}') {
			if (top == -1) {   // 桌子空了，没法匹配
				printf("no\n");
				return 0;
			}

			char last = desk[top--]; // 拿走最后放的盒子

			if ((c == ')' && last != '(') ||
			        (c == ']' && last != '[') ||
			        (c == '}' && last != '{')) {
				printf("no\n");
				return 0;
			}
		}
	}

	if (top == -1)
		printf("yes\n");
	else
		printf("no\n");

	return 0;
}