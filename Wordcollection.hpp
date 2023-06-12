#ifndef WORDCOLLECTION_HPP
#define WORDCOLLECTION_HPP

#include "Word.hpp"
#include <vector>

class WordCollection {
private:
    std::vector<Word> words;

public:
    void addWord(const Word& word);
    std::vector<Word> getWordsWithPagesGreaterThan(int n) const;
    void sortAlphabetically();
    std::vector<int> getPagesForWord(const std::string& targetWord) const;
    void showAllWords() const;
    std::vector<Word> getWords() const; // Добавленное определение
};

#endif
