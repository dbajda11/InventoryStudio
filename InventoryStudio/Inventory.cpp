#include "Inventory.h"

#include <iostream>
#include <limits>

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

	cout << "\nPodaj nazwe produktu: ";
	cin >> product.name;

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
	}

	for (const Product& product : products)
	{
		cout << "\nID: " << product.id << '\n';
		cout << "Nazwa: " << product.name << '\n';
		cout << "Cena: " << product.price << " zl\n";
		cout << "Ilosc: " << product.quantity << '\n';
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