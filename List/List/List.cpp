#include "List.h"

List& List::push_back(int value)
{
	if (head == nullptr)
	{
		head = new Node;
		head->data = value;
	}
	else
	{
		Node* iter = head;
		while (iter->ptr != nullptr)
			iter = iter->ptr;

		Node* new_node = new Node;
		new_node->data = value;
		iter->ptr = new_node;
	}
	++length;
	return *this;
}

List& List::push_front(int value)
{
	Node* new_head = new Node;
	new_head->data = value;
	new_head->ptr = head;
	head = new_head;
	++length;
	return *this;
}

List& List::insert(int index, int value)
{
	int count = 0;
	Node* iter = head;

	while (count != index)
	{
		iter = iter->ptr;
		++count;
	}
	Node* new_node = new Node;
	new_node->data = value;
	new_node->ptr = iter->ptr;
	iter->ptr = new_node;
	++length;
	return *this;
}

List& List::pop_back()
{
	Node* iter = head;
	while (true)
	{
		if (iter->ptr == nullptr)
		{
			delete iter;
			iter = nullptr;
			--length;
			return *this;
		}

		iter = iter->ptr;
	}

}

List& List::pop_front()
{
	if (head != nullptr)
	{
		Node* new_head = head->ptr;
		delete head;
		head = new_head;
		--length;
	}
	return *this;
}

List& List::removeAt(int index)
{
	int count = 0;
	Node* iter = head;
	Node* temp = nullptr;

	if (index == 0)
		pop_front();
	else
	{
		while (count != index)
		{
			if (count == index - 1)
			{
				temp = iter;
			}
			iter = iter->ptr;
			++count;
		}

		temp->ptr = iter->ptr;
		delete iter;
		--length;
	}
	return *this;
}

List& List::clear()
{
	while (List::length)
		pop_front();
	return *this;
}

int List::operator[](int value)
{
	int count = 0;
	Node* iter = head;

	while (iter != nullptr)
	{
		if (count == value)
			return iter->data;
		iter = iter->ptr;
		++count;
	}
}

List::~List()
{
	clear();
}
