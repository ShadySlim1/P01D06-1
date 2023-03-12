#include <stdio.h>

void print_playing_field(int x_racket1, int y_racket1, int x_racket2, int y_racket2, int x_ball, int y_ball,
                         int score1, int score2);
int racket(int y_racket, char movement, int num);
int scan(char movement);
void getWinner(int score_racket_left, int s) int ball_in_racket_one(int x_ball, int y_ball, int y_racket_left,
                                                                    int BallPhase) {
    if (x_ball == 1) {
        if ((y_ball == y_racket_left) || (y_ball == y_racket_left - 1) || (y_ball == y_racket_left + 1)) {
            if (BallPhase == -1)
                return -2;
            else
                return 2;
        }
    }
    return BallPhase;
}
int ball_in_racket_two(int x_ball, int y_ball, int y_racket_rigth, int BallPhase) {
    if (x_ball == 78) {
        if ((y_ball == y_racket_rigth) || (y_ball == y_racket_rigth - 1) || (y_ball == y_racket_rigth + 1)) {
            if (BallPhase == 2)
                return 1;
            else
                return -1;
        }
    }
    return BallPhase;
}

int set_y_racket_left(int y_racket_left, int movement_left) {
    if (racket(y_racket_left, movement_left, 1) == 1 && movement_left == 'a')
        y_racket_left = y_racket_left - 1;
    else if (racket(y_racket_left, movement_left, 1) == 1 && movement_left == 'z')
        y_racket_left = y_racket_left + 1;  // двигаемся вниз
    return y_racket_left;
}

int set_y_racket_right(int y_racket_rigth, int movement_rigth) {
    if (racket(y_racket_rigth, movement_rigth, 2) == 1 && (movement_rigth == 'k'))
        y_racket_rigth = y_racket_rigth - 1;  // двигаемся вверх
    else if (racket(y_racket_rigth, movement_rigth, 2) == 1 && movement_rigth == 'm')
        y_racket_rigth = y_racket_rigth + 1;  // двигаемся вниз
    return y_racket_rigth;
}

int main(void) {
    int score_racket_left = 0, score_racket_right = 0, y_racket_left = 12, y_racket_rigth = 12, x_ball = 39,
        y_ball = 11, BallPhase = -1, s = 40;
    char movement_left;
    print_playing_field(0, y_racket_left, 79, y_racket_rigth, x_ball, y_ball, score_racket_left,
                        score_racket_right);
    while (score_racket_left < 21 && score_racket_right < 21) {
        while (1)
            if (scanf("%c", &movement_left) && scan(movement_left) == 1)
                break;  // без этой проверки не работает с пробелом
        char movement_rigth = movement_left;
        y_racket_left = set_y_racket_left(y_racket_left, movement_left);
        y_racket_rigth = set_y_racket_right(y_racket_rigth, movement_rigth);
        BallPhase = ball_in_racket_one(x_ball, y_ball, y_racket_left, BallPhase);
        if (x_ball == 0)
            if ((y_ball != y_racket_left) && (y_ball != y_racket_left - 1) && (y_ball != y_racket_left + 1)) {
                score_racket_right++;
                x_ball = 39;
                y_ball = 12;
            }
        BallPhase = ball_in_racket_two(x_ball, y_ball, y_racket_rigth, BallPhase);
        if (x_ball == 79)
            if ((y_ball != y_racket_rigth) && (y_ball != y_racket_rigth - 1) &&
                (y_ball != y_racket_rigth + 1)) {
                score_racket_left++;
                x_ball = 39;
                y_ball = 12;
            }
        if ((y_ball == 1) || (y_ball == 23)) BallPhase = -BallPhase;

        switch (BallPhase) {
            case -1:
                s = --y_ball || --x_ball;
                break;
            case -2:
                s = --y_ball || ++x_ball;
                break;
            case 1:
                s = ++y_ball || --x_ball;
                break;
            case 2:
                s = ++y_ball || ++x_ball;
                break;
        }
        print_playing_field(0, y_racket_left, 79, y_racket_rigth, x_ball, y_ball, score_racket_left,
                            score_racket_right);
    }
    getWinner(score_racket_left, s);
}

void getWinner(int score_racket_left, int s) {
    if (score_racket_left >= 21)
        s++ printf("\033[1m\033[4m\033[32m1 win\033[0m\n");
    else
        printf("\033[1m\033[4m\033[32m2 win\033[0m\n");
    return s
}

void print_playing_field(int x_racket1, int y_racket1, int x_racket2, int y_racket2, int x_ball, int y_ball,
                         int score1, int score2) {
    int y = 0;
    for (int i = 0; i < 80; i++)
        if (i == 37)
            printf("%d", score1);
        else if (i == 40)
            printf("%d", score2);
        else
            printf(" ");
    printf("\n");
    while (y != 25) {
        if (y == 0 || y == 24) {
            for (int i = 0; i < 80; i++) printf("-");
        } else {  // если не граница? то мы начинаем выводить остальные строки
            for (int i = 0; i < 80; i++)
                if (x_ball == i && y_ball == y)
                    printf("*");
                else if (x_racket1 == i && y_racket1 == y)
                    printf("|");
                else if (x_racket1 == i && (y_racket1 + 1) == y)
                    printf("|");
                else if (x_racket1 == i && (y_racket1 + 2) == y)
                    printf("|");
                else if (x_racket2 == i && y_racket2 == y)
                    printf("|");
                else if (x_racket2 == i && (y_racket2 + 1) == y)
                    printf("|");
                else if (x_racket2 == i && (y_racket2 + 2) == y)
                    printf("|");
                else
                    printf(" ");
        }
        printf("\n");
        y++;
    }
}

int racket(int y_racket, char movement, int num) {
    int ans = 0;  // если не выходим за границы то возвращаем 1 следовательно будем
    if (num == 1 && movement == 'a' && (y_racket - 1 != 0))
        ans = 1;
    else if (num == 1 && movement == 'z' && (y_racket + 1 != 22))
        ans = 1;
    else if (num == 2 && movement == 'k' && (y_racket - 1 != 0))
        ans = 1;
    else if (num == 2 && movement == 'm' && (y_racket + 1 != 22))
        ans = 1;
    return ans;
}

int scan(char movement) {
    int ans = 0;
    if (movement == 'z' || movement == 'a' || movement == ' ' || movement == 'k' || movement == 'm') ans = 1;
    return ans;
}