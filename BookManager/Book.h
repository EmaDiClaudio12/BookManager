// Book.h
// Declaración de la clase Book.
// Propósito: definir atributos, constructores y la interfaz pública.

#pragma once

#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;
    bool availability;

public:
    // Constructor por defecto
    Book();

    // Sobrecargas solicitadas para setBookDetails
    void setBookDetails(const std::string& title, const std::string& author, const std::string& isbn);
    void setBookDetails(const std::string& title, const std::string& author, const std::string& isbn, bool available);

    // Accesores
    std::string getISBN() const;
    bool isAvailable() const;

    // Utilidades
    void displayBookDetails() const;
    bool borrowBook();
};