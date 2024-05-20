#pragma once
#include <iostream>
#include "Node.h"
#include "Structure.h"

using namespace std;

class SLL_DP : public Structure {

private:
    Node* head;
    Node* tail;
    int size;

public:
    SLL_DP() : head(nullptr), tail(nullptr), size(0) {};
    ~SLL_DP() {};

    void insertFront(int value);
    void insertBack(int value);
    void removeFront();
    void removeBack();
    int search(int value);
    void insert(int value, int id);
    void remove(int id);
    void print();
    int Size_of_list()const;
    void generateRandomNumbers(int count);

};

