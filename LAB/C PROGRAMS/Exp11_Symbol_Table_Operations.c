#include <stdio.h>
#include <string.h>

struct Symbol { char name[30]; int address; };
struct Symbol table[100];
int count = 0;

int search(const char *name) {
    for (int i = 0; i < count; i++)
        if (strcmp(table[i].name, name) == 0) return i;
    return -1;
}

int main(void) {
    int choice, address, pos;
    char name[30];
    do {
        printf("\n1.Insert  2.Display  3.Search  4.Modify  5.Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) return 1;
        switch (choice) {
            case 1:
                printf("Enter symbol name: "); scanf("%29s", name);
                if (search(name) >= 0) puts("Duplicate symbol.");
                else if (count == 100) puts("Symbol table is full.");
                else {
                    printf("Enter address: "); scanf("%d", &address);
                    strcpy(table[count].name, name); table[count++].address = address;
                    puts("Symbol inserted.");
                }
                break;
            case 2:
                puts("Symbol\tAddress");
                for (int i = 0; i < count; i++) printf("%s\t%d\n", table[i].name, table[i].address);
                break;
            case 3:
                printf("Enter symbol to search: "); scanf("%29s", name);
                pos = search(name);
                if (pos >= 0) printf("Found: %s at address %d\n", name, table[pos].address);
                else puts("Symbol not found.");
                break;
            case 4:
                printf("Enter symbol to modify: "); scanf("%29s", name);
                pos = search(name);
                if (pos < 0) puts("Symbol not found.");
                else { printf("Enter new address: "); scanf("%d", &address); table[pos].address = address; puts("Address updated."); }
                break;
            case 5: puts("Exiting."); break;
            default: puts("Invalid choice.");
        }
    } while (choice != 5);
    return 0;
}
