// Book.cpp
// Implementación de los métodos de la clase Book definidos en Book.h.

#include "Book.h"
#include <iostream>

// Constructor por defecto
Book::Book()
    : title{}, author{}, isbn{}, availability{true}
{
}

// setBookDetails: versión con 3 parámetros
void Book::setBookDetails(const std::string& title, const std::string& author, const std::string& isbn)
{
    // Delegar a la versión de 4 parámetros usando disponibilidad por defecto = true
    setBookDetails(title, author, isbn, true);
}

// setBookDetails: versión con 4 parámetros
void Book::setBookDetails(const std::string& title, const std::string& author, const std::string& isbn, bool available)
{
    this->title = title;
    this->author = author;
    this->isbn = isbn;
    this->availability = available;
}

std::string Book::getISBN() const
{
    return isbn;
}

bool Book::isAvailable() const
{
    return availability;
}

void Book::displayBookDetails() const
{
    std::cout << "Title: " << title << '\n'
              << "Author: " << author << '\n'
              << "ISBN: " << isbn << '\n'
              << "Availability: " << (availability ? "Available" : "Not available") << '\n';
}

bool Book::borrowBook()
{
    if (!availability) {
        std::cout << "Cannot borrow. The book is already borrowed.\n";
        return false;
    }
    availability = false;
    std::cout << "Book borrowed successfully.\n";
    return true;
}