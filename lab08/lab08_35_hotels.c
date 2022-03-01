#include <stdio.h>

// not impl-ing any further due to lack of info

#define MAX_HOTELS 10

struct Hotel {
    char *name;
    char *address;
    int grade;       // ???
    int room_charge; // ???
    int num_rooms;
};

struct Hotel hotels[MAX_HOTELS];

void print_hotel(int grade);

int main(void) {}

void print_hotel(int grade)
{
    for (int i = 0; i < MAX_HOTELS; i++) {
        if (hotels[i].grade == grade) {
            printf("%s\n", hotels[i].name);
            return;
        }
    }
}