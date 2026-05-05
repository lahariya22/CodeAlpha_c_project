#include <stdio.h>

int main() {
    int choice;
    float a, b;

    printf("Enter two numbers: ");
    scanf("%f %f", &a, &b);

    printf("\nSelect Operation:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Result = %.2f\n", a + b);
            break;
        case 2:
            printf("Result = %.2f\n", a - b);
            break;
        case 3:
            printf("Result = %.2f\n", a * b);
            break;
        case 4:
            if(b != 0)
                printf("Result = %.2f\n", a / b);
            else
                printf("Division by zero not allowed!\n");
            break;
        default:
            printf("Invalid Choice!\n");
    }

    return 0;
}