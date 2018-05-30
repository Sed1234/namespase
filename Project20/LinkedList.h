#pragma once
#include "ElementOfLinkedList.h"
#include <vector>
#include <ostream>

using el_linked::ElementOfLinkedList;
template <typename type>
class LinkedList
{
	ElementOfLinkedList<type> * head;
public:
	LinkedList()
	{
		head = nullptr;
	}
	void swap(size_t & first, size_t & second)
	{
		ElementOfLinkedList<type> * first_temp = head, *second_temp = head;
		while (first > 0)
		{
			first_temp = first_temp->next;
			first--;
		}
		while (second > 0)
		{
			second_temp = second_temp->next;
			second--;
		}
		type temp = first_temp->value;
		first_temp->value = second_temp->value;
		second_temp->value = temp;
	}
	std::vector<size_t> searchByValue(const type & value) const
	{
		std::vector<size_t> result;
		size_t i = 0;
		for (
			ElementOfLinkedList<type> * temp = head;
			temp != nullptr;
			temp = temp->next)
		{
			if (temp->value == value)
			{
				result.push_back(i);
			}
			++i;
		}
		return result;
	}
	type & operator [](size_t & position) const {
		ElementOfLinkedList<type> * result = head;
		while (position > 0)
		{
			result = result->next;
			position--;
		}
		return result->value;
	}
	void addToTail(const type & value)
	{
		if (head == nullptr)
		{
			head = new ElementOfLinkedList<type>(value);
		}
		else
		{
			ElementOfLinkedList<type> * temp = head;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = new ElementOfLinkedList<type>(value);
		}
	}
	void deleteByValue(const type & value)
	{
		if (head != nullptr)
		{
			ElementOfLinkedList<type> * temp = head;
			if (head->value == value)
			{
				head = head->next;
			}
			else
			{
				while (temp->next != nullptr)
				{
					if (temp->next->value == value)
					{
						temp->next = temp->next->next;
					}
					temp = temp->next;
				}
			}
		}
	}
	friend std::ostream & operator << (std::ostream & stream, LinkedList<type> & list)
	{
		if (list.head != nullptr)
		{
			ElementOfLinkedList<type> * temp = list.head;
			while (temp != nullptr)
			{
				stream << temp->value << std::endl;
				temp = temp->next;
			}
		}
		return stream;
	}
	~LinkedList()
	{
		delete head;
	}
};

