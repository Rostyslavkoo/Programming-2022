#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

string ukr(string name) {
    return "З днем народження " + name;
}

string eng(string name) {
    return "Happy birthday " + name;
}

string pol(string name) {
    return "Wszystkiego najlepszego z okazji urodzin, " + name + "!";
}

void happyBirthday(string (*lang)(string), string name) {

    try{
        ostringstream os;
        os << lang(name);
        ofstream file("birthday_greetings.txt");
        file.close();
        if(!file.is_open()){
            throw "File not open";
        }
        file << os.str();
        file.close();
    }catch(const char* exception)
    {
        std::cerr << exception  << '\n';
    }

}

int main() {
    int lang;
    cout << "Enter the language (1 - English, 2 - Ukrainian, 3 - Polish): " << endl;
    cin >> lang;
    try
    {
        if(lang < 1 || lang > 3){
            throw "Choose valid language";
        }
        string name;
        cout << "Enter the name: " << endl;
        cin >> name;
        if(name.length() < 2){
            throw "Name is short";
        }

        switch (lang) {
            case 1:
                happyBirthday(eng, name);
                break;
            case 2:
                happyBirthday(ukr, name);
                break;
            case 3:
                happyBirthday(pol, name);
                break;
            default:
                happyBirthday(ukr, name);
                break;
        }
    }
    catch(const char* exception)
    {
        std::cerr << exception  << '\n';
    }




    return 0;
}