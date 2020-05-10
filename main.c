//Kornel Oskroba
//R00174822
#include <stdio.h>

int get_question_count(const char *filepath){
    FILE *fp;
    char ch;
    int linesCount=0; //used to keep track of how many lines there are

    //open file in read more
    fp=fopen(filepath,"r");
    if(fp==NULL) {
        printf("File \"%s\" does not exist!!!\n",filepath);
        return -1;
    }

    //read character by character and check for new line
    while((ch=fgetc(fp))!=EOF) {
        if(ch=='\n')
            linesCount++;
    }

    //close the file
    fclose(fp);

    return linesCount+1; //returns the amount of lines +1 as it always shows theres 1 lines less
}

int main() {
    int questionsCount = get_question_count("C:\\Users\\Kornel\\Desktop\\C-Assigment2\\SampleQuestions.txt");
    printf("There are %d Questions in the File\n",questionsCount);

    char questions[questionsCount][1000]; // makes array with same size as amount of lines in file
    char answers[questionsCount][100];  // makes array with same size as amount of answers


    printf("Hello, World!\n");
    return 0;
}
