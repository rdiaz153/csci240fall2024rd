#pragma once
#include <iostream>           // provides std::ostream
#include <string>             // provides std::string
#include <vector>
namespace dsac::design {

/// A customer credit card
class CreditCard {
  private:
    std::string customer;     // name of the customer (e.g., "John Bowman")
    std::string bank;         // name of the bank (e.g., "California Savings")
    std::string account;      // account identifier (e.g., "5391 0375 9387 5309")
    int limit;                // credit limit (measured in dollars)
    double annualInterest;
    std::vector<std::string> transactions;

  protected:
    double balance;           // current balance (measured in dollars)

  public:
    /// Constructs a new credit card. The initial balance is 0.0 by default.
    CreditCard(std::string cust, std::string bk, std::string acnt, int lim, double initial_bal = 0.0)
        : customer{cust}, bank{bk}, account{acnt}, limit{lim}, balance{initial_bal}, annualInterest{0.15} {}

    // ------------- Accessors -------------

    /// Returns the customer's name
    /// @return a string representing the customer's name
    std::string get_customer() const { return customer; }

    /// Returns the bank's name
    /// @return a string representing the credit card's bank
    std::string get_bank() const { return bank; }

    /// Returns the account number as a string
    /// @return a string representing the account number
    std::string get_account() const { return account; }

    /// Returns the credit limit (measured in dollars)
    /// @return an integer representing the credit limit, it dollars
    int get_limit() const { return limit; }

    /// Returns the current balance (measured in dollars)
    /// @return a floating-point representation of the current balance, in dollars
    double get_balance() const { return balance; }

    // ------------- Mutators -------------

    /// Charges the give price to the card, assuming sufficient credit limit.
    /// @param price  the amount to be charged
    /// @return true if charge was accepted; false if charge was denied
    bool charge(double price) {
        if (price + balance > limit)                      // if charge would surpass limit
            return false;                                 // refuse the charge
        // at this point, the charge is successful
        balance += price;                                 // update the balance
        transactions.push_back("Charge: $" + std::to_string(price));
        return true;                                      // announce the good news
    }

    /// Processes customer payment to reduce the balance
    /// @param amount the amount to pay down the balance
    void make_payment(double amount) {
      balance -= amount; 
      transactions.push_back("Payment: $" + std::to_string(amount));
    }

    void addMonthlyInterest() {
      double monthlyInterest = (annualInterest / 12.0) * balance;
      balance += monthlyInterest;
      transactions.push_back("Interest: $" + std::to_string(monthlyInterest));
    }

    void print_transactions() {
      std::cout << "Transactions for account " << account << ":\n";
      for (std::string& transaction : transactions) {
        std::cout << " " << transaction << std::endl;
      }
    }

    // ------------- Overloaded output operator (as friend) -------------

    /// Displays the credit card to an output stream
    /// @param out the output stream
    /// @param c the credit card
    /// @return the resulting output stream
    friend std::ostream& operator<<(std::ostream& out, const CreditCard& c) {
        out << "Customer = " << c.customer << std::endl;
        out << "Bank = " << c.bank << std::endl;
        out << "Account = " << c.account << std::endl;
        out << "Balance = " << c.balance << std::endl;
        out << "Limit = " << c.limit << std::endl;
        return out;
    }

}; // CreditCard class

}  // namespace dsac::design
