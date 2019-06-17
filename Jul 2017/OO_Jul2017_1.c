#include <stdio.h>

#define MAX_LENGTH 100
#define MAX_FRIENDS 2

typedef struct person {
    int friends[MAX_FRIENDS];
} Person;

void load(Person *persons, int *n) {
    printf("n? ");
    scanf("%d", n);

    printf("Friends:\n");
    for (int i = 0; i < *n; i++) 
        for (int j = 0; j < MAX_FRIENDS; j++)
            scanf("%d", &persons[i].friends[j]);
}

void send(Person *persons, int n, int *received, int recipient) {
    int end = 0;

    while (!end) {
        end = 1;
        for (int i = 0; i < MAX_FRIENDS; i++) {
            int neighbour = persons[recipient].friends[i];
            if (neighbour != -1 && !received[neighbour]) {
                recipient = neighbour;
                received[neighbour] = 1;
                end = 0;
                break;
            }
        }
    }
}

void proccess(Person *persons, int n) {
    int first, received[MAX_LENGTH] = { 0 };

    printf("Messenger's id? [0-%d] ", n - 1);
    scanf("%d", first);

    received[first] = 1;

    for (int i = 0; i < MAX_FRIENDS; i++) {
        int neighbour = persons[first].friends[i];
        if (neighbour != -1) {
            received[neighbour] = 1;
            send(persons, n, received, neighbour);
        }
    }

    for (int i = 0; i < n; i++)
        if (!received[i])
            printf("%d\n", i);
}

int main() {
    Person persons[MAX_LENGTH];
    int n;

    load(persons, &n);

    proccess(persons, n);

    return 0;
}