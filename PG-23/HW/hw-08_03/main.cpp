#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Phone {
protected:
    string name;
    string firma;
    double price;

public:
    Phone(string _name, string _firma, double _price) : name(_name), firma(_firma), price(_price) {}

    virtual ~Phone() {}

    virtual void print() const {
        cout << "Phone " << name << "  " << firma << ", price: " << price << " uah." << endl;
    }

    string getName() const {
        return name;
    }
    double getPrice() const {
        return price;
    }
    string getFirm() const {
        return firma;
    }
};
class MobilePhone : public Phone {
protected:
    string color;
    int memory;

public:
    MobilePhone(string _name, string _firma, double _price, string _color, int _memory) : Phone(_name, _firma, _price), color(_color), memory(_memory) {}

    virtual ~MobilePhone() {}

    virtual void print() const {
        cout << "Mobile Phone " << name << "  " << firma << ", color: " << color << ", Memory: " << memory << " Gb, price: " << price << " uah." << endl;
    }
};

class RadioPhone : public Phone {
protected:
    double radiusDii;
    bool autoVid;

public:
    RadioPhone(string _name, string _firma, double _price, double _radiusDii, bool _autoVid) : Phone(_name, _firma, _price), radiusDii(_radiusDii), autoVid(_autoVid) {}

    virtual ~RadioPhone() {}

    virtual void print() const {
        cout << "RadioPhone " << name << " від " << firma << ", radius: " << radiusDii << " km, autoVid: " << (autoVid ? "yes": "no")  << ", price: " << price << " uah." << endl;
    }

    bool hasAutoVid() const {
        return autoVid == 1;
    }
};
bool comparePhones(const Phone* t1, const Phone* t2) {
    return t1->getPrice() < t2->getPrice();
}

int main() {
    vector<Phone*> phones;

    ifstream file1("phones1.txt");
    if (!file1) {
        cout << "Error open file" << endl;
        return 1;
    }
    string name, firma, color;
    double price, radiusDii;
    int memory;
    bool autoVid;
//    file1 >> name;
    while (file1 >> name >> firma >> price >> color >> memory) {
        phones.push_back(new MobilePhone(name,firma,price,color,memory));
    }

    file1.close();

    ifstream file2("phones2.txt");
    if (!file2) {
        cout << "Error open file" << endl;
        return 1;
    }
    while (file2 >> name >> firma >> price >> radiusDii ) {
        phones.push_back(new RadioPhone(name, firma, price, radiusDii, true));
    }
    file2.close();

    sort(phones.begin(), phones.end(), comparePhones);

    double total = 0;

    ofstream output("phone_output.txt");
    if (!output) {
        cout << "Error open file" << endl;
        return 1;
    }

    for (const auto& phone : phones) {
        phone->print();
        total += phone->getPrice();
        phone->print();
    }

    output << "Total: " << total << " uah." << endl;
    output.close();

    ofstream output2("radioPhone_output.txt");
    if (!output2) {
        cout << "Error open file" << endl;
        return 1;
    }
    for (const auto& phone : phones) {
        RadioPhone* rt = dynamic_cast<RadioPhone*>(phone);
            if(phone->getName() == "Radio"){
                phone->print();
                if(rt->hasAutoVid()){
                    output2 << phone->getName() << " "<< phone->getFirm() << " "<< phone->getPrice()<< endl;
                }else{
                    cout << rt->hasAutoVid();
                }
        }
//        cout << rt->hasAutoVid();
//        phone->print();
//        if (rp->hasAutoVid()) {
//            rp->print();
//            output2 << rp->hasAutoVid();
//        }
    }
    output2.close();

    for (const auto& phone : phones) {
        delete phone;
    }

    return 0;
}
