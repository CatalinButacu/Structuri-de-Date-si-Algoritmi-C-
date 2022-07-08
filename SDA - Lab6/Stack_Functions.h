#pragma once
#include "Stack.h"
#include "Element.h"

// 1)
void initStack(Stack& S);
void Push(Stack& S, int a);
int Pop(Stack& S);
int Top(Stack S);
bool IsEmpty(Stack S);
bool IsFull(Stack S);

// 2)
void initStack(Element* cap);
void Push(Element*& cap, char val);
char Pop(Element*& cap);
char Top(Element* cap);
bool IsEmpty(Element* cap);

// 3)
int calcul_postfixata(Element*& s, char v[]);

// 4)
void transform_postfixata(char rez[], char v[]);