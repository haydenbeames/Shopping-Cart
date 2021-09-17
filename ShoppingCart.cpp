#include <iostream>
#include <string>
#include <string>
#include <iomanip>
#include <vector>
#include <cctype>
#include "ShoppingCart.h"
#include "ItemToPurchase.h"
using namespace std;

ShoppingCart::ShoppingCart () {
  custmrName = "none";
  creationDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart (string name, string date) {
  custmrName = name;
  creationDate = date;
}

string ShoppingCart::GetName() {
  return custmrName;
}

string ShoppingCart::GetDate() {
  return creationDate;
}

void ShoppingCart::AddMenuOption(ItemToPurchase item) {
  bool itemCheck = false;
  for (int i = 0; i < itemsObj.size(); i++) {
    if (itemsObj.at(i).GetName() == item.GetName()) {
      cout << "Item is already found in the cart. It will not be added." << endl;
      itemCheck = true;
    }
  }
  if (!itemCheck) {
    itemsObj.push_back(item);
  }
}

void ShoppingCart::RemoveMenuOption(string item) {
  int OrigSize = itemsObj.size();
  for (int i = 0; i < itemsObj.size(); i++) {
    if (itemsObj.at(i).GetName() == item) {
      itemsObj.erase(itemsObj.begin()+i);
    }
  }
  if (OrigSize == itemsObj.size()) {
    cout << "item not found in cart. It will not be removed." << endl;
  }
}

void ShoppingCart::ChangeMenuOption(string nameOfItemToChange, int newItemQuantity) {
  bool modifiedCheck = false;
  for(int i = 0; i < itemsObj.size(); i++) {
    if(itemsObj.at(i).GetName() == nameOfItemToChange) {
      itemsObj.at(i).SetQuantity(newItemQuantity);
      modifiedCheck = true;
      return;
    }
  }
  cout << "Item not found in cart. It will not be modified." << endl;
}

int ShoppingCart::ItemsQuantity() {
  int itemCount = 0;
  for(int i = 0; i < itemsObj.size(); i++) {
    itemCount += itemsObj.at(i).GetQuantity();
  }
  return itemCount;
}

double ShoppingCart::CartCost() {
  double totalCost = 0;
  for (int i = 0; i < itemsObj.size(); i++) {  
    totalCost += (itemsObj.at(i).GetPrice()*itemsObj.at(i).GetQuantity());
  }
  return totalCost;
}

void ShoppingCart::PrintDescriptions() {
  cout << custmrName << "'s Shopping Cart - " << creationDate << endl;
  if(itemsObj.size() == 0) {
    cout << "Shopping cart is empty." << endl;
    return;
  }
  cout << "Item Descriptions" << endl;
  for(int i = 0; i < itemsObj.size(); i++) {
    ItemToPurchase current = itemsObj.at(i);
    current.PrintDescription();
  }  
}

void ShoppingCart::PrintTotal() {
  cout << custmrName << "'s Shopping Cart - " << creationDate << endl;
  if(itemsObj.size() == 0) {
    cout << "Shopping cart is empty." << endl;
  }
  else {
    cout << "Number of Items: " << ItemsQuantity() << endl;
    for(int i = 0; i < itemsObj.size(); i++) {
      itemsObj.at(i).PrintCost();
    }
    cout << fixed << setprecision(2);
    cout << endl << endl;
    cout << "Total: $" << CartCost() << endl;
    
  }
}




