#include "main.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[ ]){
	if (argc < 3) {
        printf("Usage: %s -c <filename> or -we <filename> <content> or -r <filename>\n", argv[0]);
        return 1; // Exit with an error code
    }

    if (strcmp(argv[1], "-c") == 0) {
        createFile(argv[2]);
    } else if(strcmp(argv[1], "-we") == 0) {
		appendExitingFile(argv[2], argv[3]);
	}else if(strcmp(argv[1], "-r") == 0){
        readFile(argv[2]);
    }else {
        printf("Usage: %s -c <filename> or -we <filename> <content> or -r <filename>\n", argv[0]);

        return 1;
    }


    return 0; // Exit without errors

}

void createFile(char* name){
    char filename[25];
    FILE *file;

	strcpy(filename, name);
	strcat(filename, ".txt");

	file = fopen(filename, "w");
	fclose(file);
}

void appendExitingFile(char* fileName, char* content){
	 FILE *file;

    file = fopen(fileName, "a");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

	 fprintf(file, "%s\n", content);

	fclose(file);

}

void readFile(char* fileName){
    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line); 
    }

    fclose(file);
}

void deleteLine(char* fileName, int nbline){
    FILE *file = fopen(fileName, 'w');
    char line[256];
    int count = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        if (count == nbline){
            strcopy(line, "");
        }
        count ++;
    }
    
    fclose(file);
}
