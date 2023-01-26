#include <iostream>
#include <vector>
using namespace std;
// class of item
class Item
{
// variables
private:
int itemNumber;
string itemName;
double itemPrice;
// functions
public:
// default constructor
Item();
// parametrize constructor
Item(int number, string name, double price)
{
itemNumber = number;
itemName = name;
itemPrice = price;
}
// setter
void setItemNumber(int number) { itemNumber = number; }
void setItemName(string name) { itemName = name; }
void setItemPrice(double price) { itemPrice = price; }
// getter
int getItemNumber() { return itemNumber; }

string getItemName() { return itemName; }
double getItemPrice() { return itemPrice; }
// display
void displayDetails()
{
cout << "Item Number: " << itemNumber << endl;
cout << "Item Name: " << itemName << endl;
cout << "Item Price: " << itemPrice << endl;
}
};

class DiscountedItem : public Item
{
private:
double discountPercentage;
double discountedPrice;
public:
// default constructor
DiscountedItem();
// parametrize constructor
DiscountedItem(int number, string name, double price, double discount) : Item(number, name, price)
{
discountPercentage = discount;
discountedPrice = price - (price * discount / 100);
}

void setDiscountPercentage(double discount)
{
discountPercentage = discount;
discountedPrice = getItemPrice() - (getItemPrice() * discount / 100);
}
double getDiscountPercentage() { return discountPercentage; }
double getDiscountedPrice() { return discountedPrice; }
// function overriding
void displayDetails()
{
Item::displayDetails();
cout << "Discount Percentage: " << discountPercentage << endl;
cout << "Discounted Price: " << discountedPrice << endl;
}
};
int main()
{
int numItems;
double totalPrice = 0, totalDiscount = 0;
cout << "How many items you want to enter: ";
cin >> numItems;
// dangling point

// DiscountedItem **items= new DiscountedItem *[numItems]; // dynamic
vector<DiscountedItem *> items(numItems);
// vector<DiscountedItem *> items(numItems);

for (int i = 0; i < numItems; i++)
{
int itemNumber;
string itemName;
double itemPrice;
double discountPercentage;
cout << "Enter details for item " << i + 1 << ":" << endl;
cout << "Item name: ";
cin >> itemName;
cout << "Item No: ";
cin >> itemNumber;
cout << "Item price: ";
cin >> itemPrice;
cout << "Discount percentage (Enter 0 if item is not discounted): ";
cin >> discountPercentage;
if (discountPercentage > 0)
{
items[i] = new DiscountedItem(itemNumber, itemName, itemPrice, discountPercentage);
totalDiscount += (itemPrice * discountPercentage / 100);
}
totalPrice += items[i]->getItemPrice();

cout<<"-------------------------"<<endl;
}
cout << "Details for all items:" << endl;
for (int i = 0; i < numItems; i++)
{
items[i]->displayDetails();
cout<<"-------------------------"<<endl;
}
cout<<"-------------------------"<<endl;
cout<<"Total Price" <<totalPrice<<endl;
cout<<"Total Discount" <<(totalDiscount);
cout<<"-------------------------"<<endl;
return 0;
}