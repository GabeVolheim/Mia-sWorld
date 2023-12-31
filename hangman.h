#ifndef gameStuff_H
#define gameStuff_H_

int checkWord(char *, char , char *, int* ,char *);
int checkGuessed(char *, int *, char);
int inAlphabet(char);
void validateInput(char*);
void printScreen(int, char*, char*);
void playHangman();

#endif // gameStuff_H_