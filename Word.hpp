#ifndef WORD_HPP
#define WORD_HPP

#include <string>
#include <vector>

class Word {
private:
    std::string word;
    std::vector<int> pages;

public:
    Word(const std::string& w, const std::vector<int>& p);

    std::string getWord() const;
    std::vector<int> getPages() const;
    void show() const;
};

#endif
