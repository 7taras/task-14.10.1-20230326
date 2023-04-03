// task 14.10.1 20230326.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Book.h"

int main()
{
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

    std::vector<std::string> temp;
    vocabulary.find("cap", temp);
    for (auto it : temp)
    {
        std::cout << it << ' ';
    }
    std::cout << '\n';

    /*while (true)
    {
        std::cout << "Type first letters of word and press button '+'";
    }*/



    return 0;
}