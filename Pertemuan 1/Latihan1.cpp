#include<iostream>
using namespace std;

#include <iostream>
using namespace std;

#define max 5
int stack[max];
int top = -1; // awalnya kosong

//push
void push (int value) {
    if (top == max) {
        cout << "stack penuh!!\n";
    } else {
        top++;
        stack[top] = value;
        cout << value << " masuk ke stack \n";
    }
}

//pop
void pop () {
    if (top == -1) {
        cout << "Stack kosong!!\n";
    } else {
        cout << stack[top] << " keluar dari stack \n";
        top--;
    }
}

//nampilin stack
void display() {
    if (top == -1) {
        cout << "stack kosong\n";
    } else {
        cout << "\nisi stack : ";
        for(int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        // cout << "\nisi array (index 0 ke max-1): \n";
        // for(int i = 0; i < top; i++) {
        //     cout << "[ " << i << " ]" << stack[i] << " ";
        // }
        cout << endl;
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    for(int i = 0; i <= 4; i++) {
        display();
        pop();
    }
    display();

    return 0;
}