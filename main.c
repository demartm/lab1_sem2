#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>

#define array_size 256
/*
   Формулировка задачи:
   Дана непустая последовательность слов из строчных букв; между соседними словами – запятая, за последним словом – точка.
   Напечатать все слова из списка, содержащие ровно две буквы d
*/




int find_suitable_words(char* words_stricted, int* list) {

    if (words_stricted && list) {

        bool Tab[256] = { 0 };
        char delimeters[] = " ,.";

        size_t len = strlen(delimeters);
        for (int i = 0; i < len; i++) {
            Tab[(unsigned char)delimeters[i]] = true;
        }

        len = strlen(words_stricted);
        int word_begin = 0;
        int d_counter = 0;
        int word_counter = 0;
        for (int i = 0;i < len; i++) {

            if (Tab[(unsigned char)words_stricted[i]]) {

                if (d_counter == 2) {

                    list[word_counter] = word_begin;
                    list[word_counter + 1] = i - word_begin;
                    word_counter += 2;
                }

                word_begin = i + 1;
                d_counter = 0;
                if (words_stricted[i] == '.') {
                    i = len;
                }

            }
            else {
                if (words_stricted[i] == 'd') {
                    d_counter++;
                }
            if (i == (len - 1) && d_counter == 2) {
                    list[word_counter] = word_begin;
                    list[word_counter + 1] = i - word_begin + 1;
                    word_counter += 2;
                }


            }
        }
        return word_counter;
    }
    else {
        return -1;

    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    //char words[] = "hello,worldd,dd.";  //Вывод: worldd  dd
    //char words[] = "hello,world,char."; //Вывод: No souitable words found
    //char words[] = "add,odd,doubled.";  //Вывод: add odd doubled
    //char words[] = "      o     dds,,,,     ddd,          nothingdd, fxdeed ,      . doubled.";   //Вывод: dds nothingdd fxdeed
    //char words[] = "div ide,od,,,,,,,,,,d,,,,,,,,.doubled.";// Вывод: No souitable words found

    //char words[] = "rudder,headed,faded.";//Вывод: rudder  headed  faded
    //char words[] = "coded,banded,landed.";//Вывод: coded  banded  landed
    //char words[] = "ended,mended,tended.";//Вывод: ended  mended  tended
    //char words[] = "blended,waded,sided.";//Вывод: blended  waded  sided

    //char words[] = "blended,waded,sided";//Вывод: blended  waded  sided
    //char words[] = "blended,waded.sided";//Вывод: blended  waded

    //char words[] = "I didn't add commas or dots hered";//Вывод: didn't  add
    //char words[] = "I didn't add commas or dots heredd";//Вывод: didn't  add  heredd

    //char words[] = "   hello   ,,,   add   ,,,   world   ,,,   odd   ,,,   dd   ,,,   ddd   .";//Вывод: add  odd  dd

    //char words[] = ".coded,banded,landed.";//Вывод: No souitable words found

    //char words[] = "ended,привет,tended.";//Вывод: ended  tended
    //char words[] = "ended,приветdd,tended.";//Вывод: ended  приветdd  tended

    // char words[] = "     add,odd. doubled.";// вывод: add odd

    //char words[] = "d-d, d_____d, d,,,,,,d";//Вывод: d-d  d_____d
    //char words[] = "coded,banded     ,landed.";//Вывод: coded  banded  landed

    char words[] = "      ,    coded     ,     banded   .          ,      landed.";//Вывод: coded  banded



    int list[array_size] = { 0 };

  //int *ptr;

  int word_counter = find_suitable_words(words, list);
  //int word_counter = find_suitable_words(NULL, list); //Вывод: Invalid pointer
  //int word_counter = find_suitable_words(words, NULL);//Вывод: Invalid pointer
  //int word_counter = find_suitable_words(NULL,NULL);  //Вывод: Invalid pointer

    if (word_counter == -1) {
        printf("Invalid pointer");
        return 0;
    }
    else {
        if (word_counter == 0) {
            printf("No souitable words found");
            return 0;
        }
    }
    for (int i = 0; i < word_counter; i += 2) {

        printf("%.*s  ", list[i+1], words + list[i]);

    }

    return 0;
}

