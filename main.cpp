#include <iostream>
#include <fstream>
#include <chrono>
#include <conio.h>
#include "ArrList.h"
#include "DLL.h"
#include "SLL_SP.h"
#include "SLL_DP.h"
using namespace std;
using namespace std::chrono;

class Timer {
private:
    time_point<steady_clock> start_time;
    time_point<steady_clock> end_time;
public:
    void start() {
        start_time = steady_clock::now();
    }

    void stop() {
        end_time = steady_clock::now();
    }

    double elapsed_milliseconds() const {
        return duration<double, std::milli>(end_time - start_time).count();
    }
};

void run() {
    Structure* wsk{};
    ArrList array;
    SLL_SP sll_h;
    SLL_DP sll_ht;
    DLL dll;
    Timer timer;
    int choice = 0;
    while (choice != 5) {
        cout << "Wybierz strukture:" << endl;
        cout << "1. Tablica dynamiczna" << endl;
        cout << "2. Lista jednokierunkowa (head)" << endl;
        cout << "3. Lista jednokierunkowa (head,tail)" << endl;
        cout << "4. Lista dwukierunkowa" << endl;
        cout << "5. Wyjdz" << endl;

        cin >> choice;
        system("cls");
        switch (choice) {
        case 1: {
            wsk = &array;
            break;
        }
        case 2: {
            wsk = &sll_h;
            break;
        }
        case 3: {
            wsk = &sll_ht;
            break;
        }
        case 4: {
            wsk = &dll;
            break;
        }
        case 5: {
            return;
            break;
        }
        }

        int choice1 = 0;
        while (choice1 != 10)
        {
            cout << "1. Dodaj element na poczatku" << endl;
            cout << "2. Dodaj element na wybranej pozycji" << endl;
            cout << "3. Dodaj element na koncu" << endl;
            cout << "4. Usun element na poczatku" << endl;
            cout << "5. Usun element na wybranej pozycji" << endl;
            cout << "6. Usun element na koncu" << endl;
            cout << "7. Znajdz wybrany element (zwraca pozycje)" << endl;
            cout << "8. Wyswietl" << endl;
            cout << "9. Cofnij do menu glownego" << endl;
            cout << "10. Wygeneruj losowo liczby " << endl;
            cin >> choice1;

            switch (choice1) {
            case 1: {
                system("cls");
                int data;
                cout << "Podaj wartosc: ";
                cin >> data;
                timer.start();
                wsk->insertFront(data);
                timer.stop();
                cout << "Czas wykonania operacji: " << timer.elapsed_milliseconds() << " ms" << endl;
                break;
            }
            case 2: {
                system("cls");
                int data;
                int index;
                cout << "Podaj wartosc: ";
                cin >> data;
                cout << endl << "Podaj numer indeksu (numeracja od 0): ";
                cin >> index;
                timer.start();
                wsk->insert(data, index);
                timer.stop();
                cout << "Czas wykonania operacji: " << timer.elapsed_milliseconds() << " ms" << endl;
                break;
            }
            case 3: {
                system("cls");
                int data;
                cout << "Podaj wartosc: ";
                cin >> data;
                timer.start();
                wsk->insertBack(data);
                timer.stop();
                cout << "Czas wykonania operacji: " << timer.elapsed_milliseconds() << " ms" << endl;
                break;
            }
            case 4: {
                timer.start();
                wsk->removeFront();
                timer.stop();
                cout << "Czas wykonania operacji: " << timer.elapsed_milliseconds() << " ms" << endl;
                break;
            }
            case 5: {
                system("cls");
                int index;
                cout << "Podaj numer indeksu, ktory chcesz usunac (numeracja od 0): ";
                cin >> index;
                timer.start();
                wsk->remove(index);
                timer.stop();
                cout << "Czas wykonania operacji: " << timer.elapsed_milliseconds() << " ms" << endl;
                break;
            }
            case 6: {
                timer.start();
                wsk->removeBack();
                timer.stop();
                cout << "Czas wykonania operacji: " << timer.elapsed_milliseconds() << " ms" << endl;
                break;
            }
            case 7: {
                system("cls");
                int data;
                cout << "Podaj wartosc: ";
                cin >> data;
                timer.start();
                cout << "Pozycja znalezionego elementu: " << wsk->search(data) << endl;
                timer.stop();
                cout << "Czas wykonania operacji: " << timer.elapsed_milliseconds() << " ms" << endl;
                break;
            }
            case 8: {
                timer.start();
                wsk->print();
                timer.stop();
                cout << "Czas wykonania operacji: " << timer.elapsed_milliseconds() << " ms" << endl;
                break;
            }
            case 9: {
                system("cls");
                break;
            }
            case 10: {
                system("cls");
                int count;
                cout << "Podaj ilosc liczb do wygenerowania: ";
                cin >> count;
                timer.start();
                wsk->generateRandomNumbers(count);
                timer.stop();
                cout << "Czas wykonania operacji: " << timer.elapsed_milliseconds() << " ms" << endl;
                break;
            }
            }
        }
    }
}

int main() {
    run();
    return 0;
}
