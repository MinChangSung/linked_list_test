//단일 연결 리스트를 만들어 볼게요. 큐에 해당합니다.

#include <stdio.h>

typedef struct node
{
	int data; // 값 저장
	//주소 저장하는데 자기 자신의 크기만큼 메모리를 할당해야하나? //struct로 선언하는 이유는?
	struct node* _next; // 다음 노드의 주소를 저장
} node_t;

node_t* _head = NULL, * _tail = NULL;

void insert_node(int value);
int delete_node();

int main(void)
{
	int n, r, f;

	printf("음수 입력시 프로그램이 종료됩니다.\n");
	printf("양수 입력시 대기번호로 입력됩니다.\n");
	printf("0 입력시 대기번호가 출력됩니다.\n");

	do {
		printf("\n대기번호를 입력해주세요.");
		f = scanf_s("%d",&n,1);
		while (getchar() != '\n'); // 입력 버퍼 비우기
		if (f == 0)
		{
			printf("잘못 입력하셨습니다. 다시입력해주세요.\n");
			continue;
		}
		if (n > 0)
			insert_node(n);
		else if (n == 0)
		{
			r = delete_node();
			if (r == -1)
				printf("대기번호가 없습니다.\n");
			else
				printf("대기번호:%d\n", r);
		}
	} while (n >= 0);

	return 0;

}

void insert_node(int value)
{
	node_t* _new_node = (node_t*)malloc(sizeof(node_t));

	_new_node->data = value;
	_new_node->_next = NULL;

	if (_head == NULL) // 노드가 없는 상태
	{
		_head = _new_node;
		_tail = _new_node;
	}
	else
	{
		_tail->_next = _new_node;
		_tail = _new_node;
	}
}

int delete_node(void)
{
	node_t* _node_n;
	int r;

	if (_head == NULL) // 노드가 없는 상태
		return -1;
	
	_node_n = _head;
	_head = _head->_next; // head의 위치를 다음 노드로  변경


	//head의 next가 NULL이다. == tail이다. == 마지막 노드이다. + head와 tail을 동시에 가지는 단일 노드이다.
	//이 경우에 tail은 변경 이전의 head 주소를 가진다. 하지만 나중에 노드를 새로 만들어도,
	//변경된 head가 NULL값을 가지기 때문에 무조건 tail도 NULL로 초기화 되는게 아닌가?
	// 그렇다면 이 문장이 필요한가?
	if (_head == NULL)
		_tail = NULL;


	r = _node_n->data;
	free(_node_n); // 삭제할 노드의 동적 메모리 할당 해제
	return r; // 삭제된 노드의 값 반환

}