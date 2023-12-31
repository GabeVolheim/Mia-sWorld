#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hangman.h"
#include "2048.h"

int main(void)
{
    char miaChoice;
    for(;;)
    {
        // Initial menu
        printf("Hello Mia\n");
        printf("What do you want to do today?\n");
        printf("1. Hangman\n2. 2048\n3. Quit\nYour Choice: ");
        scanf(" %c", &miaChoice);

        switch (miaChoice)
        {
            
        case '1':
            // Plays hangman
            playHangman();
            break;
        case '2':
            // Plays 2048
            play2048();
            break;
        case '3':
            // Mia quits
            puts("Okay bye loser :(");
            return 0;
            break;
        default:
            // Option is not availiable
            puts("\nThats not an option bruh\n");
            break;
        }
    }
    return 1;
}


