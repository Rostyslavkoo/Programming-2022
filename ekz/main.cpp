// Визначити шаблонну функцію, яка підраховує кількість
// елементів, відмінних від вказаного i-го елемента в масиві. 
// Передбачити перехоплення винятків при невірному значенні i.

#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
#include<sstream>

using namespace std;

template<typename T>
int Func(vector<T> arr, T el)
{

        if(count(arr.begin(), arr.end(), el) == 0){
            throw invalid_argument("element does not exist");
        }

        return arr.size() - count(arr.begin(), arr.end(), el);
}

int main()
{
    try {
        ifstream file1("input.txt");
        ofstream file2("output.txt");

        vector<int> v1;
        int diff;

        while(!file1.eof())
        {
            int n;
            file1 >> n;
            for(int i = 0; i < n; i++)
            {
                int tmp;
                file1 >> tmp;
                v1.push_back(tmp);
            }

            file1 >> diff;
        }

//        vector<int> v1;
//        int n;
//        int diff;
//        cout << "Enter vector size: ";
//        cin >> n;
//        for (int i = 0; i < n; i++) {
//            int val;
//            cout << "Enter vector el " << i << "\n";
//            cin >> val;
//            v1.push_back(val);
//        }

//        cout << "Enter diff: ";
//        cin >> diff;
        file2 << Func(v1, diff);
        return 0;
    }
    catch(const invalid_argument& e)
    {
        cerr << e.what();
    }
}