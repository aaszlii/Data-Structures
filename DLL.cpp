#include <iostream>
#include "DLL.h"
#include "Node.h"
using namespace std;


DLL::DLL() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}


DLL::~DLL() {
    Node* current = head; // Ustawia wskaŸnik na pocz¹tek listy
    Node* next;

    while (current != nullptr) { // Przechodzi przez ca³¹ listê
        next = current->next; // Zapisuje wskaŸnik na nastêpny element
        delete current; // Usuwa bie¿¹cy element
        current = next; // Przechodzi do nastêpnego elementu
    }

    head = nullptr; // Ustawia wskaŸnik na pocz¹tek listy na null
    tail = nullptr; // Ustawia wskaŸnik na koniec listy na null
}

// Wstawia element na pocz¹tek listy
void DLL::insertFront(int data) {
    Node* newNode = new Node(data);
    if (head != nullptr) {
        newNode->next = head; // Ustawia wskaŸnik na nastêpny element na pocz¹tek listy
        head->prev = newNode; // Ustawia wskaŸnik na poprzedni element pocz¹tku listy na nowy wêze³
    }
    head = newNode; // Ustawia pocz¹tek listy na nowy wêze³
    if (tail == nullptr) {
        tail = newNode; // Ustawia koniec listy na nowy wêze³
    }
    size++;
}

// Wstawia element na okreœlonej pozycji w liœcie
void DLL::insert(int data, int index) {
    if (index < 0 || index > size) {
        return;
    }

    Node* newNode = new Node(data);

    if (index <= size / 2) { // Je¿eli indeks jest bli¿ej pocz¹tku listy
        Node* temp = head; // Ustawia wskaŸnik na pocz¹tek listy
        for (int i = 0; i < index; i++) { // Przechodzi do okreœlonej pozycji
            temp = temp->next;
        }
        newNode->next = temp; // Ustawia wskaŸnik na nastêpny element na bie¿¹cy element
        newNode->prev = temp->prev; // Ustawia wskaŸnik na poprzedni element na poprzedni element bie¿¹cego elementu
        if (temp->prev != nullptr) { // Je¿eli bie¿¹cy element nie jest pocz¹tkiem listy
            temp->prev->next = newNode; // Ustawia wskaŸnik na nastêpny element poprzedniego elementu na nowy wêze³
        }
        temp->prev = newNode; // Ustawia wskaŸnik na poprzedni element bie¿¹cego elementu na nowy wêze³
        if (index == 0) { // Je¿eli nowy wêze³ jest pocz¹tkiem listy
            head = newNode; // Ustawia pocz¹tek listy na nowy wêze³
        }
    }
    else { // Je¿eli indeks jest bli¿ej koñca listy
        Node* temp = tail; // Ustawia wskaŸnik na koniec listy
        for (int i = size; i > index; i--) { // Przechodzi do okreœlonej pozycji
            temp = temp->prev;
        }
        newNode->prev = temp; // Ustawia wskaŸnik na poprzedni element na bie¿¹cy element
        newNode->next = temp->next; // Ustawia wskaŸnik na nastêpny element na nastêpny element bie¿¹cego elementu
        if (temp->next != nullptr) { // Je¿eli bie¿¹cy element nie jest koñcem listy
            temp->next->prev = newNode; // Ustawia wskaŸnik na poprzedni element nastêpnego elementu na nowy wêze³
        }
        temp->next = newNode; // Ustawia wskaŸnik na nastêpny element bie¿¹cego elementu na nowy wêze³
        if (index == size) { // Je¿eli nowy wêze³ jest koñcem listy
            tail = newNode; // Ustawia koniec listy na nowy wêze³
        }
    }

    size++; // Zwiêksza rozmiar listy
}

// Wstawia element na koniec listy
void DLL::insertBack(int data) {
    Node* newNode = new Node(data); // Tworzy nowy wêze³ z danymi
    if (head == nullptr) { // Je¿eli lista jest pusta
        head = newNode; // Ustawia pocz¹tek listy na nowy wêze³
        tail = newNode; // Ustawia koniec listy na nowy wêze³
    }
    else { // Je¿eli lista nie jest pusta
        tail->next = newNode; // Ustawia wskaŸnik na nastêpny element koñca listy na nowy wêze³
        newNode->prev = tail; // Ustawia wskaŸnik na poprzedni element nowego wêz³a na koniec listy
        tail = newNode; // Ustawia koniec listy na nowy wêze³
    }
    size++; // Zwiêksza rozmiar listy
}

// Usuwa element z pocz¹tku listy
void DLL::removeFront() {
    if (size == 0) { // Je¿eli lista jest pusta
        return; // Koñczy funkcjê
    }

    Node* temp = head; // Ustawia wskaŸnik na pocz¹tek listy

    if (temp->next != nullptr) { // Je¿eli lista ma wiêcej ni¿ jeden element
        temp->next->prev = nullptr; // Ustawia wskaŸnik na poprzedni element drugiego elementu na null
        head = temp->next; // Ustawia pocz¹tek listy na drugi element
    }
    else { // Je¿eli lista ma tylko jeden element
        head = nullptr; // Ustawia pocz¹tek listy na null
        tail = nullptr; // Ustawia koniec listy na null
    }

    delete temp; // Usuwa pierwszy element
    size--; // Zmniejsza rozmiar listy
}

void DLL::remove(int index) {
    if (index < 0 || index >= size) {
        return;
    }

    Node* temp;
    if (index <= size / 2) {
        temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
    }
    else {
        temp = tail;
        for (int i = size - 1; i > index; i--) {
            temp = temp->prev;
        }
    }

    if (temp->prev != head->prev) {
        temp->prev->next = temp->next;
    }
    else {
        head = temp->next;
    }

    if (temp->next != tail->next) {
        temp->next->prev = temp->prev;
    }
    else {
        tail = temp->prev;
    }

    delete temp;   // usuwa obiekt zadany obiekt 
    size--;
}



void DLL::removeBack() {
    if (size == 0) {
        return;
    }

    Node* temp = tail;

    if (temp->prev != nullptr) {
        temp->prev->next = nullptr;
        tail = temp->prev;
    }
    else {
        head = nullptr;
        tail = nullptr;
    }

    delete temp;
    size--;
}

int DLL::search(int data) {
    Node* temp = head;
    int position = 0;
    while (temp != nullptr) {
        if (temp->data == data) {
            return position;
        }
        position++;
        temp = temp->next;
    }
    return -1;
}

void DLL::print() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


void DLL::generateRandomNumbers(int count) {
    // Generowanie i dodawanie losowych liczb do struktury ArrList
    for (int i = 0; i < count; ++i) {
        int randomNumber = rand(); // Generowanie losowej liczby
        insertBack(randomNumber); // Dodanie liczby do koñca listy
    }
}