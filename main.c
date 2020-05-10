//Kornel Oskroba
//R00174822
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include<time.h>


int get_question_count(const char *filepath) {
    char ch;
    int linesCount = 0; //used to keep track of how many lines there are

    while ((ch = fgetc(filepath)) != EOF) {    //read character by character and check for new line
        if (ch == '\n')
            linesCount++;
    }
    return linesCount + 1; //returns the amount of lines +1 as it always shows theres 1 lines less
}

int clue_level_2(char *answer) {
    for (int i = 0; i < strlen(answer); ++i) {
        printf("-"); // prints dashes for lenght of answer
    }
}

int clue_level_3(char *answer) {
    int lenOfAnswer = strlen(answer);
    if (lenOfAnswer > 2) {
        printf("%c", answer[0]); //prints first letter
        for (int i = 0; i < strlen(answer) - 2; ++i) { // prints dashes for lenght -2
            printf("-");
        }
        printf("%c", answer[lenOfAnswer - 1]); //prints last letter
    } else if (lenOfAnswer == 2) { //prints 1 and second letter if word is 2 letters long
        printf("%c", answer[0]);
        printf("%c", answer[1]);
    } else {
        printf("%c", answer[0]);//pritns only one letter if word is one letter long
    }
}

int clue_level_4(char *answer) {
    int lenOfAnswer = strlen(answer);
    char *clue[100];

    if (lenOfAnswer > 2) {
        int rand_num1 = (rand() % (lenOfAnswer)); //gets a random number
        int rand_num2 = (rand() % (lenOfAnswer));
        for (int i = 0; i < strlen(answer); ++i) {
            clue[i] = '-'; //set clues to dashes for lenght of answer
        }
        clue[rand_num2] = answer[rand_num2]; // changers the randomly selectd letters to actual letters from answer
        clue[rand_num1] = answer[rand_num1];
        for (int j = 0; j < strlen(answer); ++j) {
            printf("%c", clue[j]); //prints the clue
        }
    } else if (lenOfAnswer == 2) { //prints both letters if theres only 2
        printf("%c", answer[0]);
        printf("%c", answer[1]);
    } else {
        printf("%c", answer[0]); //pritns 1 letter if only 1 there
    }
}

int clue_level_5(char *answer) {
    int lenOfAnswer = strlen(answer);
    char *clue[100];
    int randomness = 0; // used to see if random letter was assigned
    if (lenOfAnswer > 2) {
        for (int i = 0; i < strlen(answer) + 1; ++i) { //loops for lenght of answer
            while (randomness == 0) {                   //keeps running until a new random letter is chosen
                int rand_num1 = (rand() % (lenOfAnswer + 1));
                if (clue[rand_num1] != '-') {           //used to keep track of what position have already been used
                    printf("%c", answer[rand_num1]); // prints the position from the answer
                    clue[rand_num1] = '-';
                    randomness = 1; //breaks the loop as a random letter was used
                }
            }
            randomness = 0; // resets randomness
        }
    } else if (lenOfAnswer == 2) {
        printf("%c", answer[1]);
        printf("%c", answer[2]);
    } else {
        printf("%c", answer[0]);
    }
}

int main(int argc, char **argv) {
    srand(time(0)); // used to generate a random seed for random generators used later

//    const char *filepath = "C:\\Users\\Kornel\\Desktop\\C-Assigment2\\SampleQuestions.txt";
    const char *filepath = argv[1]; // reads in file location (Used Absolute Path)
    FILE *fp;
    fp = fopen(filepath, "r"); //Opens file
    if (fp == NULL) { //Makes sure its not empty
        printf("File \"%s\" does not exist!!!\nPlease make sure you are using Absolute Path\n progrmaName file int", filepath);
        exit(1);
    }
    int questionsCount = get_question_count(fp);

    int difficultyLevel = atoi(argv[2]); // reading in difficulty from paramater

    char *questions[questionsCount][100]; // makes array with same size as amount of lines in file
    char *answers[questionsCount][100];  // makes array with same size as amount of answers
    char *tempArray[questionsCount][100];
    fp = fopen(filepath, "r"); //opens file

    for (int j = 0; j < questionsCount; ++j) { //Reads File contents and adds it to temporary Array
        fgets(tempArray[j], 100, fp);
        printf("%s", tempArray[j]);
    }
    fclose(fp);// closes File

    for (int k = 0; k < questionsCount; ++k) {

        char *question = strtok(tempArray[k], "?");//breakes the temp array on characters
        *questions[k] = question; // adds to questoion array
        char *answer = strtok(NULL, "? ");
        *answers[k] = answer;//adds to answers array
    }

    //Getting user input
    int questionsAnswered = 0; //used to run a while loop
    char wordInput[100]; //used to store users answer
    char answerInLowercase[100]; //answer for the question to be asked
    int correct = 0; //keep track of how many correctly answered question there are
    int incorrect = 0; //keep track of how many incorrectly answered question there are
    char *answerTracker[questionsCount]; //Used to keep track of which question the user got wrong
    char getAnswers; //used when asking if the player wishes to continue


    if (difficultyLevel == 6) { // if difficulty 6 is selected it randomly picked between 1 or 5
        difficultyLevel = (rand() % (5) +
                           1); // has to be range to 5 as it will gen (0 - 4) and the plus 1 makes it between (1 - 5)
    }

    printf("\nThere are %d Questions in the File\n", questionsCount); //tells the user how many questions were loaded
    printf("difficulty level %d\n\n", difficultyLevel); // tells the user what the difficulty setting is
    int exit = 0;
    while (exit == 0) {
        //random question Picker
        int questionNumber = 0;
        char *usedQuestions[questionsCount];
        int randomness = 0; // used to see if random letter was assigned
        for (int i = 0; i < questionsCount; ++i) { //loops for lenght of answer
            while (randomness == 0) {                   //keeps running until a new random letter is chosen
                int rand_num1 = (rand() % (questionsCount));
                if (usedQuestions[rand_num1] !=
                    '-') {           //used to keep track of what position have already been used
                    questionNumber = rand_num1;
                    usedQuestions[rand_num1] = '-';
                    randomness = 1; //breaks the loop as a random letter was used
                }
            }
            randomness = 0; // resets randomness


            strncpy(answerInLowercase, *answers[questionNumber], 100);


            for (int i = 0; answerInLowercase[i]; i++) { //makes all the letters lowercase
                answerInLowercase[i] = tolower(answerInLowercase[i]);
            }

            char *pos;
            if ((pos = strchr(answerInLowercase, '\n')) != NULL) // removes \n from answer so it can be compared
                *pos = '\0';
            if ((pos = strchr(answerInLowercase, '\r')) != NULL)// removes \r from answer so it can be compared
                *pos = '\0';

            //Clue
            if (difficultyLevel == 1) { // used to give different clues based on the difficulty
                printf("%d:%s?\n", questionsAnswered, *questions[questionNumber]);
                printf("?");
            } else if (difficultyLevel == 2) {
                printf("%d:%s?\n", questionsAnswered, *questions[questionNumber]);
                clue_level_2(answerInLowercase);
            } else if (difficultyLevel == 3) {
                printf("%d:%s?\n", questionsAnswered, *questions[questionNumber]);
                clue_level_3(answerInLowercase);
            } else if (difficultyLevel == 4) {
                printf("%d:%s?\n", questionsAnswered, *questions[questionNumber]);
                clue_level_4(answerInLowercase);
            } else if (difficultyLevel == 5) {
                printf("%d:%s?\n", questionsAnswered, *questions[questionNumber]);
                clue_level_5(answerInLowercase);
            }


            scanf("%s", wordInput); //gets user input

            for (int i = 0; wordInput[i]; i++) { //makes all the letters lowercase
                wordInput[i] = tolower(wordInput[i]);
            }

            if (strcmp(answerInLowercase, wordInput) == 0) { //compares words to see if they are the same
                correct++; // add to correctly answered
                printf("Correct %d Questions Answered Correctly So Far", correct);
            } else {
                printf("Incorrect %d Questions Answered Correctly So Far", correct);
                answerTracker[incorrect] = questionNumber;
                incorrect++;
            }

            questionsAnswered++;
            printf("\n");

        }

        printf("%d questions answered correctly\n\n", correct);
//        printf("Would you like to see the answers to the questions you got wrong?(y/n) ");
//        scanf("%c", &getAnswers); //gets user input if they wish to continue playing
//        getchar();
//        if (((char *) getAnswers == 'Y') || (getAnswers == 'y')) {
//            printf("hello\n");
//            printf("hello\n");
//            printf("hello\n");
//            printf("hello\n");
//            for (int i = 0; i < incorrect; ++i) {
//                int wrongQuestion = answerTracker[i];
//                printf("%d Q:%s? A:%s", i, *questions[wrongQuestion], *answers[wrongQuestion]);
//            }
//        }
        exit = 1;
    }

    return 0;
}