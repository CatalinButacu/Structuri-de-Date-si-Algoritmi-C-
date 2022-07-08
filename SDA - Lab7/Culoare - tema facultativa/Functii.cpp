#include "stdafx.h"
#include "Functii.h"

void InitQueue(Queue*& queue)
{
	queue = nullptr;
}

void Put(Queue*& queue, Pozitie val)
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

Pozitie Get(Queue*& queue)
{
	if (!isEmpty(queue))
	{
		Pozitie aux = queue->data;
		Queue* p = queue;
		queue = p->leg;
		if (p != p->tail)
			queue->tail = p->tail;
		delete p;
		return aux;
	}
	std::cout << "Queue is empty" << std::endl;
	return Pozitie();
}

Pozitie Front(Queue* queue)
{
	if (!isEmpty(queue))
	{
		return queue->data;
	}
	std::cout << "Queue is empty" << std::endl;
	return Pozitie();
}

bool isEmpty(Queue* queue)
{
	return queue == nullptr;
}
