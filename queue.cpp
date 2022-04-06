#include "queue.h"
#include <iostream>
#include <cstring>

using namespace std;
inline man create_elem(string fullName, int age, bool genderIsWoman, string jobPlace, double income, bool aimIsCredit)
{
	man m;
	m.fullName =  fullName;	
	m.jobPlace = jobPlace;
	m.genderIsWoman = genderIsWoman;
	m.aimIsCredit = aimIsCredit;
	m.age = age;
	m.income = income;

	return m;
}
void enqueue(queue& queue, string fullName, int age, bool genderIsWoman, string jobPlace, double income, bool aimIsCredit)
{
	man newm = create_elem(fullName, age, genderIsWoman, jobPlace, income, aimIsCredit);
	elem* newel = new elem;
	newel->m = newm;
	if (!queue.tail)
	{
		queue.head = queue.tail = newel;
	}
	else
	{
		queue.tail->next = newel;
		queue.tail = newel;
	}
	queue.size++;
}
bool dequeue(queue& queue, man& m)
{
	if (!queue.head) 
		return false; 
	m = queue.head->m;
	elem* rem = queue.head;
	queue.head = queue.head->next;
	delete rem;
	if (!queue.head) queue.tail = nullptr;
	queue.size--;
	return true;
}
void clear(queue& queue)
{
	while (queue.head)
	{
		elem* rem = queue.head; 
		queue.head = queue.head->next;
		delete rem;
	}
	queue.size = 0;
	queue.tail = nullptr; 
}