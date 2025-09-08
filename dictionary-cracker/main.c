#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*

This is a rudimentary dictionary password cracker. 
Its not perfect as it only accepts words 1024 characters or less and will likely break if it encounters words of length >1024.
This was mainly done to practice accessing files and reading file contents in C.


*/

int main() {

    FILE *pFile = fopen("/usr/share/wordlists/rockyou.txt", "r"); // Change the path accordingly to your setup. For mine, I'm using the wordlists package so I'm following that path
    char buffer[1024] = {0};
    char password[1024] = {0};
    clock_t startTime,endTime;
    double elapsedSeconds = 0.0f;

    if (pFile == NULL) {
        printf("Could not access file");
        return 1;
    }

    printf("Enter the password you wish to get cracked (Maximum of 1024 characters long): ");
    fgets(password,sizeof(password),stdin);
    password[strlen(password)-1] = '\0';

    startTime = clock();

    while (fgets(buffer,sizeof(buffer)/sizeof(buffer[0]),pFile)) {
        buffer[strlen(buffer)-1] = '\0';
        if (strcmp(buffer,password) == 0) {
            endTime = clock();
            printf("Cracked in %f seconds!\nThe password was \"%s\"", ((double)(endTime-startTime)/CLOCKS_PER_SEC),buffer);
            return 0;
        }
    }

    fclose(pFile);
    printf("Password was not cracked!");
    return 0;
}