#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INITIAL_CAPACITY 10

// V структура для стека V
typedef struct {
    int *data;      // указатель на массив данных
    int top;        // индекс верхнего элемента
    int capacity;   // емкость стека
} Stack;

// V ф-ия создания стека V
Stack* createStack() {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
    stack->top = -1;
    stack->capacity = INITIAL_CAPACITY;
    return stack;
}

// V проверка на пустоту стека V
bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

// V проверка на переполнение стека V
bool isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

// V добавление элемента в стек V
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        stack->capacity *= 2;
        stack->data = (int*)realloc(stack->data, stack->capacity * sizeof(int));
    }
    stack->data[++stack->top] = value;
}

// V удаление элемента из стека V
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ошибка: стек пуст!");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}

// V просмотр верхнего элемента стека V
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ошибка: стек пуст!\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top];
}

// V освобождение памяти стека V
void freeStack(Stack *stack) {
    free(stack->data);
    free(stack);
}

// V сама работа стека V
int main() {
    Stack *stack = createStack();

    // V тест V
    push(stack, 5);
    push(stack, 10);
    push(stack, 15);

    printf("Верхний элемент: %d\n", peek(stack));
    printf("Удалён элемент: %d\n", pop(stack));
    printf("Верхний элемент: %d", peek(stack));

    freeStack(stack);
    return 0;
}
