//function start 재귀함수?
//종료조건 대답하고 라고 대답하였지 cnt -= 4
//잘들어보게
// reculsive
//라고 대답하였지 cnt -=4

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int count = 0;//_의 갯수 저장


int What_is_recursive_function(int i) {
	for (int j = 0; j < count; j++)printf("_");
	printf("\"재귀함수가 뭔가요?\"\n");

	if (0 == i) {
		for (int j = 0; j < count; j++)printf("_");
		printf("\"재귀함수는 자기 자신을 호출하는 함수라네\"\n");
		for (int j = 0; j < count; j++)printf("_");
		printf("라고 답변하였지.\n");
		count -= 4;
		return 0;
	}
	for (int j = 0; j < count; j++)printf("_");
	printf("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n");
	for (int j = 0; j < count; j++)printf("_");
	printf("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n");
	for (int j = 0; j < count; j++)printf("_");
	printf("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n");
	count += 4;
		What_is_recursive_function(i - 1);
		for (int j = 0; j < count; j++)printf("_");
		printf("라고 답변하였지.\n");
		count -= 4;
		return 0;

}

int main() {
	int count;
	scanf("%d", &count);
	printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");
	int a = What_is_recursive_function(count);


	return 0;
}
