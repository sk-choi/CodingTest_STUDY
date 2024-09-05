#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1. 모음(a, e, i, o, u) 하나를 반드시 포함하여야 한다. o
//2. 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
//3. 같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다. o
// 마지막 테스트 케이스는 end이며, 패스워드는 한글자 이상 20글자 이하의 문자열이다. 또한 패스워드는 대문자를 포함하지 않는다.

int isEnd(char arr[]);
int strchr_n(char arr[], char a);
int isVowel(char arr[]);
int isSameWord(char arr[]);
int continuous(char arr[]);

int main() {

	char words[21];

	/*scanf("%s", &words);

	printf("%d\n", isVowel(words));
	printf("%d\n", continuous(words));
	printf("%d\n", isSameWord(words));*/

	while (1) {
		scanf("%s", &words);

		//printf("%d", isSameWord(words));

		if (isEnd(words) == 1) {
			break;
		}
		else if ((isVowel(words) == 1) && (continuous(words) == 0) && (isSameWord(words) == 0)) {
			printf("<%s> is acceptable.\n", words);
		}
		else {
			printf("<%s> is not acceptable.\n", words);
		}
	}
	return 0;
}

int isEnd(char arr[]) {
	for (int i = 0; i < 1; i++) {
		if (arr[i] == 'e' && arr[i + 1] == 'n' && arr[i + 2] == 'd') {
			return 1;
		}
	}
	return 0;
}

int strchr_n(char vowels[], char a) {
	for (int i = 0; i < strlen(vowels); i++) {
		if (vowels[i] == a) {
			return 1;
		}
	}
	return 0;
}

//모음 있는지 확인
int isVowel(char arr[]) {

	int count = 0;
	for (int i = 0; i < strlen(arr); i++) {
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
			count++;
		}
		else {
			count = count;
		}
	}
	if (count == 0) { // 카운트가 0이면
		return 0; //모음 없음 :0
	}
	else {
		return 1; //모음 있음 :1
	}
}

// 모음이 3개 혹은 자음이 3개 연속으로 있는지 확인
int continuous(char arr[]) {
	char vowels[6] = { 'a', 'e', 'i', 'o', 'u' };
	int first = 0;
	int second = 0;
	for (int i = 0; i < strlen(arr); i++) {
		if (strchr_n(vowels, arr[i]) == 1) {
			first++;
			second = 0;
		}
		else {
			first = 0;
			second++;
		}
		if (first == 3 || second == 3) {
			return 1; //조건 만족: 연속된 같은 글자 3개
		}
	}
	return 0; // 연속된 같은 글자 3개 없음
}

// 같은 글자 확인 1이면 안됨
int isSameWord(char arr[]) {
	for (int i = 0; i < strlen(arr) - 1; i++) {
		if (arr[i] == arr[i + 1]) {
			if (!((arr[i] == 'o' && arr[i + 1] == 'o') || (arr[i] == 'e' && arr[i + 1] == 'e'))){
				return 1;
			}
		}
	}
	return 0;
}



