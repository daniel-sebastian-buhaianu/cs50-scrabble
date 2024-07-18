#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STRING_LENGTH 1000

bool isUpperLetter(char);
bool isLowerLetter(char);
bool isLetter(char);
int calculateScore(char*);
void playScrabble(char*, char*);
void getPlayerInput(int, char*);

int main(void)
{
  char player1[MAX_STRING_LENGTH];
  char player2[MAX_STRING_LENGTH];

  getPlayerInput(1, player1);
  getPlayerInput(2, player2);

  playScrabble(player1, player2);

  return 0;
}

bool isUpperLetter(char c)
{
  return c >= 'A' && c <= 'Z';
}

bool isLowerLetter(char c)
{
  return c >= 'a' && c <= 'z';
}

bool isLetter(char c)
{
  return isUpperLetter(c) || isLowerLetter(c);
}

int calculateScore(char* str)
{
  const int LETTER_SCORES[] = {
    1, // A
    3, // B
    3, // C
    2, // D
    1, // E
    4, // F
    2, // G
    4, // H
    1, // I
    8, // J
    5, // K
    1, // L
    3, // M
    1, // N
    1, // O
    3, // P
    10, // Q
    1, // R
    1, // S
    1, // T
    1, // U
    4, // V
    4, // W
    8, // X
    4, // Y
    10 // Z
  };
  int score = 0;

  for(int i = 0, n = strlen(str); i < n; i++)
  {
    if (isLetter(str[i]))
    {
      int index = isUpperLetter(str[i]) ? str[i] - 'A' : str[i] - 'a';
      score += LETTER_SCORES[index];
    }
  }
  
  return score;
}

void playScrabble(char* player1, char* player2)
{
  int score1 = calculateScore(player1);
  int score2 = calculateScore(player2);

  if (score1 == score2)
  {
    printf("Tie!");
  }
  else if (score1 > score2)
  {
    printf("Player 1 wins!");
  }
  else
  {
    printf("Player 2 wins!");
  }

  printf("\n");
}

void getPlayerInput(int playerID, char* playerInput)
{
  printf("Player %d: ", playerID);

  if (fgets(playerInput, MAX_STRING_LENGTH, stdin) != NULL)
  {
    // Remove the newline character if it's present
    size_t len = strlen(playerInput);
    if (len > 0 && playerInput[len-1] == '\n')
    {
      playerInput[len-1] = '\0';
    }
  }
  else
  {
    printf("Error reading player %d input\n", playerID);
    exit(EXIT_FAILURE);
  }
}
