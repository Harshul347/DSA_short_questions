1. What is a Data Structure? Differentiate between Linear and Non-linear Data Structures.
Definition: A data structure is a way of organizing, storing, and managing data in a computer so that it can be accessed and modified efficiently.

Types of Data Structures:
1. Linear Data Structure
2. Non-linear Data Structure
Difference:
Linear Data Structure	Non-linear Data Structure
Data elements are arranged sequentially.	Data elements are arranged hierarchically or in networks.
Each element is connected to its previous and next element (in general).	One element can be connected to multiple elements.
Easy to implement.	Comparatively complex to implement.
Examples: Array, Stack, Queue, Linked List.	Examples: Tree, Graph.

2. What is an Array? Write two advantages and two disadvantages.
Definition: An array is a linear data structure that stores multiple elements of the same data type in contiguous memory locations.

Example:

int arr[5] = {10, 20, 30, 40, 50};

Advantages:
1. Random access: Elements can be accessed directly using their index.
2. Easy to implement and traverse.
Disadvantages:
1. Fixed size: Generally, the size of an array cannot be changed after declaration.
2. Insertion and deletion are costly because elements may need to be shifted.
3. Why is Random Access in an Array O(1)?
Random access means accessing any element directly using its index without traversing other elements.

The memory address of an array element is calculated using a formula:
\[
Address(A[i])=Base+i\times Size
\]

Where:
- Base = Address of the first element.
- i = Index of the element.
- Size = Size of each element in bytes.
Since the address is calculated directly using a mathematical formula, it takes constant time.

Therefore, random access in an array has O(1) time complexity.
4. What are Row-Major and Column-Major Order?
These are two methods of storing a two-dimensional array in computer memory.

1. Row-Major Order:

In row-major order, elements are stored row by row in consecutive memory locations.

Example:
\[
A=\begin{bmatrix}
1&2&3\\
4&5&6
\end{bmatrix}
\]

Memory representation:

1 → 2 → 3 → 4 → 5 → 6

2. Column-Major Order:

In column-major order, elements are stored column by column in consecutive memory locations.

Memory representation:

1 → 4 → 2 → 5 → 3 → 6
5. What is a Stack? Explain the LIFO Principle.
Definition: A stack is a linear data structure in which insertion and deletion of elements are performed from only one end, called the TOP.

LIFO: LIFO stands for Last In, First Out.

It means the element inserted last will be removed first.









Basic Operations:
1. Push: Inserts an element into the stack.
2. Pop: Removes the top element.
3. Peek: Returns the top element without removing it.
4. isEmpty: Checks whether the stack is empty.
6. What are Stack Overflow and Stack Underflow?
1. Stack Overflow:

Stack overflow occurs when we try to insert an element into a stack that is already full.

Example: Inserting an element into a stack with a maximum capacity of 5 when all five positions are occupied.

2. Stack Underflow:

Stack underflow occurs when we try to remove an element from an empty stack.

Example: Performing the POP operation on an empty stack.
7. What is a Queue? Explain the FIFO Principle.
Definition: A queue is a linear data structure in which insertion is performed at the REAR end and deletion is performed at the FRONT end.

FIFO: FIFO stands for First In, First Out.

It means the element inserted first will be removed first.









Basic Operations:
1. Enqueue: Inserts an element into the queue.
2. Dequeue: Removes an element from the queue.
3. Front: Returns the first element.
4. Rear: Returns the last element.
8. Write the Four Types of Queues.
The four main types of queues are:
1. Simple Queue: Insertion takes place at the rear, and deletion takes place at the front.
2. Circular Queue: The last position is connected to the first position to utilize memory efficiently.
3. Priority Queue: Elements are deleted according to their priority.
4. Double-Ended Queue (Deque): Insertion and deletion can take place from both ends.









9. What is a Priority Queue?
Definition: A priority queue is a special type of queue in which each element is assigned a priority, and elements are processed according to their priority.

The element with the highest priority is generally removed first.

Example: In a hospital emergency department, patients requiring urgent medical attention are treated before less urgent cases.

Types:
1. Ascending Priority Queue.
2. Descending Priority Queue.
10. What is a Deque?
Definition: A deque (Double-Ended Queue) is a linear data structure in which insertion and deletion operations can be performed from both the front and rear ends.

Types of Deque:
1. Input Restricted Deque: Insertion is allowed at only one end, but deletion is allowed at both ends.
2. Output Restricted Deque: Deletion is allowed at only one end, but insertion is allowed at both ends.
11. What is a Call Stack?
Definition: A call stack is a special stack used by a computer program to manage function calls.

Whenever a function is called, its information is stored in the call stack. When the function finishes execution, its information is removed from the stack.

Example:
void fun1() {
    fun2();
}

void fun2() {
    cout << "Hello";
}

int main() {
    fun1();
    return 0;
}


Here, main() calls fun1(), and fun1() calls fun2().

The functions are managed using the LIFO principle.
12. Write Three Real-Life Applications of a Stack.
1. Undo/Redo Operation: Used in text editors to undo or redo previous actions.
2. Browser History: Helps navigate backward through previously visited pages.
3. Function Calls: Used to manage function calls and recursion.
Other applications:
- Expression evaluation.
- Parentheses matching.
- Reversing strings.
13. Write Three Real-Life Applications of a Queue.
1. Printer Queue: Documents are printed in the order they are submitted.
2. Ticket Booking: Customers are served according to their position in the queue.
3. CPU Scheduling: Processes are managed and scheduled for execution.
Other applications:
- Customer service systems.
- Network data transmission.
- Breadth-First Search (BFS).
14. What are Time Complexity and Space Complexity?
1. Time Complexity:

Time complexity is the amount of time an algorithm takes to execute as a function of the input size.

It helps us measure the efficiency of an algorithm.

Example:
- Linear Search: O(n)
- Binary Search: O(log n)
- Array Access: O(1)
2. Space Complexity:

Space complexity is the total amount of memory required by an algorithm during its execution.

Example:
- An algorithm using a fixed number of extra variables generally has O(1) auxiliary space.
- An algorithm using an additional array of size n has O(n) auxiliary space.
15. Explain Big-O, Omega and Theta Notations.
These are mathematical notations used to describe the growth rate of an algorithm's time or space requirements.

1. Big-O Notation (O):

Big-O represents the asymptotic upper bound of an algorithm's growth rate.

It is commonly used to describe the worst-case time complexity.

Example: Linear Search has O(n) worst-case time complexity.

2. Omega Notation (Ω):

Omega represents the asymptotic lower bound of an algorithm's growth rate.

It is commonly used to describe the best-case time complexity.

Example: Linear Search has Ω(1) best-case time complexity.

3. Theta Notation (Θ):

Theta represents the asymptotically tight bound of an algorithm's growth rate.

It describes both upper and lower bounds when they grow at the same rate.

Example: Traversing all elements of an array has Θ(n) time complexity.

Difference between O, Ω and Θ:
Notation	Meaning	Common interpretation
O	Upper Bound	Worst-case
Ω	Lower Bound	Best-case
Θ	Tight Bound	Exact asymptotic growth rate











Important Time Complexities for Exams
Operation / Algorithm	Time Complexity
Array Access	O(1)
Array Traversal	O(n)
Linear Search	O(n)
Binary Search	O(log n)
Stack Push	O(1)
Stack Pop	O(1)
Queue Enqueue	O(1)
Queue Dequeue	O(1)
