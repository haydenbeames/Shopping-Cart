#ifndef SHOPPINGCART_H_INCLUDED
#define SHOPPINGCART_H_INCLUDED

#include <string>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "ItemToPurchase.h"
using namespace std;

class ShoppingCart {
  public:
    ShoppingCart();
    ShoppingCart(string name, string date);
    string GetName();
    string GetDate();
    void AddMenuOption(ItemToPurchase);
    void RemoveMenuOption(string);
    void ChangeMenuOption(string, int);
    int ItemsQuantity();
    double CartCost();
    void PrintDescriptions();
    void PrintTotal();
    
  private:
    string custmrName;
    string creationDate;
    vector<ItemToPurchase> itemsObj;

};

#endif