#pragma once
#include <iostream>

using namespace std;
struct man
{
	string fullName;
	bool genderIsWoman;
	string jobPlace;
	double income;
	bool aimIsCredit;
	int age;
};
struct elem
{
	man m;
	elem* next = nullptr;
};
struct queue
{
	elem* head = nullptr;
	elem* tail = nullptr;
	size_t size = 0;
};
void enqueue(queue& queue, string fullName, int age, bool genderIsWoman, string jobPlace, double income, bool aimIsCredit);
bool dequeue(queue& queue, man& man);
void clear(queue& queue);
