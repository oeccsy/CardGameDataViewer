#pragma once
#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

template<typename T>
class Vector
{
public:
	Vector() : size(0), capacity(2)
	{
		data = new T[capacity];
	}

	// 반환하는 지역변수 result의 이중 해제 문제를 막기 위한 복사 생성자
	Vector(const Vector& other) : size(other.size), capacity(other.capacity)
	{
		data = new T[capacity];

		for (int i = 0; i < size; ++i)
		{
			data[i] = other.data[i];
		}
	}

	// Vector<Card*> 임시객체에서 누수 발생?
	~Vector()
	{
		if (data) delete[] data;
	}

	void PushBack(const T& value)
	{
		if (size == capacity) ReAllocate(capacity * 2);

		data[size] = value;
		++size;
	}

	void EmplaceBack(T&& value)
	{
		if (size == capacity) ReAllocate(capacity * 2);

		data[size] = std::move(value);
		++size;
	}

	// 임시 객체의 포인터 주소를 얕은 복사 하는 경우 댕글링 문제가 발생 -> 이를 방지하기 위한 대입 연산자
	Vector& operator=(const Vector& other)
	{
		if (this != &other)
		{
			if(data) delete[] data;

			size = other.size;
			capacity = other.capacity;
			data = new T[capacity];

			for (int i = 0; i < size; ++i)
			{
				data[i] = other.data[i];
			}
		}

		return *this;
	}

	T& operator[](int index) { return data[index]; }
	const T& operator[](int index) const { return data[index]; }
	T& At(int index) { return data[index]; }

	void Set(int index, const T& value) { data[index] = value; }

	T* Begin() { return data; }
	T* End() { return data + size; }

	bool Empty() const { return (size == 0); }

	int Size() const { return size; }
	int Capacity() const { return capacity; }

private:
	void ReAllocate(int newCapacity)
	{
		T* newBlock = new T[newCapacity];
		
		for (int i = 0; i < size; ++i)
		{
			newBlock[i] = std::move(data[i]);
		}

		delete[] data;
		data = newBlock;
		capacity = newCapacity;
	}

private:
	T* data = nullptr;

	int size = 0;
	int capacity = 0;
};