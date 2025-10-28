#include <iostream>
#include <string>
#include <cassert>

#include "AmazonItem.hpp"
#include "HashTableTemplate.hpp"
#include "ListTemplate.hpp"

//#define TEST_MODE

using namespace std;

HashTable<string, AmazonItem> inventoryAmazon(1000);
HashTable<string, List<string>> categoryAmazon(1000);


string removeChar(string& input, char ch)
{
    string newstr = "";
    for (char c : input) if (c != ch) newstr += c;
    return newstr;
}

//look up for id in hashtable of unique ids
void findInventory(string id)
{
    auto it = inventoryAmazon.find(id);
    if (it == inventoryAmazon.end()) cout << "Inventory/Product not found" << endl;
    else (*it).second.display();
 }

// find and print item's id and name of all items corresponding to the given category
void findCategories(string cat)
{
    // remove spaces and quotes from filter
    string category = removeChar(cat, ' ');
    category = removeChar(category, '\"');

    auto it = categoryAmazon.find(category);
    if (it == categoryAmazon.end()) cout << "Invalid Category" << endl;
    else
    {
        for (auto itCat = (*it).second.begin(); itCat != (*it).second.end(); ++itCat)
        {
            auto itID = inventoryAmazon.find(*itCat);
            if (itID != inventoryAmazon.end())
            {
                cout << (*itID).second.getUniq_Id() << " - " << (*itID).second.getProduct_Name() << endl;
            }
        }

    }
}

//inserts item in category hashtable
void updateCategories(AmazonItem& itemInfo)
{
    string allCategories = itemInfo.getCategory();
    string category = "";
    List <string> emptyList;

    for (size_t i = 0; i < allCategories.size(); i++)
    {
        if (allCategories[i] != '|') category += allCategories[i];

        if (allCategories[i] == '|' || i == allCategories.size() - 1)
        {
            category = removeChar(category, ' ');
            category = removeChar(category, '\"');
            if (category == "") category = "NA";

            auto it = categoryAmazon.find(category);
            if (it == categoryAmazon.end())
            {
                it = categoryAmazon.insert(category, emptyList);
            }
            if (it != categoryAmazon.end())
            {
                (*it).second.addNodeBack(itemInfo.getUniq_Id());
            }

            category = "";
        }

    }
}


void printHelp()
{
    cout << "Supported list of commands: " << endl;
    cout << " 1. find <inventoryid> - Finds if the inventory exists. If exists, prints details. If not, prints 'Inventory not found'." << endl;
    cout << " 2. listInventory <category_string> - Lists just the id and name of all inventory belonging to the specified category. If the category doesn't exists, prints 'Invalid Category'.\n"
         << endl;
    cout << " Use :quit to quit the REPL" << endl;
}

bool validCommand(string line)
{
    return (line == ":help") ||
           (line.rfind("find", 0) == 0) ||
           (line.rfind("listInventory") == 0);
}

void evalCommand(string line)
{
    if (line == ":help")
    {
        printHelp();
    }
    // if line starts with find
    else if (line.rfind("find", 0) == 0)
    {
        // Look up the appropriate datastructure to find if the inventory exist
        if (line.length() >= 14) findInventory(line.substr(5));
    }
    // if line starts with listInventory
    else if (line.rfind("listInventory") == 0)
    {
        // Look up the appropriate datastructure to find all inventory belonging to a specific category
        if(line.length() >= 14) findCategories(line.substr(14));
    }
}

void readStringCSV(int &i, char* line, string &strField)
{
    strField = "";

    while (line[i] != ',' && line[i] != 0 && line[i] != '\n')
    {
        strField += line[i++];
        if (line[i - 1] == '\"')
        {
            while (line[i] != '\"') strField += line[i++];
            strField += line[i++];
        }
    }
    i++;
}


//loads amazon itmes from csv file
void loadCsv(FILE* givenCsv)
{
    char line[20000];
    AmazonItem itemInfo;
    int zip = 0;
    string strField = "";

    //checks if file was opened correctly
    if (givenCsv == NULL)
    {
        printf("There was an error opening the command.csv file\n");
        system("pause");
        return;
    }

    //reads header line and discards it
    fgets(line, sizeof(line), givenCsv);

    //for each line of the csv file 
    while (fgets(line, sizeof(line), givenCsv))
    {
        int i = 0;

        string test = line;

        //reads the field 'Uniq_Id' 
        readStringCSV(i, line, strField);
        itemInfo.setUniq_Id(strField);

        //reads the field 'Product_Name' 
        readStringCSV(i, line, strField);
        itemInfo.setProduct_Name(strField);

        //reads the field 'Brand_Name' 
        readStringCSV(i, line, strField);
        itemInfo.setBrand_Name(strField);

        //reads the field 'Asin' 
        readStringCSV(i, line, strField);
        itemInfo.setAsin(strField);

        //reads the field 'Category' 
        readStringCSV(i, line, strField);
        itemInfo.setCategory(strField);

        //reads the field 'Upc_Ean_Code' 
        readStringCSV(i, line, strField);
        itemInfo.setUpc_Ean_Code(strField);

        //reads the field 'List_Price' 
        readStringCSV(i, line, strField);
        itemInfo.setList_Price(strField);

        //reads the field 'Selling_Price' 
        readStringCSV(i, line, strField);
        itemInfo.setSelling_Price(strField);

        //reads the field 'Quantity' 
        readStringCSV(i, line, strField);
        itemInfo.setQuantity(strField);

        //reads the field 'Model_Number' 
        readStringCSV(i, line, strField);
        itemInfo.setModel_Number(strField);

        //reads the field 'About_Product' 
        readStringCSV(i, line, strField);
        itemInfo.setAbout_Product(strField);

        //reads the field 'Product_Specification' 
        readStringCSV(i, line, strField);
        itemInfo.setProduct_Specification(strField);

        //reads the field 'Technical_Details' 
        readStringCSV(i, line, strField);
        itemInfo.setTechnical_Details(strField);

        //reads the field 'Shipping_Weight' 
        readStringCSV(i, line, strField);
        itemInfo.setShipping_Weight(strField);

        //reads the field 'Product_Dimensions' 
        readStringCSV(i, line, strField);
        itemInfo.setProduct_Dimensions(strField);

        //reads the field 'Image' 
        readStringCSV(i, line, strField);
        itemInfo.setImage(strField);

        //reads the field 'Variants' 
        readStringCSV(i, line, strField);
        itemInfo.setVariants(strField);

        //reads the field 'Sku' 
        readStringCSV(i, line, strField);
        itemInfo.setSku(strField);

        //reads the field 'Product_Url' 
        readStringCSV(i, line, strField);
        itemInfo.setProduct_Url(strField);

        //reads the field 'Stock' 
        readStringCSV(i, line, strField);
        itemInfo.setStock(strField);

        //reads the field 'Product_Details' 
        readStringCSV(i, line, strField);
        itemInfo.setProduct_Details(strField);

        //reads the field 'Dimensions' 
        readStringCSV(i, line, strField);
        itemInfo.setDimensions(strField);

        //reads the field 'Color' 
        readStringCSV(i, line, strField);
        itemInfo.setColor(strField);

        //reads the field 'Ingredients' 
        readStringCSV(i, line, strField);
        itemInfo.setIngredients(strField);

        //reads the field 'Direction_To_Use' 
        readStringCSV(i, line, strField);
        itemInfo.setDirection_To_Use(strField);

        //reads the field 'Is_Amazon_Seller' 
        readStringCSV(i, line, strField);
        itemInfo.setIs_Amazon_Seller(strField);

        //reads the field 'Size_Quantity_Variant' 
        readStringCSV(i, line, strField);
        itemInfo.setSize_Quantity_Variant(strField);

        //reads the field 'Product_Description' 
        readStringCSV(i, line, strField);
        itemInfo.setProduct_Description(strField);

        //inserts item in inventory hashtable
        inventoryAmazon.insert(itemInfo.getUniq_Id(), itemInfo);

        //inserts item in category hashtable
        updateCategories(itemInfo);
    }
    return;
}

void bootStrap()
{
    cout << "\n Welcome to Amazon Inventory Query System" << endl;

    //opens csv file and load data in hashtables
    FILE* csvFile = fopen("amazondata.csv", "r");
    loadCsv(csvFile);

    cout << " enter :quit to exit. or :help to list supported commands." << endl;
    cout << "\n> ";
}

void runTests() 
{
    HashTable<string, int> testHashTable(10);

    //tests empty check
    assert(testHashTable.isEmpty());

    //tests insert and find
    testHashTable.insert("apple",  10);
    assert((*testHashTable.find("apple")).second == 10);
    testHashTable.insert("banana", 20);
    testHashTable.insert("cherry", 30);
    assert((*testHashTable.find("apple")).second == 10);
    assert((*testHashTable.find("banana")).second == 20);
    assert((*testHashTable.find("cherry")).second == 30);

    //tests not found
    assert(testHashTable.find("orange") == testHashTable.end());

    //tests remove
    testHashTable.remove("apple");
    assert(testHashTable.find("apple") == testHashTable.end());

    //tests empty
    testHashTable.emptyTable();
    assert(testHashTable.find("cherry") == testHashTable.end());

    //tests rehash
    testHashTable.emptyTable();
    assert(testHashTable.getSize() == 11); //first prime number larger than 10
    testHashTable.insert("apple", 10);
    testHashTable.insert("banana", 20);
    testHashTable.insert("cherry", 30);
    testHashTable.insert("orange", 40);
    testHashTable.insert("mango", 50);
    testHashTable.insert("pineapple", 60);
    assert(testHashTable.getSize() == 23); //first prime number larger than 11*2
    testHashTable.insert("watermelon", 70);
    assert((*testHashTable.find("apple")).second == 10);
    assert((*testHashTable.find("banana")).second == 20);
    assert((*testHashTable.find("cherry")).second == 30);
    assert((*testHashTable.find("orange")).second == 40);
    assert((*testHashTable.find("mango")).second == 50);
    assert((*testHashTable.find("pineapple")).second == 60);
    assert((*testHashTable.find("watermelon")).second == 70);

    std::cout << "All test cases passed!\n";
}

int main(int argc, char const *argv[])
{
#ifdef TEST_MODE
    runTests(); 
#else
    string line;
    bootStrap();
    while (getline(cin, line) && line != ":quit")
    {
        if (validCommand(line))
        {
            evalCommand(line);
        }
        else
        {
            cout << "Command not supported. Enter :help for list of supported commands" << endl;
        }
        cout << "> ";
    }
#endif
    return 0;
}
