#pragma once
#include "Book.h"
#include <string>
#include <iostream>

class Library {
private:
    Book books[5];

public:
    void initSampleBooks();
    void displayAllBooks() const;
    void borrowByISBN(const std::string& isbn);
};