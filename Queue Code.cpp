#include <iostream>
using namespace std;

// Define the maximum size of the queue
#define MAX_SIZE 100

class Queue {
private:
    int front, rear;
    int arr[MAX_SIZE];

public:
    Queue() {
        front = rear = -1; // Initialize front and rear to -1 to indicate an empty queue
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue more elements.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0; // If queue is empty, set both front and rear to 0
        }
        else {
            rear++;
        }
        arr[rear] = value;
        cout << value << " enqueued to queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue from an empty queue.\n";
            return;
        }
        cout << arr[front] << " dequeued from queue.\n";
        if (front == rear) {
            front = rear = -1; // If queue has only one element, reset front and rear
        }
        else {
            front++;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1; // Return -1 if queue is empty
        }
        return arr[front];
    }
};

int main() {
    Queue myQueue;

    myQueue.enqueue(5);
    myQueue.enqueue(10);
    myQueue.enqueue(15);

    cout << "Front element of queue: " << myQueue.peek() << endl;

    myQueue.dequeue();
    myQueue.dequeue();

    cout << "Front element of queue after dequeuing: " << myQueue.peek() << endl;

    return 0;
}
