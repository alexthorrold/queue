#include <iostream>

struct Node
{
	int data;
	Node *next;
};

struct Queue
{
	Node *front, *back;
};

Node *newNode(int data)
{
	Node *n = (Node *)malloc(sizeof(Node));
	n->data = data;
	n->next = NULL;
	return n;
}

Queue *createQueue()
{
	Queue *q = (Queue *)malloc(sizeof(Queue));
	q->front = q->back = NULL;
	return q;
}

void enqueue(Queue *q, int data)
{
	Node *temp = newNode(data);

	if (q->front == NULL)
	{
		q->front = q->back = temp;
		return;
	}

	q->back->next = temp;
	q->back = temp;
}

int dequeue(Queue *q)
{
	if (q->front == NULL)
		return INT_MIN;

	int i = q->front->data;
	Node *temp = q->front;
	
	q->front = q->front->next;

	if (q->front == NULL)
		q->back = NULL;

	free(temp);
	return i;
}

bool isEmpty(Queue *q)
{
	return q->front == NULL;
}

Node *first(Queue *q)
{
	return q->front;
}

Node *last(Queue *q)
{
	return q->back;
}

int main()
{
	struct Queue *q = createQueue();
	enqueue(q, 10);
	enqueue(q, 20);
	dequeue(q);
	dequeue(q);
	enqueue(q, 30);
	enqueue(q, 40);
	enqueue(q, 50);
	dequeue(q);
	printf("Queue Front : %d \n", q->front->data);
	printf("Queue Rear : %d", q->back->data);

	return 0;
}

//struct Queue
//{
//	unsigned size;
//	int front, back, length;
//	int *a;
//};
//
//Queue *createQueue(unsigned size)
//{
//	Queue *q = (Queue *)malloc(sizeof(Queue));
//	q->size = size;
//	q->front = q->length = 0;
//	q->back = size - 1;
//	q->a = (int *)malloc(size * sizeof(int));
//	return q;
//}
//
//int isFull(Queue *q)
//{
//	return q->length == q->size;
//}
//
//int isEmpty(Queue *q)
//{
//	return q->length == 0;
//}
//
//void enqueue(Queue *q, int i)
//{
//	if (isFull(q))
//		return;
//
//	q->back = (q->back + 1) % q->size;
//	q->a[q->back] = i;
//	q->length++;
//}
//
//int dequeue(Queue *q)
//{
//	if (isEmpty(q))
//		return INT_MIN;
//
//	int i = q->a[q->front];
//	q->front = (q->front + 1) % q->size;
//	q->length--;
//	return i;
//}
//
//int front(Queue *q)
//{
//	if (isEmpty(q))
//		return INT_MIN;
//
//	return q->a[q->front];
//}
//
//int back(Queue *q)
//{
//	if (isEmpty(q))
//		return INT_MIN;
//	
//	return q->a[q->back];
//}

