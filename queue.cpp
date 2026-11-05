12. Implement a Queue Using an Array (Enqueue, Dequeue).
Definition: A queue is a linear data structure that follows the FIFO (First In, First Out) principle. Insertion takes place at the REAR and deletion takes place at the FRONT.

C++ Program:

#include <iostream>
using namespace std;

#define MAX 5

class Queue {
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Insert element
    void enqueue(int x) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow\n";
            return;
        }

        if (front == -1) {
            front = 0;
        }

        arr[++rear] = x;
    }

    // Delete element
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow\n";
            return;
        }

        cout << "Deleted: " << arr[front] << endl;

        front++;

        if (front > rear) {
            front = rear = -1;
        }
    }

    // Display queue
    void display() {
        if (front == -1) {
            cout << "Queue is Empty\n";
            return;
        }

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue: ";
    q.display();

    q.dequeue();

    cout << "Queue after deletion: ";
    q.display();

    return 0;
}



Output:
Queue: 10 20 30
Deleted: 10
Queue after deletion: 20 30


Time Complexity:
Operation	Complexity
Enqueue	O(1)
Dequeue	O(1)
Display	O(n)

Space Complexity: O(n).

Note: This is a simple linear queue. It may waste array space after deletions. A circular queue solves this problem.
13. Implement a Queue Using a Linked List.
Definition: A queue can be implemented using a linked list in which each node contains data and a pointer to the next node.

Two pointers are maintained:
- FRONT: Points to the first node.
- REAR: Points to the last node.









C++ Program:

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    // Insert element
    void enqueue(int x) {
        Node* newNode = new Node(x);

        if (rear == NULL) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    // Delete element
    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = front;

        cout << "Deleted: " << temp->data << endl;

        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
    }

    // Display queue
    void display() {
        Node* temp = front;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue: ";
    q.display();

    q.dequeue();

    cout << "After deletion: ";
    q.display();

    return 0;
}



Output:
Queue: 10 20 30
Deleted: 10
After deletion: 20 30


Time Complexity:
Operation	Complexity
Enqueue	O(1)
Dequeue	O(1)
Display	O(n)

Space Complexity: O(n).
14. Deque Operations (Insert/Delete from Both Ends).
Definition: Deque stands for Double-Ended Queue. It is a linear data structure in which insertion and deletion can be performed from both the FRONT and REAR ends.

Main Operations:
1. insertFront(): Insert an element at the front.
2. insertRear(): Insert an element at the rear.
3. deleteFront(): Delete an element from the front.
4. deleteRear(): Delete an element from the rear.









C++ Program (Using STL):

#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    // Insert from both ends
    dq.push_front(10);
    dq.push_back(20);
    dq.push_front(5);
    dq.push_back(30);

    cout << "Deque: ";

    for (int x : dq) {
        cout << x << " ";
    }

    cout << endl;

    // Delete from front
    dq.pop_front();

    // Delete from rear
    dq.pop_back();

    cout << "After deletion: ";

    for (int x : dq) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}



Output:
Deque: 5 10 20 30
After deletion: 10 20


Time Complexity:
Operation	Complexity
Insert Front	O(1)
Insert Rear	O(1)
Delete Front	O(1)
Delete Rear	O(1)

Space Complexity: O(n).
15. Reverse a Queue with the Help of a Stack.
Definition: A queue can be reversed using a stack because a stack follows LIFO, whereas a queue follows FIFO.

Algorithm:
1. Create an empty stack.
2. Remove all elements from the queue and push them into the stack.
3. Pop all elements from the stack and insert them back into the queue.
4. The queue will now be reversed.
Example:

Original Queue:

10 → 20 → 30 → 40

After pushing into stack:

10, 20, 30, 40

After popping and inserting into queue:

40 → 30 → 20 → 10

C++ Program:

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueue(queue<int>& q) {

    stack<int> s;

    // Push queue elements into stack
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    // Push stack elements back into queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

int main() {
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    reverseQueue(q);

    cout << "Reversed Queue: ";

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}



Output:
Reversed Queue: 40 30 20 10


Time Complexity: O(n).

Space Complexity: O(n), because an additional stack is used.
16. Generate Binary Numbers from 1 to n Using a Queue.
Definition: A queue can be used to generate binary numbers from 1 to n by following the FIFO principle.

Approach:
1. Create an empty queue of strings.
2. Insert "1" into the queue.
3. Remove the front element and print it.
4. Generate two new binary numbers by appending 0 and 1.
5. Insert both new numbers into the queue.
6. Repeat until n binary numbers are generated.
Example:

Input: n = 5

Generated binary numbers:

1, 10, 11, 100, 101

C++ Program:

#include <iostream>
#include <queue>
using namespace std;

void generateBinary(int n) {

    queue<string> q;

    q.push("1");

    for (int i = 1; i <= n; i++) {

        string curr = q.front();
        q.pop();

        cout << curr << " ";

        q.push(curr + "0");
        q.push(curr + "1");
    }
}

int main() {

    int n = 5;

    cout << "Binary Numbers: ";

    generateBinary(n);

    return 0;
}



Output:
Binary Numbers: 1 10 11 100 101


Time Complexity: O(n log n) character operations, because the generated binary strings have O(log n) length.

Space Complexity: O(n log n) in total for the strings stored and generated during the algorithm.

Quick Revision – Questions 12 to 16
Q. No.	Topic	Important Complexity
12	Queue using Array	Enqueue O(1), Dequeue O(1)
13	Queue using Linked List	Enqueue O(1), Dequeue O(1)
14	Deque	All four operations O(1)
15	Reverse Queue using Stack	O(n)
16	Generate Binary Numbers	O(n log n)
