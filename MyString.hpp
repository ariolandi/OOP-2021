#ifndef _MYSTRING_H
#define _MYSTRING_H
#include <cstring>
#include <iostream>

class MyString{
private:
    char *str;
    int strsize;

    void resize(const int);
    int cmp(const MyString&) const;

    void createString(const char*);
    void copyString(const MyString&);
    void deleteString();

public:
    MyString(const char*);
    MyString(const MyString&);
    MyString(MyString&&);
    MyString& operator=(const MyString&);
    ~MyString();

    MyString operator+(const MyString&) const;
    void operator+=(const MyString&);
    void operator+=(const char);

    bool operator==(const MyString&) const;
    bool operator!=(const MyString&) const;
    bool operator>(const MyString&) const;
    bool operator<(const MyString&) const;
    bool operator>=(const MyString&) const;
    bool operator<=(const MyString&) const;

    int len() const;
    const char& get(const int) const;
    char& get(const int);

    friend std::istream& operator>>(std::istream& is, MyString& object);
    friend std::ostream& operator<<(std::ostream& os, const MyString& object);
};

void MyString::resize(const int n = 1){
    char *tmp = new char[strsize+n+1];
    strcpy(tmp, str);
    delete[] str;
    str = tmp;
    strsize += n;
}

int MyString::cmp(const MyString& other) const{
    return strcmp(str, other.str);
}

void MyString::createString(const char* str_){
    strsize = strlen(str_);
    str = new char[strsize+1];
    strcpy(str, str_);
}

void MyString::copyString(const MyString& other){
    createString(other.str);
}

void MyString::deleteString(){
    delete[] str;
    str = nullptr;
    strsize = 0;
}

MyString::MyString(const char* str_=""){
    createString(str_);
}

MyString::MyString(const MyString& other){
    copyString(other);
}

MyString::MyString(MyString&& rhs){
    createString(rhs.str);
    rhs.deleteString();
}

MyString& MyString::operator=(const MyString& other){
    if(this != &other){
        deleteString();
        copyString(other);
    }
    return *this;
}

MyString::~MyString(){
    deleteString();
}

MyString MyString::operator+(const MyString& other) const{
    MyString tmp(str);
    tmp.resize(other.strsize);
    strcat(tmp.str, other.str);
    return tmp;
}

void MyString::operator+=(const MyString& other){
    /// operator=(operator+(other));
    /// (*this) = (*this) + other;
    resize(other.strsize);
    strcat(str, other.str);
}

void MyString::operator+=(const char c){
    resize(2);
    str[strsize-2] = c;
    str[strsize-1] = '\n';
}

bool MyString::operator==(const MyString& other) const{
    return cmp(other) == 0;
}

bool MyString::operator!=(const MyString& other) const{
    return cmp(other) != 0;
}

bool MyString::operator>(const MyString& other) const{
    return cmp(other) > 0;
}

bool MyString::operator<(const MyString& other) const{
    return cmp(other) < 0;
}

bool MyString::operator>=(const MyString& other) const{
    return cmp(other) >= 0;
}

bool MyString::operator<=(const MyString& other) const{
    return cmp(other) <= 0;
}

int MyString::len() const{
    return strsize;
}

const char& MyString::get(const int p) const{
    if (p < 0 || p >= strsize)
        throw std::out_of_range("Index out of range");
    return str[p];
}

char& MyString::get(const int p){
     if (p < 0 || p >= strsize)
        throw std::out_of_range("Index out of range");
    return str[p];
}


std::istream& operator>>(std::istream& is, MyString& object){
    object = MyString();
    char c;
    while(is.get(c)){
        if(c == ' ' || c == '\n'/* || c == '\t'*/) break;
        object+=c;
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const MyString& object){
    os << object.str;
    return os;
}


#endif // _MYSTRING_H
