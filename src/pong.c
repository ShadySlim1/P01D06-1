#include <stdio.h>

void print_playing_field(int x_racket1, int y_racket1, int x_racket2,
                         int y_racket2, int x_ball, int y_ball, int score1,
                         int score2);

int racket(int y_racket, char movement, int num);

int main(void) {

    int score_racket_left = 0;  //  cчет левого
    int score_racket_right = 0; // счет правого
    int y_racket_left = 12; // положение по игреку у левой ракетки
    int y_racket_rigth = 12; // положение по игреку у правой ракетки
    int x_ball = 39; // положение мяча по иксу (пока сделала чисто по середине)
    int y_ball = 11; // положение мяча по игреку (пока сделала чисто по середине)
    char movement_left, movement_rigth; // команды для передвижения ракеток
    int BallPhase = -1; // вектор мяча
    // сначала просто выводим поле чтоб понимать че куда
    print_playing_field(0, y_racket_left, 79, y_racket_rigth, x_ball, y_ball,
                        score_racket_left, score_racket_right);

    // пока никто не победил то продолжаем игру писать команды двигать мяч итд
    while (score_racket_left < 21 && score_racket_right < 21) {

        // считываем чисто все наши команды
        while (1) {
            scanf("%c", &movement_left);
            movement_rigth = movement_left;
            if (movement_left == 'z' || movement_left == 'a' ||
                movement_left == ' ' || movement_left == 'k' || movement_left == 'm')
                break; // без этой проверки не работает с пробелом
        }

        movement_rigth = movement_left;
        if (racket(y_racket_left, movement_left, 1) ==
            1) { // если мы не вышли за границы то меняем положение ракеток иначе
            // ничего не делаем
            if (movement_left == 'a') {
                y_racket_left = y_racket_left - 1; // двигаемся вверх
            } else if (movement_left == 'z') {
                y_racket_left = y_racket_left + 1; // двигаемся вниз
            }
        }

        if (racket(y_racket_rigth, movement_rigth, 2) ==
            1) { // если мы не вышли за границы то меняем положение ракеток иначе
            // ничего не делаем
            if (movement_rigth == 'k') {
                y_racket_rigth = y_racket_rigth - 1; // двигаемся вверх
            } else if (movement_rigth == 'm') {
                y_racket_rigth = y_racket_rigth + 1; // двигаемся вниз
            }
        }

        //  здесь происходит все относительно мяча следовательно и подсчета очков

        // проверяем попала ли первая ракетка в мяч
        if (x_ball == 1) {
            // по 3 позициям
            if ((y_ball == y_racket_left) || (y_ball == y_racket_left - 1) ||
                (y_ball == y_racket_left + 1)) {
                if (BallPhase == -1) {
                    BallPhase = -2;
                } else {
                    BallPhase = 2;
                }
            }
        }
        // проверяем вышел ли наш мяч за границы первого, если да то даём балл
        // второму игроку
        if (x_ball == 0) {
            if ((y_ball != y_racket_left) && (y_ball != y_racket_left - 1) &&
                (y_ball != y_racket_left + 1)) {
                score_racket_right++;
                x_ball = 39;
                y_ball = 12;
            }
        }
        // проверяем попала ли вторая ракетка в мяч
        if (x_ball == 78) {
            if ((y_ball == y_racket_rigth) || (y_ball == y_racket_rigth - 1) ||
                (y_ball == y_racket_rigth + 1)) {
                if (BallPhase == 2) {
                    BallPhase = 1;
                } else {
                    BallPhase = -1;
                }
            }
        }
        // проверяем вышел ли наш мяч за границы первого, если да то даём балл
        // первому игроку
        if (x_ball == 79) {
            if ((y_ball != y_racket_rigth) && (y_ball != y_racket_rigth - 1) &&
                (y_ball != y_racket_rigth + 1)) {
                score_racket_left++;
                x_ball = 39;
                y_ball = 12;
            }
        }
        // Меняем траекторию мяча если вверх то вниз и обратно. Такая система у нас
        // работает, так как при отрицательном значение идёт вверх, при
        // положительном вниз. А от направления влево право влияет значение:
        // 1-влево, 2- вправо
        if ((y_ball == 1) || (y_ball == 23)) {
            BallPhase = -BallPhase;
        }
        // от BallPhase зависит вектор мяча
        switch (BallPhase) {
            // вверх лево
            case -1:
                y_ball = y_ball - 1;
                x_ball = x_ball - 1;
                break;
                // вверх право
            case -2:
                y_ball = y_ball - 1;
                x_ball = x_ball + 1;
                break;
                // вниз влево
            case 1:
                y_ball = y_ball + 1;
                x_ball = x_ball - 1;
                break;
                // вниз вправо
            case 2:
                y_ball = y_ball + 1;
                x_ball = x_ball + 1;
                break;
        }

        //  после команд снова выводим наше поле (но когда появится мяч то наверн
        //  несколько раз придется для быстроты выводить)
        print_playing_field(0, y_racket_left, 79, y_racket_rigth, x_ball, y_ball,
                            score_racket_left, score_racket_right);
    }
    if (score_racket_left >= 21)
        printf("\033[1m\033[4m\033[32m1 win\033[0m\n");
    else
        printf("\033[1m\033[4m\033[32m2 win\033[0m\n");

    return 0;
}


// выводим игровое поле
void print_playing_field(int x_racket1, int y_racket1, int x_racket2,
                         int y_racket2, int x_ball, int y_ball, int score1,
                         int score2) {
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
        if (y == 0 || y == 24) { // выводим нижнюю и верхнюю границу
            for (int i = 0; i < 80; i++) {
                printf("-");
            }
        } else { // если не граница то мы начинаем выводить остальные строки
            for (int i = 0; i < 80; i++) { 
                if (x_ball == i && y_ball == y) { // мяч
                    printf("*");
                } else if (x_racket1 == i && y_racket1 == y) { // ракетка 1 (левая)
                    printf("|");
                } else if (x_racket1 == i && (y_racket1 + 1) == y) { 
                    printf("|");
                } else if (x_racket1 == i && (y_racket1 + 2) == y) {
                    printf("|");
                } else if (x_racket2 == i && y_racket2 == y) { // ракетка 2 (правая)
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

//  проверка на выходы за границы ракеток чтоб чекнуть нужно ли менять их
//  положение на поле
int racket(int y_racket, char movement, int num) {
    int ans = 0; // если не выходим за границы то возвращаем 1 следовательно будем
    // потом менять положение ракеток
    if (num == 1 && movement == 'a' && (y_racket - 1 != 0)) {
        ans = 1;
    } else if (num == 1 && movement == 'z' && (y_racket + 1 != 22)) {
        ans = 1;
    } else if (num == 2 && movement == 'k' && (y_racket - 1 != 0)) {
        ans = 1;
    } else if (num == 2 && movement == 'm' && (y_racket + 1 != 22)) {
        ans = 1;
    }
    return ans;
}