#include "Inventory.h"

#include <iostream>
#include <limits>
#include <algorithm>
#include <cctype>

using namespace std;


void Inventory::displayProduct(const Product& product) const
{
	cout << "\nID: " << product.id << '\n';
	cout << "Nazwa: " << product.name << '\n';
	cout << "Marka: " << product.brand << '\n';
	cout << "Kategoria: " << product.category << '\n';
	cout << "Kod EAN: " << product.barcode << '\n';
	cout << "Cena: " << product.price << " zl\n";
	cout << "Ilosc: " << product.quantity << '\n';
}

void Inventory::addProduct()
{
	Product product{};

	cout << "---- Dodawanie produktu ----";

	cout << "\nPodaj id produktu: ";
	cin >> product.id;

	if (productIdExists(product.id))
	{
		cout << "Produkt o takim ID juz istnieje.\n";
		return;
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "\nPodaj nazwe produktu: ";
	cin >> product.name;

	cout << "\nPodaj marke produktu: ";
	cin >> product.brand;

	cout << "\nPodaj kategorie produktu: ";
	cin >> product.category;

	cout << "\nPodaj kod kreskowy/EAN produktu: ";
	cin >> product.barcode;

	cout << "\nPodaj cene produktu: ";
	cin >> product.price;

	cout << "\nPodaj ilosc produktu: ";
	cin >> product.quantity;

	products.push_back(product);

	cout << "\n Produkt zostal dodany.\n";
}

void Inventory::showProducts() const
{
	cout << "\n--- Lista produktow ---\n";

	if (products.empty())
	{
		cout << "Magazyn jest pusty";
		return;
	}

	for (const Product& product : products)
	{
		displayProduct(product);
	}

}

bool Inventory::productIdExists(int id) const
{
	for (const Product& product : products)
	{
		if (product.id == id)
		{
			return true;
		}
	}
	return false;
}

void Inventory::searchProduct() const
{
	string searchValue;

	cout << "\n--- Wyszukaj produkt ---\n";

	if (products.empty())
	{
		cout << "Magazyn jest pusty";
		return;
	}

	cout << "Podaj ID lub nazwe produktu: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, searchValue);

	bool isNumber = !searchValue.empty() && all_of(searchValue.begin(), searchValue.end(), [](char c)
			{
				return isdigit(static_cast<unsigned char>(c));
			});

	if (isNumber)
	{
		int searchId = stoi(searchValue);
		for (const Product& product : products)
		{
			if (product.id == searchId)
			{
				cout << "Znaleziono produkt.\n\n";
				displayProduct(product);

				return;
			}
		}
	}
	else
	{
		for (const Product& product : products)
		{
			if (product.name == searchValue)
			{
				cout << "Znaleziono produkt.\n\n";
				displayProduct(product);

				return;
			}
		}
	}

	cout << "Nie znaleziono produktu o ID = " << searchValue;
}

void Inventory::editProduct()
{
	int searchValue;
	string choiceToContinue;
	int choiceValueToChange;

	if (products.empty())
	{
		cout << "Magazyn jest pusty.\n";
		return;
	}

	cout << "Podaj ID produktu, ktory chcesz edytowac: ";
	cin >> searchValue;

	for (Product& product : products)
	{
		if (product.id == searchValue)
		{
			displayProduct(product);

			do
			{
				cout << "\nCo chcesz zmienic?\n";
				cout << "1. ID\n";
				cout << "2. Nazwe\n";
				cout << "3. Marke\n";
				cout << "4. Kategorie\n";
				cout << "5. Kod kreskowy/EAN\n";
				cout << "6. Cene\n";
				cout << "7. Ilosc\n";

				cout << "Wybor: ";
				cin >> choiceValueToChange;

				switch (choiceValueToChange)
				{
				case 1:
				{
					int newId;

					cout << "Podaj nowe ID: ";
					cin >> newId;

					product.id = newId;
					break;
				}

				case 2:
				{
					string newName;

					cout << "Podaj nowa nazwe: ";
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					getline(cin, newName);

					product.name = newName;
					break;
				}

				case 3:
				{
					string newBrand;

					cout << "Podaj nowa marke: ";
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					getline(cin, newBrand);

					product.brand = newBrand;
					break;
				}

				case 4:
				{
					string newCategory;

					cout << "Podaj nowa katogarie: ";
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					getline(cin, newCategory);

					product.category = newCategory;
					break;
				}

				case 5:
				{
					string newBarcode;

					cout << "Podaj nowy kod kreskowy/EAN: ";
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					getline(cin, newBarcode);

					product.barcode = newBarcode;
					break;
				}

				case 6:
				{
					double newPrice;

					cout << "Podaj nowa cene: ";
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cin >> newPrice;

					product.price = newPrice;
					break;
				}

				case 7:
				{
					int newQuantity;

					cout << "Podaj nowa ilosc: ";
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cin >> newQuantity;

					product.quantity = newQuantity;
					break;
				}

				default:
					cout << "Nieprawidlowy wybor.\n";
				}

				cout << "Czy chcesz zmienic kolejne pole? tak/nie: ";
				cin >> choiceToContinue;

			} while (choiceToContinue != "nie");

			cout << "Produkt zostal zaktualizowany.\n";

			cout << "\nAktualne dane produktu:\n";
			displayProduct(product);
			return;
		}
	}

	cout << "Nie znaleziono produktu o ID = " << searchValue << "\n";
}

void Inventory::deleteProduct()
{
	int searchValue;
	string choiceToDelete;

	if (products.empty())
	{
		cout << "Magazyn jest pusty\n";
		return;
	}

	cout << "Podaj ID produktu, ktory chcesz usunac: ";
	cin >> searchValue;

	for (auto it = products.begin(); it != products.end(); ++it)
	{
		if (it->id == searchValue)
		{
			cout << "\nAktualne dane produktu:\n";
			displayProduct(*it);

			cout << "\nCzy napewno chcesz usunac produkt? (tak/nie)";
			cin >> choiceToDelete;

			if (choiceToDelete == "tak")
			{
				products.erase(it);
				cout << "Produkt zostal usuniety.\n";
				return;
			}
			else
			{
				return;
			}
		}
	}
	cout << "Nie znaleziono produktu o ID = " << searchValue << "\n";
}