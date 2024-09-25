#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10000

void push(int X);
void pop(void);
int top = -1, stack[MAX]; //top : 스택의 top 값이 저장되어있는 인덱스

int main(void)
{
	char cmd[20], *num_X; //명령을 저장할 배열, push 에서 삽입할 수를 저장할 배열의 포인터 주소
	int N, X; //명령 수
	scanf("%d", &N);
	getchar(); //fgets 함수가 버퍼에 남아있는 개행문자를 받지 않게 개행문자 제거

	for (int i = 0; i < N; i++) {
		fgets(cmd, 20, stdin);
		cmd[strcspn(cmd, "\n")] = '\0'; // fgets 함수는 문자열 끝에 개행문자를 추가, 이를 제거해야 아래 strcmp 가 작동 

		switch (cmd[0]) {
		case 'p':
			if (!strcmp(cmd, "pop")) pop();
			else {
				num_X = cmd + 5; // 아래설명
				push(atoi(num_X));
			}
			break;

		case 's':
			printf("%d\n", top + 1); //현재 저장된 수의 개수는 top + 1임. (top 이 0부터 1개 저장된것이기 때문)
			break;
		case 'e':
			if (top == -1) printf("1\n");
			else printf("0\n");
			break;
		case 't':
			if (top == -1) printf("-1\n");
			else printf("%d\n", stack[top]);
			break;
		}
	}
}

void push(int X) //stack 에 수를 push 했을때 top 을 1씩 늘려가면서 해당 인덱스에 저장!
{
	stack[++top] = X;
}

void pop(void)
{
	if (top == -1) printf("-1\n");
	else {
		printf("%d\n", stack[top]);
		--top;
	}
}
