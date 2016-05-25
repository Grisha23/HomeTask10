#include <iostream>
#include <fstream>
#include "Debug.h"
std::string Debug::f_name = "/home/gri/Рабочий стол/Debug1.txt";
#include "Set.h"


template <class T>
Set<T> only_in_one(Set<T>& set1, Set<T>& set2) {
    Set<T> s;
    s = (set1 + set2) - (set1 * set2);
    return s;
}

int main() {


    std::ifstream file1;
    std::ifstream file2;

    file1.open("/home/gri/Рабочий стол/HT10");
    file2.open("/home/gri/Рабочий стол/HT10_2");

    if (!file1.is_open() || !file2.is_open()) {
        std::cout << "Файл не может быть открыт.\n";
        return 0;
    }


    Set<std::string > set1;
    Set<std::string > set2;

    try {
        file1 >> set1;
    }
    catch (std::exception& e) {
        std::cout << e.what();
        return 0;
    }

    // Вопрос (<<).

    try {
        file2 >> set2;
    }
    catch (std::exception& e) {
        std::cout << e.what();
        return 0;
    }

    file1.close();
    file2.close();


    std::cout << "Set #1: \n" << set1 << "\n";
    std::cout << "Set #2: \n" << set2 << "\n";

    Set<std::string > set3;

    set3 = set2;

    std::cout << "Set #3 = Set #2: \n" << set3 << "\n";

    set3 = set1 + set2;

    std::cout << "Set 1 + Set 2 (объединение): \n" << set3 << "   \n";

    set3 = set1 - set2;

    std::cout << "Set 1 - Set 2 (разность): \n" << set3 << "   \n";

    set3 =  set2 * set1 ;

    std::cout << "Set 1 * Set 2 (пересечение): \n" << set3 << "   \n";

    std::cout << "Есть только в одном: " << only_in_one(set1,set2);

    return 0;
}