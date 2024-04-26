#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#define CHUNK 200

char* ask_item(){
    char* item;
    do {
        item = NULL;
        printf("\nDo you choose rock, paper or scissors?\n");
        char tempbuf[CHUNK];
        size_t inputlen = 0, templen = 0;
        do {
            fgets(tempbuf, CHUNK, stdin);
            templen = strlen(tempbuf);
            item = realloc(item, inputlen + templen + 1);
            strcpy(item + inputlen, tempbuf);
            inputlen += templen;
        } while (templen == CHUNK - 1 && tempbuf[CHUNK - 2] != '\n');
        if (strcasecmp("rock\n", item) == 0 || strcasecmp("paper\n", item) == 0 ||
            strcasecmp("scissors\n", item) == 0) {
            return item;
        }
        printf("That is not a valid item\n");
    } while (strcasecmp("rock\n", item) != 0 || strcasecmp("paper\n", item) != 0 || strcasecmp("scissors\n", item) != 0);
}

const char* choose(){
    char* item = malloc(sizeof(char) * (strlen("scissors") + 1));
    int item_choose = rand() % 3;
    switch (item_choose) {
        case 0:
            strcpy(item, "rock\n");
            break;
        case 1:
            strcpy(item, "paper\n");
            break;
        case 2:
            strcpy(item, "scissors\n");
            break;
    }
    return item;
}

int referee(const char* item, const char* comp_item){
    if (strcasecmp(item,comp_item) == 0){
        printf("It's a tie!\n");
        return 2;
    }
    if (strcasecmp(item, "rock\n") == 0){
        if(strcmp(comp_item, "scissors") == 0){
            return 0;
        }
        else{
            return 1;
        }
    }
    if (strcasecmp(item, "paper\n") == 0){
        if(strcmp(comp_item, "rock") == 0){
            return 0;
        }
        else{
            return 1;
        }
    }
    if (strcasecmp(item, "scissors\n") == 0){
        if(strcmp(comp_item, "paper") == 0){
            return 0;
        }
        else{
            return 1;
        }
    }
    return 3;
}

int main(void) {
    char *item;
    srand(time(NULL));
    printf("*********************\n");
    printf("ROCK PAPER SCISSORS\n");
    printf("*********************\n");
    do {
        item = ask_item();
        for (int i = 0; i < strlen(item); ++i) {
            item[i] = tolower(item[i]);
        }
        printf("You chose %s\n", item);
        const char *comp_item = choose();
        printf("Computer chose %s", comp_item);
        int state = referee(item, comp_item);
        switch (state) {
            case 0:
                printf("You won!\n");
                break;
            case 1:
                printf("You lost! :(\n");
                break;
            case 2:
                printf("You tied with the computer.\n");
                break;
            case 3:
                printf("That is not a valid item!\n");
                break;
        }
        printf("Press enter to play again");
    }while (getchar() != "\n");
}
