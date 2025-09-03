#include <stdio.h>
#include <string.h>
#include <ctype.h>

int points[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

int scrabbleGame(char word[]) {
    int score = 0;
    for(int i = 0; i < strlen(word); i++) {
        if(isalpha(word[i])) {
            int idx = toupper(word[i]) - 'A';
            score += points[idx];
        }
    }
    return score;
}

int main() {
    char word1[100];
    char word2[100];
    printf("Player1: ");
    scanf("%99s", word1);
    printf("Player2: ");
    scanf("%99s", word2);

    int score1 = scrabbleGame(word1);
    int score2 = scrabbleGame(word2);

    if(score1 > score2) {
        printf("Player 1 Wins!\n");
    }
    else if (score2 > score1) {
        printf("Player 2 Wins!\n");
    }
    else {
        printf("Tie!\n");
    }

    return 0;
}
