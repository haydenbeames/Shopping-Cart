#include <string>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "ShoppingCart.h"
#include "ItemToPurchase.h"
using namespace std;

string GetUserString(const string& prompt);
void AddMenuOption(ShoppingCart &cart);
void RemoveMenuOption(ShoppingCart &cart);
void ChangeMenuOption(ShoppingCart &cart);
void DescriptionsMenuOption(ShoppingCart &cart);
void CartMenuOption(ShoppingCart &cart);
void OptionsMenuOption();
void QuitMenuOption();

int main() {
   string customerName = GetUserString("Enter Customer's Name: ");
   string todayDate = GetUserString("Enter Today's Date: ");
   string userMenuChoice = "none";
   bool continueMenuLoop = true;

   ShoppingCart cart(customerName, todayDate);
   while (continueMenuLoop) {
      userMenuChoice = GetUserString("Enter option: ");

      if (userMenuChoice == "add") {
         AddMenuOption(cart);
      }
      else if (userMenuChoice == "remove") {
         RemoveMenuOption(cart);
      }
      else if (userMenuChoice == "change") {
         ChangeMenuOption(cart);
      }
      else if (userMenuChoice == "descriptions") {
         DescriptionsMenuOption(cart);
      }
      else if (userMenuChoice == "cart") {
         CartMenuOption(cart);
      }
      else if (userMenuChoice == "options") {
         OptionsMenuOption();
      }
      else if (userMenuChoice == "quit") {
         QuitMenuOption();
         continueMenuLoop = false;
      }
      else {
         OptionsMenuOption();
      }
      cout << endl;
   }

   return 0;
}


string GetUserString(const std::string& prompt) {
   std::string userAnswer = "none";
   cout << prompt;
   std::getline(std::cin, userAnswer);
   std::cout << std::endl;

   return userAnswer;
}
double GetUserDouble(const std::string& prompt) {
   double userAnswer = 0.0;

   std::cout << prompt;
   std::cin >> userAnswer;
   std::cin.ignore();
   std::cout << std::endl;
   return userAnswer;
}
int GetUserInt(const std::string& prompt) {
   int userAnswer = 0;

   std::cout << prompt;
   std::cin >> userAnswer;
   std::cin.ignore();
   std::cout << std::endl;
   return userAnswer;
}


void AddMenuOption(ShoppingCart &cart) {
   string itemName = GetUserString("Enter the item name: ");
   string itemDescription = GetUserString("Enter the item description: ");
   double itemPrice = GetUserDouble("Enter the item price: ");
   int itemQuantity = GetUserInt("Enter the item quantity: ");
   ItemToPurchase newItem(itemName, itemDescription, itemPrice, itemQuantity);
   cart.AddMenuOption(newItem);
}

void RemoveMenuOption(ShoppingCart &cart) {
   string nameOfItemToRemove = GetUserString("Enter name of the item to remove: ");
   cart.RemoveMenuOption(nameOfItemToRemove);
}

void ChangeMenuOption(ShoppingCart &cart) {
   string nameOfItemToChange = GetUserString("Enter the item name: ");
   int newItemQuantity = GetUserInt("Enter the new quantity: ");
   cart.ChangeMenuOption(nameOfItemToChange, newItemQuantity);
}

void DescriptionsMenuOption(ShoppingCart &cart) {
   cart.PrintDescriptions();
}

void CartMenuOption(ShoppingCart &cart) {
   cart.PrintTotal();
}

void OptionsMenuOption() {
   cout << "MENU" << endl
             << "add - Add item to cart" << std::endl
             << "remove - Remove item from cart" << std::endl
             << "change - Change item quantity" << std::endl
             << "descriptions - Print the items' descriptions" << std::endl
             << "cart - Print the shopping cart" << std::endl
             << "options - Print the options menu" << std::endl
             << "quit - Quit" << std::endl << std::endl;
}

void QuitMenuOption() {
   cout << "Goodbye." << std::endl;
}