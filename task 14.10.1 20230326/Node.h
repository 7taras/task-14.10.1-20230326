#pragma once
#define ALPHABET_SIZE 26

class Node
{
	Node* children[ALPHABET_SIZE];
	bool isEndOfWord[26];
};

