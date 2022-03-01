#include <stdbool.h>
#include <stdio.h>

#define MAX_PLAYERS 50
#define MAX_TEAMS 5

struct Cricket {
    char *name;
    char *team_name;
    int batting_avg;
};

struct Cricket cricket[MAX_PLAYERS];

int main(void)
{
    // ? NOTE: cricket array is not populated
    // so the prog won't work obv

    char *teams[MAX_TEAMS];
    int teams_sz = 0;

    // populating teams array; we can use this later to do stuff team wise
    for (int i = 0; i < MAX_PLAYERS; i++) {
        bool exists = false;

        for (int j = 0; j < teams_sz; j++) {
            if (teams[j] == cricket[i].team_name) {
                exists = true;
                break;
            }
        }

        if (exists) {
            continue;
        }

        teams[teams_sz++] = cricket[i].team_name;
    }

    // printing details team wise
    for (int i = 0; i < teams_sz; i++) {
        printf("for team '%s'\n", teams[i]);
        for (int j = 0; j < MAX_PLAYERS; j++) {
            if (teams[i] == cricket[j].team_name) {
                printf("%s with batting average of %d\n", cricket[j].name,
                       cricket[j].batting_avg);
            }
        }
    }
}