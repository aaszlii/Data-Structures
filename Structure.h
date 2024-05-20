#pragma once

class Structure {
public:
    virtual void insertFront(int data) = 0;
    virtual void insert(int data, int index) = 0;
    virtual void insertBack(int data) = 0;
    virtual void removeFront() = 0;
    virtual void remove(int index) = 0;
    virtual void removeBack() = 0;
    virtual int search(int data) = 0;
    virtual void print() = 0;
    virtual void generateRandomNumbers(int count) =0;
};
