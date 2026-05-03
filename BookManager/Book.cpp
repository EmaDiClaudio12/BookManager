#include "Book.h"

Book::Book() {
    title = "";
    author = "";
    isbn = "";
    available = true;
}

void Book::setBookDetails(const std::string& t, const std::string& a, const std::string& i, bool avail) {
    title = t;
    author = a;
    isbn = i;
    available = avail;
}

void Book::displayBookDetails() const {
    std::cout << "Título: " << title << "\n";
    std::cout << "Autor: " << author << "\n";
    std::cout << "ISBN: " << isbn << "\n";
    std::cout << "Disponible: " << (available ? "Sí" : "No") << "\n";
}

bool Book::isAvailable() const {
    return available;
}

std::string Book::getISBN() const {
    return isbn;
}

void Book::borrowBook() {
    if (available) {
        available = false;
        std::cout << "Libro prestado correctamente.\n";
    }
    else {
        std::cout << "El libro ya está prestado.\n";
    }
}

void Book::returnBook() {
    available = true;
}
