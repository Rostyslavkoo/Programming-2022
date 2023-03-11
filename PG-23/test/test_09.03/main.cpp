#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Computer {
public:
    string firm;
    int price;

    Computer(string f, int p) {
        firm = f;
        price = p;
    }


};

class Desktop : public Computer {
public:
    string type;
    string processor;

    Desktop(string f, int p, string t, string pr) : Computer(f, p) {
        type = t;
        processor = pr;
    }
};

class Laptop : public Computer {
public:
    double screen_size;
    int memory;

    Laptop(string f, int p, double s, int m) : Computer(f, p) {
        screen_size = s;
        memory = m;
    }
};

int main() {
    vector<Computer*> computers;

    ifstream input("computers.txt");
    if (input) {
        string type, firm, processor;
        int price, memory;
        double screen_size;

        while (input >> type >> firm >> price) {
            if (type == "Desktop") {
                input >> processor;
                computers.push_back(new Desktop(firm, price, type, processor));
            } else if (type == "Laptop") {
                input >> screen_size >> memory;
                computers.push_back(new Laptop(firm, price, screen_size, memory));
            }
        }
        input.close();
    } else {
        cout << "File open error";
        return 1;
    }

    sort(computers.begin(), computers.end(), [](Computer* a, Computer* b) {
        return a->price < b->price;
    });

    ofstream output("sortedComputers.txt");
    if (output) {
        output << "\n|| sorted computers by price ||\n";
        for (auto c : computers) {
            output << "\tFirm: " << c->firm << ", Price: " << c->price << endl;
        }

        output << "\n|| Total price ||\n";
        int total = 0;
        for (auto c : computers) {
            total += c->price;
        }
        output << "\tTotal Price: " << total << endl;

        output << "\n|| Dell computers ||\n";
        for (auto c : computers) {
           if(c->firm == "Dell")
           {
               output << "\tFirm: " << c->firm << ", Price: " << c->price << endl;
           }
        }

        output.close();
    } else {
        cout << "File open error";
        return 1;
    }


    return 0;

}
