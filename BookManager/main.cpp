#include "Library.h"
#include <iostream>

int main() {
    Library library;
    library.initSampleBooks();

    std::cout << "=== Sistema de gestión de biblioteca ===\n";
    std::cout << "Libros cargados correctamente.\n\n";

    library.displayAllBooks();

    std::string isbn;
    std::cout << "\nIngrese el ISBN del libro que desea pedir prestado: ";
    std::getline(std::cin, isbn);

    library.borrowByISBN(isbn);

    std::cout << "\nEstado actualizado de los libros:\n";
    library.displayAllBooks();

    std::cout << "\nFin del programa.\n";
    return 0;
}
