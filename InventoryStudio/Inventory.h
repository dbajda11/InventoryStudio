#pragma once

#include <vector>
#include "Product.h"


class Inventory
{
private:
	std::vector<Product> products;
	bool productIdExists(int id) const;
	void displayProduct(const Product& product) const;
	
public:
	void addProduct();
	void showProducts() const;
	void searchProduct() const;
	void editProduct();
};