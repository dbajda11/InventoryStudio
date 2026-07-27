#include <iostream>
#include "Inventory.h"

void showMenu()
{
    std::cout << "\n=========================\n";
    std::cout << "     INVENTORY STUDIO\n";
    std::cout << "=========================\n";
    std::cout << "1. Dodaj produkt\n";
    std::cout << "2. Wyswietl produkty\n";
    std::cout << "3. Wyszukaj produkt\n";
    std::cout << "4. Edytuj produkt\n";
    std::cout << "5. Usun produkt\n";
    std::cout << "0. Zakoncz program\n";
    std::cout << "Wybor: ";
}

using namespace std;

int main()
{
    Inventory inventory;
    int choice = -1;

    do
    {
        showMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            inventory.addProduct();
            break;

        case 2:
            inventory.showProducts();
            break;

        case 3:
            inventory.searchProduct();
            break;
        case 4:
            inventory.editProduct();
            break;
        case 5:
            inventory.deleteProduct();
            break;

        case 0:
            cout << "Zamykanie programu...\n";
            break;

        default:
            cout << "Nieprawidlowa opcja.\n";
            break;
        }

    } while (choice != 0);

    return 0;
}