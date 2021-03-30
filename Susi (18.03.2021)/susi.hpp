#ifndef SUSI_H
#define SUSI_H
#include "student.hpp"


struct Susi{
    Student students[100];
    int studentsCnt;
    char studentsFile[205];
    char subjectsFile[100];

    Susi(const char* subjectsFile, const char* studentsFile);

    /// We need some helping methods to search in the database
    int findStudent(const int fn);
    bool findSubject(const char *subject);

    void addStudent(const Student& student);
    void addSubjectToStudent(const int fn, const char *subject);
    void printInfo(const int fn);

    /// We save all changes in the end of the program
    void save();
};

Susi::Susi(const char* subjectsFile, const char* studentsFile){
    strcpy(this->studentsFile, studentsFile);

    this->studentsCnt = 0;

    char filename[205];
    std::ifstream fin(studentsFile);
    while(fin>>filename){
        Student newStudent((const char*)filename);
        addStudent(newStudent);
    }
    fin.close();

    /// We only need the file with the list of Subjects because we never change it
    strcpy(this->subjectsFile, subjectsFile);
}

void Susi::addStudent(const Student& student){
    this->students[this->studentsCnt].copyStudent(student);
    this->studentsCnt++;
}

int Susi::findStudent(const int fn){
    for(int i=0; i<this->studentsCnt; i++){
        if(this->students[i].fn == fn) return i;
    }
    return -1;
}

bool Susi::findSubject(const char *subject){
    char readSubject[100];
    std::ifstream fin(subjectsFile);

    bool found = false;
    while(fin>>readSubject && !found){
        if(!strcmp(readSubject, subject)){
            found = true;
        }
    }
    fin.close();
    return found;
}

void Susi::addSubjectToStudent(const int fn, const char* subject){
    int studentPosition = findStudent(fn);
    if(studentPosition == -1 || !findSubject(subject)) return;

    this->students[studentPosition].addSubject(subject);
}

void Susi::printInfo(const int fn){
    int studentPosition = findStudent(fn);
    if(studentPosition == -1) return;
    this->students[studentPosition].printInfo();
}

void Susi::save(){
    std::ofstream fout(this->studentsFile);

    for(int i=0; i<this->studentsCnt; i++){
        this->students[i].save();
        fout << this->students[i].fileName << std::endl;
    }

    fout.close();
}

#endif //SUSI_H
