#pragma once

struct Stack {
	int data;
	Stack* next;
};

int clear(Stack*& myStk);
void push(int x, Stack*& myStk);
void toFile(Stack*& myStk);
void fromFile(Stack*& myStk);
void function(Stack*& myStk);
void show(Stack* myStk);