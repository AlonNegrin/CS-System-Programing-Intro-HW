//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <stdbool.h>
///**
// *
// * Student1: Alon Negrin - 205843733
// * Student2: Matan Elbaz - 318321429
// */
//
///**
// * function that picks a number from 1-1000 lets user guess the
// * number until he makes a correct guess.
// */
//void guessing_game(void) {
//    srand(time(0));
//    int ran = rand() % 1000;
//    int pick = 0;
//    int count = 0;
//    while (pick != ran) {
//        printf("Enter a number (1-1000): ");
//        scanf("%d", &pick);
//        if (pick > ran) {
//            printf("Nope, too high!\n");
//            count++;
//        }
//        if (pick < ran) {
//            printf("Nope, too low!\n");
//            count++;
//        }
//        if (pick == ran) {
//            printf("Correct, the number is %d! You guessed it right after %d attempts\n", ran, count);
//        }
//    }
//}
//
///**
// * a function that ask user for numbers and tell him if its an
// * arithmetic progression.
// **/
//
//void is_arithmetic_progression(void) {
//    printf("Enter the first and second items separated by a comma: ");
//    int num1;
//    int num2;
//    int temp;
//    int diff;
//    int count = 2;
//    bool flag = true;
//    if (scanf("%d,%d", &num1, &num2) != 2) {
//        printf("Wrong input! goodbye");
//        exit(0);
//    } else {
//        diff = num2 - num1;
//        printf("What is the next item?");
//        while (scanf("%d", &temp) == 1) {
//
//            printf("What is the next item?");
//            count++;
//            if (diff != temp - num2) {
//                flag = false;
//            }
//            num2 = temp;
//        }
//        if (flag) {
//            printf("This series of %d items is an arithmetic progression with a1=%d and diff=%d", count, num1, diff);
//        } else {
//            printf("This series of %d items is not an arithmetic progression", count);
//        }
//
//    }
//
//}
//
///**
// * this function draws shapes to console (square or diamond).
// */
//
//void ascii_art(void) {
//    int num = 0;
//    printf("Would you like to draw a square (1) or a diamond (2)?");
//    if (!scanf("%d", &num)) {
//        printf("Wrong choice! good bye");
//        exit(0);
//    }
//    if (num != 1 && num != 2) {
//        printf("Wrong choice! good bye");
//        exit(0);
//    }
//    if (num == 1) {
//        printf("What should be the edge size? (1-30): ");
//        if (!scanf("%d", &num)) {
//            printf("Wrong choice! good bye");
//            exit(0);
//        }
//        if (num < 1 || num > 30) {
//            printf("Wrong choice! good bye");
//            exit(0);
//        } else {
//            for (int i = 0; i < num; i++) {
//                for (int j = 0; j < num; j++) {
//                    printf("*");
//                    if (j == num - 1) {
//                        printf("\n");
//                    }
//                }
//            }
//        }
//    }
//    if (num == 2) {
//        printf("What should be the diagonal size? (odd, 1-29): ");
//        if (!scanf("%d", &num)) {
//            printf("Wrong choice! good bye");
//            exit(0);
//        }
//        if (num < 1 || num > 29 || num % 2 != 1) {
//            printf("Wrong choice! good bye");
//            exit(0);
//        } else {
//            int start = (num / 2) + 0.5;
//            int end = start;
//            for (int r = 0; r < num; r++) {
//                if (r > 0 && r < (num / 2) + 0.5) {
//                    start = start - 1;
//                    end = end + 1;
//                }
//                if (r >= (num / 2) + 0.5) {
//                    start = start + 1;
//                    end = end - 1;
//                }
//                for (int p = 0; p <= num; p++) {
//                    if (p >= start && p <= end) {
//                        printf("*");
//                    } else {
//                        printf(" ");
//                    }
//                    if (p == num) {
//                        printf("\n");
//                    }
//                    if (start == 0 || end == num) {
//
//                    }
//                }
//            }
//
//        }
//    }
//}
//
//int main() {
//    ascii_art();
//    return 0;
//}
