#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int n;
const char* script[4] = { "\"����Լ��� ������?\"",
	"\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.",
"���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.",
"���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" };

void recursion(int incrase, int max) {
	if (incrase == max + 1)
		return 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < incrase; j++)
			printf("____");
		if (incrase == max && i == 1) {
			puts("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"");
			break;
		}
		puts(script[i]);
	}
	recursion(incrase + 1, max);
	for (int j = 0; j < incrase; j++)
		printf("____");
	puts("��� �亯�Ͽ���.");
}
int main() {
	scanf("%d", &n);
	printf("��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n");
	recursion(0, n);
}
