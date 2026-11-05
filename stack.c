7. Implement a Stack Using an Array (Push, Pop, Peek, isEmpty, isFull).
Definition: A stack is a linear data structure that follows the LIFO (Last In, First Out) principle. Insertion and deletion take place from the TOP.

C++ Program:

#include <iostream>
using namespace std;

#define MAX 5

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    // Check whether stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check whether stack is full
    bool isFull() {
        return top == MAX - 1;
    }

    // Insert element
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }

        arr[++top] = x;
    }

    // Delete element
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }

        cout << "Deleted: " << arr[top--] << endl;
    }

    // Return top element
    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return -1;
        }

        return arr[top];
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.peek() << endl;

    s.pop();

    cout << "Top: " << s.peek() << endl;

    return 0;
}



Output:
Top: 30
Deleted: 30
Top: 20


Time Complexity:
Operation	Complexity
Push	O(1)
Pop	O(1)
Peek	O(1)
isEmpty	O(1)
isFull	O(1)

Space Complexity: O(n), where n is the maximum stack capacity.
8. Write Push and Pop Using a Linked List.
Definition: A stack can also be implemented using a linked list. Each node contains data and a pointer to the next node.

In this implementation, the TOP points to the first node.









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

class Stack {
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    // Push operation
    void push(int x) {
        Node* newNode = new Node(x);

        newNode->next = top;
        top = newNode;
    }

    // Pop operation
    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow\n";
            return;
        }

        Node* temp = top;

        cout << "Deleted: " << temp->data << endl;

        top = top->next;

        delete temp;
    }

    // Peek operation
    int peek() {
        if (top == NULL) {
            cout << "Stack is Empty\n";
            return -1;
        }

        return top->data;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.peek() << endl;

    s.pop();

    cout << "Top: " << s.peek() << endl;

    return 0;
}



Output:
Top: 30
Deleted: 30
Top: 20


Time Complexity:
- Push: O(1)
- Pop: O(1)
- Peek: O(1)
Space Complexity: O(n).

Important Difference:
Array Stack	Linked List Stack
Fixed capacity (in a basic implementation).	Dynamic size.
Uses contiguous memory.	Uses non-contiguous memory.
May cause stack overflow when full.	Can grow until memory is exhausted.
No pointer required for elements.	Requires pointers.

9. Reverse a String Using a Stack.
Definition: A stack can be used to reverse a string because it follows the LIFO (Last In, First Out) principle.

Algorithm:
1. Start.
2. Create an empty stack.
3. Push every character of the string into the stack.
4. Pop characters one by one.
5. Store the popped characters in the result string.
6. Print the reversed string.
7. Stop.
C++ Program:

#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str = "HELLO";

    stack<char> s;

    // Push all characters
    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }

    string rev = "";

    // Pop characters
    while (!s.empty()) {
        rev += s.top();
        s.pop();
    }

    cout << "Original String: " << str << endl;
    cout << "Reversed String: " << rev << endl;

    return 0;
}



Output:
Original String: HELLO
Reversed String: OLLEH


Time Complexity: O(n)

Space Complexity: O(n), because the stack stores n characters and the result string also stores n characters.
10. Find the Next Greater Element Using a Stack.
Definition: Next Greater Element (NGE) is the first element on the right side of an element that is greater than that element.

If no greater element exists, the answer is -1.

Example:

Input:

[4, 5, 2, 10, 8]

Output:

[5, 10, 10, -1, -1]

Explanation:
Element	Next Greater Element
4	5
5	10
2	10
10	-1
8	-1

Algorithm:
1. Create an empty stack.
2. Traverse the array from right to left.
3. Remove elements from the stack that are smaller than or equal to the current element.
4. If the stack is empty, NGE = -1.
5. Otherwise, the top element of the stack is the NGE.
6. Push the current element into the stack.
7. Repeat until all elements are processed.
C++ Program:

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};

    int n = arr.size();

    vector<int> ans(n);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {

        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }

        if (s.empty()) {
            ans[i] = -1;
        }
        else {
            ans[i] = s.top();
        }

        s.push(arr[i]);
    }

    cout << "Next Greater Elements: ";

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}



Output:
Next Greater Elements: 5 10 10 -1 -1


Time Complexity: O(n)

Space Complexity: O(n)

Why O(n)? Each element is pushed into the stack once and popped at most once. Therefore, the total operations are linear.
11. Min Stack: Implement getMin() in O(1).
Definition: A Min Stack is a special stack that supports normal stack operations (push, pop and top) along with a getMin() operation that returns the minimum element in constant time O(1).

Approach: Using Two Stacks

We maintain two stacks:
1. Main Stack: Stores all elements.
2. Min Stack: Stores the minimum element at each level.
Working Example:

Suppose we push the following elements:

10, 5, 20, 2
Operation	Main Stack	Minimum
Push(10)	10	10
Push(5)	10, 5	5
Push(20)	10, 5, 20	5
Push(2)	10, 5, 20, 2	2
Pop()	10, 5, 20	5

getMin() = O(1)
C++ Program:

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<int> s;
    stack<int> minS;

public:

    // Push operation
    void push(int x) {
        s.push(x);

        if (minS.empty() || x <= minS.top()) {
            minS.push(x);
        }
    }

    // Pop operation
    void pop() {
        if (s.empty()) {
            cout << "Stack Underflow\n";
            return;
        }

        if (s.top() == minS.top()) {
            minS.pop();
        }

        s.pop();
    }

    // Get minimum element
    int getMin() {
        if (minS.empty()) {
            cout << "Stack is Empty\n";
            return -1;
        }

        return minS.top();
    }

    // Get top element
    int top() {
        if (s.empty()) {
            return -1;
        }

        return s.top();
    }
};

int main() {
    MinStack s;

    s.push(10);
    s.push(5);
    s.push(20);
    s.push(2);

    cout << "Minimum: " << s.getMin() << endl;

    s.pop();

    cout << "Minimum: " << s.getMin() << endl;

    return 0;
}



Output:
Minimum: 2
Minimum: 5


Time and Space Complexity:
Operation	Complexity
Push	O(1)
Pop	O(1)
Top	O(1)
getMin()	O(1)

Space Complexity: O(n), because two stacks are used.

Quick Revision – Questions 7 to 11
Question	Important concept	Time Complexity
7. Array Stack	Push, Pop, Peek	O(1)
8. Linked List Stack	Dynamic Stack	O(1)
9. Reverse String	LIFO	O(n)
10. Next Greater Element	Monotonic Stack	O(n)
11. Min Stack	Two Stacks	O(1) for getMin

Exam tip: Focus especially on Q7, Q8, Q10 and Q11. Practise writing their C++ code without looking at the answers. These questions also build a foundation for stack-based DSA problems.
