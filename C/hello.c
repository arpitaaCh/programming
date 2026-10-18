#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Item {
    char Item_Name[100];
    char Category[100];
    int Item_ID;
    float Price;
    int Quantity;
};

void input(struct Item a[]) {
    printf("Enter Item Name: ");
    scanf(" %99[^\n]", a[0].Item_Name);

    printf("Enter Category: ");
    scanf(" %99[^\n]", a[0].Category);

    printf("Enter Item ID: ");
    scanf("%d", &a[0].Item_ID);

    printf("Enter Price: ");
    scanf("%f", &a[0].Price);

    printf("Enter Quantity: ");
    scanf("%d", &a[0].Quantity);
}

void display(struct Item a[]) {
    printf("\n--- Item Details ---\n");
    printf("Item Name: %s\n", a[0].Item_Name);
    printf("Category: %s\n", a[0].Category);
    printf("Item ID: %d\n", a[0].Item_ID);
    printf("Price: %.2f\n", a[0].Price);
    printf("Quantity: %d\n", a[0].Quantity);
}

void process(struct Item a[]) {
    char full_code[200];
    char short_code[100];
    int i, len;

    // Replace first letter of Category with X
    if (strlen(a[0].Category) > 0) {
        a[0].Category[0] = 'X';
    }
    printf("\nModified Category: %s\n", a[0].Category);

    // Convert Item Name to uppercase and separate by #
    len = strlen(a[0].Item_Name);

    printf("Uppercase Item Name: ");

    for (i = 0; i < len; i++) {
        a[0].Item_Name[i] = toupper((unsigned char)a[0].Item_Name[i]);

        printf("%c", a[0].Item_Name[i]);

        if (i < len - 1) {
            printf("#");
        }
    }
    printf("\n");

    // Display string lengths
    printf("Item Name Length: %zu\n",
           strlen(a[0].Item_Name));

    printf("Category Length: %zu\n",
           strlen(a[0].Category));

    // Concatenate Item Name and Category
    strcpy(full_code, a[0].Item_Name);
    strcat(full_code, a[0].Category);

    printf("Full Code: %s\n", full_code);

    // Copy first half of Item Name
    len = strlen(a[0].Item_Name);

    for (i = 0; i < len / 2; i++) {
        short_code[i] = a[0].Item_Name[i];
    }

    short_code[i] = '\0';

    printf("First Half: %s\n", short_code);
}

int main() {
    struct Item a[1];

    input(a);
    display(a);
    process(a);

    return 0;
}