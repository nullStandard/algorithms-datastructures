#pragma once

class List
{
	class Node
	{
	public:
		int data;
		Node* ptr = nullptr;
	};

	Node* head = nullptr;
	int length = 0;

public:
	int getLength() { return length; }

	List& push_back(int value);

	List& push_front(int value);

	List& insert(int index, int value);

	List& pop_back();

	List& pop_front();

	List& removeAt(int index);

	List& clear();

	int operator[](int value);

	~List();
};


