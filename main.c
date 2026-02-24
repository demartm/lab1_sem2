#include <stdio.h>

#define array_size 256
/*
   Формулировка задачи:
   Дана непустая последовательность слов из строчных букв; между соседними словами – запятая, за последним словом – точка.
   Напечатать все слова из списка, содержащие ровно две буквы d
*/
int main()
{
    //char words[] = "hello,worldd,dd.";  //Вывод: worldd  dd
    //char words[] = "hello,world,char."; //Вывод:
   // char words[] = "add,odd,doubled.";  //Вывод: add odd doubled
    char words[] = "odds,ddd,nothing.";   //Вывод: odds

    int begin[array_size] = { 0 };
    int size[array_size] = { 0 };

    int word_begin = 0;
    int d_counter = 0;
    int word_counter = 0;

    for (int i = 0; words[i] != '\0'; i++) {

        if (words[i] == ',' || (words[i] == '.' && words[i + 1] == '\0')) {

            if (d_counter == 2) {

                /*printf("%.*s", (i - word_begin), words + word_begin);
                printf("\n\n");*/

                begin[word_counter] = word_begin;
                size[word_counter] = i - word_begin;
                word_counter++;
            }

            word_begin = i + 1;
            d_counter = 0;

        }
        else {
            if (words[i] == 'd') {
                d_counter++;
            }
        }
    }

    for (int i = 0; i < word_counter; i++) {

        printf("%.*s", size[i], words + begin[i]);
        printf("\n\n");
    }

    return 0;
}
