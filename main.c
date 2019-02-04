#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
void main(void)
{
    setlocale(LC_ALL, "rus");
    printf("Hello.\nThis is my interpretation of the \"Bulls and Cows\" game.\n\n");
    printf("The rules are simple: the code will generate random four-digit number.\n\nThe digits in it will not repeat, of course.\n\n");
    printf("You have 10 tries to guess this number.\n\nIf you have guessed the digit but it stands not on its place, this digit is a \"cow\".\n\n");
    printf("If you have guessed both digit and its place, this digit is a - \"bull\".");
    printf("\n\nFor example, if you had to guess the \"7250\", but you typed \"5230\", \"2\" will be \"bull\", and \"5\" will be \"cow\".");
    printf("\n\nThe information about your current try will be given in \"nB, mC\", where B and C are the amount of bulls and cows in the number.");
    printf("\n\n\nLet's go!\n\n\n");
    srand(time(NULL));
    int ts1 = 0 + rand() %9;
    int ts2 = 0 + rand() %9;
    while(ts2==ts1)
    {
        ts2 = 0 + rand() %9;
    }
    int ts3 = 0 + rand() %9;
    while(ts3==ts2||ts3==ts1)
    {
        ts3 = 0 + rand() %9;
    }
    int ts4 = 0 + rand() %9;
    while(ts4==ts3||ts4==ts2||ts4==ts1)
    {
        ts4 = 0 + rand() %9;
    }
    int chislo, i;
    int bik=0, korova=0, lose = 0;
    int ch1, ch2, ch3, ch4;
    for(i=0;i<10;i++)
    {
    bik = 0;
    korova = 0;
    printf("\nEnter four-digit number: ");
    while(scanf("%d", &chislo)==0)
    {
        puts("Please enter ONLY digits!");
        fflush(stdin);
    }
    if (chislo<1000||chislo>10000)
    {
        printf("It has to have FOUR digits");
        i = i - 1;
        continue;
    }
    ch4 = chislo%10;
    ch3 = (chislo%100)/10;
    ch2 = (chislo%1000)/100;
    ch1 = (chislo%10000)/1000;
    if (ch1==ch2||ch1==ch3||ch1==ch4||ch2==ch3||ch2==ch4||ch3==ch4)
    {
        printf("The digits in the number must not repeat.");
        i = i - 1;
        continue;
    }
    if(ts1==ch1)
    {
        bik = bik + 1;
    }
    if(ts1==ch2||ts1==ch3||ts1==ch4)
    {
        korova = korova + 1;
    }
    if(ts2==ch2)
    {
        bik = bik + 1;
    }
    if(ts2==ch1||ts2==ch3||ts2==ch4)
    {
        korova = korova + 1;
    }
    if(ts3==ch3)
    {
        bik = bik + 1;
    }
    if(ts3==ch1||ts3==ch2||ts3==ch4)
    {
        korova = korova + 1;
    }
    if(ts4==ch4)
    {
        bik = bik + 1;
    }
    if(ts4==ch1||ts4==ch3||ts4==ch2)
    {
        korova = korova + 1;
    }
    printf("%dB, %dC",bik,korova);
    if(bik==4)
    {printf("\nGreat job!");
    lose = lose + 1;
    printf("\nYou've just guessed the number!");
    break;}
    }
    if(lose==0)
    {printf("\nSorry, you were wrong\n");
    printf("\nThe correct answer was: %d%d%d%d\n", ts1,ts2,ts3,ts4);}
    }
