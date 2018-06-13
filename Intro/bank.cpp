#include <iostream>

using namespace std;

class BankAccount{

private:

  double balance;

public:

  BankAccount(double openingBalance){

    balance = openingBalance;
  }
  
  void deposit(double amount){

    balance = balance + amount;
  }

  void withdraw(double amount){

    balance = balance - amount;
  }

  void display(){

    cout << "Balance=" << balance << endl;
  }
};

int main(){

  BankAccount ba1(100.00);

  cout << "Before transactions, ";
  ba1.display();

  ba1.deposit(74.35);
  ba1.withdraw(20.00);

  cout << "After transaction, ";
  ba1.display();

  return 0;
}
