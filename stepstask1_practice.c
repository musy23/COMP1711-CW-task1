#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main(){
     FITNESS_DATA fitness[100];
    int buffer_size = 250;
    char linebuffer[buffer_size];
    int recordcounter=0;
    int linestoprint = 3;
    int linesprinted = 0;

    FILE *input = fopen("FitnessData_2023.csv", "r");
    if (input == NULL){
        return 1;
    }
    //printing the number of lines in the data file using a while loop
    while (fgets(linebuffer, sizeof(linebuffer), input) != NULL){
    recordcounter++;
    }
    printf("Number of records in file: %d\n", recordcounter);
    fclose(input); 

    char date[1], time[6], steps[4];
    tokeniseRecord(linebuffer,",",date,time,steps);

    input = fopen("FitnessData_2023.csv", "r");
    while (fgets(linebuffer, buffer_size, input))
    {
        if (recordcounter < 100){
            strcpy(fitness[recordcounter].date,date);
            strcpy(fitness[recordcounter].time,time);
            fitness[recordcounter].steps = atoi(steps);
        }
        recordcounter++;

        
        input = fopen("FitnessData_2023.csv", "r");
        while (fgets(linebuffer, sizeof(linebuffer), input) != NULL && linesprinted < linestoprint){
            printf("%s", linebuffer);
            linesprinted++;
    }
     fclose(input);
    }

    return 0;
}
   