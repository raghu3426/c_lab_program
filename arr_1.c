#include <stdio.h>
#include <stdlib.h>

void insert(int **arr, int *size, int pos, int value) {
    if (pos < 0 || pos > *size) {
        printf("Invalid position!\n");
        return;
    }
    *arr = realloc(*arr, (*size + 1) * sizeof(int));
    for (int i = *size; i > pos; i--) {
        (*arr)[i] = (*arr)[i - 1];
    }
    (*arr)[pos] = value;
    (*size)++;
}

void delete(int **arr, int *size, int key) {
    int pos = -1;
    for (int i = 0; i < *size; i++) {
        if ((*arr)[i] == key) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        printf("Key not found!\n");
        return;
    }
    for (int i = pos; i < *size - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }
    *arr = realloc(*arr, (*size - 1) * sizeof(int));
    (*size)--;
}

void search(int *arr, int size, int pos) {
    if (pos < 0 || pos >= size) {
        printf("Invalid position!\n");
        return;
    }
    printf("Element at position %d is %d\n", pos, arr[pos]);
}

void reverse(int *arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

void display(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int *arr = NULL;
    int size = 0;
    int choice, pos, value, key;

    while (1) {
        printf("Menu:\n");
        printf("1. Insert by position\n");
        printf("2. Delete by key\n");
        printf("3. Search by position\n");
        printf("4. Reverse the contents\n");
        printf("5. Display array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter position and value to insert: ");
                scanf("%d %d", &pos, &value);
                insert(&arr, &size, pos, value);
                display(arr, size);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete(&arr, &size, key);
                display(arr, size);
                break;
            case 3:
                printf("Enter position to search: ");
                scanf("%d", &pos);
                search(arr, size, pos);
                break;
            case 4:
                reverse(arr, size);
                display(arr, size);
                break;
            case 5:
                display(arr, size);
                break;
            case 6:
                free(arr);
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
