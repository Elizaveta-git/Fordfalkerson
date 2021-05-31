#pragma once
#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	string vertex;
	int maxDist;
	Node* next;
	Node(string vertex = "", int maxDist = 0, Node* next=NULL)
	{
		this->vertex = vertex;
		this->maxDist = maxDist;
		this->next = next;
	}
};

class NodeList
{
	Node* head;
	Node* tail;
	int size;
public:
	NodeList()
	{
		tail = head = NULL;
		size = 0;
	}
	void push_back(string NodeGraph, int max)
	{
		Node* current = new Node();
		if (head == NULL)
		{
			tail = head = current;
			current->vertex = NodeGraph;
			current->maxDist = max;
		}
		else
		{
			tail->next = current;
			tail = current;
			current->vertex = NodeGraph;
			current->maxDist = max;
		}
		size++;
	}
	void Clear()
	{
		Node* current = head;
		while (current != tail)
		{
			Node* sup = current->next;
			delete current;
			current = sup;
		}
		delete tail;
		tail = head = NULL;
		size = 0;
	}
	Node* Head()
	{
		return head;
	}
	Node* Find(string From)
	{
		Node* current = head;
		while (current->vertex != From)
		{
			current = current->next;
		}
		return current;
	}
	~NodeList()
	{
		if (head != NULL)
		{
			Node* current = head;
			while (current != tail)
			{
				Node* sup = current->next;
				delete current;
				current = sup;
			}
			delete tail;
		}
	}
};
