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