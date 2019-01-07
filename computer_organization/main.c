#include <stdio.h>
#include <stdlib.h>
#include "render.h"

//nLines == number of instructions on file.txt

int nLines = 15;
int completedInstructions = 0;
int instructions[20];

void buildPipeline(int clock, int pipeline[][20], int k);

void runClock() {
    int pipeline[20][20];
    int clock = 0;
    int k = 0;
    int option = 1;

    //Filling array instructions and pipeline with zeros
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++)
            pipeline[i][j] = 0;
        instructions[i] = 0;
    }

    //run while input != "enter"
    while (option) {
        if (k == 0)
            instructions[k] = 1;
        else
            instructions[k] = instructions[k-1] + 1;
        buildPipeline(clock, pipeline, k);
        renderPipeline(pipeline, k, clock, completedInstructions, instructions);
        clock++;
        if(k < nLines)
            k++;

        option = (getchar() == '\n') ? 1 : 0;
    }
}





void buildPipeline(int clock, int pipeline[][20], int k) {
    if (k < nLines)
        pipeline[k][clock] = 1;

    if (clock != 0) {
        for (int i = 0; i < k; i++) {
            if (pipeline[i][clock-1] != 0)
                pipeline[i][clock] = pipeline[i][clock - 1] + 1;

            if (pipeline[i][clock] == 6) {
                completedInstructions++;
                //read instruction i;
                //if (instruction == conditional)
                    //i++
                    //while (i < k) {
                        //pipeline[i][clock] = 0
                    //}
                if (clock == 8) {
                    i++;
                    while (i < k) {
                        pipeline[i][clock] = 0;
                        i++;
                    }
                    instructions[k] = 17;
                }
            }
        }
    }


}

int main() {

    runClock();

    return 0;
}