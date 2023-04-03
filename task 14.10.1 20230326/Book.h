#pragma once
#include <iostream>
#include <vector>
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

	Node* createNewNode(Node* parent);
	void insert(const std::string& key);
	bool remove(const std::string& key);
	void print();
	bool find(const std::string& key, std::vector<std::string>& passedWords);

private:
	Node* pRoot = new Node;

	void subprint(Node* root, std::string& word);
	void subremove(Node* root, std::string& mkey);
	void subfind(Node* root, std::string& word, std::vector<std::string>& passedWords);
};

