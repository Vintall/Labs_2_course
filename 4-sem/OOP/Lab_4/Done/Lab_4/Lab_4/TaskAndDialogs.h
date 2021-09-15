#pragma once
#include <iostream>
#include "MyVector.h"

#define WITH_STD

#ifdef WITH_STD
#include <queue>
#include <vector>
using namespace std;
#else
#include "Queue.h"
using namespace none_std;
#endif // WITH_STD

#define cout std::cout
#define cin std::cin
#define endl std::endl

template <typename T>
class TaskAndDialogs
{
	queue<T> container;
	MyVec::vector<T> vec;

public:
	TaskAndDialogs()
	{
		while (1)
			MainMenu();
	}
	void MainMenu()
	{
		cout << "1) ������ � queue (2 stack's)" << endl;
		cout << "2) ������ � vector (iterator)" << endl;
		cout << "3) �����" << endl;
		cout << "�������� ����� ����: ";

		int choice = -1;
		cin >> choice;
		system("cls");
		if (choice == 1)
		{
			QueueMenu();
		}
		else if (choice == 2)
		{
			VectorMenu();
		}
		else 
			exit(0);
	}
	void VectorMenu()
	{
		int while_checker = 1;
		while (while_checker)
		{
			cout << "1) �������� ����� �������" << endl;
			cout << "2) �������� vector" << endl;
			cout << "3) ������� vector" << endl;
			cout << "4) ����� � MainMenu" << endl;

			cout << "�������� ����� ����: ";
			int choice = -1;
			cin >> choice;
			switch (choice)
			{
			case 1:
				T elem;
				cout << "������� �������: ";
				cin >> elem; cout << endl;
				vec.push_back(elem);
				break;
			case 2:
				vec.clear();
				break;
			case 3:
			{
				typename MyVec::vector<T> ::iterator iter = vec.begin();
				while (iter != vec.end())
				{
					cout << *iter << endl;
					iter++;
				}
				system("Pause");
				break;
			}
			default:
				while_checker = 0;
				break;
			}
			system("cls");
		};
	}
	void QueueMenu()
	{
		int while_checker = 1;
		while (while_checker)
		{
			cout << "1) �������� ����� �������" << endl;
			cout << "2) �������� �������" << endl;
			cout << "3) ������� �������" << endl;
			cout << "4) ������� �����" << endl;
			cout << "5) ����� � MainMenu" << endl;

			cout << "�������� ����� ����: ";
			int choice = -1;
			cin >> choice;
			switch (choice)
			{
			case 1:
				AddNewElem();
				break;
			case 2:
				Clear();
				break;
			case 3:
				ShowQueue();
				system("Pause");
				break;
			case 4:
				cout << Sum() << endl;
				system("Pause");
				break;
			default:
				while_checker = 0;
				break;
			}
			system("cls");
		};
	}
	T Sum()
	{
		queue<T> buf = container;
		T sum = 0;
		int count = container.size();
		for (int i = 0; i < count; i++)
		{
			sum += buf.front();
			buf.pop();
		}
		return sum;
	}
	void ShowQueue()
	{
		int size = container.size();
		for (int i = 0; i < size; i++)
		{
			T buf;
			buf = container.front();
			container.pop();
			cout << buf << endl;
			container.push(buf);
		}
	}
	void AddNewElem()
	{
		cout << "������� ����� �������: ";
		T new_elem;
		cin >> new_elem;
		cout << endl;
		container.push(new_elem);
	}
	void Clear()
	{
		int size = container.size();
		for (int i = 0; i < size; i++)
			container.pop();
	}
};
