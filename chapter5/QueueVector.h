#pragma once
#include "Queue.h"
#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class QueueVector : public Queue <T>
{
public:
	T* data[];
	int capacity;
	int head;
	int rear;

	QueueVector() : capacity(100) {};
	~QueueVector() {};
	QueueVector(const QueueVector& q) {};

	void clear() override;
	void enqueue(T value) override;
	T dequeue() override;
	T front() const override;
	bool isEmpty()const override;
};

template <class T>
void QueueVector <T> ::clear() {
	for (int i = 0; i < this->capacity; i++)
	{
		this->dequeue();
	}
	head = 0;
	rear = 0;

}

template <class T>
void QueueVector<T>::enqueue(T val) {
	try
	{
		if ((this->head + 1) % this->capacity == rear)
			throw "can not enqueue because the queue is full!"
		else
			if (this->rear == this->capacity)
				this->rear = 0;
		this->data[this->rear] = val;
		this->rear += 1;

	}
	catch (const char* c)
	{
		cout << c << endl;
	}

}
template <class T>
T QueueVector <T> ::dequeue() {
	try
	{
		if (this->isEmpty)
			throw "can not dequeue because the queue is empty!"
		else 
		{
			T temp = this->front();
			if (this->head == this->capacity - 1)
				this->head = 0;
			else
				this->head += 1;
			return temp;
		}

	}
	catch (const char* c)
	{
		cout << c << endl;
	}

}
template <class T>
T QueueVector <T> ::front() const {
	try
	{
		if(this->isEmpty)
			throw "the queue is empty!"
		else
		    return this->head;

	}
	catch (const char* c)
	{
		cout << c << endl;
	}
}
template <class T>
bool QueueVector <T> ::isEmpty() const {
	if (this->head == this->rear)
		return true;
	return false;
}
template <class T>
QueueVector <T> ::QueueVector(const QueueVector& q){
	capacity = q.capacity;
	data = new T[capacity];
	for (int i = 0; i < capacity; i++)
	{
		data[i] = q.data[i];
	}
	head=q.head;
	rear=q.rear;
}
template <class T>
QueueVector <T> :: ~QueueVector(){
	if (data)
		delete[data];
	data = nullptr;
}



