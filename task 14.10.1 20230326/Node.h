#pragma once
#define ALPHABET_SIZE 26

class Node
{
public:
		Node()
		{
		}
private:
	Node* children[ALPHABET_SIZE]{ nullptr };
	bool isEndOfWord[26]{ false };

	friend class Book;
};

