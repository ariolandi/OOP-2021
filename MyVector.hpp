#ifndef _VECTOR_H
#define _VECTOR_H
#include <stdexcept>
#include <exception>


template <typename T>
class MyVector{
private:
    T* arr;
    int l;

    void copyArr(const T* arr);
    void copyMyVector(const MyVector<T>& MyVector);
    void resize(const int l);
public:
    MyVector(const T* arr=nullptr, int l_=0);
    MyVector(const MyVector<T>& other);
    MyVector(MyVector<T>&& other);
    ~MyVector();

    MyVector<T>& operator=(const MyVector<T>& other);

    void addElement(const T& obj);
    /// void addElement(const T&& obj);
    void removeElement(const int position);

    int getSize() const;
    const T& operator[](const int position)const;
    T& operator[](const int position);
};


template <typename T>
MyVector<T>::MyVector(const T* arr, int l_): l(l_){
    copyArr(arr);
}

template <typename T>
MyVector<T>::MyVector(const MyVector<T>& other){
    copyMyVector(other);
}

template <typename T>
MyVector<T>::MyVector(MyVector<T>&& other){
    copyMyVector(other);
    delete other;
    other=nullptr;
}

template <typename T>
MyVector<T>::~MyVector(){
    delete[] arr;
    arr=nullptr;
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other){
    if(this != &other){
        delete[] arr;
        arr=nullptr;
        copyMyVector(other);
    }
    return *this;
}

template <typename T>
void MyVector<T>::copyArr(const T* arr){
    this->arr = nullptr;
    if(arr != nullptr){
        this->arr = new T[this->l];
        for(int i = 0; i < this->l; i++){
            this->arr[i] = arr[i];
        }
    }
}

template <typename T>
void MyVector<T>::copyMyVector(const MyVector<T>& other){
    this->l = other.l;
    copyArr(other.arr);
}

template <typename T>
void MyVector<T>::resize(const int l){
    int newSize = this->l + l;
    T* temp = new T[newSize];
    for(int i = 0; i < this->l; i++){
        temp[i] = this->arr[i];
    }

    delete[] this->arr;
    this->arr = temp;
    this->l += l;
}

template <typename T>
void MyVector<T>::addElement(const T& obj){
    resize(1);
    arr[l-1] = obj;
}

/**
template <typename T>
void MyVector<T>::addElement(const T&& obj)
{
    resize(1);
    arr[l-1] = obj;
}
*/

template <typename T>
void MyVector<T>::removeElement(const int position){
    MyVector<T> tmp;
    for(int i=0; i<this->l; i++){
        if(i != position){
            tmp.addElement(this->arr[i]);
        }
    }
    *this = tmp;
}

template <typename T>
int MyVector<T>::getSize() const{
    return l;
}
template <typename T>
const T& MyVector<T>::operator[](const int position)const{
    if (position >= l || position < 0)
        throw std::out_of_range("Index out of range");
    return arr[position];
}

template <typename T>
T& MyVector<T>::operator[](const int position){
    if (position >= l || position < 0)
        throw std::out_of_range("Index out of range");
    return arr[position];
}


#endif //_VECTOR_H
