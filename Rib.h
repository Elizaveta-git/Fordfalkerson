#pragma once;
#include <iostream>
#include "Node.h"
using namespace std;

class Rib
{
public:
	string From;
	string To;
	int weight;
	Rib* next;
	bool ToVertexProcessed;//if vertex processed - true, else -false
	Rib(string From = "", string To = "",int weight = 0,Rib* next=NULL)
	{
		this->From = From;
		this->To = To;
		this->weight = weight;
		this->next = next;
		ToVertexProcessed = false;
	}
};

class RibList
{
	Rib* head;
	Rib* tail;
	int Size;
public:
	RibList()
	{
		tail = head = NULL;
		Size = 0;
	}
	void push_back(string From, string To, int weight)
	{
		Rib* current = new Rib(From, To, weight);
		if (head == NULL)
		{
			tail = head = current;
			current->next = NULL;
		}
		else
		{
			tail->next = current;
			tail = current;
		}
		Size++;
	}
	bool IsCheckedVertex(string To, Node* Head)
	{
		Node* current = Head;
		while (current != NULL)
		{
			if (current->vertex == To)
				return true;
			current = current->next;
		}
		return false;
	}
	int minRibOfPath()//edge with minimum weight in the found path to the drain
	{
		int min = INT_MAX;
		Rib* current = head;
		while (current != NULL)
		{
			if (current->ToVertexProcessed == true)
			{
				if (current->weight < min)
					min = current->weight;
			}
			current = current->next;
		}
		return min;
	}
	Rib* reverseDirection(string To, string From)
	{
		Rib* current = head;
		while (current != NULL)
		{
			if ((current->To == To) && (current->From == From))
				break;
			current = current->next;
		}
		return current;
	}
	void newWeightOfRibs(int newweight)//change edge weight
	{
		Rib* current = head;
		while (current != NULL)
		{
			if ((current->ToVertexProcessed == true))
			{
				Rib* reverseEdge = reverseDirection(current->From, current->To);
				reverseEdge->weight += newweight;
				current->weight = current->weight - newweight;
			}
			current = current->next;
		}
	}
	void makeRibsUncheked()
	{
		Rib* current = head;
		while (current != NULL)
		{
			current->ToVertexProcessed = false;
			current = current->next;
		}
 	}
	Rib* MaxRibFromVertex(string from, Node* Head)//rib with maximum weight
	{
		Rib* current = head;
		Rib* SearchMaxTo = NULL;
		int min = -1;

		for (int i = 0; i < Size; i++)
		{
			if (current->From == from)
			{
				if (current->weight > min && (IsCheckedVertex(current->To, Head) == false))
				{
					min = current->weight;
					SearchMaxTo = current;
				}
			}
			current = current->next;
		}
		return SearchMaxTo;
	}

	~RibList()
	{
		Rib* current = head;
		while (current != tail)
		{
			Rib* sup = current->next;
			delete current;
			current = sup;
		}
		delete tail;
		Size = 0;
	}
};
