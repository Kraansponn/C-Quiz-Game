//Kornel Oskroba
//R00174822
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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

int clue_level_2(char *answer) {
    for (int i = 0; i < strlen(answer); ++i) {
        printf("-");
    }
}

int clue_level_3(char *answer) {
    int lenOfAnswer = strlen(answer);
    if (lenOfAnswer > 2) {
        printf("%c", answer[0]);
        for (int i = 0; i < strlen(answer) - 2; ++i) {
            printf("-");
        }
        printf("%c", answer[lenOfAnswer - 1]);
    } else if (lenOfAnswer == 2) {
        printf("%c", answer[0]);
        printf("%c", answer[1]);
    } else {
        printf("%c", answer[0]);
    }
}

int clue_level_4(char *answer) {
    int lenOfAnswer = strlen(answer);
    char *clue[100];

    if (lenOfAnswer > 2) {
        int rand_num1 = (rand() % (lenOfAnswer));
        int rand_num2 = (rand() % (lenOfAnswer));
        for (int i = 0; i < strlen(answer); ++i) {
            clue[i] = '-';
        }
        clue[rand_num2] = answer[rand_num2];
        clue[rand_num1] = answer[rand_num1];
        for (int j = 0; j < strlen(answer); ++j) {
            printf("%c", clue[j]);
        }
    } else if (lenOfAnswer == 2) {
        printf("%c", answer[0]);
        printf("%c", answer[1]);
    } else {
        printf("%c", answer[0]);
    }
}

int clue_level_5() {}

int main() {
    int questionsCount = get_question_count("C:\\Users\\Kornel\\Desktop\\C-Assigment2\\SampleQuestions.txt");
    int difficultyLevel = 4;

    char *questions[questionsCount][100]; // makes array with same size as amount of lines in file
    char *answers[questionsCount][100];  // makes array with same size as amount of answers

    printf("got in question\n");
    const char *filepath = "C:\\Users\\Kornel\\Desktop\\C-Assigment2\\SampleQuestions.txt";
    FILE *fp;
    char *tempArray[questionsCount][100];
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

    for (int k = 0; k < questionsCount; ++k) {

        char *question = strtok(tempArray[k], "?");
        *questions[k] = question;
        char *answer = strtok(NULL, "? ");
        *answers[k] = answer;
    }

    printf("\nBack in Main\n");
    for (int i = 0; i < questionsCount; ++i) {
        printf("%d Q:%s A:%s\n", i, *questions[i], *answers[i]);
    }


    printf("There are %d Questions in the File\n", questionsCount);
    //Getting user input
    int questionsAnswered = 0; //used to run a while loop
    char wordInput[100]; //used to store users answer
    char answerInLowercase[100];
    int correct = 0;

    while (questionsCount > questionsAnswered) {

        strncpy(answerInLowercase, *answers[questionsAnswered], 100);

        for (int i = 0; answerInLowercase[i]; i++) { //makes all the letters lowercase
            answerInLowercase[i] = tolower(answerInLowercase[i]);
        }

        char *pos;
        if ((pos = strchr(answerInLowercase, '\n')) != NULL) // removes \n from answer so it can be compared
            *pos = '\0';
        if ((pos = strchr(answerInLowercase, '\r')) != NULL)// removes \r from answer so it can be compared
            *pos = '\0';

        //Clue
        if (difficultyLevel == 1) {
            printf("%s?\n", *questions[questionsAnswered]);
            printf("?");
        } else if (difficultyLevel == 2) {
            printf("%s?\n", *questions[questionsAnswered]);
            clue_level_2(answerInLowercase);
        } else if (difficultyLevel == 3) {
            printf("%s?\n", *questions[questionsAnswered]);
            clue_level_3(answerInLowercase);
        } else if (difficultyLevel == 4) {
            printf("%s?\n", *questions[questionsAnswered]);
            clue_level_4(answerInLowercase);
        } else if (difficultyLevel == 5) {
            printf("%s?\n", *questions[questionsAnswered]);
            clue_level_5(answerInLowercase);
        }


        scanf("%s", wordInput); //gets user input

        for (int i = 0; wordInput[i]; i++) { //makes all the letters lowercase
            wordInput[i] = tolower(wordInput[i]);
        }

        if (strcmp(answerInLowercase, wordInput) == 0) {
            printf("Correct");
            correct++;
        } else {
            printf("Incorrect");
        }

        questionsAnswered++;
        printf("\n");
    }
    printf("%d questions answered correctly", correct);
    return 0;
}