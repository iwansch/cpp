#include "Word.cpp"
#include "Wordcollection.cpp"
#include "Fileio.cpp"
#include <iostream>

int main() {
    if (!readDataFromFile("input.txt", collection)) {
        return 1;
    }

    std::cout << "Слова що зустрічаються більше ніж на N сторінках:" << std::endl;
    std::vector<Word> wordsWithMoreThan3Pages = collection.getWordsWithPagesGreaterThan(3);
    for (const Word& word : wordsWithMoreThan3Pages) {
        word.show();
    }
    std::cout << std::endl;

    std::cout << "Слова у алфавітному порядку:" << std::endl;
    collection.sortAlphabetically();
    collection.showAllWords();
    std::cout << std::endl;

    std::string targetWord = "розетка";
    std::cout << "Сторінки, на якіх зустрічається слово '" << targetWord << "': ";
    std::vector<int> pagesForTargetWord = collection.getPagesForWord(targetWord);
    for (int page : pagesForTargetWord) {
        std::cout << page << " ";
    }
    std::cout << std::endl;

    if (!writeDataToFile("output.bin", collection)) {
        return 1;
    }

    return 0;
}
