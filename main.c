#include <stdio.h>
#include <stdbool.h>

#define word_size 11

/*
Формулировка задачи:

Дана непустая последовательность слов из строчных букв; между соседними словами – запятая, за последним словом – точка.
Напечатать все слова из списка, содержащие ровно две буквы d
*/

int main()
{
        //char W1[word_size] = "qwertyuiop";
        //char W2[word_size] = "uiopqwerty"; //Вывод: annogram


    //char W1[word_size] = "noannogram";
        //char W2[word_size] = "annogram"; //Вывод: not an annogram

        char W1[word_size] = "randomtext";
        char W2[word_size] = "ardnmoettx"; //Вывод: annogram

        int exist[127] = { 0 };
        bool annogram = true;

        int length = 0;



        for (length = 0; W1[length] != '\0'; length++) {
                exist[(int)(W1[length] - 'a')] += 1;
        }
        int i = 0;

        for (i = 0; W2[i] != '\0' && annogram; i++) {

                if (!exist[(int)(W2[i] - 'a')]) {
                        annogram = false;
                }
                else {
                        exist[(int)(W2[i] - 'a')] -= 1;
                }
        }

        if (annogram && length == i) {
                printf("annogram");
        }
        else {
                printf("not an annogram");
        }
        return 0;
}
