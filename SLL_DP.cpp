#include "SLL_DP.h"
#include "Node.h"

#include <iostream>

using namespace std;


void SLL_DP::insertFront(int value) {

    Node* newNode = new Node(value);

    if (!head) {
        head = newNode;
        tail = newNode;
        size++;

    }
    else {

        newNode->next = head;
        head = newNode;
        size++;

    }

}

void SLL_DP::insertBack(int value) {

    Node* newNode = new Node(value);

    if (!head) {
        head = newNode;
        tail = newNode;
        size++;

    }
    else {

        tail->next = newNode;
        tail = newNode;
        size++;


    }

}

void SLL_DP::removeFront() {

    if (!head) {
        cout << "List is empty" << endl;
        return;
    }

    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
        size--;
        return;
    }

    Node* current = head;
    head = current->next;
    delete current;
    size--;

}


void SLL_DP::removeBack() {

    if (!head) {
        cout << "List is empty" << endl;
        return;
    }

    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
        size--;
        return;  // Dodajemy return tutaj
    }

    Node* current = head;

    while (current->next != tail) {
        current = current->next;
    }
    delete tail;
    tail = current;
    tail->next = nullptr;
    size--;

}


int SLL_DP::search(int value) {

    Node* current = head;

    while (current) {

        if (current->data == value) {
            return current->data;
        }
        current = current->next;
    }
    return -1;

}

void SLL_DP::insert(int value, int id) {

    Node* newNode = new Node(value);
    Node* current = head;

    if (id > size) {

        cout << "Za ma?a lista" << endl;
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

void SLL_DP::remove(int id) {

    Node* behind = head;

    if (size == 0) {

        cout << "Lista nie ma element?w" << endl;
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
    else if (id > size || id < 0) {

        cout << "Podany indeks nie pasuje do rozmiru listy" << endl;
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

void SLL_DP::print() {

    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;

    }
    cout << endl;

}

int SLL_DP::Size_of_list()const {
    return size;
}

void SLL_DP::generateRandomNumbers(int count) {
    // Generowanie i dodawanie losowych liczb do struktury ArrList
    for (int i = 0; i < count; ++i) {
        int randomNumber = rand(); // Generowanie losowej liczby
        insertBack(randomNumber); // Dodanie liczby do koñca listy
    }
}