#include <iostream>
#include <fstream>
#include <sstream>
#include "windows.h"
#include <vector>
#include "queue.h"
using namespace std;
void load_data(const char* filename, queue& manCredit, queue& manDeposit);
void write_data(queue& q, const char* filename);
static std::vector<std::string> split(const std::string& s, char delim);
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	queue manCredit;
	queue manDeposit;
	load_data("listMan.txt", manCredit, manDeposit);
	write_data(manCredit, "manCredit.txt");
	write_data(manDeposit, "manDeposit.txt");
	system("pause");
}
void load_data(const char* filename, queue& manCredit, queue& manDeposit)
{
	ifstream f(filename);
	if (f.is_open())
	{
		while (!f.eof())
		{
			char* strFile = new char[500];
			f.getline(strFile, 500);
			vector<string> date = split(static_cast<string>(strFile), '|');
			string fullName = date[0];
			int age = stoi(date[2]);
			string jobPlace = date[3];
			double income = atof(date[4].c_str());
			bool aimIsCredit;
			if (date[5] == "кредит")
			{
				enqueue(manCredit, fullName, age, date[1] == "жен", jobPlace, income, true);
			}
			else
			{
				enqueue(manDeposit, fullName, age, date[1] == "жен", jobPlace, income, false);
			}
		}
		f.close();
	}
}
void write_data(queue& q, const char* filename)
{
	std::ofstream out;         
	out.open(filename); 
	if (out.is_open())
	{
		int i = 0;
		while (q.size > 0)
		{
			man m;
			if (dequeue(q, m))
			{
				out << ++i << ".\t" << m.fullName << "\tВозраст:" << m.age;
				if (m.genderIsWoman)
				{
					out << "\tПол: " << "женский";
				}
				else {
					out << "\tПол: " << "мужской";
				}
				out << "\tЗарплата: " << m.income << "\tМесто работы: " << m.jobPlace << endl;
			}
		}
	}
	out.close();
}
static std::vector<std::string> split(const std::string& s, char delim)
{
	std::vector<std::string> elems;
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}