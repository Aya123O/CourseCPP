#include <iostream>
using namespace std;

class Stack {
private:
    int size;
    int capacity;
    int* arr;
    int* topPtr;
    void resize() {
        int newcapacity = capacity * 2;
        int* newArr = new int[newcapacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newcapacity;
        topPtr = arr + size;
    }

public:
    Stack(int start = 2) {
        arr = new int[start];
        size = 0;
        capacity = start;
        topPtr = arr;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int val) {
        if (size == capacity) {
            resize();
        }
        *topPtr = val;
        ++topPtr;
        ++size;
        cout << "Pushed: " << val << endl;
    }

    int pop() {
        if (size == 0) {
            cout << "Stack underflow! No elements to pop." << endl;
            return -1;
        }
        --topPtr;
        int popvalue = *topPtr;
        --size;
        cout << "Popped: " << popvalue << endl;
        return popvalue;
    }

   void display() const {
    if (size == 0) {
        cout << "Stack is Empty" << endl;
        return;
    }
    cout << "Stack elements: [";
    for (int i = 0; i < size; ++i) {
        cout << arr[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);
    stack.push(8);

   cout<<"********************************************************************"<<"\n";

    stack.display();
  cout<<"********************************************************************"<<"\n";

    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    cout<<"********************************************************************"<<"\n";

    stack.display();

    return 0;
}
