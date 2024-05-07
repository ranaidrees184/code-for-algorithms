#include <iostream>
using namespace std;

// Define the maximum size of the stack
#define MAX_SIZE 100

class Stack {
private:
    int top;
    int arr[MAX_SIZE];

public:
    Stack() {
        top = -1; // Initialize top to -1 to indicate an empty stack
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX_SIZE - 1);
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push more elements.\n";
            return;
        }
        arr[++top] = value;
        cout << value << " pushed to stack.\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop from an empty stack.\n";
            return;
        }
        cout << arr[top--] << " popped from stack.\n";
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return -1; // Return -1 if stack is empty
        }
        return arr[top];
    }
};

int main() {
    Stack myStack;

    myStack.push(5);
    myStack.push(10);
    myStack.push(15);

    cout << "Top element of stack: " << myStack.peek() << endl;

    myStack.pop();
    myStack.pop();

    cout << "Top element of stack after popping: " << myStack.peek() << endl;

    return 0;
}
