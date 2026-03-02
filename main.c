#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define array_size 256
    /*
       Формулировка задачи:
       Дана непустая последовательность слов из строчных букв; между соседними словами – запятая, за последним словом – точка.
       Напечатать все слова из списка, содержащие ровно две буквы d
    */

bool fill_tab(char *delimeters, bool *Tab) {
    if (delimeters && Tab) {

        size_t len = strlen(delimeters);

        for (int i = 0; i < len; i++) {
            Tab[delimeters[i]] = true;
        }
        return 1;
    }
    else {
        return 0;
    }
}

bool standartize_string(char *words, char *words_stricted, bool *Tab) {
    if (words && words_stricted && Tab) {


    int index = 0;
    int temp = 0;
    bool need_comma = false;

    size_t len = strlen(words);


        for (int i = 0; i < len; i++) {

            if (!Tab[words[i]]) {

                words_stricted[index] = words[i];
                index++;

            }
            else {
                if (words[i] == ',') {
                    if (index > 0) {
                        need_comma = true;
                    }

                    temp = index;
                }
                else {
                    if (!need_comma && index > 0) {
                        words_stricted[index] = words[i];
                        index++;

                    }
                }


                if (words[i] == '.') {
                    words_stricted[index] = words[i];
                    index++;

                    i = len;
                }
                else {


                    if (!Tab[words[i + 1]] && index > 0 && need_comma) {
                        index = temp;
                        words_stricted[index] = ',';
                        index++;
                        need_comma = false;
                    }
                }
            }


        }

        words_stricted[index] = '.';
        words_stricted[index+1] = '\0';
        return 1;
    }
    return 0;
}

int find_suitable_words(char *words_stricted, bool *Tab ,int *begin, int *size) {

    if (words_stricted && Tab && begin && size) {
        size_t len = strlen(words_stricted);
        int word_begin = 0;
        int d_counter = 0;
        int word_counter = 0;
        for (int i = 0; i < len; i++) {

            if (Tab[words_stricted[i]]/*words_stricted[i] == ',' || words_stricted[i] == '.'*/) {

                if (d_counter == 2) {

                    begin[word_counter] = word_begin;
                    size[word_counter] = i - word_begin;
                    word_counter++;
                }

                word_begin = i + 1;
                d_counter = 0;
                if (words_stricted[i] == '.') {////
                    i = len;
                }
            }
            else {
                if (words_stricted[i] == 'd'/* || words_stricted[i] == 'D'*/) {
                    d_counter++;
                }
            }
        }
        return word_counter;
    }
    else {
        return 0;

    }
}

int main()
{
    //unsigned char words[] = "hello,worldd,dd.";  //Вывод: worldd  dd
    //unsigned char words[] = "hello,world,char."; //Вывод:Invalid pointer or zero words found
   // unsigned char words[] = "add,odd,doubled.";  //Вывод: add odd doubled
    //unsigned char words[] = "      o     dds,,,,     ddd,          nothingdd, need,          .     doubled.";   //Вывод: "o     dds"    "nothingdd"
    //unsigned char words[] = "div ide,od,,,,,,,,,,d,,,,,,,,.doubled.";// Вывод: div ide
    unsigned char words[] = "      add,odd , doubled    ";// вывод: add odd doubled
    unsigned char words_stricted[array_size] = { 0 };

    int begin[array_size] = { 0 };
    int size[array_size] = { 0 };

    unsigned char delimeters[] = " ,.";

    bool Tab[256] = { 0 };




    if (!fill_tab(delimeters,Tab)) {
        printf("Invalid pointer");
        return 0;
    }
    if (!standartize_string(words, words_stricted, Tab)) {
        printf("Invalid pointer");
        return 0;
    }
   // printf("%s", words_stricted);
    Tab[' '] = 0;
    int word_counter = find_suitable_words(words_stricted, Tab, begin, size);
    if (!word_counter) {
        printf("Invalid pointer or zero words found");
        return 0;
    }
    for (int i = 0; i < word_counter; i++) {

        printf("%.*s", size[i], words_stricted + begin[i]);
        printf("\n\n");
    }

    return 0;
}
