#ifndef ITEMTOPURCHASE_H_INCLUDED
#define ITEMTOPURCHASE_H_INCLUDED
#include <string>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class ItemToPurchase {
  public:
    ItemToPurchase();
    ItemToPurchase(string name, string desc, double price, int quantity);
    void SetName(string name);
    string GetName() const;
    void SetPrice(double price);
    double GetPrice() const;
    void SetQuantity(int quantity);
    int GetQuantity() const;
    void SetDescription(string description);
    string GetDescription() const;
    void PrintCost();
    void PrintDescription();

  private:
    string itemName;
    double itemPrice;
    int itemQuantity;
    string itemDescription;

};

#endif
