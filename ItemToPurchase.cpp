#include <string>
#include <string>
#include <iomanip>
#include "ItemToPurchase.h"
using namespace std;

ItemToPurchase::ItemToPurchase () {
  itemName = "none";
  itemPrice = 0.0;
  itemQuantity = 0;
  itemDescription = "none";
}

ItemToPurchase::ItemToPurchase(string name, string desc, double price, int quantity) {
  itemName = name;
  itemDescription = desc;
  itemPrice = price;
  itemQuantity = quantity;
}

void ItemToPurchase::SetName(string name) {
  itemName = name;
}
string ItemToPurchase::GetName() const {
  return itemName;
}
void ItemToPurchase::SetPrice(double price) {
  itemPrice = price;
}

double ItemToPurchase::GetPrice() const {
  return itemPrice;
}

void ItemToPurchase::SetQuantity(int quantity) {
  itemQuantity = quantity;
}

int ItemToPurchase::GetQuantity() const {
  return itemQuantity;
}

void ItemToPurchase::SetDescription(string descript) {
  itemDescription = descript;
}

string ItemToPurchase::GetDescription() const {
  return itemDescription;
}

void ItemToPurchase::PrintCost() {
  cout << fixed << setprecision(2) << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << itemQuantity*itemPrice << endl;
}

void ItemToPurchase::PrintDescription() {
  cout << itemName << ": " << itemDescription << endl;
}