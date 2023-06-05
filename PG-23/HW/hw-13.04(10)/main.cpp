// Task 10
//Визначити шаблонну функцію, яка отримує масив елементів
// та його розмір. Функція подвоює кількість елементів, що
// стоять на непарних місцях (напр. 263264->226332664).

#include <iostream>
#include <type_traits>
#include <vector>


template<typename T>
std::vector<T> double_odd(T* arr, size_t size)
{
    try{
    std::vector<T> new_arr;
    for (size_t i = 0; i < size; i++)
    {
        new_arr.push_back(arr[i]);
        if(i % 2 == 0){
            new_arr.push_back(arr[i]);
        }
    }
    return new_arr;
    }catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

int main()
{
    int int_arr[] = { 2, 6, 3, 2, 6, 4 };
    size_t int_size = sizeof(int_arr) / sizeof(int_arr[0]);
    //std::string int_arr[] = { "a", "b", "c", "d", "e", "f" };
    std::vector<int> res = double_odd(int_arr, int_size);
//  std::vector<std::string> res= double_odd(int_arr, int_size);

    for (size_t i = 0; i < res.size(); ++i)
    {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;


    return 0;
}