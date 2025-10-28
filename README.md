
CLEAN UP STRATEGY

    My cleanup of the data consisted only on removing quotes and whitespaces from the 
    category section in order to avoid the need for the user to input the category exactly as
    included for each item in the csv file.

    Also, I used NA as the category for all items without a category included in the file. They can be listed with the command 
        listInventory NA

DATA STRUCTURES

    I have implemented a hash table template using quadratic probing to solve collisions and using lazy deletion. 
    I have instantiated two hashtables it in my implementation:
       - One hashtable uses the uniqueID of each item as the key and an object containing all the item information as the value.
       - One second hashtable uses the category as the key and a list with the uniqueID (string) of all the items that belong to this category. 
         I used a list template that I had already created for PA1 to implement the list of uniqueId strings that belong to each category. 

TESTING APPROACH

    I implemented a function called runTests() in main.cpp where I included several test cases and verified they worked well using cassert.
    Test cases included verification of insert, find, and remove functions, including some edge cases, like working verifiying an item can't be
    found in an empty table. There is one test case forcing the load factor to be greater than 0.5 to verify automatic rehasing. 
    To run the tests, just need to define TEST_MODE in the header of main.cpp
