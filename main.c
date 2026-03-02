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

//bool fill_tab(char* delimeters, bool* Tab) {
//    if (delimeters && Tab) {
//
//        size_t len = strlen(delimeters);
//        for (int i = 0; i < len; i++) {
//            Tab[(unsigned char)delimeters[i]] = true;
//        }
//        return 1;
//    }
//    else {
//
//        return 0;
//    }
//}

bool standartize_string(char* words, char* words_stricted) {
    if (words && words_stricted) {

        bool Tab[256] = { 0 };
        char delimeters[] = " ,.";

        size_t len = strlen(delimeters);
        for (int i = 0; i < len; i++) {
            Tab[(unsigned char)delimeters[i]] = true;
        }

        int temp = 0;
        bool need_comma = false;
        int index = 0;

        len = strlen(words);

        for (int i = 0; i < len; i++) {

            if (!Tab[(unsigned char)words[i]]) {

                words_stricted[index] = words[i];
                index++;
            }
            else {
                if (words[i] == '.') {//????????????
                    //words_stricted[index] = '.';
                    //index++;
                    i = len;
                }
                else {
                    if (!Tab[(unsigned char)words[i + 1]] && index > 0) {
                        words_stricted[index] = ',';
                        index++;
                    }
                }



            }
        }

        words_stricted[index] = '.';
        words_stricted[index + 1] = '\0';
        return 1;
    }
    return 0;
}

int find_suitable_words(char* words_stricted, int* begin, int* size) {

    if (words_stricted && begin && size) {

        bool Tab[256] = { 0 };
        char delimeters[] = ",.";

        size_t len = strlen(delimeters);
        for (int i = 0; i < len; i++) {
            Tab[(unsigned char)delimeters[i]] = true;
        }

        len = strlen(words_stricted);
        int word_begin = 0;
        int d_counter = 0;
        int word_counter = 0;
        for (int i = 0; i < len; i++) {

            if (Tab[(unsigned char)words_stricted[i]]) {

                if (d_counter == 2) {

                    begin[word_counter] = word_begin;
                    size[word_counter] = i - word_begin;
                    word_counter++;
                }

                word_begin = i + 1;
                d_counter = 0;
                /*if (words_stricted[i] == '.') {
                    i = len;
                }*/

            }
            else {
                if (words_stricted[i] == 'd') {
                    d_counter++;
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

    //char words[] = "I didn't add commas or dots here";//Вывод: didn't  add

    //char words[] = "   hello   ,,,   add   ,,,   world   ,,,   odd   ,,,   dd   ,,,   ddd   .";//Вывод: add  odd  dd

    //char words[] = ".coded,banded,landed.";//Вывод: No souitable words found

    //char words[] = "ended,привет,tended.";//Вывод: ended  tended
    //char words[] = "ended,приветdd,tended.";//Вывод: ended  приветdd  tended
    //char words[] = "ended,привет,tended.";//Вывод: ended  tended

    // char words[] = "     add,odd. doubled.";// вывод: add odd

    //char words[] = "d-d, d_____d, d,,,,,,d";//Вывод: d-d  d_____d
    //char words[] = "coded,banded,landed.";//Вывод: coded  banded  landed

    char words[] = "       coded  , banded ,     landed.";//Вывод: coded  banded  landed

     char words_stricted[array_size] = { 0 };

    int begin[array_size] = { 0 };
    int size[array_size] = { 0 };

     //char delimeters[] = " ,.";

    //bool Tab[256] = { 0 };


    /*if (!fill_tab(delimeters, Tab)) {
        printf("Invalid pointer");
        return 0;
    }*/
    if (!standartize_string(words, words_stricted)) {
        printf("Invalid pointer");
        return 0;
    }
    //printf("%s\n", words_stricted);
    //size_t len = strlen(words_stricted);
    int word_counter = find_suitable_words(words_stricted, begin, size);
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
    for (int i = 0; i < word_counter; i++) {

        printf("%.*s  ", size[i], words_stricted + begin[i]);

    }

    return 0;
}
