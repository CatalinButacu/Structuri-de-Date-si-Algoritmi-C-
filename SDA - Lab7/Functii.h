#pragma once
#include "Element.h"
#include "Queue.h"

// 1)
void InitQueue(Element &queue);

void Put(Element &queue, int val);

int Get(Element &queue);

int Front(Element queue);

bool isEmpty(Element queue);

bool isFull(Element queue);

// 2)

void InitQueue(Queue *&queue);

void Put(Queue *&queue, int val);

int Get(Queue *&queue);

int Front(Queue *queue);

bool isEmpty(Queue *queue);