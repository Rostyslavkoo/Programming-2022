#include<iostream>
#include<string>
#include <iomanip>

using namespace std;
int i;
class Item
{
    string itemName[50];
    float itemPrice[50];
    int itemAmount[50];
    int count = 0;
public:
     void addItem();
     void showAllItems();
     void removeItem();
     void showTotalPrice();
};

void Item::addItem()
{
    cout<< "----\n";
    cout<<"Enter Name ";
    cin>>itemName[count];
    cout<<"Enter Price ";
    cin>>itemPrice[count];
    cout<<"Enter Amount ";
    cin>>itemAmount[count];
    count++;
}
void Item::showAllItems()
{
    cout<< "Show All:\n";
    cout<< "------:\n";
    cout << "ItemName"<< setw(13)<<"ItemPrice" << setw(13) << "ItemAmount\n";
    for(i=0;i<count;i++)
    {
        cout<<itemName[i] << setw(13) << itemPrice[i]<<   setw(13) << itemAmount[i]<< endl;
    }
    cout<< "------:\n";

}
void Item::removeItem() {
    string name;
    int deletedAmount;
    cout << "Enter item Name to delete: ";
    cin >> name;
    cout << "Enter amount of item to delete: ";
    cin >> deletedAmount;

    for (i = 0; i < count; i++) {
        if (itemName[i] == name) {
            if (itemAmount[i] - deletedAmount < 0) {
                cout << "deleted Amount more than available\n available is - " << itemAmount[i] << endl;
            } else {
                itemAmount[i] = itemAmount[i] - deletedAmount;
            }
        }
    }
}
void Item::showTotalPrice()
{
    int sum = 0;
    for(i=0;i<count;i++){
        sum += itemPrice[i]*itemAmount[i] ;
    };
    cout << "Total price:" << sum << endl;
}


int main()
{
    Item firstCart;
    int n;
    while(n != 5){
    cout << "Chose operation:\n";
    cout << "add item :1\n";
    cout << "remove item :2\n";
    cout << "show all items :3\n";
    cout << "show total items price  :4\n";
    cout << "exit  :5\n";

        cin>> n ;

    switch (n) {
        case 1:
            firstCart.addItem();
            break;
        case 2:
            firstCart.removeItem();
            break;
        case 3:
            firstCart.showAllItems();
            break;
        case 4:
            firstCart.showTotalPrice();
            break;
    }}


    return 0;
}