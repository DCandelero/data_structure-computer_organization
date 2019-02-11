import numpy as np

flag = 1

def renderPipeline(pipeline, lenght, clock, completedInstructions, pc):

    for i in range(40):
        print("-", end=" ")  # display "------"
    print()  # move cursor down to next line
    print("CLK", clock)  # display variable clock
    print()  # move cursor down to next line

    for i in range(lenght):  # for i to lenght
        print()  # move cursor down to next line
        print("instruction", pc[0][i], "\t", end=" ")  # display pipelne steps
        for j in range(clock):
            if pipeline[i][j] == 1:
                print(" FI ", end=" ")
            elif pipeline[i][j] == 2:
                print(" DI ", end=" ")
            elif pipeline[i][j] == 3:
                print(" FO ", end=" ")
            elif pipeline[i][j] == 4:
                print(" CO ", end=" ")
            elif pipeline[i][j] == 5:
                print(" EI ", end=" ")
            elif pipeline[i][j] == 6:
                print(" WO ", end=" ")
            else:
                print("    ", end=" ")
        print()
    print()
    print("\nCompleted Instructions :", completedInstructions)
    print()

def buildPipeline(pipeline, lenght, clock, completedInstructions, id):
    global flag  # to modify global variable
    pipeline[lenght][clock] = 1  # set 1 on the diagonal of the matrix
    if clock != 0:
        for i in range(lenght):
            if pipeline[i][clock - 1] != 0:
                pipeline[i][clock] = pipeline[i][clock - 1] + 1  # increment value of the last column

            if pipeline[i][clock] == 6:
                completedInstructions += 1
                flag = 1  # set flag case a instruction has been read
                #  Case a conditional action has ocurred
                if completedInstructions == 4 and flag == 1:
                    flag = 0
                    #  Move pc to the next address which contains the next instruction
                    pc[0][lenght] = 15  # getlineJump()
                    break

    return completedInstructions  # return number of instruction witch had already been read


if __name__ == '__main__':

    #  inicialization of variables
    clock = 0
    lenght = 0
    option = '1'
    completedInstructions = 0
    pipeline = np.zeros((50, 50))
    pc = np.zeros((1, 50))
    endProgram = 0

    # run while input != "0"
    print('Type any key to proceed and 0 to exit!')
    while option != '0':
        if lenght == 0:
            #  set first address which pc points to (represents)
            pc[0][0] = 1
        else:
            #  increment pc
            pc[0][lenght] = pc[0][lenght-1] + 1

        #  call functions to build and render the pipeline
        completedInstructions = buildPipeline(pipeline, lenght, clock, completedInstructions, pc)
        renderPipeline(pipeline, lenght, clock, completedInstructions, pc)
        clock += 1
        #verify if next instruction != NULL
        # if yes:
            #endProgram = 1

        if lenght < 17: #if endProgram != 1:
            lenght += 1

        option = input()







