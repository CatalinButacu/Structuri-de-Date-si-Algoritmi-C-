#pragma once
#include "Queue.h"

void InitQueue(Queue*& queue);

void Put(Queue*& queue, Pozitie val);

Pozitie Get(Queue*& queue);

Pozitie Front(Queue* queue);

bool isEmpty(Queue* queue);