#include <iostream>
#include <unordered_map>
#include <string>
#include<stdlib.h>

using namespace std;

class BillSplitter {
private:
    unordered_map<string, double> balances;

public:
    void addDinnerOuting(int numFriends) {
        string payer, payee;
        double totalAmount;

        cout << "Enter the name of the person who paid the bill: ";
        cin >> payer;

        cout << "Enter the name of the person who was treated: ";
        cin >> payee;

        cout << "Enter the total amount of the bill: ";
        cin >> totalAmount;

        double splitAmount = totalAmount / (numFriends - 1);

        // Update payer's balance
        balances[payer] -= totalAmount;

        // Update payee's balance
        balances[payee] += splitAmount;

        // Update other friends' balances
        for (int i = 0; i < numFriends; i++) {
            string friendName;
            cout << "Enter the name of friend " << i + 1 << ": ";
            cin >> friendName;

            if (friendName != payer && friendName != payee) {
                balances[friendName] -= splitAmount;
            }
        }
    }

    void displayBalances() {
        cout << "Final Report:" << endl;
      for(auto it = balances.begin(); it != balances.end(); ++it) {
    string friendName = it->first;
    double balance = it->second;
    

            if (balance > 0) {
                cout << friendName << " needs to collect $" << balance << endl;
            } else if (balance < 0) {
                cout << friendName << " needs to pay $" << -balance << endl;
            } else {
                cout << friendName << " has no balance." << endl;
            }
        }
    }
};

int main() {
    BillSplitter billSplitter;

    int numFriends;
    cout << "Enter the number of friends involved: ";
    cin >> numFriends;

    billSplitter.addDinnerOuting(numFriends);

    billSplitter.displayBalances();

    return 0;
}
