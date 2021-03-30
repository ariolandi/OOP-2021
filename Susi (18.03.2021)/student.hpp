#ifndef SUSI_STUDENTS_H
#define SUSI_STUDENTS_H
#include <cstring>
#include<fstream>
#include<iostream>


struct Student{
    char firstName[100];
    char lastName[100];
    int fn;
    int subjectsCount;
    char subjects[100][50];
    char fileName[205];

    /// We have three different constructors here:
    /// We need a default constuctor because we have an Student array
    /// We need to can create a new student with their names and faculty number
    /// And we need have a way to load a student from a file
    /// If we murge the Default constructor with the second one we will create an ambiguous situation for Student(const char*)
    Student(){}
    Student(const char* firstName, const char* lastName, const int fn);
    Student(const char* filename);

    void createFilename();
    /// We need a mechanism to copy the information from another Student object
    void copyStudent(const Student& other);

    void addSubject(const char* subjectName);

    void read();
    void printInfo(std::ostream& out = std::cout);

    /// We need a way to save the updated information in the file
    void save();
};

Student::Student(const char* firstName, const char* lastName, const int fn){
    strcpy(this->firstName, firstName);
    strcpy(this->lastName,lastName);
    this->fn = fn;
    this->subjectsCount = 0;
    createFilename();
}

Student::Student(const char* filename){
    /// In the feature we will handle the possible errors for working with files
    /// Think about how we can implement it here
    std::ifstream fin(filename);
    fin >> this->firstName >> this->lastName >> this->fn;

    char subjectName[50];
    while(fin >> subjectName){
        addSubject(subjectName);
    }

    strcpy(this->fileName, filename);
    fin.close();
}

void Student::createFilename(){
    strcpy(this->fileName, this->firstName);
    strcat(this->fileName, "_");
    strcat(this->fileName, this->lastName);
    strcat(this->fileName, ".txt");
}

void Student::copyStudent(const Student& other){
    strcpy(this->firstName, other.firstName);
    strcpy(this->lastName, other.lastName);
    this->fn = other.fn;
    this->subjectsCount = other.subjectsCount;
    for(int i=0; i<this->subjectsCount; i++){
        addSubject(other.subjects[i]);
    }
    createFilename();
}

void Student::addSubject(const char *subjectName){
    strcpy(this->subjects[this->subjectsCount], subjectName);
    this->subjectsCount++;
}

void Student::read(){
    std::cin >> this->firstName >> this->lastName >> this->fn;
    this->subjectsCount = 0;
    createFilename();
}

void Student::printInfo(std::ostream& out){
    out << this->firstName << " " << this->lastName << " " << this->fn << std::endl;
    for (int i = 0; i < this->subjectsCount; i++) {
        out << this->subjects[i] << std::endl;
    }
}

void Student::save(){
    std::ofstream fout(this->fileName);
    printInfo(fout);
    fout.close();
}

#endif //SUSI_STUDENTS_H
