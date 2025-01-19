#include <stdio.h>
#include <stdlib.h>

void insertByOrder(int **arr, int *size, int value) {
    *arr = realloc(*arr, (*size + 1) * sizeof(int));
    int i = *size - 1;
    while (i >= 0 && (*arr)[i] > value) {
        (*arr)[i + 1] = (*arr)[i];
        i--;
    }
    (*arr)[i + 1] = value;
    (*size)++;
}

void deleteByPosition(int **arr, int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = position; i < *size - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }
    *arr = realloc(*arr, (*size - 1) * sizeof(int));
    (*size)--;
}

int searchByKey(int *arr, int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

void reverseContents(int *arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

void displayArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int *arr = NULL;
    int size = 0;
    int choice, value, position, key;

    while (1) {
        printf("Menu:\n");
        printf("1. Insert by order\n");
        printf("2. Delete by position\n");
        printf("3. Search by key\n");
        printf("4. Reverse the contents\n");
        printf("5. Display array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertByOrder(&arr, &size, value);
                displayArray(arr, size);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteByPosition(&arr, &size, position);
                displayArray(arr, size);
                break;
            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                position = searchByKey(arr, size, key);
                if (position != -1) {
                    printf("Key found at position %d\n", position);
                } else {
                    printf("Key not found\n");
                }
                break;
            case 4:
                reverseContents(arr, size);
                displayArray(arr, size);
                break;
            case 5:
                displayArray(arr, size);
                break;
            case 6:
                free(arr);
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
