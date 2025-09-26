#include <iostream>
using namespace std;

struct lifo {
   int value;         
   struct lifo *next; 
};
typedef struct lifo stack;

void create (stack **top) {
   *top = NULL; 
}

void push (stack **top, int element) {
    stack *newNode = new stack;

    if (newNode == NULL) {
        cout << "gagal mengalokasikan memori\n" << endl;
    }

    newNode->value = element; 
    newNode->next = *top;    
    *top = newNode;          
    cout << "Pushed: " << element << endl; 
} 

int pop (stack **top) {
    int t;  
    stack *p;

    if (*top == NULL){ 
        cout << "Stack kosong\n" << endl;
    } else {
        t = (*top)->value;      
        p = *top;              
        *top = (*top)->next;   
        delete p;             
        cout << "Popped: " << t << endl; 
        return t;              
    }
}

void display(stack *top) {
    if (top == NULL) {
        cout << "stack kosong\n";
    } else {
        cout << "\nisi stack : \n";
        stack *current = top;
        while (current != NULL) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
}

int main() {
    stack *A;
    create(&A);

    push(&A,10);
    push(&A,20);
    push(&A,30);

    display(A);

    pop(&A);

    display(A);

    return 0;
}