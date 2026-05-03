#pragma once
#include <string>
#include <iostream>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;
    bool available;

public:
    Book();

    void setBookDetails(const std::string& t, const std::string& a, const std::string& i, bool avail);

    void displayBookDetails() const;

    bool isAvailable() const;

    std::string getISBN() const;

    void borrowBook();

    void returnBook();
};
