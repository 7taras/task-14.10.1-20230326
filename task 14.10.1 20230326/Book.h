#pragma once
#include <iostream>
#include "Node.h"

class Book
{
public:
	Book()
	{

	}
	~Book()
	{
		delete pRoot;
	}

	Node* createNewNode();
	void insert(const std::string& key);

private:
	Node* pRoot = new Node;
};

