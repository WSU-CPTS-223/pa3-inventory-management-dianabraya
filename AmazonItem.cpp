/***********************
Diana Raya Sanchez
October 22nd, 2025
Programming Assignment 3
CPTS 223
************************/
#include <iostream>
#include <string>
#include "AmazonItem.hpp"

using namespace std;

//constructor 
AmazonItem::AmazonItem()
{
	Uniq_Id = ""; 
	Product_Name = "";
	Brand_Name = "";
	Asin = "";
	Category = "";
	Upc_Ean_Code = "";
	List_Price = "";
	Selling_Price = "";
	Quantity = "";
	Model_Number = "";
	About_Product = "";
	Product_Specification = "";
	Technical_Details = "";
	Shipping_Weight = "";
	Product_Dimensions = "";
	Image = "";
	Variants = "";
	Sku = "";
	Product_Url = "";
	Stock = "";
	Product_Details = "";
	Dimensions = "";
	Color = "";
	Ingredients = "";
	Direction_To_Use = "";
	Is_Amazon_Seller = "";
	Size_Quantity_Variant = "";
	Product_Description = "";
}

//copy constructor
AmazonItem::AmazonItem(const AmazonItem& source)
{
	Uniq_Id = source.Uniq_Id;
	Product_Name = source.Product_Name;
	Brand_Name = source.Brand_Name;
	Asin = source.Asin;
	Category = source.Category;
	Upc_Ean_Code = source.Upc_Ean_Code;
	List_Price = source.List_Price;
	Selling_Price = source.Selling_Price;
	Quantity = source.Quantity;
	Model_Number = source.Model_Number;
	About_Product = source.About_Product;
	Product_Specification = source.Product_Specification;
	Technical_Details = source.Technical_Details;
	Shipping_Weight = source.Shipping_Weight;
	Product_Dimensions = source.Product_Dimensions;
	Image = source.Image;
	Variants = source.Variants;
	Sku = source.Sku;
	Product_Url = source.Product_Url;
	Stock = source.Stock;
	Product_Details = source.Product_Details;
	Dimensions = source.Dimensions;
	Color = source.Color;
	Ingredients = source.Ingredients;
	Direction_To_Use = source.Direction_To_Use;
	Is_Amazon_Seller = source.Is_Amazon_Seller;
	Size_Quantity_Variant = source.Size_Quantity_Variant;
	Product_Description = source.Product_Description;
}

//assignment operator
AmazonItem& AmazonItem::operator=(const AmazonItem& other)
{
	Uniq_Id = other.Uniq_Id;
	Product_Name = other.Product_Name;
	Brand_Name = other.Brand_Name;
	Asin = other.Asin;
	Category = other.Category;
	Upc_Ean_Code = other.Upc_Ean_Code;
	List_Price = other.List_Price;
	Selling_Price = other.Selling_Price;
	Quantity = other.Quantity;
	Model_Number = other.Model_Number;
	About_Product = other.About_Product;
	Product_Specification = other.Product_Specification;
	Technical_Details = other.Technical_Details;
	Shipping_Weight = other.Shipping_Weight;
	Product_Dimensions = other.Product_Dimensions;
	Image = other.Image;
	Variants = other.Variants;
	Sku = other.Sku;
	Product_Url = other.Product_Url;
	Stock = other.Stock;
	Product_Details = other.Product_Details;
	Dimensions = other.Dimensions;
	Color = other.Color;
	Ingredients = other.Ingredients;
	Direction_To_Use = other.Direction_To_Use;
	Is_Amazon_Seller = other.Is_Amazon_Seller;
	Size_Quantity_Variant = other.Size_Quantity_Variant;
	Product_Description = other.Product_Description;

	return (*this);
}

//display
void AmazonItem::display()
{
	cout << "Uniq_Id ID: " << Uniq_Id << endl;
	cout << "Product_Name: " << Product_Name << endl;
	cout << "Brand_Name: " << Brand_Name << endl;
	cout << "Asin: " << Asin << endl;
	cout << "Category: " << Category << endl;
	cout << "Upc_Ean_Code: " << Upc_Ean_Code << endl;
	cout << "List_Price: " << List_Price << endl;
	cout << "Selling_Price: " << Selling_Price << endl;
	cout << "Quantity: " << Quantity << endl;
	cout << "Model_Number: " << Model_Number << endl;
	cout << "Model_Number: " << Model_Number << endl;
	cout << "About_Product: " << About_Product << endl;
	cout << "Product_Specification: " << Product_Specification << endl;
	cout << "Technical_Details: " << Technical_Details << endl;
	cout << "Shipping_Weight: " << Shipping_Weight << endl;
	cout << "Product_Dimensions: " << Product_Dimensions << endl;
	cout << "Image: " << Image << endl;
	cout << "Variants: " << Variants << endl;
	cout << "Sku: " << Sku << endl;
	cout << "Product_Url: " << Product_Url << endl;
	cout << "Stock: " << Stock << endl;
	cout << "Product_Details: " << Product_Details << endl;
	cout << "Dimensions: " << Dimensions << endl;
	cout << "Color: " << Color << endl;
	cout << "Ingredients: " << Ingredients << endl;
	cout << "Direction_To_Use: " << Direction_To_Use << endl;
	cout << "Is_Amazon_Seller: " << Is_Amazon_Seller << endl;
	cout << "Size_Quantity_Variant: " << Size_Quantity_Variant << endl;
	cout << "Product_Description: " << Product_Description << endl;
}

//equal operator
bool AmazonItem::operator==(const AmazonItem& other)
{
	//if (zip == other.zip) return true;
	if (Uniq_Id == other.Uniq_Id) return true;
	return false;
}