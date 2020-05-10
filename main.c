//Kornel Oskroba
//R00174822
#include <stdio.h>
#include <string.h>

int get_question_count(const char *filepath) {
    FILE *fp;
    char ch;
    int linesCount = 0; //used to keep track of how many lines there are

    fp = fopen(filepath, "r"); //Opens file
    if (fp == NULL) { //Makes sure its not empty
        printf("File \"%s\" does not exist!!!\n", filepath);
        return -1;
    }

    while ((ch = fgetc(fp)) != EOF) {    //read character by character and check for new line
        if (ch == '\n')
            linesCount++;
    }

    return linesCount + 1; //returns the amount of lines +1 as it always shows theres 1 lines less
}

int get_questions_and_answers(const char *filepath, char *questionArray, char *answersArray, int questionsCount) {
    printf("got in question\n");
    FILE *fp;
    char string[100];
    char *tempArray[questionsCount][100];
    char **ptr = tempArray;
    fp = fopen(filepath, "r"); //opens file

    for (int j = 0; j < questionsCount; ++j) { //Reads File contents and adds it to temporary Array
        fgets(tempArray[j], 100, fp);
        printf("%s", tempArray[j]);
    }

    fclose(fp);// closes File

    printf("\nchecking contents \n");
    for (int i = 0; i < questionsCount; ++i) {
        printf("%s", tempArray[i]);
    }

//    for (int z = 0; z < questionsCount; ++z) {
//        printf("%s  ", tempArray[z]);
//
//        char *token = strtok(tempArray[z], "?");
//        questionArray[z] = token;
//
//        printf("Q:%s", token);
//
//        token = strtok(NULL, " ");
//        answersArray[z] = token;
//
//        printf(" A:%s \n", token);
//
//    }

    return 1;
}

int main() {
    int questionsCount = get_question_count("C:\\Users\\Kornel\\Desktop\\C-Assigment2\\SampleQuestions.txt");
    printf("There are %d Questions in the File\n", questionsCount);

    char *questions[questionsCount][100]; // makes array with same size as amount of lines in file
    char *answers[questionsCount][100];  // makes array with same size as amount of answers

    get_questions_and_answers("C:\\Users\\Kornel\\Desktop\\C-Assigment2\\SampleQuestions.txt", questions, answers,
                              questionsCount);

    printf("Back in Main\n");
    for (int i = 0; i < questionsCount; ++i) {
        printf("%d Q:%s A:%s\n", i, questions[i], answers[i]);
    }
    return 0;
}
