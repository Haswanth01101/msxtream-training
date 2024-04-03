#ifndef ARRAY_H
#define ARRAY_H
#include<iostream>
using namespace std;
class array
{
	private:
		int count,sum;
		int size;
		int *arr;
	public:
		array(int sz);
		void sumOfEntireArray();
		int MaxValue();
		int MinValue();
		void average();
		void search(int value);
		void sort();
		void EvenNumbers();
		void OddNumbers();
		void display();
		void insert(int value);
};
#endif

