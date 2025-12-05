#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[50];
    int stock;
} Item;

Item inventory[MAX_ITEMS];
int itemCount = 0;

void addItem(int id, const char* name, int stock) {
    if (itemCount >= MAX_ITEMS) return;
    inventory[itemCount].id = id;
    strcpy(inventory[itemCount].name, name);
    inventory[itemCount].stock = stock;
    itemCount++;
}

void updateStock(int id, int newStock) {
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            inventory[i].stock = newStock;
            return;
        }
    }
}

void removeItem(int id) {
    int i, j;
    for (i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            for (j = i; j < itemCount - 1; j++)
                inventory[j] = inventory[j + 1];
            itemCount--;
            return;
        }
    }
}

void listItems() {
    printf("=== INVENTORY LIST ===\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d - %s : %d pcs\n",
               inventory[i].id,
               inventory[i].name,
               inventory[i].stock);
    }
}

int main() {
    addItem(1, "Keyboard", 10);
    addItem(2, "Mouse", 15);
    updateStock(1, 7);
    removeItem(2);
    listItems();
    return 0;
}
