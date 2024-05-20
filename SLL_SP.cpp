#include<iostream>
#include "SLL_SP.h"
#include "Node.h"
using namespace std;

void SLL_SP::insertFront(int value) {

    Node* newNode = new Node(value);

    if (!head) {
        head = newNode;
        size++;

    }
    else {

        newNode->next = head;
        head = newNode;
        size++;

    }

}

void SLL_SP::insertBack(int value) {

    Node* newNode = new Node(value);

    if (!head) {
        head = newNode;
        size++;

    }
    else {
        Node* current = head;

        while (current->next) {
            current = current->next;
        }

        current->next = newNode;

        size++;


    }
}

void SLL_SP::removeFront() {

    if (!head) {
        cout << "Lista nie posiada elementow" << endl;
        return;
    }
    else if (!head->next) {
        delete head;
        head = nullptr;
        size--;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
    size--;

}

void SLL_SP::removeBack() {

    if (!head) {
        cout << "Lista nie posiada elementow" << endl;
        return;
    }
    else if (!head->next) {
        delete head;
        head = nullptr;
        size--;
        return;  // Dodajemy return tutaj
    }

    Node* current = head;

    while (current->next->next) {
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;
    size--;

}


void SLL_SP::insert(int value, int id) {

    Node* newNode = new Node(value);
    Node* current = head;

    if (id > size || id < 0) {

        cout << "Wskazujesz poza zakres listy" << endl;
        return;

    }
    else if (id == 1) {

        insertFront(value);
        return;

    }
    else if (id == size) {

        insertBack(value);
        return;
    }

    while (id - 2) {
        current = current->next;
        id--;
    }
    newNode->next = current->next;
    current->next = newNode;
    size++;


}

void SLL_SP::remove(int id) {

    Node* behind = head;

    if (size == 0) {

        cout << "Lista nie ma elementow" << endl;
        return;

    }
    else if (id > size || id < 0) {
        cout << "Podany indeks nie pasuje do rozmiaru listy" << endl;
        return;

    }
    else if (id == 0) {

        cout << "Nie ma elementu o indeksie 0" << endl;
        return;

    }
    else if (id == 1) {

        removeFront();
        return;

    }
    else if (id == size) {

        removeBack();
        return;
    }

    while (id - 2) {
        behind = behind->next;
        id--;
    }
    Node* current = behind->next;
    behind->next = current->next;
    delete current;

    size--;


}

int SLL_SP::search(int value) {

    Node* current = head;

    while (current) {

        if (current->data == value) {

            return current->data;
        }
        current = current->next;
    }
    return -1;

}


void SLL_SP::print() {

    Node* current = head;

    while (current) {

        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

}

int SLL_SP::Size_of_list()const {
    return size;
}

void SLL_SP::generateRandomNumbers(int count) {
    // Generowanie i dodawanie losowych liczb do struktury ArrList
    for (int i = 0; i < count; ++i) {
        int randomNumber = rand(); // Generowanie losowej liczby
        insertBack(randomNumber); // Dodanie liczby do koñca listy
    }
}