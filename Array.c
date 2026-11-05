1. Write an algorithm to insert an element at a given position in an array. Show the shifting and state the complexity.
Definition: Insertion means adding a new element at a specified position in an array.

Algorithm: INSERT(A, N, POS, ITEM)
1. Start
2. If N == MAX, print "Overflow" and Stop.
3. If POS < 1 or POS > N+1, print "Invalid Position" and Stop.
4. For i = N-1 down to POS-1:
       A[i+1] = A[i]
5. A[POS-1] = ITEM
6. N = N+1
7. Stop


Example:

Original array:

A = [10, 20, 30, 40, 50]

Insert 25 at position 3.

Shifting process:
Step 1: [10, 20, 30, 40, 50]
Step 2: [10, 20, 30, 40, 50, 50]
Step 3: [10, 20, 30, 40, 40, 50]
Step 4: [10, 20, 30, 30, 40, 50]
Step 5: [10, 20, 25, 30, 40, 50]


Final Array
[10, 20, 25, 30, 40, 50]

Time Complexity:
- Best Case: O(1), insertion at the end.
- Worst Case: O(n), insertion at the beginning.
- Space Complexity: O(1), assuming available array capacity.
2. Write an algorithm to delete the element at a given position. State the complexity.
Definition: Deletion means removing an element from a specified position in an array.

Algorithm: DELETE(A, N, POS)
1. Start
2. If N == 0, print "Underflow" and Stop.
3. If POS < 1 or POS > N, print "Invalid Position" and Stop.
4. ITEM = A[POS-1]
5. For i = POS-1 to N-2:
       A[i] = A[i+1]
6. N = N-1
7. Stop


Example:

Original array:

A = [10, 20, 30, 40, 50]

Delete the element at position 3.

Shifting process:
Original: [10, 20, 30, 40, 50]

After deleting 30:
         [10, 20, 40, 50]


Final Array: [10, 20, 40, 50]

Time Complexity:
- Best Case: O(1), deleting the last element.
- Worst Case: O(n), deleting the first element.
- Space Complexity: O(1).
3. Write the algorithms for Linear Search and Binary Search and compare them.
A. Linear Search
Definition: Linear search is a searching technique that checks each element one by one until the required element is found or the array ends.

Algorithm: LINEAR_SEARCH(A, N, KEY)
1. Start
2. For i = 0 to N-1:
       If A[i] == KEY:
           Return i
3. Return -1
4. Stop


Example:

Array: [10, 20, 30, 40, 50]

KEY = 40

Searching:

10 → 20 → 30 → 40

Element found at index 3 (position 4).

Time Complexity:
- Best Case: O(1)
- Worst Case: O(n)
- Space Complexity: O(1)
B. Binary Search
Definition: Binary search is a searching technique that repeatedly divides a sorted array into two halves to find the required element.

Important
 Binary search works only on sorted data.

Algorithm: BINARY_SEARCH(A, N, KEY)
1. Start
2. LOW = 0, HIGH = N-1
3. While LOW <= HIGH:
       MID = LOW + (HIGH-LOW)/2

       If A[MID] == KEY:
           Return MID

       Else if A[MID] < KEY:
           LOW = MID + 1

       Else:
           HIGH = MID - 1

4. Return -1
5. Stop


Example:

Array: [10, 20, 30, 40, 50]

KEY = 40
- MID = 2, A[2] = 30.
- 40 is greater than 30, so search the right half.
- MID = 3, A[3] = 40.
- Element found.
Difference between Linear Search and Binary Search
Linear Search	Binary Search
Checks elements one by one.	Divides the array into two halves.
Works on sorted and unsorted arrays.	Requires sorted data.
Best case O(1).	Best case O(1).
Worst case O(n).	Worst case O(log n).
Simple to implement.	Comparatively complex.

4. Reverse an array in-place and state its complexity.
Definition: Reversing an array means changing the order of its elements so that the first element becomes the last and the last becomes the first.

Algorithm: REVERSE(A, N)
1. Start
2. LOW = 0, HIGH = N-1
3. While LOW < HIGH:
       TEMP = A[LOW]
       A[LOW] = A[HIGH]
       A[HIGH] = TEMP

       LOW = LOW + 1
       HIGH = HIGH - 1
4. Stop


Example:

Original array:

[10, 20, 30, 40, 50]

Swapping process:
Step 1: [50, 20, 30, 40, 10]
Step 2: [50, 40, 30, 20, 10]


Reversed Array
[50, 40, 30, 20, 10]

Complexity:
- Time Complexity: O(n)
- Space Complexity: O(1)
In-place means reversing the array without using another array.
5. Rotate an array by k positions.
Definition: Array rotation means shifting the elements of an array by k positions towards the left or right.

There are two types:
1. Left Rotation
2. Right Rotation
A. Left Rotation by k positions
Example:

Original array:

[1, 2, 3, 4, 5]

Rotate left by k = 2.

Result:

[3, 4, 5, 1, 2]

Algorithm using reversal:
1. Start
2. k = k % N
3. Reverse A[0 to k-1]
4. Reverse A[k to N-1]
5. Reverse A[0 to N-1]
6. Stop


B. Right Rotation by k positions
Example:

Original array:

[1, 2, 3, 4, 5]

Rotate right by k = 2.

Result:

[4, 5, 1, 2, 3]

Algorithm using reversal:
1. Start
2. k = k % N
3. Reverse A[0 to N-1]
4. Reverse A[0 to k-1]
5. Reverse A[k to N-1]
6. Stop


Complexity:
Complexity	Value
Time Complexity	O(n)
Space Complexity	O(1)

6. Write the address calculation formula for a 2D array (Row-Major / Column-Major) and solve one numerical.
A two-dimensional array is stored in linear memory using either row-major or column-major order.
A. Row-Major Order Formula
In row-major order, elements are stored row by row.
\[
LOC(A[i][j])=BA+w[i\times N+j]
\]

Where:
- BA = Base address
- w = Size of each element in bytes
- N = Number of columns
- i = Row index
- j = Column index
B. Column-Major Order Formula
In column-major order, elements are stored column by column.
\[
LOC(A[i][j])=BA+w[j\times M+i]
\]

Where:
- BA = Base address
- w = Size of each element in bytes
- M = Number of rows
- i = Row index
- j = Column index
Numerical Example
Question: A 2D array A[3][4] has a base address of 1000. Each element occupies 4 bytes. Find the address of A[2][3] using row-major and column-major order. Assume zero-based indexing.

Given:
- BA = 1000
- w = 4 bytes
- M = 3 rows
- N = 4 columns
- i = 2
- j = 3
1. Row-Major Calculation

Formula:
\[
LOC=BA+w(i\times N+j)
\]

Putting values:
\[
=1000+4(2\times4+3)
\]

\[
=1000+4(11)
\]

\[
\boxed{1044}
\]

Answer: 1044
2. Column-Major Calculation

Formula:
\[
LOC=BA+w(j\times M+i)
\]

Putting values:
\[
=1000+4(3\times3+2)
\]

\[
=1000+4(11)
\]

\[
\boxed{1044}
\]

Answer: 1044
Note: Both answers happen to be equal in this example. In general, row-major and column-major addresses can be different.

You can use these algorithms to prepare for your BCA Data Structures examination.
