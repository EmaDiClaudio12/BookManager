// BookManager.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;
    bool availability;

public:
    // Constructor por defecto
    Book()
        : title{}, author{}, isbn{}, availability{true}
    {
    }

    // Asigna los detalles del libro
    void setBookDetails(const std::string& t, const std::string& a, const std::string& i, bool available = true)
    {
        title = t;
        author = a;
        isbn = i;
        availability = available;
    }

    // Getters solicitados
    std::string getISBN() const
    {
        return isbn;
    }

    bool isAvailable() const
    {
        return availability;
    }

    // Muestra los detalles del libro
    void displayBookDetails() const
    {
        std::cout << "Title: " << title << '\n'
                  << "Author: " << author << '\n'
                  << "ISBN: " << isbn << '\n'
                  << "Availability: " << (availability ? "Available" : "Not available") << '\n';
    }

    // Intenta tomar prestado el libro; devuelve true si se pudo prestar
    bool borrowBook()
    {
        if (!availability) {
            std::cout << "Cannot borrow. The book is already borrowed.\n";
            return false;
        }
        availability = false;
        std::cout << "Book borrowed successfully.\n";
        return true;
    }

    // Devuelve el libro; devuelve true si la operación cambió el estado
    bool returnBook()
    {
        if (availability) {
            std::cout << "Return not necessary. The book is already available.\n";
            return false;
        }
        availability = true;
        std::cout << "Book returned successfully.\n";
        return true;
    }
};

int main()
{
    // Crear y inicializar arreglo de 5 libros
    Book books[5];
    books[0].setBookDetails("Cien años de soledad", "Gabriel García Márquez", "978-0307474728");
    books[1].setBookDetails("Don Quijote de la Mancha", "Miguel de Cervantes", "978-8491050278");
    books[2].setBookDetails("La sombra del viento", "Carlos Ruiz Zafón", "978-8408163385");
    books[3].setBookDetails("El amor en los tiempos del cólera", "Gabriel García Márquez", "978-0307389732");
    books[4].setBookDetails("Ficciones", "Jorge Luis Borges", "978-0142437478");

    while (true) {
        std::cout << "Ingrese ISBN (0 para salir): ";
        std::string input;
        if (!(std::cin >> input)) {
            // Entrada inválida o EOF
            break;
        }
        if (input == "0") {
            break;
        }

        bool found = false;
        for (int i = 0; i < 5; ++i) {
            if (books[i].getISBN() == input) {
                found = true;

                books[i].displayBookDetails();

                if (books[i].isAvailable()) {
                    books[i].borrowBook();
                } else {
                    std::cout << "Book unavailable\n";
                }
                break;
            }
        }

        if (!found) {
            std::cout << "Book not found\n";
        }
    }

    return 0;
}

// Ejecutar programa: __Ctrl + F5__ o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración
