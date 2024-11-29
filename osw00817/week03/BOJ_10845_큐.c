#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 10000

/*
push X: ���� X�� ť�� �ִ� �����̴�.
pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�.
���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ť�� ����ִ� ������ ������ ����Ѵ�.
empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
front: ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
*/

typedef struct {
	int data[SIZE];
	int front, rear;
}Queue;

void init(Queue* Q) {
	Q->front = Q->rear = -1;
}
int isEmpty(Queue* Q) {
	if (Q->front == Q->rear)
		return 1;
	return 0;
}
int isFull(Queue* Q) {
	if (Q->rear == SIZE - 1)
		return 1;
	return 0;
}
void enqueue(Queue* Q, int e) {
	if (!isFull(Q)) {
		Q->rear++;
		Q->data[Q->rear] = e;
	}
}
int dequeue(Queue* Q) {
	if (!isEmpty(Q)) {
		Q->front++;
		return Q->data[Q->front];
	}
	else {
		return -1;
	}
}

int front(Queue* Q) {
	if (!isEmpty(Q)) {
		return Q->data[Q->front + 1];
	}
	else {
		return -1;
	}
}

int back(Queue* Q) {
	if (!isEmpty(Q)) {
		return Q->data[Q->rear];
	}
	else {
		return -1;
	}
}

int main() {
	int loop = 0;
	scanf("%d", &loop);

	Queue Queue;
	init(&Queue);

	while (loop > 0) {
		loop--;
		char command[10];
		scanf("%s", command);
		if (!strcmp(command, "push")) {
			//���� X�� ť�� �ִ� �����̴�.
			int num = 0;
			scanf("%d", &num);
			enqueue(&Queue, num);
		}
		else if (!strcmp(command, "pop")) {
			printf("%d\n", dequeue(&Queue));
		}
		else if (!strcmp(command, "size")) {
			printf("%d\n", Queue.rear - Queue.front);
		}
		else if (!strcmp(command, "empty")) {
			printf("%d\n", isEmpty(&Queue));
			// ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
		}
		else if (!strcmp(command, "front")) {
			printf("%d\n", front(&Queue));
			//ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
		}
		else if (!strcmp(command, "back")) {
			printf("%d\n", back(&Queue));
			//ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
		}
	}
}