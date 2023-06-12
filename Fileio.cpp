#include "Fileio.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

bool readDataFromFile(const std::string& filename, WordCollection& collection) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Failed to open file: " << filename << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::string word;
        std::vector<int> pages;

        std::istringstream iss(line);
        iss >> word;

        int page;
        while (iss >> page) {
            pages.push_back(page);
        }

        Word newWord(word, pages);
        collection.addWord(newWord);
    }

    file.close();
    return true;
}

bool writeDataToFile(const std::string& filename, const WordCollection& collection) {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "Failed to create file: " << filename << std::endl;
        return false;
    }

    const std::vector<Word>& words = collection.getWords(); // Звернення до приватного члена words в класі WordCollection

    for (const Word& word : words) {
        file << word.getWord() << " - " << word.getPages().size() << " стор." << std::endl;
    }

    file.close();
    return true;
}
