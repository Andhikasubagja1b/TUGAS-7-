#include <iostream>
using namespace std;

int langkah = 1; // Untuk menghitung langkah

// Sekarang hanoi menerima array berat
void hanoi(int n, int berat[], char from, char aux, char to) {
    if (n == 1) {
        cout << "Langkah " << langkah++ << ": ";
        cout << "Pindahkan batu " << berat[n] << " dari " << from << " ke " << to << endl;
        return;
    }

    hanoi(n - 1, berat, from, to, aux);

    cout << "Langkah " << langkah++ << ": ";
    cout << "Pindahkan batu " << berat[n] << " dari " << from << " ke " << to << endl;

    hanoi(n - 1, berat, aux, from, to);
}

// ==============================================
// Implementasi Stack tambahan tanpa mengubah kode di atas
// ==============================================

const int MAX_SIZE = 100;

class Stack {
private:
    int data[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    // Operasi push
    void push(int value) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack penuh!" << endl;
            return;
        }
        data[++top] = value;
    }

    // Operasi pop
    int pop() {
        if (isEmpty()) {
            cout << "Stack kosong!" << endl;
            return -1;
        }
        return data[top--];
    }

    // Operasi peek
    int peek() {
        if (isEmpty()) {
            cout << "Stack kosong!" << endl;
            return -1;
        }
        return data[top];
    }

    // Operasi isEmpty
    bool isEmpty() {
        return (top < 0);
    }

    // Operasi isFull
    bool isFull() {
        return (top >= MAX_SIZE - 1);
    }
};

void demoStack() {
    cout << "\nDemo Operasi Stack:" << endl;
    Stack s;

    cout << "Apakah stack kosong? " << (s.isEmpty() ? "Ya" : "Tidak") << endl;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Elemen teratas: " << s.peek() << endl;
    cout << "Pop: " << s.pop() << endl;
    cout << "Elemen teratas setelah pop: " << s.peek() << endl;

    cout << "Apakah stack kosong? " << (s.isEmpty() ? "Ya" : "Tidak") << endl;
}

int main() {
    int jumlahbatu;
    cout << "Masukkan jumlah batu: ";
    cin >> jumlahbatu;

    int berat[jumlahbatu + 1]; // Array berat batu, +1 karena kita mulai dari indeks 1

    // Mengisi berat batu
    for (int i = 1; i <= jumlahbatu; i++) {
        berat[i] = i * 10; // Misal berat batu kelipatan 10
    }

    cout << "\nLangkah-langkah perpindahan:\n" << endl;
    hanoi(jumlahbatu, berat, 'A', 'B', 'C');

    // Demo operasi stack
    demoStack();

    return 0;
}
