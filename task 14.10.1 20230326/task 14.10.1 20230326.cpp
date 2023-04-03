// task 14.10.1 20230326.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h> // for _getch()
#include "Book.h"

int main()
{
    std::string word;
    std::vector<std::string> suffixes;

    Book vocabulary;
    vocabulary.insert("air");
    vocabulary.insert("boy");
    vocabulary.insert("cat");
    vocabulary.insert("cab");
    vocabulary.insert("car");
    vocabulary.insert("cast");
    vocabulary.insert("caught");
    vocabulary.insert("cow");
    vocabulary.insert("cage");
    vocabulary.insert("cake");
    vocabulary.insert("calulate");
    vocabulary.insert("call");
    vocabulary.insert("calm");
    vocabulary.insert("can");
    vocabulary.insert("cancel");
    vocabulary.insert("candy");
    vocabulary.insert("cap");
    vocabulary.insert("capacity");
    vocabulary.insert("capital");
    vocabulary.insert("captain"); 
    vocabulary.insert("cast");
    vocabulary.insert("card");
    vocabulary.insert("care");
    vocabulary.insert("case");
    vocabulary.insert("cash");
    vocabulary.insert("catch");
    vocabulary.insert("castle");
    vocabulary.insert("cell");
    vocabulary.insert("chair");
    vocabulary.insert("change");
    vocabulary.insert("chat");
    vocabulary.insert("circle");
    vocabulary.insert("city");
    vocabulary.insert("class");
    vocabulary.insert("click");
    vocabulary.insert("close");
    vocabulary.insert("code");
    vocabulary.insert("color");
    vocabulary.insert("column");
    vocabulary.insert("coin");
    vocabulary.insert("comfort");
    vocabulary.insert("commit");
    vocabulary.insert("crash");
    vocabulary.insert("crazy");
    
    //vocabulary.print();
    //std::cout << vocabulary.remove("boy") << '\n';
    //vocabulary.print();
    //std::cout << vocabulary.remove("boys") << '\n';
    //std::cout << vocabulary.remove("cow") << '\n';
    //vocabulary.print();

    
    vocabulary.find("cap", suffixes);
    for (auto it : suffixes)
    {
        std::cout << it << ' ';
    }
    std::cout << '\n';


    char ch = 'X';
    std::cin.clear();
    while (ch != '+')
    {
        ch = _getch();
        std::cout << ch;
        word.push_back(ch);
    }
    vocabulary.find(word, suffixes);
    std::cout << char(0x08);

    int counter = 0;
    std::cout << suffixes[counter];
    ++counter;
    if (counter == suffixes.size()) counter = 0;
    while (_getch())
    {
        std::cout << suffixes[counter];
        ++counter;
        if (counter == suffixes.size()) counter = 0;
    }

    /*while (true)
    {
        std::cout << "Type first letters of word and press button '+' for promt.\nTry press '+' again and again.";
    }*/



    return 0;
}