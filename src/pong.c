#include <stdio.h>

void print_playing_field(int x_racket1, int y_racket1, int x_racket2, int y_racket2, int x_ball, int y_ball);

int main(void) {
    print_playing_field(2,5,70,10,10,20);
    return 0;
}

// выводим игровое поле

// int x_racket1, int y_racket1, int x_racket2, int y_racket2, int x_ball, int y_ball)
void print_playing_field(int x_racket1, int y_racket1, int x_racket2, int y_racket2, int x_ball, int y_ball) {
      //int x = 0;
      int y = 0;

      while (y != 25) {
          // выводим нижнюю и верхнюю границу (вывод норм)
          if (y == 0 || y == 24) {
              for (int i = 0; i < 80; i++) {
                  printf("-");
              }
          } else {

          // в любом случае выводим новую строку
          for (int i = 0; i < 80; i++) {
              if (i == 41) {
                  printf("|");
              } 
              else {
                  // мяч
                  if (x_ball == i && y_ball == y) {
                      printf("*");
                  }

                  // ракетка 1 (левая)
                  if (x_racket1 == i && y_racket1 == y) {
                      printf("|");
                  }
                  if (x_racket1 == i && (y_racket1 + 1) == y) {
                      printf("|");
                  }
                  if (x_racket1 == i && (y_racket1 + 2) == y) {
                      printf("|");
                  }

                  //  ракетка 2 (правая)
                  if (x_racket2 == i && y_racket2 == y) {
                      printf("|");
                  }
                  if (x_racket2 == i && (y_racket2 + 1) == y) {
                      printf("|");
                  }
                  if (x_racket2 == i && (y_racket2 + 2) == y) {
                      printf("|");
                  }
              }
          }
          }

          printf("\n");
          y++;
      }
}
