//���� ���� ����Ʈ�� ����� ���Կ�. ť�� �ش��մϴ�.

#include <stdio.h>

typedef struct node
{
	int data; // �� ����
	//�ּ� �����ϴµ� �ڱ� �ڽ��� ũ�⸸ŭ �޸𸮸� �Ҵ��ؾ��ϳ�? //struct�� �����ϴ� ������?
	struct node* _next; // ���� ����� �ּҸ� ����
} node_t;

node_t* _head = NULL, * _tail = NULL;

void insert_node(int value);
int delete_node();

int main(void)
{
	int n, r, f;

	printf("���� �Է½� ���α׷��� ����˴ϴ�.\n");
	printf("��� �Է½� ����ȣ�� �Էµ˴ϴ�.\n");
	printf("0 �Է½� ����ȣ�� ��µ˴ϴ�.\n");

	do {
		printf("\n����ȣ�� �Է����ּ���.");
		f = scanf_s("%d",&n,1);
		while (getchar() != '\n'); // �Է� ���� ����
		if (f == 0)
		{
			printf("�߸� �Է��ϼ̽��ϴ�. �ٽ��Է����ּ���.\n");
			continue;
		}
		if (n > 0)
			insert_node(n);
		else if (n == 0)
		{
			r = delete_node();
			if (r == -1)
				printf("����ȣ�� �����ϴ�.\n");
			else
				printf("����ȣ:%d\n", r);
		}
	} while (n >= 0);

	return 0;

}

void insert_node(int value)
{
	node_t* _new_node = (node_t*)malloc(sizeof(node_t));

	_new_node->data = value;
	_new_node->_next = NULL;

	if (_head == NULL) // ��尡 ���� ����
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

	if (_head == NULL) // ��尡 ���� ����
		return -1;
	
	_node_n = _head;
	_head = _head->_next; // head�� ��ġ�� ���� ����  ����


	//head�� next�� NULL�̴�. == tail�̴�. == ������ ����̴�. + head�� tail�� ���ÿ� ������ ���� ����̴�.
	//�� ��쿡 tail�� ���� ������ head �ּҸ� ������. ������ ���߿� ��带 ���� ����,
	//����� head�� NULL���� ������ ������ ������ tail�� NULL�� �ʱ�ȭ �Ǵ°� �ƴѰ�?
	// �׷��ٸ� �� ������ �ʿ��Ѱ�?
	if (_head == NULL)
		_tail = NULL;


	r = _node_n->data;
	free(_node_n); // ������ ����� ���� �޸� �Ҵ� ����
	return r; // ������ ����� �� ��ȯ

}