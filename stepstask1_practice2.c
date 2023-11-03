#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[9];
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
    int counter=0;
    int recordcounter=0;
    int linestoprint = 3;
    int linesprinted = 0;
//Used the slides on reading from file to wrte the following code
    FILE *input = fopen("FitnessData_2023.csv", "r");
    if (input == NULL){
        return 1;
    }
    while (fgets(linebuffer, sizeof(linebuffer), input) != NULL){
    recordcounter++;
    }
    printf("Number of records in file: %d\n", recordcounter);
    fclose(input); 
    
    
    input = fopen("FitnessData_2023.csv", "r");
    while (fgets(linebuffer, sizeof(linebuffer), input) && counter < linestoprint){
        char date[11]; 
        char time[7];
        char steps[4];


        //Had to search online for following line of code as output was not printing in required format 
        linebuffer[strcspn(linebuffer,"\r\n")] = '\0';

        tokeniseRecord(linebuffer,",",date, time, steps);
        printf("%s/""%s/""%s\n", date, time, steps);
    
            strcpy(fitness[counter].date, date);
            strcpy(fitness[counter].time, time);
            fitness[counter].steps = atoi(steps);
            counter++;
        }

     fclose(input);
     return 0;
    }

    
   