#include "Wordcollection.hpp"
#include <algorithm>

 WordCollection collection;
 std::vector<Word> WordCollection::getWords() const {
    return words;
 }
    

// Функтор для порівняння двох об'єктів Word за алфавітом
struct WordComparator {
    bool operator()(const Word& a, const Word& b) {
        return a.getWord() < b.getWord();
    }
};

void WordCollection::addWord(const Word& word) {
    words.push_back(word);
}

std::vector<Word> WordCollection::getWordsWithPagesGreaterThan(int n) const {
    std::vector<Word> result;
    for (const Word& word : words) {
        if (word.getPages().size() > n) {
            result.push_back(word);
        }
    }
    return result;
}

void WordCollection::sortAlphabetically() {
    WordComparator comparator;
    std::sort(words.begin(), words.end(), comparator);
}

std::vector<int> WordCollection::getPagesForWord(const std::string& targetWord) const {
    for (const Word& word : words) {
        if (word.getWord() == targetWord) {
            return word.getPages();
        }
    }
    return std::vector<int>(); // Повертаємо порожній вектор, якщо слово не знайдено
}

void WordCollection::showAllWords() const {
    for (const Word& word : words) {
        word.show();
    }
}
