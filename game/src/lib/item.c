#include "item.h"

#include <stdio.h>
#include <malloc.h>
#include <string.h>

inventory *new_inventory() {
    inventory *new = malloc(sizeof(inventory));
    item *items = malloc(sizeof(item) * INVENTORY_LIMIT);
    unsigned int latest = 0;

    new->items = items;
    new->latest = latest;
    
    return new;
}

item *new_item(char *name, unsigned int price) {
    item *new = malloc(sizeof(item));
    char *new_name = malloc(strlen(name));
    memcpy(new_name, name, strlen(new_name));

    new->name = new_name;
    new->price = price;

    return new;
}

int add_item(item *i, inventory *inv) {
    if (inv->latest >= INVENTORY_LIMIT) {
        return -1;
    }

    unsigned int idx = inv->latest;
    inv->items[idx] = *i;
    inv->latest++;

    return 0;
}

int remove_item(item *i, inventory *inv) {
    inv->latest--;
    free(i->name);
    free(i);

    return 0;
}

void destroy_inventory(inventory *inv) {
    item *items = inv->items;
    unsigned int i;

    for (i = 0; i < inv->latest; i++) {
        free(items[i].name);
    }

    free(items);
    free(inv);
}

