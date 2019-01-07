#include "render.h"
#include <stdio.h>

void renderPipeline(int pipeline[][20], int k, int clock, int completedInstructions, int instructions[]) {

    printf("\n");
    for (int i = 0; i < 50;i++)
        printf("-");
    printf("\n");
    printf("CLK : %d", clock);
    printf("\n");

    for (int i = 0; i <= k; i++) {
        printf("\n");
        printf("instruction %d\t", instructions[i]);
        for (int j = 0; j <= clock; j++) {
            //printf("%d", pipeline[i][j]);
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
    printf("\n");
    printf("Completed Instructions : %d", completedInstructions);
    printf("\n");
}
