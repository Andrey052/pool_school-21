#include <curses.h>
#include <stdio.h>
// printw ("\033[0d\033[2J");; //очистка консили

/*
НОВЫЕ ПРАВИЛЬНЫЕ ПАРАМЕТРЫ
параметры переменной вектора движения
1 - движение по вертикали вверх (y-)
2 - движение по диагонали влево вверх (x- y-)
3 - движение по горизонтали влево (x-)
4 - движение по диагонали влево вниз (x- y+)
5 - движение по вертикали вниз (y+)
6 - движение по диагонали вправо вниз (x+ y+)
7 - движение по горизонтали вправо (x+)
8 - движение по диагонали вправо вверх (x+ y-)

параметры переменной object
b - мячик
r - рокетка
*/

int move_b(int last_coord_x, int last_coord_y, int vector, char axis);
int move_r(int last_coord, int vector);
int reso_move(int last_coord, int vector);
int change_vector(int vector, char axis);
int game();
void draw(int p1_y, int p2_y, int ball_x, int ball_y, int score_player1, int score_player2);
char read_char(void);
int chan(int c_b_y, int vector_ball, int c_b_x, int coor_left_r_y, int coor_right_r_y);
void draw_win(int player);

int main() {
    initscr();
    int winner = game();
    clear();
    draw_win(winner);
    while (getch() != 'q') {
    }
    endwin();
    return 0;
}

int game() {
    int c_b_x = 37, c_b_y = 12, coor_left_r_y = 11, coor_right_r_y = 11;
    int vector_ball = 3, l_points = 0, r_points = 0;
    draw(coor_left_r_y, coor_right_r_y, c_b_x, c_b_y, l_points, r_points);
    while (1) {
        refresh();
        int ch = getch();
        timeout(118);
        draw(coor_left_r_y, coor_right_r_y, c_b_x, c_b_y, l_points, r_points);
        if (ch == 'a' || ch == 'A') {
            coor_left_r_y = move_r(coor_left_r_y, 1);
            vector_ball = chan(c_b_y, vector_ball, c_b_x, coor_left_r_y, coor_right_r_y);
            c_b_y = move_b(c_b_x, c_b_y, vector_ball, 'y');
            c_b_x = move_b(c_b_x, c_b_y, vector_ball, 'x');
            draw(coor_left_r_y, coor_right_r_y, c_b_x, c_b_y, l_points, r_points);
        } else if (ch == 'z' || ch == 'Z') {
            coor_left_r_y = move_r(coor_left_r_y, 5);
            vector_ball = chan(c_b_y, vector_ball, c_b_x, coor_left_r_y, coor_right_r_y);
            c_b_y = move_b(c_b_x, c_b_y, vector_ball, 'y');
            c_b_x = move_b(c_b_x, c_b_y, vector_ball, 'x');
            draw(coor_left_r_y, coor_right_r_y, c_b_x, c_b_y, l_points, r_points);
        } else if (ch == 'k' || ch == 'K') {
            coor_right_r_y = move_r(coor_right_r_y, 1);
            vector_ball = chan(c_b_y, vector_ball, c_b_x, coor_left_r_y, coor_right_r_y);
            c_b_y = move_b(c_b_x, c_b_y, vector_ball, 'y');
            c_b_x = move_b(c_b_x, c_b_y, vector_ball, 'x');
            draw(coor_left_r_y, coor_right_r_y, c_b_x, c_b_y, l_points, r_points);
        } else if (ch == 'm' || ch == 'M') {
            coor_right_r_y = move_r(coor_right_r_y, 5);
            vector_ball = chan(c_b_y, vector_ball, c_b_x, coor_left_r_y, coor_right_r_y);
            c_b_y = move_b(c_b_x, c_b_y, vector_ball, 'y');
            c_b_x = move_b(c_b_x, c_b_y, vector_ball, 'x');
            draw(coor_left_r_y, coor_right_r_y, c_b_x, c_b_y, l_points, r_points);
        } else {
            coor_right_r_y = move_r(coor_right_r_y, 0);
            coor_right_r_y = move_r(coor_right_r_y, 0);
            vector_ball = chan(c_b_y, vector_ball, c_b_x, coor_left_r_y, coor_right_r_y);
            c_b_y = move_b(c_b_x, c_b_y, vector_ball, 'y');
            c_b_x = move_b(c_b_x, c_b_y, vector_ball, 'x');
            draw(coor_left_r_y, coor_right_r_y, c_b_x, c_b_y, l_points, r_points);
        }
        if (c_b_x == 4) {
            r_points++, c_b_x = 37, c_b_y = 12, coor_left_r_y = 11, coor_right_r_y = 11;
        } else if (c_b_x == 75) {
            l_points++, c_b_x = 37, c_b_y = 12, coor_left_r_y = 11, coor_right_r_y = 11;
        }
        if (l_points == 21) {
            draw_win(1);
            return 1;
        } else if (r_points == 21) {
            draw_win(2);
            return 2;
        }
    }
    return 1;
}

int chan(int c_b_y, int vector_ball, int c_b_x, int coor_left_r_y, int coor_right_r_y) {
    if (c_b_y == 0 && (vector_ball == 1 || vector_ball == 2 || vector_ball == 8)) {
        vector_ball = change_vector(vector_ball, 'y');
    } else if (c_b_y == 24 && vector_ball > 3 && vector_ball < 7) {
        vector_ball = change_vector(vector_ball, 'y');
    }
    if (c_b_x == 5 && vector_ball > 1 && vector_ball < 5 && c_b_y > coor_left_r_y - 1 &&
        c_b_y < coor_left_r_y + 3) {  // если мяч движется влево
        vector_ball = change_vector(vector_ball, 'x');
        if (c_b_y == coor_left_r_y + 2) {  // если мяч попадает в нижний блок левой ракетки,
            vector_ball = 6;  // то задаем мячу направление 6 (вправо вниз)
        }
        if (c_b_y == coor_left_r_y + 1) {  // если мяч попадает в средний блок левой ракетки,
            vector_ball = 7;  // то задаем мячу направление 7 (вправо)
        }
        if (c_b_y == coor_left_r_y) {  // если мяч попадает в верхний блок левой ракетки,
            vector_ball = 8;  // то задаем мячу направление 8 (вправо вверх)
        }
    } else if (c_b_x == 74 && vector_ball > 5 && vector_ball < 9 && c_b_y > coor_right_r_y - 1 &&
               c_b_y < coor_right_r_y + 3) {  // если мяч движется вправо
        vector_ball = change_vector(vector_ball, 'x');
        if (c_b_y == coor_right_r_y + 2) {  // если мяч попадает в нижний блок правой ракетки,
            vector_ball = 4;  // то задаем мячу направление 4 (влево вниз)
        }
        if (c_b_y == coor_right_r_y + 1) {  // если мяч попадает в средний блок правой ракетки,
            vector_ball = 3;  // то задаем мячу направление 3 (влево)
        }
        if (c_b_y == coor_right_r_y) {  // если мяч попадает в верхний блок правой ракетки,
            vector_ball = 2;  // то задаем мячу направление 2 (влево вверх)
        }
    }
    return vector_ball;
}

int move_r(int last_coord, int vector) {
    if (reso_move(last_coord, vector) == 0) {
        return last_coord;
    }
    if (vector == 3 || vector == 7) {
        return last_coord;
    } else if (vector == 1 || vector == 2 || vector == 8) {
        return last_coord - 1;
    } else if (vector == 4 || vector == 5 || vector == 6) {
        return last_coord + 1;
    }
    return last_coord;
}

int move_b(int last_coord_x, int last_coord_y, int vector, char axis) {
    if (axis == 'x') {
        if (vector == 1 || vector == 5) {
            return last_coord_x;
        } else if (vector == 2 || vector == 3 || vector == 4) {
            return last_coord_x - 1;
        } else if (vector == 6 || vector == 7 || vector == 8) {
            return last_coord_x + 1;
        }
    } else {
        if (vector == 3 || vector == 7) {
            return last_coord_y;
        } else if (vector == 1 || vector == 2 || vector == 8) {
            return last_coord_y - 1;
        } else if (vector == 4 || vector == 5 || vector == 6) {
            return last_coord_y + 1;
        }
    }
    return 1;
}

int reso_move(int coord, int vector) {
    if (vector == 1) {
        if (coord == 0) {
            return 0;
        } else {
            return 1;
        }
    } else if (vector == 5) {
        if (coord == 22) {
            return 0;
        } else {
            return 1;
        }
    }
    return 1;
}

int change_vector(int vector, char axis) {
    if (axis == 'y') {
        if (vector == 1) {
            return 5;
        } else if (vector == 2 || vector == 6) {
            return vector + 2;
        } else if (vector == 4 || vector == 8) {
            return vector - 2;
        } else if (vector == 5) {
            return 1;
        }
    } else {
        if (vector == 3) {
            return 7;
        } else if (vector == 2 || vector == 4 || vector == 6) {
            return vector + 2;
        } else if (vector == 8) {
            return 2;
        } else if (vector == 7) {
            return 3;
        }
    }
    return vector;
}

void draw(int p1_y, int p2_y, int ball_x, int ball_y, int score_player1, int score_player2) {
    int WIDTH = 80, HEIGHT = 25, PADDLE_SIZE = 3;
    int p1_x = 4, p2_x = 75;
    clear();
    //  Верхняя граница
    for (int i = 0; i < WIDTH; i++) printw("_");
    printw("\n");

    // Вывод счета
    printw(" %02d                                                                          %02d\n",
           score_player1, score_player2);
    for (int i = 0; i < WIDTH; i++) printw("_");

    // Поле
    for (int y = 0; y < HEIGHT; y++) {
        if (y == 0) printw("\n");  // нужно для отображения номера нулевой строки в правильном месте
        for (int x = 0; x < WIDTH; x++) {
            if (x == p1_x && y >= p1_y && y < p1_y + PADDLE_SIZE)
                printw("|");
            else if (x == p2_x && y >= p2_y && y < p2_y + PADDLE_SIZE)
                printw("|");
            else if (x == ball_x && y == ball_y)
                printw("O");
            else
                printw(" ");
        }
        printw("\n");
    }

    // Нижняя граница
    for (int i = 0; i < WIDTH; i++) printw("-");
    printw("\n");
}

void draw_win(int player) {
    int WIDTH = 80, HEIGHT = 25;

    for (int i = 0; i < WIDTH; i++) printw("-");
    // Поле
    printw("\n");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (y != HEIGHT / 2 || x < 25 || x > 55) {
                printw("*");
            } else if (x == 25) {
                printw("         Player %d won!!!       ", player);
            }
        }
        printw("\n");
    }
    for (int i = 0; i < WIDTH; i++) printw("-");
    printw("\n");
}
