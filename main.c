#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
//#include <Windows.h>
#include <wchar.h>


/*
Формулировка задачи:
2. Уплотнить строку S1, удалив символы, встречающиеся в строке S2.
*/


bool delete_matches(wchar_t* S1, wchar_t* S2) {

    if (S1 && S2) {

        bool Tab[65536] = { 0 };

        for (int i = 0; S2[i] != '\0'; i++) {
            Tab[(unsigned int)S2[i]] = 1;
        }

        int old = 0;

        for (int i = 0; S1[i] != '\0'; i++) {
            if (!Tab[(unsigned int)S1[i]]) {
                S1[old] = S1[i];
                old++;
            }

        }
        S1[old] = '\0';
        return 1;
    }
    else {
        return 0;
    }
}


int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    //SetConsoleOutputCP(65001);  // UTF-8
    //SetConsoleCP(65001);

    //wchar_t S1[] = L"nothingspc"; //Вывод: ningspc
    //wchar_t S2[] = L"oth";

    //wchar_t S1[] = L"somerandom"; //Вывод: smandm
    //wchar_t S2[] = L"qwertyuiop";

    //wchar_t S1[] = L"randomtext"; //Вывод: random
    //wchar_t S2[] = L"text";


    //wchar_t S1[] = L"aab";// Латинские a-a-b
    //wchar_t S2[] = L"а";// Кириллическая а
    //Вывод: aab

    //wchar_t S1[] = L"ааb";// Кириллические а-а + латинская b
    //wchar_t S2[] = L"a";// Латинская a
    //Вывод: ааb

    //wchar_t S1[] = L"аab";// Кириллическая а + латинская a + латинская b
    //wchar_t S2[] = L"a";// Латинская a
    //Вывод: ab



    //wchar_t S1[] = L"google";// Все латинские
    //wchar_t S2[] = L"о";// Кириллическая о
    //Вывод: google

    //wchar_t S1[] = L"смеshaнnый теkst";
    //wchar_t S2[] = L"йnыsk";
    //Вывод: смеhaн теt

    //wchar_t S1[] = L"dataданные";
    //wchar_t S2[] = L"atд";
    //Вывод: dанные

    //wchar_t S1[] = L"hello, world!!@#$%^&*(";
    //wchar_t S2[] = L",!$%^";
    //Вывод: hello world@#&*(

    //wchar_t S1[] = L"hello, world!!@#$%^&*(";
    //wchar_t S2[] = L"elow,!$%^";
    //Вывод: h rd@#&*(

    //wchar_t S1[] = L"привет мир!!@#$%^&*(";
    //wchar_t S2[] = L",!$%^";
    //Вывод: привет мир@#&*(

    //wchar_t S1[] = L"привет мир!!@#$%^&*(";
    //wchar_t S2[] = L"при,!$%^";
    //Вывод: вет м@#&*(

    wchar_t S1[] = L"Проверка"; //Вывод: Провер
    wchar_t S2[] = L"ка";
    //bool Tab[256] = { 0 };

    wprintf(L"%ls\n", S1);

    /*   if (!fill_Tab(S2, Tab)) {
           printf("Invalid pointer");
           return 0;
       }*/
    if (!delete_matches(S1, S2)) {
        printf("Invalid pointer");
        return 0;
    }

    wprintf(L"%ls\n", S1);
}
