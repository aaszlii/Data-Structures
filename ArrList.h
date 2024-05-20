#pragma once
#include <iostream>
#include "Structure.h"
using namespace std;

class ArrList : public Structure
{
private:
    int* arr;
    int size;
    int end;

public:
    ArrList();
    ~ArrList();

    void insertFront(int data);
    void insert(int data, int index);
    void insertBack(int data);
    void removeFront();
    void remove(int index);
    void removeBack();
    int search(int data);
    void loadFile();
    void print();
    int getSize();
    void generateRandomNumbers(int count);

};

