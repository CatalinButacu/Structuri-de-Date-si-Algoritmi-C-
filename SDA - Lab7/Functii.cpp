#include <iostream>
#include "Functii.h"

// 1)
void InitQueue(Element &queue)
{
	queue.head = 0;
	queue.tail = 0;
}

void Put(Element &queue, int val)
{
	if (!isFull(queue))
	{
		queue.data[queue.tail] = val;
		queue.tail++;
		if (queue.tail >= length)
			queue.tail = 0;
	}
	else
		std::cout << "Queue is full" << std::endl;
}

int Get(Element &queue)
{
	if (!isEmpty(queue)) 
	{
		int data = queue.data[queue.head];
		queue.head++;
		if (queue.head >= length)
			queue.head = 0;
		return data;
	}
	else
		std::cout << "Queue is empty" << std::endl;
	return 0;
}

int Front(Element queue)
{
	if(!isEmpty(queue))
		return queue.data[queue.head];
	return 0;
}

bool isEmpty(Element queue)
{
	if (queue.head == queue.tail)
		return true;
	return false;
}

bool isFull(Element queue)
{
	int tail;
	if (queue.tail + 1 >= length)
		tail = 0;
	else
		tail = queue.tail + 1;

	if (tail == queue.head)
		return true;
	return false;
}


// 2)
void InitQueue(Queue *&queue)
{
	queue = nullptr;
}

void Put(Queue *&queue, int val)
{
	if (queue == nullptr) 
	{
		queue = new Queue();
		queue->data = val;
		queue->leg = nullptr;
		queue->tail = queue;
		return;
	}
	Queue* p = new Queue();
	p->data = val;
	p->leg = nullptr;
	queue->tail->leg = p;
	queue->tail = p;
}

int Get(Queue *&queue)
{
	if (!isEmpty(queue)) 
	{
		int aux = queue->data;
		Queue* p = queue;
		queue = p->leg;
		if (p != p->tail)
			queue->tail = p->tail;
		delete p;
		return aux;
	}
	std::cout << "Queue is empty" << std::endl;
	return 0;
}

int Front(Queue *queue)
{
	if (!isEmpty(queue)) 
	{
		return queue->data;
	}
	std::cout << "Queue is empty" << std::endl;
	return 0;
}

bool isEmpty(Queue *queue)
{
	return queue==nullptr;
}
