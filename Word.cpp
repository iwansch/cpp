#include "Word.hpp"
#include <iostream>

Word::Word(const std::string& w, const std::vector<int>& p) : word(w), pages(p) {}

std::string Word::getWord() const {
    return word;
}

std::vector<int> Word::getPages() const {
    return pages;
}

void Word::show() const {
    std::cout <<  word << std::endl;
    std::cout << std::endl;
}