#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
char data[100001];
int top = -1;
int cnt = 0;
/*
(�� ���� push
()�ΰ�� (������ŭ sum�� �߰�
)�� ���� pop
pop �ϸ鼭 1�� �߰�
*/
int main() {
	char input[100001];
	scanf("%s", input);
	for (int i = 0; i < strlen(input); i++) {
		//printf("%d %c %d\n", i, input[i], cnt);
		if (input[i] == '(') {
			if (input[i + 1] == ')') {
				// ������
				cnt += (top == -1) ? 0 : top + 1;
				i++;
			}
			else {
				// �踷��� ����
				// push
				data[++top] = '(';
			}
		}
		else {
			// �踷��� ������
			// pop
			top--;
			cnt += 1;
		}
	}
	printf("%d", cnt);
}