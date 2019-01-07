#include <stdio.h>
#include <stdlib.h>

int runClock() {
    int clock = 0;
    int i = 0;
    int line[20];
    int aux = 0;
    int option = 1;

    //filling array with zeros
    for (int j = 0; j < 20; j++) {
        line[j] = 0;
    }

    while (option) {
        clock++;
        i = aux;
        while (i < clock) {
            line[i]++;

            //6 stages
            if (line[i] == 6) {
                aux = i;
            }

            i++;
        }

        for (int j = 0; j < clock; j++) {
            switch (line[j]) {
                case 1:
                    printf(" FI ");
                    break;
                case 2:
                    printf(" DI ");
                    break;
                case 3:
                    printf(" CO ");
                    break;
                case 4:
                    printf(" FO ");
                    break;
                case 5:
                    printf(" EI ");
                    break;
                case 6:
                    printf(" WO ");
                    break;
                default:
                    printf("    ");
            }
        }
        printf("\n");

        option = (getchar() == '\n') ? 1 : 0;
    }

}

int main() {

    runClock();


    return 0;
}