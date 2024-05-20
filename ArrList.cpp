#include <iostream>
#include "ArrList.h"
using namespace std;


ArrList::ArrList() {
    size = 1;
    arr = new int[size];
    end = 0;
}


ArrList::~ArrList() {
    delete[] arr;
}

// Wstawia element na pocz¹tek tablicy
void ArrList::insertFront(int data) {
    if (end == size) {
        int* temp = new int[2 * size]; // Tworzy tymczasow¹ tablicê o dwukrotnie wiêkszym rozmiarze

        for (int i = 0; i < end; i++) { // Przenosi wszystkie elementy ze starej tablicy do nowej
            temp[i + 1] = arr[i]; // Z indeksem przesuniêtym o 1 w prawo 
        }

        delete[] arr;
        size *= 2;
        arr = temp;
    }
    else { // Przesuwa wszystkie elementy o jeden w prawo 
        for (int i = end; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
    }

    arr[0] = data;
    end++;
}

// Wstawia element na okreœlonej pozycji w tablicy
void ArrList::insert(int data, int index) {
    if (index <= end) {
        if (end == size) {
            int* temp = new int[2 * size]; // Tworzy tymczasow¹ tablicê o dwukrotnie wiêkszym rozmiarze

            for (int i = 0; i < index; i++) { // Przenosi elementy ze starej tablicy do nowej
                temp[i] = arr[i];
            }

            for (int i = index; i < end; i++) { // Przenosi resztê elementów ze starej tablicy do nowej
                temp[i + 1] = arr[i]; // Z indeksem przesuniêtym o 1 w prawo
            }

            delete[] arr;
            size *= 2;
            arr = temp;
        }
        else {
            for (int i = end; i > index; i--) { // Przesuwa wszystkie elementy o jeden w prawo od indeksu
                arr[i] = arr[i - 1];
            }
        }

        arr[index] = data;
        end++;
    }
}

// Wstawia element na koniec tablicy
void ArrList::insertBack(int data) {
    if (end == size) {
        int* temp = new int[2 * size]; // Tworzy tymczasow¹ tablicê o dwukrotnie wiêkszym rozmiarze

        for (int i = 0; i < size; i++) { // Przenosi wszystkie elementy ze starej tablicy do nowej
            temp[i] = arr[i];
        }

        delete[] arr;
        size *= 2;
        arr = temp;
    }

    arr[end] = data;
    end++;
}

// Usuwa element z pocz¹tku tablicy
void ArrList::removeFront() {
    if (end > 0) {
        for (int i = 0; i < end - 1; i++) { // Przesuwa wszystkie elementy o jeden w lewo
            arr[i] = arr[i + 1];
        }
        end--;
    }
}

// Usuwa element z okreœlonej pozycji w tablicy
void ArrList::remove(int index) {
    if (index < end) {
        for (int i = index; i < end - 1; i++) { // Przesuwa wszystkie elementy o jeden w lewo od indeksu
            arr[i] = arr[i + 1];
        }
        end--;
    }
}

// Usuwa element z koñca tablicy
void ArrList::removeBack() {
    if (end > 0) {
        end--;
    }
}

// Szuka elementu w tablicy
int ArrList::search(int data) {
    for (int i = 0; i < end; i++) { // Przeszukuje tablicê
        if (arr[i] == data) { // Je¿eli znajdzie szukany element zwraca go
            return i;
        }
    }
    return -1;
}

// Wyœwietla wszystkie elementy tablicy
void  ArrList::print() {
    for (int i = 0; i < end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void ArrList::loadFile() {};

// Zwraca rozmiar tablicy
int ArrList::getSize() {
    return size;
}

void ArrList::generateRandomNumbers(int count) {
    // Generowanie i dodawanie losowych liczb do struktury ArrList
    for (int i = 0; i < count; ++i) {
        int randomNumber = rand(); // Generowanie losowej liczby
        insertBack(randomNumber); // Dodanie liczby do koñca listy
    }
}








