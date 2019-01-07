#include <stdio.h>
#include <stdlib.h>

void buildPipeline(int clock, int pipeline[][20], int k);

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

void renderPipeline(int pipeline[][20]) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            switch (pipeline[i][j]) {
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
    }
}


void runClock2() {
    int pipeline[20][20];
    int clock = 0;
    int k = 0;
    int option = 1;

    while (option) {

        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++)
                pipeline[i][j] = 0;
        }

        buildPipeline(clock, pipeline, k);
        clock++;
        k++;

        renderPipeline(pipeline);

        option = (getchar() == '\n') ? 1 : 0;
    }
}





void buildPipeline(int clock, int pipeline[][20], int k) {
    if (pipeline[k][clock] == 0)
        pipeline[k][clock] = 1;
    else {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < clock; j++)
                pipeline[i][clock] += pipeline[i][clock - 1];
        }
    }
}







int main() {

    //runClock();
    runClock2();


    return 0;
}