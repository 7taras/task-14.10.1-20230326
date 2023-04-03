#include "Book.h"

Node* Book::createNewNode(Node* parent)
{
    Node* pNode = new Node(parent);
    return pNode;
}

void Book::insert(const std::string& key)
{
    std::string mkey;
    for (int i = 0; i < key.size(); ++i)
    {
        if (key[i] >= 'a' && key[i] <= 'z') mkey.push_back(key[i]);
        if (key[i] >= 'A' && key[i] <= 'Z') mkey.push_back(key[i] + 32);
    }

    if (mkey.size() <= 1) return;
    if (mkey.size() == 2)
    {
        pRoot->isEndOfWord[mkey[1] - 'a'] = true;
        return;
    }

    Node* tempNode = pRoot;
    for (int i = 0; i < (mkey.length() - 1); i++)
    {
        int index = mkey[i] - 'a';
        if (tempNode->children[index] == nullptr)
        {
            tempNode->children[index] = createNewNode(tempNode);
        }
        tempNode = tempNode->children[index];
    }
    tempNode->isEndOfWord[mkey[(mkey.length() - 1)] - 'a'] = true;
}

bool Book::remove(const std::string& key)
{       
    std::string mkey;
    for (int i = 0; i < key.size(); ++i)
    {
        if (key[i] >= 'a' && key[i] <= 'z') mkey.push_back(key[i]);
        if (key[i] >= 'A' && key[i] <= 'Z') mkey.push_back(key[i] + 32);
    }
    
    if (mkey.size() <= 1) return false;
    if (mkey.size() == 2)
    {
        pRoot->isEndOfWord[mkey[1] - 'a'] = false;
        return true;
    }

    Node* tempNode = pRoot;
    for (int i = 0; i < (mkey.length() - 1); i++)
    {
        int index = mkey[i] - 'a';
        if (tempNode->children[index] == nullptr) return false;
        tempNode = tempNode->children[index];
    }
    if (tempNode->isEndOfWord[mkey[(mkey.length() - 1)] - 'a'] == false) return false;
    else
    {
        tempNode->isEndOfWord[mkey[(mkey.length() - 1)] - 'a'] = false;
    }

    if (tempNode->children[mkey[(mkey.length() - 1)] - 'a'] != nullptr) return true;
    else
    {
        subremove(tempNode, mkey);
        return true;
    }
}

void Book::subremove(Node* root, std::string& mkey)
{
    for (int i = 0; i < ALPHABET_SIZE; ++i)
    {
        if (root->isEndOfWord[i] == true) return;
        if (root->children[i] != nullptr) return;
    }
    Node* temp = root->parent;
    temp->children[mkey[(mkey.length() - 2)] - 'a'] = nullptr;
    delete root;
    mkey.pop_back();
    subremove(temp, mkey);
    return;
}

bool Book::find(const std::string& key, std::vector<std::string>& passedWords)
{
    passedWords.clear();
    std::string mkey;
    for (int i = 0; i < key.size(); ++i)
    {
        if (key[i] >= 'a' && key[i] <= 'z') mkey.push_back(key[i]);
        if (key[i] >= 'A' && key[i] <= 'Z') mkey.push_back(key[i] + 32);
    }

    Node* head = pRoot;
    for (int i = 0; i < mkey.size(); ++i)
    {
        if (head->children[mkey[i] - 'a'] == nullptr) return false;
        else
        {
            head = head->children[mkey[i] - 'a'];
        }        
    }

    std::string word;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (head->isEndOfWord[i] == true)
        {
            word.push_back(char(i + 'a'));
            passedWords.push_back(word);
            word.pop_back();
        }
        if (head->children[i] != nullptr)
        {
            word.push_back(char(i + 'a'));
            subfind(head->children[i], word, passedWords);
        }
    }
    return true;
}

void Book::subfind(Node* root, std::string& word, std::vector<std::string>& passedWords)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->isEndOfWord[i] == true)
        {
            word.push_back(char(i + 'a'));
            passedWords.push_back(word);
            word.pop_back();
        }
        if (root->children[i] != nullptr)
        {
            word.push_back(char(i + 'a'));
            subfind(root->children[i], word, passedWords);
        }
    }
    word.pop_back();
}

void Book::print()
{
    std::string word;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (pRoot->isEndOfWord[i] == true)
        {
            word.push_back(char(i + 'a'));
            std::cout << word << ' ';
            word.pop_back();
        }
        if (pRoot->children[i] != nullptr)
        {
            word.push_back(char(i + 'a'));
            subprint(pRoot->children[i], word);
        }
    }
    std::cout << '\n';
}

void Book::subprint(Node* root, std::string& word)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->isEndOfWord[i] == true)
        {
            word.push_back(char(i + 'a'));
            std::cout << word << ' ';
            word.pop_back();
        }
        if (root->children[i] != nullptr)
        {
            word.push_back(char(i + 'a'));
            subprint(root->children[i], word);
        }
    }
    word.pop_back();
}