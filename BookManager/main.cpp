// main.cpp
// Programa de prueba para la clase Book.
// Contiene: pruebas iniciales con tres instancias y demostración de sortBooks().

#include <iostream>
#include <algorithm> // requerido por std::sort 
#include <cstddef>   // requerido por std::size_t
#include "Book.h"

// Ordena un arreglo de Book por ISBN en orden ascendente usando std::sort y una lambda.
// Parámetros:
// - arr: arreglo de Book
// - size: cantidad de elementos en el arreglo
void sortBooks(Book arr[], std::size_t size)
{
    std::sort(arr, arr + size, [](const Book& a, const Book& b) {
        return a.getISBN() < b.getISBN();
    });
}

int main()
{
    // --- Prueba original: tres instancias (una correcta y dos "incorrectas") ---
    // Instancia correcta
    Book good;
    good.setBookDetails("Cien años de soledad", "Gabriel García Márquez", "978-0307474728");

    // Instancia con título vacío (incorrecta)
    Book missingTitle;
    missingTitle.setBookDetails("", "Autor Desconocido", "111-1111111111");

    // Instancia no disponible y sin ISBN (incorrecta)
    Book unavailable;
    unavailable.setBookDetails("Libro sin ISBN", "Autor X", "", false);

    Book books[3] = { good, missingTitle, unavailable };

    std::cout << "=== Prueba inicial: 3 instancias ===\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "---- Libro " << (i + 1) << " ----\n";
        books[i].displayBookDetails();
        std::cout << "Disponible: " << (books[i].isAvailable() ? "Sí" : "No") << '\n';

        if (books[i].isAvailable()) {
            std::cout << "Intentando tomar prestado:\n";
            books[i].borrowBook();
        } else {
            std::cout << "No se puede tomar prestado (no disponible)\n";
        }
        std::cout << '\n';
    }

    // --- Demostración de sortBooks(): tres arreglos de 3 libros cada uno ---
    // Arreglo en orden ascendente (por ISBN)
    Book asc[3];
    asc[0].setBookDetails("A", "Autor A", "111-000", true);
    asc[1].setBookDetails("B", "Autor B", "222-000", true);
    asc[2].setBookDetails("C", "Autor C", "333-000", true);                             

    // Arreglo en orden descendente (por ISBN)
    Book desc[3];
    desc[0].setBookDetails("X", "Autor X", "999-000", true);
    desc[1].setBookDetails("Y", "Autor Y", "555-000", true);
    desc[2].setBookDetails("Z", "Autor Z", "111-000", true);

    // Arreglo mezclado
    Book mixed[3];
    mixed[0].setBookDetails("M1", "Autor M1", "300-000", true);
    mixed[1].setBookDetails("M2", "Autor M2", "100-000", true);
    mixed[2].setBookDetails("M3", "Autor M3", "200-000", true);

    // Ordenar y mostrar cada arreglo
    sortBooks(asc, 3);
    std::cout << "=== Ascendente (ordenado por ISBN) ===\n";
    for (int i = 0; i < 3; ++i) {
        asc[i].displayBookDetails();
        std::cout << '\n';
    }

    sortBooks(desc, 3);
    std::cout << "=== Descendente (ordenado por ISBN ascendente) ===\n";
    for (int i = 0; i < 3; ++i) {
        desc[i].displayBookDetails();
        std::cout << '\n';
    }

    sortBooks(mixed, 3);
    std::cout << "=== Mezclado (ordenado por ISBN) ===\n";
    for (int i = 0; i < 3; ++i) {
        mixed[i].displayBookDetails();
        std::cout << '\n';
    }

    return 0;
}