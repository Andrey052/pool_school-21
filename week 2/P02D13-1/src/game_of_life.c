#include <curses.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#define W 25
#define H 80

void next_gen(int prev[W][H]);
void input_first_gen(int gen[W][H]);
void print_gen(int gen[W][H]);

int main() {
    int gen[W][H] = {0};
    setlocale(LC_CTYPE, "en_US.UTF-8");
    initscr();
    input_first_gen(gen);
    print_gen(gen);
    int speed = 50;
    while (1) {
        refresh();

        timeout(speed);
        clear();
        print_gen(gen);
        next_gen(gen);
        char sim = getch();
        if (sim == 'w') {
            speed--;
        }
        if (sim == 's') {
            speed++;
        }
        if (sim == 'q') {
            endwin();
            return 0;
        }
    }
}

void next_gen(int prev[W][H]) {
    int next[W][H];
    int i, j, cell;
    for (i = 0; i < W + 1; i++) {
        for (j = 0; j < H + 1; j++) {
            cell = prev[(W + i - 1) % W][(H + j - 1) % H] + prev[(W + i - 1) % W][(H + j) % H] +
                   prev[(W + i - 1) % W][(H + j + 1) % H] + prev[(W + i) % W][(H + j - 1) % H] +
                   prev[(W + i) % W][(H + j + 1) % H] + prev[(W + i + 1) % W][(H + j - 1) % H] +
                   prev[(W + i + 1) % W][(H + j) % H] + prev[(W + i + 1) % W][(H + j + 1) % H];
            if (prev[(W + i) % W][(H + j) % H] == 1) {
                if ((cell == 3) || (cell == 2)) {
                    next[(W + i) % W][(H + j) % H] = 1;
                } else {
                    next[(W + i) % W][(H + j) % H] = 0;
                }
            } else {
                if (cell == 3) {
                    next[(W + i) % W][(H + j) % H] = 1;
                } else
                    next[(W + i) % W][(H + j) % H] = 0;
            }
        }
    }

    for (i = 0; i < W + 1; i++) {
        for (j = 0; j < H + 1; j++) {
            prev[(W + i) % W][(H + j) % H] = next[(W + i) % W][(H + j) % H];
        }
    }
}

void input_first_gen(int gen[W][H]) {
    int x = 0, y = 0;
    int exit = -1;

    while (exit == -1) {
        scanw("%d %d", &x, &y);
        if (x == -1) exit = 0;

        if (y == -1) exit = 0;
        printw("x: %d y: %d\n", x, y);
        refresh();
        if (exit == -1 && x >= 0 && x < H && y >= 0 && y < W) {
            gen[y][x] = 1;
        }
    }

    stdin = freopen("/dev/tty", "r", stdin);
}

void print_gen(int gen[W][H]) {
    printw(" ");

    for (int i = 0; i < H; i++) printw("_");
    printw("\n");

    for (int i = 0; i < W; i++) {
        for (int j = -1; j < H; j++) {
            if (j == -1)
                printw("|");
            else if (gen[i][j] == 1) {
                printw("█");
            } else {
                printw(" ");
            }
        }
        printw("|\n");
    }
    printw("|");

    for (int i = 0; i < H; i++) printw("_");
    printw("|\n");
}