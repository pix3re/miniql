#include "stdlib.h"
#include "stdio.h"

#define MAX_ROWS 100
#define MAX_DATA 512
#define BUFFER_S 24

struct Row {
	int id;
	char data[MAX_DATA];
};

struct Database {
	struct Row[MAX_ROWS];
};

struct Connection {
	File *file;
	Database *db;
};

int getline(char line[], int max_l);

int main(void) {
    system("clear");

    char line[BUFFER_S];

    int len = getline(line, BUFFER_S);

    if (len == 0) {
        printf("Failed to parse line\n");
    } else {
        printf("user input - %s\n", line);
    }

    return 0;
}

int getline(char line[], int max_l) {
    char ch;
    int pos;

    for (pos = 0; pos < max_l - 1 && (ch = getchar()) != EOF && ch != '\n'; pos++) {
        line[pos] = ch;

        if (ch == '\n') {
            line[pos] = ch;
            pos++;
        }
    }

    line[pos] = '\0';

    return pos;
}
