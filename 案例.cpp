#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEXT_SIZE 100
#define WORD_SIZE 50
#define DELIMS " ,.!?\n"

void replacedWord(const char *text, const char *oldWord, const char *newWord, char *result);

int countChar (const char *text, char ch);

int countWords(const char *text);

void extractUniqueWords(const char *text, char uniqueWords[][WORD_SIZE], int *uniqueCount);

int main(void) {

	char text[TEXT_SIZE] = "This is dick. This is dicking.";

	char replacedText[TEXT_SIZE] = {0};

	char oldWord[] = "dick";

	char newWord[] = "pussy";

	char countCharTarget = 's';

	char uniqueWords[TEXT_SIZE][WORD_SIZE] = {0};

	int uniqueCount = 0;

	replacedWord(text, oldWord, newWord, replacedText);

	printf("%s\n", replacedText);

	int charCount = countChar(replacedText, countCharTarget);

	printf("%c %d\n", countCharTarget, charCount);

	int wordCount = countWords(replacedText);
	printf("%d\n", wordCount);

	extractUniqueWords(replacedText, uniqueWords, &uniqueCount);

	for (int i = 0; i < uniqueCount; i++) {

		printf("%s\n", uniqueWords[i]);
	}

	return 0;
}

void replacedWord(const char *text, const char *oldWord, const char *newWord, char *result) {
	char buffer[TEXT_SIZE] = {0};
	const char *pos = text;
	const char *temp = text;
	size_t oldLen = strlen(oldWord);

	while ((temp = strstr(pos, oldWord)) != NULL) {
		strncat_s(buffer, sizeof(buffer), pos, temp - pos);
		strcat_s(buffer, sizeof(buffer), newWord);
		pos = temp + oldLen;

	}

	strcat_s(buffer, sizeof(buffer), pos);
	strcpy_s(result, TEXT_SIZE, buffer);
}

int countChar (const char *text, char ch) {
	int count = 0;

	while (*text) {
		if  (*text == ch) {
			count++;
		}

		text++;
	}

	return count;
}

int countWords(const char *text) {
	int count = 0;
	char buffer[TEXT_SIZE] = {0};
	strcpy_s(buffer, TEXT_SIZE, text);

	char *context = NULL;

	char *token = strtok_s(buffer, DELIMS, &context);


	while (token != NULL) {
		count++;
		token = strtok_s(NULL, DELIMS, &context);
	}

	return count++;

}

void extractUniqueWords(const char *text, char uniqueWords[][WORD_SIZE], int *uniqueCount) {
	char tempText[TEXT_SIZE] = {0};
	strcpy_s(tempText, TEXT_SIZE, text);

	char *context = NULL;
	char *token = strtok_s(tempText, DELIMS, &context);

	while (token != NULL) {
		int found = 0;

		for (int j = 0; j < *uniqueCount; ++j) {

			if (strcmp(token, uniqueWords[j]) == 0) {
				found = 1;
				break;
			}
		}

		if (!found) {
			strcpy_s(uniqueWords[*uniqueCount], WORD_SIZE, token);
			(*uniqueCount)++;


		}

		token = strtok_s(NULL, DELIMS, &context);
	}
}