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

    char ch = 'X';
    int counter = 0;
    int lettersCounter = 0;
    bool plusFlag = true;
    std::cin.clear();

    std::cout << "Type first letters of word and press button '+' for promt.\npress '+' to next word, again and again.\nPress 'ENTER' to new type.\nPress 'ESC' to exit.\n\n";

    while (true)
    {
        ch = _getch();
        if ((ch >= '!' && ch <= '*') || (ch >= ',' && ch <= '~'))
        {
            std::cout << ch;
            word.push_back(ch);
            plusFlag = true;            
        }
        if (ch == '+')
        {
            if (plusFlag)
            {
                suffixes.clear();
                vocabulary.find(word, suffixes);
                if (suffixes.size() > 0)
                {
                    std::cout << suffixes[counter];
                    lettersCounter = suffixes[counter].size();
                    ++counter;
                    plusFlag = false;                    
                }
            }
            else
            {
                for (int i = 0; i < lettersCounter; ++i)
                {
                    std::cout << char(0x08);                    
                }
                for (int i = 0; i < 10; ++i)
                {
                    std::cout << ' ';
                }
                for (int i = 0; i < 10; ++i)
                {
                    std::cout << char(0x08);
                }
                std::cout << suffixes[counter];
                lettersCounter = suffixes[counter].size();
                ++counter;
            }
            
            if (counter == suffixes.size()) counter = 0;
        }
        if (ch == 0x0D)
        {
            std::cout << '\n';
            word.clear();
            counter = 0;
        }
        if (ch == 0x1B) break;
    }

    return 0;
}