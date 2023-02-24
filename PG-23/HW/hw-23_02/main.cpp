// Створіть клас для банківського рахунку та  клас Клієнт.
// Клас Банківський рахунок повинен мати поля Клієн, номера рахунку та баланс,
// повинен містити методи для додавання грошей на рахунок і знімання, показ балансу
// та загальної інформації. Клас Клієнт повинен мати поля імʼяі клієнта, адреса та номер телефону.
// Ввести дані про 10 банківських рахунків, надати можливість пошуку рахунку за іменем клієнта
// та за адресою клієнта, надати меню для додавання чи зняття грошей з вибраного рахунку
#include <iostream>
#include <string>
using namespace std;

class  Client{
    string id;
    string name;
    string address;
    string phone;
public:
    Client():id(""),name(""),address(""),phone(""){};
    Client(string _id,string _name,string _address,string _phone): id(_id),name(_name),address(_address),phone(_phone){};
    string getId(){
        return  id;
    }
    string getName(){
        return  name;
    }
    string getAddress(){
        return  address;
    }
    string getPhone(){
        return  phone;
    }
};
class BankAcc{
    Client client;
    string *accNumbers;
    int balance;
public:
    BankAcc():client(),accNumbers(new string[10]),balance(0){};
    BankAcc(Client _client, string *_accNumbers, int _balance):client(_client),accNumbers(_accNumbers),balance(_balance){};

    void addMoney(int moneyAmount)
    {
        if(moneyAmount < 0){
            return;
        }
        balance += moneyAmount;
    }
    void removeMoney(int moneyAmount)
    {
        if (moneyAmount > balance) {
            return;
        }
        balance -= moneyAmount;
    }
    Client getClient() {
        return client;
    }
    int getBalance()
    {
        return balance;
    }
    string *getAccountNumbers()
    {
        return accNumbers;
    }

    void printClientInfo() {
        cout << client.getName() << "\n";
        cout << "Account numbers: " << endl;
        for (int i = 0; i < 10; i++) {
            if (accNumbers[i] == "") {
                continue;
            }
            cout << "- " << accNumbers[i] << endl;
        }
        cout << "Balance: " << balance << endl;
    }

};
class Bank {
    BankAcc *accounts;
    int count;
public:
    Bank(): accounts(new BankAcc[10]), count(0) {}

    void addBankAcc(BankAcc _count) {
        accounts[count++] = _count;
    }

    void getAllAcc() {
        for (int i = 0; i < count; i++) {
            accounts[i].printClientInfo();
        }
    }
    BankAcc* findById(string id) {
        for (int i = 0; i < count; i++) {
            if (accounts[i].getClient().getId() == id) {
                return &accounts[i];
            }
        }
    }

    BankAcc* findByName(string name) {
        for (int i = 0; i < count; i++) {
            if (accounts[i].getClient().getName() == name) {
                return &accounts[i];
            }
        }
    }
    BankAcc* findByAddress(string address) {
        for (int i = 0; i < count; i++) {
            if (accounts[i].getClient().getAddress() == address) {
                return &accounts[i];
            }
        }
    }
};
int main() {
    Bank bank;

    Client client1("001", "Rostyk", "Lviv", "00000000");
    string accountNumbers1[2] = {"12344321","33333"};
    BankAcc bankAcc1(client1,accountNumbers1,100);
    bank.addBankAcc(bankAcc1);

    Client client2("002", "Ivan", "Kyiv", "1111111");
    string accountNumbers2[2] = {"43211234"};
    BankAcc bankAcc2(client2,accountNumbers2,200);
    bank.addBankAcc(bankAcc2);

    cout << "\nfinded by id --- \n";
    bank.findById("002")->printClientInfo();
    cout << "\nfinded by name --- \n";
    bank.findByName("Rostyk")->printClientInfo();
    cout << "\nfinded by address --- \n";
    bank.findByAddress("Lviv")->printClientInfo();

    int n;
    cout << "\nAdd money (1)\n";
    cout << "\nRemove money (2)\n";

    cin >> n;
        switch (n) {
            case 1 :{
                int m;
                 cout << "Enter how much add Money:\n\n";
                 cin >> m;
                 bank.findByName("Rostyk")->addMoney(m);
                break;
            }
            case 2 :{
                int m;
                cout << "Enter how much remove Money:\n\n";
                cin >> m;
                bank.findByName("Rostyk")->removeMoney(m);
                break;
            }

        }
        bank.findByName("Rostyk")->printClientInfo();

    return 0;
}
