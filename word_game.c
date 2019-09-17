//Eoin Daly R00161654
#include <stdio.h>
#include <stdbool.h>
void display_game_state(char* pCurrent_letters, char* pTarget_letters, const int NUMBER_OF_LETTERS,
                        const int cursor_position, const int number_of_letter_changes)
{
    int k=0;
    printf("\nTarget: ");
    while(k<NUMBER_OF_LETTERS){
        printf("%c", *pTarget_letters);
        pTarget_letters++;
        k++;
    }
    printf("\n------------\n");
    int i=0;
    while(i<NUMBER_OF_LETTERS){
        printf("%c", *pCurrent_letters);
        pCurrent_letters++;
        i++;
    }
    const char DASH = '-';
    const char SPACE = ' ';

    printf("\n");
    int j=0;
    while(j<cursor_position){
        printf("%c", SPACE);
        j++;
    }
    printf("%c", DASH);
    printf("\nChanges: %d", number_of_letter_changes);
}

void move_cursor_right(int* pPosition_of_cursor, const int max)
{
    if(*pPosition_of_cursor<max-1){
        (*pPosition_of_cursor)++;
    }
    else{
        printf("Cant go right");
    }
}

void move_cursor_left(int* pPosition_of_cursor)
{
    if(*pPosition_of_cursor>0){
        (*pPosition_of_cursor)--;
    }
    else{
        printf("Cant go left");
    }
}

void change_letter(char* pLetters, int position, char new_letter, int max)
{

    if(position>=max){
        printf("\nGreater than word size");
    }
    else{
        char* pLocation_change = pLetters + position;
        *pLocation_change = new_letter;
        printf("\nInserted - %c\n", *pLocation_change);
    }

}

bool compare_letters(char* pStart_letters, char* pTarget_letters, int size_of_array)
{
    printf("\nCompare letters\n");
    int same = 0;
    int i=0;
    while(i<size_of_array){
        printf("\n%c%c", *pStart_letters, *pTarget_letters);
        if(*pStart_letters==*pTarget_letters){
            same++;
        }
        pStart_letters++;
        pTarget_letters++;
        i++;

    }
    printf("\n%d are the same\n", same);
    if(same==size_of_array){
        printf("\nIDENTICAL\n");
        return true;
    }
    else{
        return false;
    }
}
char get_user_char() {
    //1. We create the output variable with the value the user has input by keyboard
    char res = getchar();

    //2. We discard any extra character the user has input by keyboard
    bool finish = false;
    char dummy_char = ' ';

    while (finish == false) {
        dummy_char = getchar();
        if (dummy_char == '\n')
            finish = true;
    }

    //3. We return the output variable
    return res;
}










