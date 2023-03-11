#include <stdio.h>

void print_playing_field(int x_racket1, int y_racket1, int x_racket2, int y_racket2, int x_ball, int y_ball,
                         int score1, int score2);

int racket(int y_racket, char movement, int num);


int main(void) {

    int score_racket_left = 0; //  cчет левого
    int score_racket_right = 0; // счет правого
    int y_racket_left = 12; // положение по игреку у левой ракетки 
    int y_racket_rigth = 12; // положение по игреку у правой ракетки 
    int x_ball = 39; // положение мяча по иксу (пока сделала чисто по середине)
    int y_ball = 11; // положение мяча по игреку (пока сделала чисто по середине)

    char movement_left, movement_rigth; // команды для передвижения ракеток 

    
    // сначала просто выводим поле чтоб понимать че куда
    print_playing_field(0, y_racket_left, 79, y_racket_rigth, x_ball, y_ball, score_racket_left, score_racket_right);
    
    // пока никто не победил то продолжаем игру писать команды двигать мяч итд 
    while (score_racket_left != 21 || score_racket_right != 21) {

        // считываем чисто все наши команды
        while(1) {
            scanf("%c", &movement_left);
            movement_rigth = movement_left;
            if (movement_left == 'z' || movement_left == 'a' || movement_left == ' ' || movement_left == 'k' || movement_left == 'm')
                    break; // без этой проверки не работает с пробелом
        }

        movement_rigth = movement_left;
        if (racket(y_racket_left, movement_left, 1) == 1) { // если мы не вышли за границы то меняем положение ракеток иначе ничего не делаем
            if (movement_left == 'a') {
                y_racket_left = y_racket_left - 1; // двигаемся вверх
            } else if (movement_left == 'z') {
                y_racket_left = y_racket_left + 1; // двигаемся вниз
            }
        }

        if (racket(y_racket_rigth, movement_rigth, 2) == 1) { // если мы не вышли за границы то меняем положение ракеток иначе ничего не делаем
            if (movement_rigth == 'k') {
                y_racket_rigth = y_racket_rigth - 1; // двигаемся вверх
            } else if (movement_rigth == 'm') {
                y_racket_rigth = y_racket_rigth + 1; // двигаемся вниз
            }
        }

        // наверно здесь происходит все относительно мяча следовательно и подсчета очков

        //  после команд снова выводим наше поле (но когда появится мяч то наверн несколько раз придется для быстроты выводить)
        print_playing_field(0, y_racket_left, 79, y_racket_rigth, x_ball, y_ball, score_racket_left, score_racket_right);
    }

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
        } else { // если не граница? то мы начинаем выводить остальные строки
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


//  проверка на выходы за границы ракеток чтоб чекнуть нужно ли менять их положение на поле
int racket(int y_racket, char movement, int num) {
    int ans = 0; // если не выходим за границы то возвращаем 1 следовательно будем потом менять положение ракеток
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