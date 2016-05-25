//
// Created by gri on 23.05.16.
//

#ifndef HOMETASK10_DEBUG_H
#define HOMETASK10_DEBUG_H

#include <fstream>
#include "iostream"
#include "string"



class Debug {
public:

    std::ofstream file;
    static std::string f_name;

    Debug()
    {
        if (!f_name.size()) f_name = "/home/Debug";

        std::cout << f_name;

        file.open(f_name);

        if (!file.is_open()) {
            std::cout << "Файл не может быть открыт. (Debug)\n";
        }
    }


    ~Debug()
    {
        file.close();
    }

    void log(const std::string &name_f, const std::string &param, const std::string &message)
    {
        if (!file.is_open()) std::__throw_bad_function_call();
        file << name_f + " | " + message + " | " +  param + "\n";
    }
    void log(const std::string &name_f, const std::string &message)
    {
        if (!file.is_open()) std::__throw_bad_function_call();
        file << name_f + " | " + message + "\n";
    }

};


#endif //HOMETASK10_DEBUG_H
