//
// Created by gri on 21.05.16.
//

#ifndef HOMETASK10_SET_H
#define HOMETASK10_SET_H

#include <iostream>
#include <limits>
#include "Debug.h"
#include "string"

static Debug debug;

template <class T>
class Set {
private:

    T *elem;
    int size;
    int capacity;

    void resize() {

        capacity = capacity*2;

        T *tmp;

        try {
            tmp = new T[capacity];
        }
        catch (std::exception& e) {
            debug.log("resize", "error: память");
            throw e;
        }

        for (int i = 0; i < size; ++i) {
            tmp[i] = elem[i];
        }

        delete []elem;
        elem = tmp;
        tmp = nullptr;
    }


public:

    Set(int size = 4) {

        try {
            elem = new T[size];
        }
        catch (std::exception& e) {
            debug.log("resize", "error: память");
            throw e;
        }

        this->size = 0;
        capacity = size;
    }

    ~Set()
    {
        delete[] elem;
    }

    Set(const Set& set)
    {
        T *tmp;

        try {
            tmp = new T[set.capacity];
        }
        catch (std::exception& e) {
            debug.log("constr copy", "error: память");
            throw e;
        }

        for (int i = 0; i < set.size; ++i) {
            tmp[i] = set.elem[i];
        }

        elem = tmp;
        tmp = nullptr;

        capacity = set.capacity;
        size = set.size;
    }

    void insert(const T &elem)
    {
        if (size + 1 > capacity) {
            resize();
        }

        bool flag = false;

        for (int i = 0; i < size; ++i) {
            if (this->elem[i] == elem) flag = true;
        }

        if (flag == true) {
            debug.log("insert" , std::to_string(elem) ,"элемент уже существует(error)");
            return;
        }
        else {
            this->elem[size] = elem;
            size++;
        }

    }


    void erase(const int num) {

       if (num >= size) {
           debug.log("erase" , std::to_string(num) ,"out of range(error)");
           std::__throw_out_of_range("erase");// ...
       }

       for (int i = num; i < size - 1; ++i) {
           elem[i] = elem[i+1];
       }
       size--;
    }

    bool include(const T &elem)
    {
        debug.log("include" , std::to_string(elem) ,"ENTER");

        for (int i = 0; i < size; ++i) {
            if (this->elem[i] == elem) {

                debug.log("include" , std::to_string(elem) ,"EXIT");

                return true;
            }
        }

        debug.log("include" , std::to_string(elem) ,"EXIT");

        return false;
    }

    T& operator [] (int num)
    {
        debug.log("operator []", std::to_string(num), "ENTER");
        if (num >= size) {
            debug.log("operator []", "error: out of range");
            std::__throw_out_of_range("operator []");
        }

        debug.log("operator []", "EXIT");

        return elem[num];
    }

    Set& operator = (const Set &set2)
    {
        std::string tmp("Set1( ");
        tmp+= to_string(*this);
        tmp+= ") Set2( ";
        tmp+= to_string(set2);
        tmp+= ")";

        debug.log("operator =" , tmp ,"ENTER");

        delete[] elem;

        elem = nullptr;


        try {
            elem = new T[set2.capacity];
        }
        catch (std::exception& e) {
            debug.log("resize", "error: память");
            throw e;
        }


        size = set2.size;
        capacity = set2.capacity;

        for (int i = 0; i < set2.size; ++i) {
            elem[i] = set2.elem[i];
        }
        debug.log("operator =" , "EXIT");

        return *this;
    }

    std::string to_string() const
    {
        std::string s;

        for (int i = 0; i < this->size; ++i) {
            s += std::to_string(this->elem[i]);
            s += " ";
        }

        return s;
    }

    template <class T2>
    friend Set<T2> operator * (const Set<T2> &set1, const Set<T2> &set2);

    template <class T2>
    friend Set<T2> operator + (const Set<T2> &set1, const Set<T2> &set2);

    template <class T2>
    friend Set<T2> operator - (const Set<T2> &set1, const Set<T2> &set2);

    template <class T2>
    friend std::ostream& operator << (std::ostream &ostream,const Set<T2> &set);

    template <class T2>
    friend std::istream& operator >> (std::istream& istream, Set<T2>& set);



    int get_size() const
    {
        return size;
    }

    int get_capacity() const
    {
        return capacity;
    }


};

// СПЕЦИАЛИЗАЦИЯ

template <>
class Set<std::string> {

private:

    std::string *elem;
    int size;
    int capacity;


    void resize() {

        capacity = capacity*2;

        std::string *tmp;

        try {
            tmp = new std::string[capacity];
        }
        catch (std::exception& e) {
            debug.log("resize", "error: память");
            throw e;
        }


        for (int i = 0; i < size; ++i) {
            tmp[i] = elem[i];
        }

        delete []elem;
        elem = tmp;
        tmp = nullptr;

    }


public:

    Set(int size = 4) {

        try {
            elem = new std::string[size];
        }
        catch (std::exception& e) {
            debug.log("resize", "error: память");
            throw e;
        }

        this->size = 0;
        capacity = size;
    }

    ~Set()
    {
        delete[] elem;
    }

    Set(const Set& set)
    {
        std::string *tmp;

        try {
            tmp = new std::string[set.capacity];
        }
        catch (std::exception& e) {
            debug.log("constr copy", "error: память");
            throw e;
        }


        for (int i = 0; i < set.size; ++i) {
            tmp[i] = set.elem[i];
        }

        elem = tmp;
        tmp = nullptr;

        capacity = set.capacity;
        size = set.size;
    }

    void insert(const std::string &elem)
    {
        if (size + 1 > capacity) {
            resize();
        }

        bool flag = false;

        for (int i = 0; i < size; ++i) {
            if (this->elem[i] == elem) flag = true;
        }

        if (flag == true) {
            debug.log("insert" ,elem ,"элемент уже существует(error)");
            return;
        }
        else {
            this->elem[size] = elem;
            size++;
        }

    }


    void erase(const int num) {

        if (num >= size) {
            debug.log("erase" , std::to_string(num) ,"out of range(error)");
            std::__throw_out_of_range("erase");// ...
        }

        for (int i = num; i < size - 1; ++i) {
            elem[i] = elem[i+1];
        }
        size--;
    }

    bool include(const std::string &elem)
    {
        debug.log("include" ,elem ,"ENTER");

        for (int i = 0; i < size; ++i) {
            if (this->elem[i] == elem) {

                debug.log("include" ,elem ,"EXIT");

                return true;
            }
        }

        debug.log("include" ,elem ,"EXIT");

        return false;
    }

    std::string& operator [] (int num)
    {
        debug.log("operator []", std::to_string(num), "ENTER");
        if (num >= size) {
            debug.log("operator []", "error: out of range");
            std::__throw_out_of_range("operator []");
        }

        debug.log("operator []", "EXIT");

        return elem[num];


    }

    Set& operator = (const Set &set2)
    {
        std::string tmp("Set1( ");
        tmp += this->to_string();
        tmp+= ") Set2( ";
        tmp += set2.to_string();
        tmp+= ")";

        debug.log("operator =" , tmp ,"ENTER");

        delete[] elem;

        elem = nullptr;


        try {
            elem = new std::string[set2.capacity];
        }
        catch (std::exception& e) {
            debug.log("resize", "error: память");
            throw e;
        }


        size = set2.size;
        capacity = set2.capacity;

        for (int i = 0; i < set2.size; ++i) {
            elem[i] = set2.elem[i];
        }
        debug.log("operator =" , "EXIT");

        return *this;
    }

    std::string to_string() const
    {
        std::string s;

        for (int i = 0; i < this->size; ++i) {
            s += this->elem[i];
            s += " ";
        }

        return s;
    }

    template <class T2>
    friend Set<T2> operator * (const Set<T2> &set1, const Set<T2> &set2);

    template <class T2>
    friend Set<T2> operator + (const Set<T2> &set1, const Set<T2> &set2);

    template <class T2>
    friend Set<T2> operator - (const Set<T2> &set1, const Set<T2> &set2);

    template <class T2>
    friend std::ostream& operator << (std::ostream &ostream,const Set<T2> &set);

    template <class T2>
    friend std::istream& operator >> (std::istream& istream, Set<T2>& set);



    int get_size() const
    {
        return size;
    }

    int get_capacity() const
    {
        return capacity;
    }


};



template <class T>
std::istream& operator >> (std::istream& istream, Set<T>& set)
{
    debug.log("operator >>" ,  "ENTER");


    if (!istream.good()) {
        debug.log("operator >>" , "istream not good");
        std::__throw_bad_function_call();
    }

    while (!istream.eof()) {

        T tmp;
        istream >> tmp;
        set.insert(tmp);

        istream.clear();
        istream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    }

    return istream;

}


template <class T>
std::ostream& operator << (std::ostream &ostream,const Set<T> &set)
{
    std::string tmp("Set1( ");
    tmp+= set.to_string();
    tmp+= ")";

    debug.log("operator <<" , tmp, "ENTER");


    if (set.get_size() == 0) {
        ostream << "пустое множество\n";
        debug.log("operator <<" ,"EXIT(пустое множество)");
        return ostream;
    }

    for (int i = 0; i < set.size; ++i) {
        if (i < set.size - 1) ostream << set.elem[i] << ", ";
        else ostream << set.elem[i] << "\n";
    }

    debug.log("operator <<" ,"EXIT");

    return ostream;

}


template <class T>
Set<T> operator - (const Set<T> &set1, const Set<T> &set2)
{
    if (set1.get_size() == 0) {
        return Set<T>();
    }

    std::string tmp("Set1( ");
    tmp += set1.to_string() ;
    tmp += ") Set2( ";
    tmp += set2.to_string();
    tmp += ")";

    debug.log("operator -", tmp, "ENTER");


    int new_size = set1.size;
    Set<T> set(new_size);

    set = set1;

    for (int i = 0; i < set.size; i++) {
        for (int j = 0; j < set2.size; ++j) {
            if (set.elem[i] == set2.elem[j]) {
                set.erase(i);
                i--;
                break;
            }
        }

    }
    debug.log("operator -", "EXIT");
    return set;

}

template <class T>
Set<T> operator * (const Set<T> &set1, const Set<T> &set2)
{
    std::string tmp("Set1( ");
    tmp += set1.to_string();
    tmp += ") Set2( ";
    tmp += set2.to_string();
    tmp += ")";

    debug.log("operator *" , tmp,"ENTER");


    if (set1.get_size() == 0) {
        debug.log("operator *" , "EXIT");
        return Set<T>();
    }

    Set<T> set(set1.size);

    for (int i = 0; i < set1.size; ++i) {
        for (int j = 0; j < set2.size; ++j) {
            if (set1.elem[i] == set2.elem[j]) set.insert(set1.elem[i]);
        }
    }

    debug.log("operator *" , "EXIT");

    return set;

}


template <class T>
Set<T> operator + (const Set<T> &set1, const Set<T> &set2)
{
    std::string tmp("Set1( ");
    tmp += set1.to_string();
    tmp += ") Set2( ";
    tmp += set2.to_string();
    tmp += ")";

    debug.log("operator +", tmp,"ENTER");

    int new_size = set1.size + set2.size;
    Set<T> set(new_size);

    for (int i = 0; i < new_size; ++i) {
        if (i < set1.size) set.insert(set1.elem[i]);
        else set.insert(set2.elem[i - set1.size]);
    }

    debug.log("operator +" ,"EXIT");
    return set;

}

#endif //HOMETASK10_SET_H
