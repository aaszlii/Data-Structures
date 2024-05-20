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
    Node* current = head; // Ustawia wska�nik na pocz�tek listy
    Node* next;

    while (current != nullptr) { // Przechodzi przez ca�� list�
        next = current->next; // Zapisuje wska�nik na nast�pny element
        delete current; // Usuwa bie��cy element
        current = next; // Przechodzi do nast�pnego elementu
    }

    head = nullptr; // Ustawia wska�nik na pocz�tek listy na null
    tail = nullptr; // Ustawia wska�nik na koniec listy na null
}

// Wstawia element na pocz�tek listy
void DLL::insertFront(int data) {
    Node* newNode = new Node(data);
    if (head != nullptr) {
        newNode->next = head; // Ustawia wska�nik na nast�pny element na pocz�tek listy
        head->prev = newNode; // Ustawia wska�nik na poprzedni element pocz�tku listy na nowy w�ze�
    }
    head = newNode; // Ustawia pocz�tek listy na nowy w�ze�
    if (tail == nullptr) {
        tail = newNode; // Ustawia koniec listy na nowy w�ze�
    }
    size++;
}

// Wstawia element na okre�lonej pozycji w li�cie
void DLL::insert(int data, int index) {
    if (index < 0 || index > size) {
        return;
    }

    Node* newNode = new Node(data);

    if (index <= size / 2) { // Je�eli indeks jest bli�ej pocz�tku listy
        Node* temp = head; // Ustawia wska�nik na pocz�tek listy
        for (int i = 0; i < index; i++) { // Przechodzi do okre�lonej pozycji
            temp = temp->next;
        }
        newNode->next = temp; // Ustawia wska�nik na nast�pny element na bie��cy element
        newNode->prev = temp->prev; // Ustawia wska�nik na poprzedni element na poprzedni element bie��cego elementu
        if (temp->prev != nullptr) { // Je�eli bie��cy element nie jest pocz�tkiem listy
            temp->prev->next = newNode; // Ustawia wska�nik na nast�pny element poprzedniego elementu na nowy w�ze�
        }
        temp->prev = newNode; // Ustawia wska�nik na poprzedni element bie��cego elementu na nowy w�ze�
        if (index == 0) { // Je�eli nowy w�ze� jest pocz�tkiem listy
            head = newNode; // Ustawia pocz�tek listy na nowy w�ze�
        }
    }
    else { // Je�eli indeks jest bli�ej ko�ca listy
        Node* temp = tail; // Ustawia wska�nik na koniec listy
        for (int i = size; i > index; i--) { // Przechodzi do okre�lonej pozycji
            temp = temp->prev;
        }
        newNode->prev = temp; // Ustawia wska�nik na poprzedni element na bie��cy element
        newNode->next = temp->next; // Ustawia wska�nik na nast�pny element na nast�pny element bie��cego elementu
        if (temp->next != nullptr) { // Je�eli bie��cy element nie jest ko�cem listy
            temp->next->prev = newNode; // Ustawia wska�nik na poprzedni element nast�pnego elementu na nowy w�ze�
        }
        temp->next = newNode; // Ustawia wska�nik na nast�pny element bie��cego elementu na nowy w�ze�
        if (index == size) { // Je�eli nowy w�ze� jest ko�cem listy
            tail = newNode; // Ustawia koniec listy na nowy w�ze�
        }
    }

    size++; // Zwi�ksza rozmiar listy
}

// Wstawia element na koniec listy
void DLL::insertBack(int data) {
    Node* newNode = new Node(data); // Tworzy nowy w�ze� z danymi
    if (head == nullptr) { // Je�eli lista jest pusta
        head = newNode; // Ustawia pocz�tek listy na nowy w�ze�
        tail = newNode; // Ustawia koniec listy na nowy w�ze�
    }
    else { // Je�eli lista nie jest pusta
        tail->next = newNode; // Ustawia wska�nik na nast�pny element ko�ca listy na nowy w�ze�
        newNode->prev = tail; // Ustawia wska�nik na poprzedni element nowego w�z�a na koniec listy
        tail = newNode; // Ustawia koniec listy na nowy w�ze�
    }
    size++; // Zwi�ksza rozmiar listy
}

// Usuwa element z pocz�tku listy
void DLL::removeFront() {
    if (size == 0) { // Je�eli lista jest pusta
        return; // Ko�czy funkcj�
    }

    Node* temp = head; // Ustawia wska�nik na pocz�tek listy

    if (temp->next != nullptr) { // Je�eli lista ma wi�cej ni� jeden element
        temp->next->prev = nullptr; // Ustawia wska�nik na poprzedni element drugiego elementu na null
        head = temp->next; // Ustawia pocz�tek listy na drugi element
    }
    else { // Je�eli lista ma tylko jeden element
        head = nullptr; // Ustawia pocz�tek listy na null
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
        insertBack(randomNumber); // Dodanie liczby do ko�ca listy
    }
}