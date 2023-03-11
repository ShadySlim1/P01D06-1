#include <stdio.h>

void print_playing_field(int x_racket1, int y_racket1, int x_racket2, int y_racket2, int x_ball, int y_ball,
                         int score1, int score2);

int main(void) {
    print_playing_field(0, 5, 79, 20, 10, 20, 2, 13);

    return 0;
}

// выводим игровое поле
void print_playing_field(int x_racket1, int y_racket1, int x_racket2, int y_racket2, int x_ball, int y_ball,
                         int score1, int score2) {
    int y = 0;

    // выводим счет
    for (int i = 0; i < 80; i++) {
        if (i == 37) {
            printf("%d", score1);
        } else if (i == 40) {
            printf("%d", score2);
        } else
            printf(" ");
    }
    printf("\n");

    while (y != 25) {
        // выводим нижнюю и верхнюю границу
        if (y == 0 || y == 24) {
            for (int i = 0; i < 80; i++) {
                printf("-");
            }
        } else {
            for (int i = 0; i < 80; i++) {
                // мяч
                if (x_ball == i && y_ball == y) {
                    printf("*");
                }

                // ракетка 1 (левая)
                else if (x_racket1 == i && y_racket1 == y) {
                    printf("|");
                } else if (x_racket1 == i && (y_racket1 + 1) == y) {
                    printf("|");
                } else if (x_racket1 == i && (y_racket1 + 2) == y) {
                    printf("|");
                }

                //  ракетка 2 (правая)
                else if (x_racket2 == i && y_racket2 == y) {
                    printf("|");
                } else if (x_racket2 == i && (y_racket2 + 1) == y) {
                    printf("|");

                } else if (x_racket2 == i && (y_racket2 + 2) == y) {
                    printf("|");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
        y++;
    }
}
