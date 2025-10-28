/***********************
Diana Raya Sanchez
October 22nd, 2025
Programming Assignment 3
CPTS 223
************************/

#pragma once

#include <string> 
#include <stack>

using namespace std;

class AmazonItem //data class 
{
private:
	string Uniq_Id;
	string Product_Name;
	string Brand_Name;
	string Asin;
	string Category;
	string Upc_Ean_Code;
	string List_Price;
	string Selling_Price;
	string Quantity;
	string Model_Number;
	string About_Product;
	string Product_Specification;
	string Technical_Details;
	string Shipping_Weight;
	string Product_Dimensions;
	string Image;
	string Variants;
	string Sku;
	string Product_Url;
	string Stock;
	string Product_Details;
	string Dimensions;
	string Color;
	string Ingredients;
	string Direction_To_Use;
	string Is_Amazon_Seller;
	string Size_Quantity_Variant;
	string Product_Description;


public:
	//constructor 
	AmazonItem();

	//copy constructor
	AmazonItem(const AmazonItem& source);

	//assignment operator
	AmazonItem& operator=(const AmazonItem& other);

	//equal operator
	bool operator==(const AmazonItem& other);

	//display item fields in screen
	void display();

	//getters
	string& getUniq_Id() { return Uniq_Id; }
	string& getProduct_Name() { return Product_Name; }
	string& getBrand_Name() { return Brand_Name; }
	string& getAsin() { return Asin; }
	string& getCategory() { return Category; }
	string& getUpc_Ean_Code() { return Upc_Ean_Code; }
	string& getList_Price() { return List_Price; }
	string& getSelling_Price() { return Selling_Price; }
	string& getQuantity() { return Quantity; }
	string& getModel_Number() { return Model_Number; }
	string& getAbout_Product() { return About_Product; }
	string& getProduct_Specification() { return Product_Specification; }
	string& getTechnical_Details() { return Technical_Details; }
	string& getShipping_Weight(){ return Shipping_Weight; }
	string& getProduct_Dimensions(){ return Product_Dimensions; }
	string& getImage() { return Image; }
	string& getVariants() { return Variants; }
	string& getSku() { return Sku; }
	string& getProduct_Url() { return Product_Url; }
	string& getStock() { return Stock; }
	string& getProduct_Details() { return Product_Details; }
	string& getDimensions() { return Dimensions; }
	string& getColor() { return Color; }
	string& getIngredients() { return Ingredients; }
	string& getDirection_To_Use() { return Direction_To_Use; }
	string& getIs_Amazon_Seller() { return Is_Amazon_Seller; }
	string& getSize_Quantity_Variant() { return Size_Quantity_Variant; }
	string& getProduct_Description() { return Product_Description; }

	//setters
	void setUniq_Id(string& Uniq_Id_str) { Uniq_Id = Uniq_Id_str; }
	void setProduct_Name(string& Product_Name_str) { Product_Name = Product_Name_str; }
	void setBrand_Name(string& Brand_Name_str) { Brand_Name = Brand_Name_str; }
	void setAsin(string& Asin_str) { Asin = Asin_str; }
	void setCategory(string& Category_str) { Category = Category_str; }
	void setUpc_Ean_Code(string& Upc_Ean_Code_str) { Upc_Ean_Code = Upc_Ean_Code_str; }
	void setList_Price(string& List_Price_str) { List_Price = List_Price_str; }
	void setSelling_Price(string& Selling_Price_str) { Selling_Price = Selling_Price_str; }
	void setQuantity(string& Quantity_str) { Quantity = Quantity_str; }
	void setModel_Number(string& Model_Number_str) { Model_Number = Model_Number_str; }
	void setAbout_Product(string& About_Product_str) { About_Product = About_Product_str; }
	void setProduct_Specification(string& Product_Specification_str) { Product_Specification = Product_Specification_str; }
	void setTechnical_Details(string& Technical_Details_str) { Technical_Details = Technical_Details_str; }
	void setShipping_Weight(string& Shipping_Weight_str) { Shipping_Weight = Shipping_Weight_str; }
	void setProduct_Dimensions(string& Product_Dimensions_str) { Product_Dimensions = Product_Dimensions_str; }
	void setImage(string& Image_str) { Image = Image_str; }
	void setVariants(string& Variants_str) { Variants = Variants_str; }
	void setSku(string& Sku_str) { Sku = Sku_str; }
	void setProduct_Url(string& Product_Url_str) { Product_Url = Product_Url_str; }
	void setStock(string& Stock_str) { Stock = Stock_str; }
	void setProduct_Details(string& Product_Details_str) { Product_Details = Product_Details_str; }
	void setDimensions(string& Dimensions_str) { Dimensions = Dimensions_str; }
	void setColor(string& Color_str) { Color = Color_str; }
	void setIngredients(string& Ingredients_str) { Ingredients = Ingredients_str; }
	void setDirection_To_Use(string& Direction_To_Use_str) { Direction_To_Use = Direction_To_Use_str; }
	void setIs_Amazon_Seller(string& Is_Amazon_Seller_str) { Is_Amazon_Seller = Is_Amazon_Seller_str; }
	void setSize_Quantity_Variant(string& Size_Quantity_Variant_str) { Size_Quantity_Variant = Size_Quantity_Variant_str; }
	void setProduct_Description(string& Product_Description_str) { Product_Description = Product_Description_str; }

	//destructor
	~AmazonItem() {}

};

