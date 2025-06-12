#include "stack.h"
#include "linked_list.h"

#define MAX_STACK_SIZE 100

static int stack_array[MAX_STACK_SIZE];
static unsigned int stack_top = 0;

void stack_init() {
    linked_list_init();
    stack_top = 0;
}

int stack_push(unsigned int data) {
    if (stack_top >= MAX_STACK_SIZE) {
        return -1; // Stack lleno
    }

    if (linked_list_prepend(data) == -1) {
        return -1; // Error al insertar
    }

    stack_array[stack_top++] = data; // Guardamos el valor para poder sacarlo después
    return 0;
}

int stack_pop() {
    if (stack_top == 0) {
        return -1; // Stack vacío
    }

    int value = stack_array[--stack_top]; // Último valor insertado
    linked_list_remove(value);            // Lo quitamos de la lista (por valor)

    return value;
}

unsigned int stack_size() {
    return stack_top;
}

int stack_is_full() {
    return stack_top >= MAX_STACK_SIZE ? 1 : 0;
}

int stack_is_empty() {
    return stack_top == 0 ? 1 : 0;
}
