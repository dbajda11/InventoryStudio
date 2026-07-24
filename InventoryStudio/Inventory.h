#pragma once

#include <vector>
#include "Product.h"

using namespace std;

class Inventory
{
private:
	vector<Product> products;
	bool productIdExists(int id) const;
	
public:
	void addProduct();
	void showProducts() const;
	//const
};