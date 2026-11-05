Q1. Infix to Postfix Conversion Using Stack
Question: Convert the following infix expression into postfix using a stack table. Also write the algorithm.
\[
A+B*(C-D)/E
\]

1. Definition
- Infix Expression: Operator is written between operands. Example: A+B.
- Postfix Expression: Operator is written after operands. Example: AB+.
- A stack is used to temporarily store operators and parentheses during conversion.
2. Operator Precedence
Operator	Precedence
()	Highest
*, /	Higher
+, -	Lower

3. Step-by-step Conversion
Given: A+B*(C-D)/E
Step	Symbol	Stack	Postfix
1	A	Empty	A
2	+	+	A
3	B	+	AB
4	*	+ *	AB
5	(	+ * (	AB
6	C	+ * (	ABC
7	-	+ * ( -	ABC
8	D	+ * ( -	ABCD
9	)	+ *	ABCD-
10	/	+ /	ABCD-*
11	E	+ /	ABCD-*E
12	End	Empty	ABCD-*E/+

Final Answer
\[
\boxed{ABCD-*E/+}
\]

4. Algorithm
1. Initialize an empty stack.
2. Scan the infix expression from left to right.
3. If the symbol is an operand, add it to the postfix expression.
4. If the symbol is (, push it onto the stack.
5. If the symbol is ), pop operators until ( is found.
6. If the symbol is an operator, pop operators having higher or equal precedence, then push the current operator.
7. After scanning the expression, pop all remaining operators.
8. Display the postfix expression.
Time Complexity: \(O(n)\)

Space Complexity: \(O(n)\)

Q2. Postfix Expression Evaluation Using Stack
Question: Evaluate the following postfix expression and show the stack step by step.
\[
5\quad 3\quad 2\quad *\quad +\quad 4\quad -
\]

1. Definition
Postfix evaluation is the process of calculating an expression in which operators appear after operands. A stack is used to store operands temporarily.
2. Evaluation Rules
1. Scan the expression from left to right.
2. If the symbol is an operand, push it onto the stack.
3. If the symbol is an operator, pop two operands.
4. Perform the operation in the correct order: first popped value is the right operand.
5. Push the result back onto the stack.
6. The final stack element is the answer.
3. Step-by-step Stack Table
Step	Symbol	Operation	Stack
1	5	Push 5	5
2	3	Push 3	5, 3
3	2	Push 2	5, 3, 2
4	*	3 × 2 = 6	5, 6
5	+	5 + 6 = 11	11
6	4	Push 4	11, 4
7	-	11 - 4 = 7	7

4. Final Answer
\[
5+ (3\times 2)-4
\]

\[
=5+6-4
\]

\[
\boxed{7}
\]

Time Complexity: \(O(n)\)

Space Complexity: \(O(n)\)

Q3. Circular Queue – Implementation and Explanation
1. Definition
A circular queue is a linear data structure in which the last position is connected to the first position, forming a circle.

It follows the FIFO (First In First Out) principle.



A0B1C2—3—4—5FrontRearWrap to index 0




Circular queue: 3 items, front 0 → rear 2.

LinearCircular





Enqueue DDequeue AReset





Give feedback

2. Conditions
For a circular queue of size N:

Empty Condition:
front == -1


Full Condition:
(rear + 1) % N == front


3. Why Modulo (%) Is Used
Modulo helps the rear and front pointers return to index 0 after reaching the last index.

For example, if N = 5:
\[
(4+1)\%5=0
\]

Therefore, the next position becomes index 0.
4. C++ Implementation
#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int front, rear, size;

public:
    CircularQueue(int n) {
        size = n;
        arr = new int[n];
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is Full\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = x;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Deleted: " << arr[front] << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        int i = front;

        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;

            i = (i + 1) % size;
        }

        cout << endl;
    }

    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    q.dequeue();
    q.dequeue();

    q.enqueue(50);
    q.enqueue(60);

    q.display();

    return 0;
}


5. Complexity Analysis
Operation	Complexity
Enqueue	O(1)
Dequeue	O(1)
Display	O(n)
Space	O(n)

Conclusion: A circular queue efficiently utilizes available array space by reusing deleted positions.

Q4. Implement Queue Using Two Stacks
1. Definition
A queue follows FIFO, whereas a stack follows LIFO. A queue can be implemented using two stacks by transferring elements between them.

We use:
- Stack S1: Used for insertion.
- Stack S2: Used for deletion.
2. Algorithm
Enqueue(x):

1. Push element into S1.

Dequeue():
1. If S2 is empty, transfer all elements from S1 to S2.
2. If both stacks are empty, queue is empty.
3. Otherwise, pop the top element from S2.
3. C++ Implementation
#include <iostream>
#include <stack>
using namespace std;

class Queue {
    stack<int> s1, s2;

public:
    void enqueue(int x) {
        s1.push(x);
    }

    void dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is Empty\n";
            return;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << "Deleted: " << s2.top() << endl;
        s2.pop();
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.dequeue();
    q.dequeue();

    return 0;
}


4. Complexity Analysis
Operation	Time Complexity
Enqueue	O(1)
Dequeue (Worst Case)	O(n)
Dequeue (Amortized)	O(1)
Space	O(n)

Conclusion: Two stacks can efficiently implement a queue while maintaining FIFO order.

Q5. Implement Stack Using Two Queues
1. Definition
A stack follows LIFO, whereas a queue follows FIFO. A stack can be implemented using two queues by rearranging elements during insertion or deletion.

Here, we use the costly push approach.
- Queue Q1: Main queue.
- Queue Q2: Auxiliary queue.
2. Algorithm
Push(x):
1. Insert the new element into Q2.
2. Move all elements from Q1 to Q2.
3. Swap Q1 and Q2.
Pop():
1. If Q1 is empty, display underflow.
2. Otherwise, remove the front element of Q1.
3. C++ Implementation
#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is Empty\n";
            return;
        }

        cout << "Deleted: " << q1.front() << endl;
        q1.pop();
    }

    void top() {
        if (q1.empty()) {
            cout << "Stack is Empty\n";
            return;
        }

        cout << "Top: " << q1.front() << endl;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.top();
    s.pop();
    s.top();

    return 0;
}


4. Complexity Analysis
Operation	Time Complexity
Push	O(n)
Pop	O(1)
Top	O(1)
Space	O(n)

Conclusion: Two queues can implement a stack by rearranging elements to maintain LIFO order.

Q6. Balanced Parentheses Using Stack
1. Definition
Balanced parentheses means every opening bracket must have a corresponding closing bracket in the correct order.

There are three types of brackets:
- () – Parentheses
- {} – Curly brackets
- [ ] – Square brackets
2. Algorithm
1. Create an empty stack.
2. Scan the expression from left to right.
3. If an opening bracket (, {, [ is found, push it onto the stack.
4. If a closing bracket is found:
   - Check whether the stack is empty.
   - If empty, the expression is unbalanced.
   - Otherwise, pop the top element and check whether the brackets match.
5. After scanning the complete expression:
   - If the stack is empty, the expression is balanced.
   - Otherwise, it is unbalanced.
3. C++ Implementation
#include <iostream>
#include <stack>
using namespace std;

bool isMatching(char a, char b) {
    return (a == '(' && b == ')') ||
           (a == '{' && b == '}') ||
           (a == '[' && b == ']');
}

bool isBalanced(string s) {
    stack<char> st;

    for (char ch : s) {

        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }

        else {
            if (st.empty())
                return false;

            char top = st.top();
            st.pop();

            if (!isMatching(top, ch))
                return false;
        }
    }

    return st.empty();
}

int main() {
    string s1 = "{[()]}";
    string s2 = "{[(])}";

    cout << isBalanced(s1) << endl;
    cout << isBalanced(s2) << endl;

    return 0;
}
