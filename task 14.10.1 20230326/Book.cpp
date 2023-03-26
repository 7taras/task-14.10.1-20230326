#include "Book.h"

Node* Book::createNewNode()
{
    Node* pNode = new Node;
    //for (int i = 0; i < ALPHABET_SIZE; i++)
    //    pNode->children[i] = nullptr;
    return pNode;
}

void Book::insert(const std::string& key)
{
    std::string mkey;
    for (auto i = 0; i < key.size(); ++i)
    {
        if (key[i] >= 'a' && key[i] <= 'z') mkey.push_back(key[i]);
        if (key[i] >= 'A' && key[i] <= 'Z') mkey.push_back(key[i] + 32);
    }

    if (mkey.size() == 0) return;
    if (mkey.size() == 1)
    {
        pRoot->isEndOfWord[key[0] - 'a'] = true;
        return;
    }
        
    Node* tempNode = pRoot;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';

        if (!tempNode->children[index])
            tempNode->children[index] = createNewNode();

        tempNode = tempNode->children[index];
    }

    // помечаем последний узлел как лист, т.е. конец слова
    tempNode->isEndOfWord = true;
}
//
//// Возврашает true если ключ есть в дереве, иначе false 
//bool search(struct TrieNode* root, string key)
//{
//    struct TrieNode* node = root;
//
//    for (int i = 0; i < key.length(); i++)
//    {
//        int index = key[i] - 'a';
//        if (!node->children[index])
//            return false;
//
//        node = node->children[index];
//    }
//
//    return (node != nullptr && node->isEndOfWord);
//}
//
//// Вохвращает true если root имеет лист, иначе false 
//bool isEmpty(TrieNode* root)
//{
//    for (int i = 0; i < ALPHABET_SIZE; i++)
//        if (root->children[i])
//            return false;
//    return true;
//}
//
//// Рекурсивная функция удаления ключа из дерева 
//TrieNode* remove(TrieNode* root, string key, int depth)
//{
//    // Если дерево пустое 
//    if (!root)
//        return nullptr;
//
//    // если дошли до конца ключа 
//    if (depth == key.size()) {
//
//        // Этот узел больше не конец слова 
//        if (root->isEndOfWord)
//            root->isEndOfWord = false;
//
//        // Если ключ не евляется префиксом, удаляем его
//        if (isEmpty(root)) {
//            delete (root);
//            root = nullptr;
//        }
//
//        return root;
//    }
//
//    // Если не дошли до конца ключа, рекурсивно вызываем для ребенка 
//    // соответствующего символа 
//    int index = key[depth] - 'a';
//    root->children[index] = remove(root->children[index], key, depth + 1);
//
//    // Если у корня нет дочернего слова 
//    // (удален только один его дочерний элемент), 
//    // и он не заканчивается другим словом. 
//    if (isEmpty(root) && root->isEndOfWord == false) {
//        delete (root);
//        root = nullptr;
//    }
//
//    // возвращаем новый корень
//    return root;
//}
//
//void print(TrieNode* root)
//{
//    if (root->isEndOfWord == true) return;
//    string word;
//    for (int i = 0; i < ALPHABET_SIZE; i++)
//    {
//        if (root->children[i] != nullptr)
//        {
//            word.push_back(char(i + 'a'));
//            scan(root->children[i], word);
//        }
//    }
//}
//
//void scan(TrieNode* root, string& word)
//{
//    if (root->isEndOfWord == true)
//    {
//        cout << word << ' ';
//        //word.pop_back();
//    }
//
//    {
//        for (int i = 0; i < ALPHABET_SIZE; i++)
//        {
//            if (root->children[i] != nullptr)
//            {
//                word.push_back(char(i + 'a'));
//                scan(root->children[i], word);
//            }
//        }
//        word.pop_back();
//    }
//}