# ads
<<<<<<< HEAD
question 1:
we want to improve the algorithm for reducing an integer to a single digit by repeatedly splitting and adding its digit groups. the procedure is defined as follows:
1. Split the number into two parts containing the same number of digits
    If the right part has fewer digits, miltiply it by 10 until both parts have equal digit length.
2. Add the two parts together.
3. Repeat the process on the resulting number until only one digit remains
    Starting with 47360:
    - Step 1:
        Split into 473 and 60.
        Convert 60 --> 600 so both parts have three digits.
        473 + 600 = 1073
    - Step 2:
        Split 1073 into 10 and 73.
        10 + 73 = 83
    - Step 3:
        Split 83 into 8 and 3.
        8 + 3 = 11
    - Step 4:
        Split 11 into 1 and 1.
        1 + 1 = 2 --> stop
Your tasks are:
- Implement a function to display the calculating process.
- Implement the algorithm using an Iterative approach.
- Implement the same algorithm using a Recursive function.
- For both implementations, calculate and analyze the complexity of the implemented functions. Justify your analysis, taking into account the number of digits in the original input n.

Question2:
A MinStack is a specialized stack data structure that, in addition to standard stack operations, can also return the minimum element currently stored in the stack, all in constant time, O(1).
Your task is to propose a MinStack data structure that supports the following operations:
1. push(x): Insert an element x onto the top of the stack
2. pop(): Remove the element at the top of the stack
3. top(): Return the current top element of the stack without removing it.
4. getMin(): Return the minimum element in the stack at the current moment.
     Note: This function must have a complexity of O(1). DO NOT propose an algorithm with loops, scan the stack, or use additional libraries.
     Hint: pop() removes only the top element, which is not always the minimum,. However, if the popped element is minimum, the data structure must correctly update and reveal the new minimum.
Your tasks are:
- Propose a data structure the supports all four operations in O(1) time.
- Explain the process in each function.
- Justify the complexity of the proposed functions.
Note: A complete implementation in C is not required, pseudo-code is preferable

Question 3:
Traditional Selection Sort selects only the minimum element in each pass. We want design a Two-Way Selection Sort algorithm that, during each pass, selects both minimum and maximum elements and places them at the beginning and end of the array, respectively.
Your tasks are:
- Implement the above sorting algorithm
- Analyze the time complexity of your algorithm.
=======
đây là bài 1 (độ phức tạp O(dlogd))
#include <stdio.h>

int countDigits(int n) {
    int count = 0;
    while (n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

int power10(int k) {
    int p = 1;
    for (int i = 0; i < k; i++)
        p *= 10;
    return p;
}

void displayProcess(int n) {
    int left, right, d, half;

    while (n >= 10) {
        d = countDigits(n);
        half = d / 2;

        right = n % power10(half);
        left  = n / power10(half);

        while (countDigits(right) < countDigits(left))
            right *= 10;

        printf("%d + %d = %d\n", left, right, left + right);
        n = left + right;
    }
}

int reduceIterative(int n) {
    int left, right, d, half;

    while (n >= 10) {
        d = countDigits(n);
        half = d / 2;

        right = n % power10(half);
        left  = n / power10(half);

        while (countDigits(right) < countDigits(left))
            right *= 10;

        n = left + right;
    }
    return n;
}

int reduceRecursive(int n) {
    int left, right, d, half;

    if (n < 10)
        return n;

    d = countDigits(n);
    half = d / 2;

    right = n % power10(half);
    left  = n / power10(half);

    while (countDigits(right) < countDigits(left))
        right *= 10;

    return reduceRecursive(left + right);
}

int main() {
    int n = 47360;

    printf("Displaying process:\n");
    displayProcess(n);

    printf("\nIterative result: %d\n", reduceIterative(n));
    printf("Recursive result: %d\n", reduceRecursive(n));

    return 0;
}


đây là bài 2
#include <stdio.h>

#define MAX 100

typedef struct {
    int mainStack[MAX];
    int minStack[MAX];
    int top;
    int minTop;
} MinStack;

void init(MinStack *s) {
    s->top = -1;
    s->minTop = -1;
}

void push(MinStack *s, int x) {
    s->mainStack[++s->top] = x;

    if (s->minTop == -1 || x <= s->minStack[s->minTop])
        s->minStack[++s->minTop] = x;
}

void pop(MinStack *s) {
    if (s->top == -1) return;

    int x = s->mainStack[s->top--];
    if (x == s->minStack[s->minTop])
        s->minTop--;
}

int top(MinStack *s) {
    return s->mainStack[s->top];
}

int getMin(MinStack *s) {
    return s->minStack[s->minTop];
}

int main() {
    MinStack s;
    init(&s);

    push(&s, 5);
    push(&s, 3);
    push(&s, 7);
    push(&s, 2);

    printf("Current min: %d\n", getMin(&s));
    pop(&s);
    printf("Current min after pop: %d\n", getMin(&s));

    return 0;
}

đây là bài 3 
#include <stdio.h>

#define MAX 100

typedef struct {
    int mainStack[MAX];
    int minStack[MAX];
    int top;
    int minTop;
} MinStack;

void init(MinStack *s) {
    s->top = -1;
    s->minTop = -1;
}

void push(MinStack *s, int x) {
    s->mainStack[++s->top] = x;

    if (s->minTop == -1 || x <= s->minStack[s->minTop])
        s->minStack[++s->minTop] = x;
}

void pop(MinStack *s) {
    if (s->top == -1) return;

    int x = s->mainStack[s->top--];
    if (x == s->minStack[s->minTop])
        s->minTop--;
}

int top(MinStack *s) {
    return s->mainStack[s->top];
}

int getMin(MinStack *s) {
    return s->minStack[s->minTop];
}

int main() {
    MinStack s;
    init(&s);

    push(&s, 5);
    push(&s, 3);
    push(&s, 7);
    push(&s, 2);

    printf("Current min: %d\n", getMin(&s));
    pop(&s);
    printf("Current min after pop: %d\n", getMin(&s));

    return 0;
}
>>>>>>> c558cd7398c9fe2191484e722c198d2da1a4d03d
