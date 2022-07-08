#pragma once
struct Queue 
{
	int data;
	Queue* leg, * tail;
};