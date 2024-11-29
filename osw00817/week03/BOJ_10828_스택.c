#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/*
push X: ���� X�� ���ÿ� �ִ� �����̴�.
pop: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�.
���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���ÿ� ����ִ� ������ ������ ����Ѵ�.
empty: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
top: ������ ���� ���� �ִ� ������ ����Ѵ�.
���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
*/

int data[10001] = { 0 };
int top = -1;

int main() {
	int loop;
	scanf("%d", &loop);
	while (loop > 0) {
		loop--;
		char command[20];
		scanf("%s", command);
		if (strcmp(command, "pop") == 0) {
			printf("%d\n", (top < 0) ? -1 : data[top--]);
		}
		else if (strcmp(command, "size") == 0) {
			printf("%d\n", top + 1);
		}
		else if (strcmp(command, "empty") == 0) {
			printf("%d\n", (top < 0) ? 1 : 0);
		}
		else if (strcmp(command, "top") == 0) {
			printf("%d\n", (top < 0) ? -1 : data[top]);
		}
		else {
			int num;
			scanf("%d", &num);
			data[++top] = num;
		}
	}
	return 0;
}