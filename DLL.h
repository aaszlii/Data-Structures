#pragma once
#include <iostream>
#include "Node.h"
#include "Structure.h"
using namespace std;


class DLL : public Structure {
private:
    Node* head;
    Node* tail;
    int size;
public:
    DLL();
    ~DLL();

    void insertFront(int data);
    void insert(int data, int index);
    void insertBack(int data);
    void removeFront();
    void remove(int index);
    void removeBack();
    int search(int data);
    void print();
    void generateRandomNumbers(int count);
};

