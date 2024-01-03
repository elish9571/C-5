#pragma once
template <class T>
class Queue
{
	virtual ~Queue();
	virtual void clear() = 0;
	virtual void enqueue(T value);
	virtual T dequeue() = 0;
	virtual T front() const = 0;
	virtual bool isEmpty()const = 0;
};

