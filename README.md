# ads
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
