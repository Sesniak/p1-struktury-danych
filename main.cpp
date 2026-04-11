#include <iostream>
#include <vector>
#include <random>
#include <chrono>

#include "ArrayList.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"

using namespace std;

long long now()
{
	return chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
}

int main()
{
	for (int seed = 1; seed <= 10; seed++)
	{
		cout << "-----------------------------\n";
		cout << "------------SEED-------------\n";
		cout << "-----------------------------\n";

		mt19937 rng(seed);

		for (int n : SIZE)
		{
			cout << "TEST SIZE = " << n;

			vector<int> data = n;
			for (int i = 0; i < n; i++)
			{
				data[i] = rng();
			}

			ArrayList arr;

			long long t1 = now();
			arr.dodPocz(312);
			long long t2 = now();

			long long t3 = now();
			arr.usunPocz();
			long long t4 = now();

			long long t5 = now();
			arr.dodKon(235);
			long long t6 = now();

			long long t7 = now();
			arr.usunKon();
			long long t8 = now();

			long long t9 = now();
			arr.dodNa(n/2, 124);
			long long t10 = now();

			long long t11 = now();
			arr.usunNa(n / 2);
			long long t12 = now();

			long long t13 = now();
			arr.wyszukaj(data[n / 2]);
			long long t14 = now();

			cout << "ArrayList dodanie na poczatku: " << (t2 - t1) << "\n";
			cout << "ArrayList usuwanie na poczatku: " << (t4 - t3) << "\n";
			cout << "ArrayList dodanie na koncu: " << (t6 - t5) << "\n";
			cout << "ArrayList usuwanie na koncu: " << (t8 - t7) << "\n";
			cout << "ArrayList dodanie na miejscu: " << (t10 - t9) << "\n";
			cout << "ArrayList usuwanie na miejscu: " << (t12 - t11) << "\n";
			cout << "ArrayList wyszukiwanie: " << (t14 - t13) << "\n";

			SinglyLinkedList sll;

			long long t1 = now();
			sll.addAtBeginning(312);
			long long t2 = now();

			long long t3 = now();
			sll.removeAtBeginning();
			long long t4 = now();

			long long t5 = now();
			sll.addAtEnd(235);
			long long t6 = now();

			long long t7 = now();
			sll.removeAtEnd();
			long long t8 = now();

			long long t9 = now();
			sll.addAtPos(n / 2, 124);
			long long t10 = now();

			long long t11 = now();
			sll.removeAtPos(n / 2);
			long long t12 = now();

			long long t13 = now();
			sll.find(data[n / 2]);
			long long t14 = now();

			cout << "SinglyLinkedList dodanie na poczatku: " << (t2 - t1) << "\n";
			cout << "SinglyLinkedList usuwanie na poczatku: " << (t4 - t3) << "\n";
			cout << "SinglyLinkedList dodanie na koncu: " << (t6 - t5) << "\n";
			cout << "SinglyLinkedList usuwanie na koncu: " << (t8 - t7) << "\n";
			cout << "SinglyLinkedList dodanie na miejscu: " << (t10 - t9) << "\n";
			cout << "SinglyLinkedList usuwanie na miejscu: " << (t12 - t11) << "\n";
			cout << "SinglyLinkedList wyszukiwanie: " << (t14 - t13) << "\n";

			DoublyLinkedList dll;

			long long t1 = now();
			dll.addAtBeginning(312);
			long long t2 = now();

			long long t3 = now();
			dll.removeAtBeginning();
			long long t4 = now();

			long long t5 = now();
			dll.addAtEnd(235);
			long long t6 = now();

			long long t7 = now();
			dll.removeAtEnd();
			long long t8 = now();

			long long t9 = now();
			dll.addAtPos(n / 2, 124);
			long long t10 = now();

			long long t11 = now();
			dll.removeAtPos(n / 2);
			long long t12 = now();

			long long t13 = now();
			dll.find(data[n / 2]);
			long long t14 = now();

			cout << "DoublyLinkedList dodanie na poczatku: " << (t2 - t1) << "\n";
			cout << "DoublyLinkedList usuwanie na poczatku: " << (t4 - t3) << "\n";
			cout << "DoublyLinkedList dodanie na koncu: " << (t6 - t5) << "\n";
			cout << "DoublyLinkedList usuwanie na koncu: " << (t8 - t7) << "\n";
			cout << "DoublyLinkedList dodanie na miejscu: " << (t10 - t9) << "\n";
			cout << "DoublyLinkedList usuwanie na miejscu: " << (t12 - t11) << "\n";
			cout << "DoublyLinkedList wyszukiwanie: " << (t14 - t13) << "\n";
		}
	}
}