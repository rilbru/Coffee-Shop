#include <iostream>
#include <iomanip>
using namespace std;

// setting constants for pricing and calculations
const double DONUT = 4.00,
             MUFFIN = 4.50,
             PASTRY = 5.50,
             BAGEL = 3.75,
             TOAST = 2.25,
             COFFEE = 3.50,
             TEA = 2.50,
             TEN = 10.0,
             FIFTEEN = 15.0,
             TWO = 2.0,
             HUNDRED = 100.0;
// prototypes
void welcome();
void mainMenu();
char menuOne();
char menuTwo();
char menuThree();
int readOption();
double exeOption(int option, double totalCost);
double menuFour(double totalCost);
void EndSummary(double totalCost);

// main
int main() {
  // declaring variables
  int option = 0;
  double totalCost = 0;

  // display welcome function
  welcome();

  // setting 2 decimal places
  cout << fixed << showpoint << setprecision(2);
  
  // do-while loop until the user enters 4
  do
  {
    mainMenu();                                   // main menu
    option = readOption();                        // uses readOption function
    totalCost = exeOption(option, totalCost);             // execute function
    cout << "Your total so far is: $" << totalCost << endl;
  }while(option != 4);

  menuFour(totalCost);                                // total summary with tips

  return 0;
} 

// welcome function
void welcome()
{
  cout << "Welcome to my coffee shop!" << endl;
}

// mainMenu function
void mainMenu()
{
  cout << "\nPlease pick an option below:" << endl;
  cout << "\n1. Donuts/Muffin/Pastries \n2. Bagels/Toast \n3. Coffee/Tea \n4. Quit" << endl;
}

// submenu for option 1
char menuOne()
{
  char choice;
  cout << "\nWould you like: \nD: Donuts $4.00 \nM: Muffins $4.50 \nP: Pastries $5.50" << endl;
  cin >> choice;
  choice = (tolower(choice));

  // validate user input
  while (choice != 'd' && choice != 'm' && choice != 'p')
  {
    cout << "Invalid option! \nWould you like Donuts (D), Muffins (M), or Pastries (P): ";
    cin.clear();
    cin.ignore(100, '\n');
    cin >> choice;
    choice = (tolower(choice));
  }
  // display to the user the item they selected
  if (choice == 'd') 
  {
    cout << "Donuts added." << endl;
  }
  else if (choice == 'm')
  {
    cout << "Muffin added." << endl;
  }
  else if (choice == 'p')
  {
    cout << "Pastries added." << endl;
  } 

  return choice;
}

// submenu for option 2
char menuTwo()
{
  char choice;
  cout << "\nWould you like: \nB: Bagels $3.75 \nT: Toast $2.25" << endl;
  cin >> choice;
  choice = (tolower(choice));

  // validate user input
  while (choice != 'b' && choice != 't') 
  {
    cout << "Invalid option! Would like Bagels (B) or Toast (T): ";
    cin.clear();
    cin.ignore(100, '\n');
    cin >> choice;
    choice = (tolower(choice));
  }
  // display to the user the item they selected
  if (choice == 'b') 
  {
    cout << "Bagels added." << endl;
  }
  else if (choice == 't')
  {
    cout << "Toast added." << endl;
  }
 return choice;
}

// submenu for option 3
char menuThree()
{
  char choice;
  cout << "\nWould you like: \nC: Coffee $3.50 \nT: Tea $2.50" << endl;
  cin >> choice;
  choice = (tolower(choice));

  // validate user input
  while (choice != 'c' && choice != 't') 
  {
    cout << "Invalid option! Would you lke Coffee (C) or Tea (T): ";
    cin.clear();
    cin.ignore(100, '\n');
    cin >> choice;
    choice = (tolower(choice));
  }
  // display to the user the item they selected
  if (choice == 'c') 
  {
    cout << "Coffee added." << endl;
  }
  else if (choice == 't')
  {
    cout << "Tea added." << endl;
  }
  return choice;
}

// final summary with suggested tip amounts and total cost
double menuFour(double totalCost)
{
  // declaring variables
  double tenPercent, fifteenPercent, twentyPercent, userTip;

  // calculating tip percentages
  tenPercent = totalCost / TEN;
  fifteenPercent = (totalCost * FIFTEEN) / HUNDRED;
  twentyPercent = (totalCost / TEN) * TWO;

  cout << "\nYour total cost: $" << totalCost << endl;
  cout << "\nWould you like to add a tip? Suggested amounts:" << endl;
  cout << "10% = $" << tenPercent << endl;
  cout << "15% = $" << fifteenPercent << endl;
  cout << "20% = $" << twentyPercent << endl;
  cout << "Enter tip amount: $";
  cin >> userTip;

  // validate users tip amount 
  while (!cin || userTip < 0)
  {
    cout << "\nTip amount cannot be less than 0. \nEnter tip amount: $";
    cin.clear();
    cin.ignore(100, '\n');
    cin >> userTip;
  }
  if (userTip > 0)
  {
    totalCost += userTip;
    EndSummary(totalCost);
  }
  return totalCost;
}

// read option for main menu
int readOption()
{
  int option = 0;
  cin >> option;
  // validate user input
  while(!cin || option < 1 || option > 4)
  {
    cout << "Invalid option! Please try again!\n" << endl;
    mainMenu();
    cin.clear();
    cin.ignore(100, '\n');
    cin >> option;
  }
  return option;
}

// exeOption to switch for each option and choice selected
double exeOption(int option, double totalCost)
{
  char choice;
  switch (option)
  {
    case 1:
      choice = menuOne();
      switch(choice)
      {
        case 'd':
          totalCost += DONUT;
          break;
        case 'm':
          totalCost += MUFFIN;
          break;
        case 'p':
          totalCost += PASTRY;
          break;
      }
    break;
    case 2:
    choice = menuTwo();
      switch(choice)
      {
        case 'b':
          totalCost += BAGEL;
          break;
        case 't':
          totalCost += TEA;
          break;
      }
    break;
    case 3:
    choice = menuThree();
      switch(choice)
      {
        case 'c':
          totalCost += COFFEE;
          break;
        case 't':
          totalCost += TEA;
          break;
      }
    break;
  }
  return totalCost;
}

// displays the final cost total
void EndSummary(double totalCost)
{
  cout << "\nPlease pay $"<< totalCost << endl;
  cout << "Thank you for stopping by!";
}
