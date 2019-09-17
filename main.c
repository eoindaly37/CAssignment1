//Eoin Daly R00161654
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "word_game.h"

int main()
{
    char current_letters[] = {'b', 'e', 'l', 'l'};
    char target_letters[] = {'c', 'o', 'a', 't'};

    int position_of_cursor = 1;
    const int NUMBER_OF_LETTERS = sizeof(current_letters);
    int max_goes = (2*NUMBER_OF_LETTERS)-1;
    char guesses[max_goes][NUMBER_OF_LETTERS];

    bool game_finished = false;
    int number_of_letter_changes = 0;
    start_game(current_letters,target_letters,NUMBER_OF_LETTERS, max_goes, guesses);
    return 0;
}
void start_game(char* pCurrent, char* pTarget, const int size_of_word, int max_goes, char* guesses)
{
    int position_of_cursor = 0;
    bool game_finished = false;
    int number_of_letter_changes = 0;


    display_game_state(pCurrent, pTarget, size_of_word,
                       position_of_cursor, number_of_letter_changes);

    bool state = true;
    bool check = false;
    while(state==true){
        printf("\nEnter a command: ");
        char input = get_user_char();
        if(input=='>'){
            move_cursor_right(&position_of_cursor, size_of_word);
        }
        else if(input=='<'){
            move_cursor_left(&position_of_cursor);
        }
        else if('a'<=input<='z'){
            change_letter(pCurrent, position_of_cursor, input, size_of_word);
            guesses[number_of_letter_changes] = *pCurrent;
            number_of_letter_changes++;
            check = compare_letters(pCurrent, pTarget, size_of_word);
      }
    display_game_state(pCurrent, pTarget, size_of_word,
                       position_of_cursor, number_of_letter_changes);
        if(check==true){
            printf("\nSuccess!! Strings used\n");
            int i = 0;
            while(i<number_of_letter_changes){
                printf("%c", *guesses);
                guesses++;
                i++;
            }
            state = false;
        }
        else if(number_of_letter_changes>max_goes){
            printf("\nFailure - Max number of goes exceeded\n");
            state = false;
        }

    }


}
