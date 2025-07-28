#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack-based buffer overflow
void stack_overflow() {
    char buffer[50];
    printf("Enter something (stack overflow demo): ");
    // gets is unsafe due to not limiting the number of chars that can be input.
    gets(buffer); //  unsafe - vulnerable to buffer overflow
    printf("You entered: %s\n", buffer);
}

// Heap-based buffer overflow
void heap_overflow() {
    char *buffer = (char *)malloc(10);
    printf("Enter something (heap overflow demo): ");
    // Fgets is more secure than gets but in this case it overflows the heap allocated buffer
    fgets(buffer, 100, stdin); //  writes beyond allocated size
    printf("You entered: %s\n", buffer);
    free(buffer);
}

// Format string vulnerability
void format_string() {
    char input[100];
    printf("Enter something (format string demo): ");
    fgets(input, sizeof(input), stdin);
    // Replace with printf("%s",input)
    printf(input); // vulnerable to format string attacks
}

// Use-after-free vulnerability
void use_after_free() {
    char *data = (char *)malloc(20);
    strcpy(data, "Use-after-free!");
    free(data);
    printf("Data after free: %s\n", data); // use-after-free
}

// Integer overflow vulnerability
void integer_overflow() {
    unsigned int a = 4000000000;
    unsigned int b = 1000000000;
    unsigned int result = a + b; // overflow
    printf("Integer overflow result: %u\n", result);
}

// Double free vulnerability
void double_free() {
    char *ptr = (char *)malloc(20);
    strcpy(ptr, "Double Free!");
    free(ptr);
    free(ptr); // double free
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Vulnerability Demonstrator ---\n");
        printf("1. Stack Overflow\n");
        printf("2. Heap Overflow\n");
        printf("3. Format String\n");
        printf("4. Use-After-Free\n");
        printf("5. Integer Overflow\n");
        printf("6. Double Free\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1: stack_overflow(); break;
            case 2: heap_overflow(); break;
            case 3: format_string(); break;
            case 4: use_after_free(); break;
            case 5: integer_overflow(); break;
            case 6: double_free(); break;
            case 7: exit(0);
            default: printf("Invalid option.\n");
        }
    }

    return 0;
}
