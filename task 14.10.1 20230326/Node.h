#pragma once
#define ALPHABET_SIZE 26

class Node
{
public:
		Node()
		{
		}
		Node(Node* m_parent) : parent{ m_parent }
		{			
		}
private:
	Node* children[ALPHABET_SIZE]{ nullptr };
	Node* parent{ nullptr };
	bool isEndOfWord[26]{ false };

	friend class Book;
};