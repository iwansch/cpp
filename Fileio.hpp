#ifndef FILEIO_HPP
#define FILEIO_HPP

#include <string>
#include "Wordcollection.hpp"

bool readDataFromFile(const std::string& filename, WordCollection& collection);
bool writeDataToFile(const std::string& filename, const WordCollection& collection);

#endif
