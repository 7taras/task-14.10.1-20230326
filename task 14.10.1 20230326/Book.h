#pragma once
#include "Node.h"

class Book
{
public:
	Book()
	{

	}
	~Book()
	{
		delete root;
	}
private:
	Node* root = new Node;
};

