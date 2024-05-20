#pragma once
#include<iostream>
#include "Node.h"
#include "Structure.h"
using namespace std;


class SLL_SP : public Structure {

private:
    Node* head;
    int size;

public:
    SLL_SP() : head(nullptr), size(0) {};
    ~SLL_SP() {};

    void insertFront(int value);
    void insertBack(int value);
    void removeFront();
    void removeBack();
    void insert(int value, int id);
    void remove(int id);
    int search(int value);
    void print();
    int Size_of_list()const;
    void generateRandomNumbers(int count);
};


