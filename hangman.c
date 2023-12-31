#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define ALPHABET_LENGTH 26
#define WORD_COUNT 1000
#define MAX_SIZE 256

int checkGuessed(char *guessedLetters, int *guessedIndex, char letterGuess)
{
    for(int i = 0; i < *guessedIndex + 1; i++)
    {
        if(letterGuess == guessedLetters[i])
        {
            return -1;
        }
    }
    return 1;
}

int checkWord(char *word, char letterGuess, char *guessedLetters, int* guessedIndex, char* guessArray)
{
    size_t wordLength = strlen(word);
    int timesItAppears = 0;

    // Adding the letter to the guessed array
    guessedLetters[*guessedIndex] = letterGuess;
    *guessedIndex += 1;
    guessedLetters[*guessedIndex] = '\0';

    // if the letter is inside of the word
    for(int i = 0; i < wordLength; i++)
    {
        if(word[i] == letterGuess)
        {
            timesItAppears++;
            guessArray[i] = letterGuess;
        }
    }

    // If the letter does not appear, we exit with an error and add to the array
    if(timesItAppears == 0)
    {
        return -1;
    }

    return 1;
}

int inAlphabet(char letter)
{
    // Ascii math
    for(int i = 0; i < ALPHABET_LENGTH; i++)
    {
        if(letter == ('a' + i)) return 1;
    }
    
    return -1;
}

void validateInput(char *letter)
{
    while(inAlphabet(*letter) == -1)
    {
        printf("Mia, that is not in the alphabet. R u fr.\n");
        printf("Pick another\n");
        printf("Rememeber, between a and z: ");
        scanf(" %c",letter);
    }
}

void printScreen(int tries, char* guessArray, char* guessLetters)
{
    switch(tries){
    case 0:
        printf(" __________________\n");
        printf("|                 \n");
        printf("|                 \n");
        printf("|                 \n");
        printf("|                 \n");
        printf("|                 \n");
        printf("|                 \n");
        printf("|                 \n");
        printf("|                 \n");
        printf("|__________________\n \n");
        printf("%s\n",guessArray);
        printf("Letters you have already guessed: %s\n",guessLetters);
        break;
    case 1:
        printf(" __________________\n");
        printf("|                |\n");
        printf("|               0 \n");
        printf("|                 \n");
        printf("|                 \n");
        printf("|                 \n");
        printf("|                 \n");
        printf("|                 \n");
        printf("|                 \n");
        printf("|__________________\n \n");
        printf("%s\n",guessArray);
        printf("Letters you have already guessed: %s\n",guessLetters);
        puts(guessLetters);
        break;

    case 2:
        printf(" __________________\n");
        printf("|                |\n");
        printf("|               0 0\n");
        printf("|                 \n");
        printf("|                 \n");
        printf("|                 \n");
        printf("|                 \n");
        printf("|                 \n");
        printf("|                 \n");
        printf("|__________________\n \n");
        printf("%s\n",guessArray);
        printf("Letters you have already guessed: %s\n",guessLetters);
        break;
    case 3:
        printf(" __________________\n");
        printf("|                |\n");
        printf("|               0 0\n");
        printf("|                |\n");
        printf("|                |\n");
        printf("|                 \n");
        printf("|                 \n");
        printf("|                 \n");
        printf("|                 \n");
        printf("|__________________\n \n");
        printf("%s\n",guessArray);
        printf("Letters you have already guessed: %s\n",guessLetters);
        break;
    case 4:
        printf(" __________________\n");
        printf("|                |\n");
        printf("|               0 0\n");
        printf("|                |\n");
        printf("|               / \\\n");
        printf("|                 \n");
        printf("|                 \n");
        printf("|                 \n");
        printf("|                 \n");
        printf("|__________________\n \n");
        printf("%s\n",guessArray);
        printf("Letters you have already guessed: %s\n",guessLetters);
        break;
    case 5:
        printf(" __________________\n");
        printf("|                |\n");
        printf("|               0 0\n");
        printf("|                |\n");
        printf("|               / \\\n");
        printf("|                | \n");
        printf("|                 \n");
        printf("|                 \n");
        printf("|                 \n");
        printf("|__________________\n \n");
        printf("%s\n",guessArray);
        printf("Letters you have already guessed: %s\n",guessLetters);
        break;
    case 6:
        printf(" __________________\n");
        printf("|                |\n");
        printf("|               0 0\n");
        printf("|                |\n");
        printf("|               /|\\\n");
        printf("|                | \n");
        printf("|               /  \n");
        printf("|                 \n");
        printf("|                 \n");
        printf("|__________________\n \n");
        printf("%s\n",guessArray);
        printf("Letters you have already guessed: %s\n",guessLetters);
        break;

    case 7:
        printf(" __________________\n");
        printf("|                |\n");
        printf("|               0 0\n");
        printf("|                |\n");
        printf("|               /|\\\n");
        printf("|                | \n");
        printf("|               / \\\n");
        printf("|                 \n");
        printf("|                 \n");
        printf("|__________________\n \n");
        printf("%s\n",guessArray);
        printf("Letters you have already guessed: %s\n",guessLetters);
        break;
    case 8:
        printf(" __________________\n");
        printf("|                |\n");
        printf("|               X X\n");
        printf("|                |\n");
        printf("|               /|\\\n");
        printf("|                | \n");
        printf("|               / \\\n");
        printf("|                 \n");
        printf("|                 \n");
        printf("|__________________\n \n");
        printf("%s\n",guessArray);
        printf("Letters you have already guessed: %s\n",guessLetters);
        break;
    }

    return;
}

void playHangman()
{
    int wordIndex = 0, randIndex;
    char word[MAX_SIZE], buffer[MAX_SIZE], stringArray[WORD_COUNT][MAX_SIZE], guessedLetters[27], playAgain = 'y';
    FILE *wordfile;
    memset(guessedLetters, 0, 27);

    while(playAgain == 'Y' || playAgain == 'y'){
        puts("Okay we are gonna play hangman");
        wordfile = fopen("wordlist.txt","r");
        
        // Reading in word list
        while(fgets(buffer, MAX_SIZE, wordfile))
        {
            strcpy(stringArray[wordIndex],buffer);
            wordIndex++;
        }
        fclose(wordfile);

        // Need to get a random word from the array
        srand(time(NULL));
        randIndex = rand() % wordIndex;
        strcpy(word,stringArray[randIndex]);

        // Setting the initial gamestate to empty
        size_t wordLength = strlen(word);
        char guessArray[MAX_SIZE];
        char guessedLetters[27];
        char letterGuess;
        int tries = 0;
        int guessedIndex = 0;
        strcpy(guessArray,word);
       
        for(int i = 0; i < wordLength - 1; i++)
        {
            guessArray[i] = '_';
        }

        while(strcmp(word,guessArray) != 0 && tries != 8)
        {
            printScreen(tries, guessArray, guessedLetters);
            printf("Guess a letter between a - z: ");
            scanf(" %c",&letterGuess);
            validateInput(&letterGuess);
            while(checkGuessed(guessedLetters, &guessedIndex, letterGuess) == -1)
            {
                printf("You already guessed %c, you can do better mia!\n", letterGuess);
                printf("Guess a letter between a - z: ");
                scanf(" %c",&letterGuess);
                validateInput(&letterGuess);
            }
            if(checkWord(word, letterGuess, guessedLetters, &guessedIndex, guessArray) == -1) tries++;
        }
        if(tries == 8)
        {
            printScreen(tries,guessArray,guessedLetters);
            printf("You lost! \n");
            printf("The word was %s",word);
            printf("Do you want to play again?\n");
            printf("y for yes, n for no: ");
            scanf(" %c",&playAgain);
            while(playAgain != 'y' && playAgain !=  'Y' && playAgain !=  'n' && playAgain != 'N')
            {
                printf("Do you want to play again?\n");
                printf("y for yes, n for no: ");
                scanf(" %c",&playAgain);
            }
        }
        else
        {
            printScreen(tries, guessArray, guessedLetters);
            printf("You won! \n");
            printf("The word was %s",word);
            printf("Do you want to play again?\n");
            printf("y for yes, n for no: ");
            scanf(" %c",&playAgain);
            while(playAgain != 'y' && playAgain !=  'Y' && playAgain !=  'n' && playAgain != 'N')
            {
                printf("Do you want to play again?\n");
                printf("y for yes, n for no: ");
                scanf(" %c",&playAgain);
            }
        }
        if(playAgain == 'y' || playAgain == 'Y')
        {
            guessedIndex = 0;
            wordIndex = 0;
            memset(guessedLetters, 0, 27);
        }
        else if (playAgain ==  'n' || playAgain == 'N'){
            printf("Okay :( \nThank you for playing, have fun today!\n");
        }
    }
    return;
}