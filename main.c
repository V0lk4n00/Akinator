#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int converter(char question[]) // funkcja konwertujaca "tak" na 1 i "nie" na 0
{
    if(strcmp(question, "tak")==0)
    {
        return 1;
    }

    else if(strcmp(question, "nie")==0)
    {
        return 0;
    }

    else
    {
        printf("\nLiterowka, zacznij od poczatku\n");
        exit(0);
    }
}

int compare(int arr1[], int arr2[], int len) // funkcja porownujaca ze soba 2 tablice, czy sa identyczne
{
    int check=0;

    for(int i=0; i<len; i++)
    {
        if(arr1[i] != arr2[i])
        {
            return 0;
        }
        check++;
    }

    if(check==len) return 1;
}

int first_category(int arr[], int len) // funkcja wybierajaca glowna kategorie
{
    int real_person[3]={1,1,1};             // jakis czlowiek
    int real_thing[3]={0,0,1};              // zwierze
    int maybe_animal[3]={1,0,1};            // moze dwunozne zwierze
    int not_real_person[3]={1,1,0};         // czlowiek z filmu lub ksiazki
    int not_real_thing[3]={0,0,0};          // jakas zmyslona kreatura
    int maybe_not_real_thing[3]={1,0,0};    // jakas dwunozna zmyslona kreatura
                                            // bledne: 0,1,1 i 0,1,0

    if(compare(arr, real_person, len)==1)
    {
        return 1;
    }

    else if(compare(arr, real_thing, len)==1)
    {
        return 2;
    }

    else if(compare(arr, maybe_animal, len)==1)
    {
        return 2;
    }

    else if(compare(arr, not_real_person, len)==1)
    {
        return 3;
    }

    else if(compare(arr, not_real_thing, len)==1)
    {
        return 4;
    }

    else if(compare(arr, maybe_not_real_thing, len)==1)
    {
        return 4;
    }

    else printf("Zastanow sie nastepnym razem nad odpowiedziami\n"); // jesli akinator uzna ze sciemniasz, wylacza sie
    exit(0);
}

int human(int arr[], int len) // funkcja kategorii 'ludzie'
{
    int papaj[9]={1,0,0,0,0,0,0,1,0};         // Jan Pawel 2
    int pooh[9]={0,0,1,0,0,1,1,1,0};          // Xi Jinping
    int walesa[9]={1,0,1,1,0,1,1,0,0};        // Lech Walesa
    int tokarczuk[9]={1,1,0,1,1,1,0,0,0};     // Olga Tokarczuk
    int obama[9]={0,0,1,1,0,1,1,0,0};         // Barack Obama
    int szymborska[9]={1,1,0,1,1,0,0,0,0};    // Wislawa Szymborska
    int sienkiewicz[9]={1,0,0,1,1,0,0,0,1};   // Henryk Sienkiewicz
    int reymont[9]={1,0,0,1,1,0,0,0,0};       // Wladyslaw Reymont
                                              // reszty nie ma wiec program uznaje wyzszosc gracza

    if(compare(arr, papaj, len)==1)
    {
        return 1;
    }

    else if(compare(arr, pooh, len)==1)
    {
        return 2;
    }

    else if(compare(arr, walesa, len)==1)
    {
        return 3;
    }

    else if(compare(arr, tokarczuk, len)==1)
    {
        return 4;
    }

    else if(compare(arr, obama, len)==1)
    {
        return 5;
    }

    else if(compare(arr, szymborska, len)==1)
    {
        return 6;
    }

    else if(compare(arr, sienkiewicz, len)==1)
    {
        return 7;
    }

    else if(compare(arr, reymont, len)==1)
    {
        return 8;
    }

    else printf("Poddaje sie! Udalo ci sie mnie przechytrzyc\n");
    exit(0);
}

int animal(int arr[], int len) // funkcja kategorii 'zwierzeta'
{
    int slon[9]={1,1,0,1,0,1,1,0,0};          // slon
    int nietoperz[9]={0,1,1,1,0,1,0,0,0};     // nietoperz
    int pies[9]={0,0,0,1,0,1,1,1,0};          // pies
    int kot[9]={0,0,0,1,0,1,1,0,0};           // kot
    int delfin[9]={0,1,0,1,1,1,0,0,0};        // delfin
    int orka[9]={1,1,0,1,1,1,0,0,1};          // orka
    int strus[9]={1,1,0,1,0,0,0,0,0};         // strus
    int papuga[9]={0,1,1,1,0,0,0,0,1};        // papuga
                                              // reszty nie ma wiec program uznaje wyzszosc gracza

    if(compare(arr, slon, len)==1)
    {
        return 1;
    }

    else if(compare(arr, nietoperz, len)==1)
    {
        return 2;
    }

    else if(compare(arr, pies, len)==1)
    {
        return 3;
    }

    else if(compare(arr, kot, len)==1)
    {
        return 4;
    }

    else if(compare(arr, delfin, len)==1)
    {
        return 5;
    }

    else if(compare(arr, orka, len)==1)
    {
        return 6;
    }

    else if(compare(arr, strus, len)==1)
    {
        return 7;
    }

    else if(compare(arr, papuga, len)==1)
    {
        return 8;
    }

    else printf("Poddaje sie! Udalo ci sie mnie przechytrzyc\n");
    exit(0);
}

int fake_human(int arr[], int len) // funkcja kategorii 'postacie fikcyjne'
{
    int harry[9]={1,1,1,0,1,0,0,0,0};         // Harry Potter (Harry Potter)
    int hermiona[9]={1,1,1,0,0,0,0,0,0};      // Hermiona Granger (Harry Potter)
    int luke[9]={1,1,1,0,1,1,0,0,1};          // Luke Skywalker (Gwiezdne Wojny)
    int beth[9]={1,0,0,0,0,0,1,0,0};          // Beth Harmon (Gambit Królowej)
    int clarke[9]={0,0,0,1,1,0,0,0,1};        // Isaac Clarke (Dead Space)
    int tesv[9]={0,1,0,1,1,1,0,0,0};          // Dovakhiin (The Elder Scrolls V: Skyrim)
    int thorin[9]={0,0,1,0,1,1,0,1,0};        // Thorin Debowa Tarcza (krasnolud? jaki krasnolud? :X)
    int xDDDDDD[9]={1,1,0,0,0,1,0,0,1};       // Rey Skywalker (Gwiezdne Wojny)
                                              // reszty nie ma wiec program uznaje wyzszosc gracza

    if(compare(arr, harry, len)==1)
    {
        return 1;
    }

    else if(compare(arr, hermiona, len)==1)
    {
        return 2;
    }

    else if(compare(arr, luke, len)==1)
    {
        return 3;
    }

    else if(compare(arr, beth, len)==1)
    {
        return 4;
    }

    else if(compare(arr, clarke, len)==1)
    {
        return 5;
    }

    else if(compare(arr, tesv, len)==1)
    {
        return 6;
    }

    else if(compare(arr, thorin, len)==1)
    {
        return 7;
    }

    else if(compare(arr, xDDDDDD, len)==1)
    {
        return 8;
    }

    else printf("Poddaje sie! Udalo ci sie mnie przechytrzyc\n");
    exit(0);
}

int fake_thing(int arr[], int len) // funkcja kategorii 'kreatury fikcyjne'
{
    int creeper[9]={1,1,0,0,1,1,0,0,0};        // Creeper (Minecraft)
    int pepe[9]={1,1,0,1,1,0,0,0,0};           // Pepe The Frog (Internet)
    int kraken[9]={0,1,0,0,1,1,1,0,0};         // Kraken (ogolnie fantastyka)
    int elf[9]={0,0,0,0,1,0,0,1,0};            // Elf (ogolnie fantastyka)
    int spongebob[9]={1,0,1,0,1,0,1,1,1};      // Spongebob (Spongebob Kanciastoporty)
    int amogus[9]={1,0,0,1,1,0,0,1,0};         // Amogus (Among Us)
    int shrek[9]={0,1,1,0,1,1,0,0,0};          // Shrek (Shrek)
    int krasnolud[9]={1,0,1,0,1,0,0,1,0};      // Krasnolud (ogolnie fantastyka)
                                               // reszty nie ma wiec program uznaje wyzszosc gracza

    if(compare(arr, creeper, len)==1)
    {
        return 1;
    }

    else if(compare(arr, pepe, len)==1)
    {
        return 2;
    }

    else if(compare(arr, kraken, len)==1)
    {
        return 3;
    }

    else if(compare(arr, elf, len)==1)
    {
        return 4;
    }

    else if(compare(arr, spongebob, len)==1)
    {
        return 5;
    }

    else if(compare(arr, amogus, len)==1)
    {
        return 6;
    }

    else if(compare(arr, shrek, len)==1)
    {
        return 7;
    }

    else if(compare(arr, krasnolud, len)==1)
    {
        return 8;
    }

    else printf("Poddaje sie! Udalo ci sie mnie przechytrzyc\n");
    exit(0);
}

struct info // struktura zapisujaca podstawowe informacje o grze
{
    char nick[30];
    char answer[30];
    double gametime;
} gracz;


int main()
{
    char question[3]; // pytanie tak lub nie

    int main_memory[3]; // pamiec pierwszej kategorii pytan
    int len1=sizeof(main_memory)/sizeof(main_memory[0]); // rozmiar pamieci

    int secondary_memory[9]; // pamiec drugiej kategorii pytan
    int len2=sizeof(secondary_memory)/sizeof(secondary_memory[0]); // rozmiar pamieci

    int cat1=0, cat2=0; // zmienne do trzymania koncowego kodu obu kategorii

    printf("Witaj, jestem Akinator! Chcesz sie ze mna zmierzyc?\n");
    scanf("%s", &question);

    if(strcmp(question,"tak")==0) // program sprawdza czy chcemy grac
    {
        printf("\nWpisz swoj nick\n");
        scanf("%s", &(gracz.nick)); // wpisanie nicku do struktury

        printf("\n\nSwietnie, teraz pomysl o jakiejs postaci. Gotowy? No to jedziemy!\n\n");

        double time_spent = 0.0; // start timera gry
        clock_t begin = clock();

        printf("Pytanie pierwsze: Czy twoja postac chodzi na 2 nogach?\n");
        scanf("%s", &question);
        main_memory[0]=converter(question); //  uruchomienie funkcji i wpisanie zwracanej wartosci do komorki w tablicy

        printf("\n\nPytanie drugie: Czy twoja postac jest czlowiekiem?\n");
        scanf("%s", &question);
        main_memory[1]=converter(question);

        printf("\n\nPytanie trzecie: Czy twoja postac istnieje naprawde {nie jest fikcyjna}?\n");
        scanf("%s", &question);
        main_memory[2]=converter(question);

        cat1=first_category(main_memory, len1); // utworzenie kodu pierwszej kategorii

        printf("\nOkej...to juz mi sporo mowi, ale potrzebuje jeszcze paru odpowiedzi\n\n");

        if(cat1==1) // kategoria: postacie prawdziwe
        {
            printf("\nPytanie czwarte: czy twoja postac jest z Polski?\n");
            scanf("%s", &question);
            secondary_memory[0]=converter(question);

            printf("\n\nPytanie piate: czy twoja postac jest kobieta?\n");
            scanf("%s", &question);
            secondary_memory[1]=converter(question);

            printf("\n\nPytanie szoste: czy twoja postac jest politykiem?\n");
            scanf("%s", &question);
            secondary_memory[2]=converter(question);

            printf("\n\nPytanie siodme: czy twoja postac otrzymala nagrode nobla?\n");
            scanf("%s", &question);
            secondary_memory[3]=converter(question);

            printf("\n\nPytanie osme: czy twoja postac jest pisarzem?\n");
            scanf("%s", &question);
            secondary_memory[4]=converter(question);

            printf("\n\nPytanie dziewiate: czy twoja postac zyje?\n");
            scanf("%s", &question);
            secondary_memory[5]=converter(question);

            printf("\n\nPytanie dziesiate: czy ta postac jest prezydentem?\n");
            scanf("%s", &question);
            secondary_memory[6]=converter(question);

            printf("\n\nPytanie jedenaste: czy twoja postac jest zwiazana z kolorem zoltym?\n");
            scanf("%s", &question);
            secondary_memory[7]=converter(question);

            printf("\n\nPytanie dwunaste: czy twoja postac napisala 'Trylogie'?\n");
            scanf("%s", &question);
            secondary_memory[8]=converter(question);

            cat2=human(secondary_memory, len2); // utworzenie kodu drugiej kategorii

            if(cat2==1) // porownanie koncowego kodu i generowanie odpowiedzi + zapis do struktury
            {
                printf("Twoja postac to Jan Pawel 2!\n");
                strcpy(gracz.answer, "Jan Pawel 2");
            }

            else if(cat2==2)
            {
                printf("Twoja postac to Xi Jinping!\n");
                strcpy(gracz.answer, "Xi Jinping");
            }

            else if(cat2==3)
            {
                printf("Twoja postac to Lech Walesa!\n");
                strcpy(gracz.answer, "Lech Walesa");
            }

            else if(cat2==4)
            {
                printf("Twoja postac to Olga Tokarczuk!\n");
                strcpy(gracz.answer, "Olga Tokarczuk");
            }

            else if(cat2==5)
            {
                printf("Twoja postac to Barack Obama!\n");
                strcpy(gracz.answer, "Barack Obama");
            }

            else if(cat2==6)
            {
                printf("Twoja postac to Wislawa Szymborska!\n");
                strcpy(gracz.answer, "Wislawa Szymborska");
            }

            else if(cat2==7)
            {
                printf("Twoja postac to Henryk Sienkiewicz!\n");
                strcpy(gracz.answer, "Henryk Sienkiewicz");
            }

            else if(cat2==8)
            {
                printf("Twoja postac to Wladyslaw Reymont!\n");
                strcpy(gracz.answer, "Wladyslaw Reymont");
            }
        }

        else if(cat1==2) // kategoria: zwierzeta
        {
            printf("\nPytanie czwarte: czy twoja postac jest duza?\n");
            scanf("%s", &question);
            secondary_memory[0]=converter(question);

            printf("\n\nPytanie piate: czy twoja postac zyje w dziczy?\n");
            scanf("%s", &question);
            secondary_memory[1]=converter(question);

            printf("\n\nPytanie szoste: czy twoja postac umie latac?\n");
            scanf("%s", &question);
            secondary_memory[2]=converter(question);

            printf("\n\nPytanie siodme: czy twoja postac potrafi szybko sie przemieszczac?\n");
            scanf("%s", &question);
            secondary_memory[3]=converter(question);

            printf("\n\nPytanie osme: czy twoja postac zyje w morzu?\n");
            scanf("%s", &question);
            secondary_memory[4]=converter(question);

            printf("\n\nPytanie dziewiate: czy twoja postac jest ssakiem?\n");
            scanf("%s", &question);
            secondary_memory[5]=converter(question);

            printf("\n\nPytanie dziesiate: czy twoja postac stoi na 4 lapach?\n");
            scanf("%s", &question);
            secondary_memory[6]=converter(question);

            printf("\n\nPytanie jedenaste: czy twoja postac jest najlepszym przyjacielem czlowieka?\n");
            scanf("%s", &question);
            secondary_memory[7]=converter(question);

            printf("\n\nPytanie dwunaste: czy twoja postac ma charakterystyczne barwy?\n");
            scanf("%s", &question);
            secondary_memory[8]=converter(question);

            cat2=animal(secondary_memory, len2);

            if(cat2==1)
            {
                printf("Twoja postac to Slon!\n");
                strcpy(gracz.answer, "Slon");
            }

            else if(cat2==2)
            {
                printf("Twoja postac to Nietoperz!\n");
                strcpy(gracz.answer, "Nietoperz");
            }

            else if(cat2==3)
            {
                printf("Twoja postac to Pies!\n");
                strcpy(gracz.answer, "Pies");
            }

            else if(cat2==4)
            {
                printf("Twoja postac to Kot!\n");
                strcpy(gracz.answer, "Kot");
            }

            else if(cat2==5)
            {
                printf("Twoja postac to Delfin!\n");
                strcpy(gracz.answer, "Delfin");
            }

            else if(cat2==6)
            {
                printf("Twoja postac to Orka!\n");
                strcpy(gracz.answer, "Orka");
            }

            else if(cat2==7)
            {
                printf("Twoja postac to Strus!\n");
                strcpy(gracz.answer, "Strus");
            }

            else if(cat2==8)
            {
                printf("Twoja postac to Papuga!\n");
                strcpy(gracz.answer, "Papuga");
            }
        }

        else if(cat1==3) // kategoria: postacie fikcyjne
        {
            printf("\nPytanie czwarte: czy twoja postac jest mloda?\n");
            scanf("%s", &question);
            secondary_memory[0]=converter(question);

            printf("\n\nPytanie piate: czy twoja postac ma magiczne moce?\n");
            scanf("%s", &question);
            secondary_memory[1]=converter(question);

            printf("\n\nPytanie szoste: czy twoja postac pochodzi z ksiazki?\n");
            scanf("%s", &question);
            secondary_memory[2]=converter(question);

            printf("\n\nPytanie siodme: czy twoja postac pochodzi z gry?\n");
            scanf("%s", &question);
            secondary_memory[3]=converter(question);

            printf("\n\nPytanie osme: czy twoja postac jest mezczyzna?\n");
            scanf("%s", &question);
            secondary_memory[4]=converter(question);

            printf("\n\nPytanie dziewiate: czy twoja postac walczy mieczem?\n");
            scanf("%s", &question);
            secondary_memory[5]=converter(question);

            printf("\n\nPytanie dziesiate: czy twoja postac gra w szachy?\n");
            scanf("%s", &question);
            secondary_memory[6]=converter(question);

            printf("\n\nPytanie jedenaste: czy twoja postac chodzi do szkoly?\n");
            scanf("%s", &question);
            secondary_memory[7]=converter(question);

            printf("\n\nPytanie dwunaste: czy twoja postac lata w kosmosie?\n");
            scanf("%s", &question);
            secondary_memory[8]=converter(question);

            cat2=fake_human(secondary_memory, len2);

            if(cat2==1)
            {
                printf("Twoja postac to Harry Poter!\n");
                strcpy(gracz.answer, "Harry Poter");
            }

            else if(cat2==2)
            {
                printf("Twoja postac to Hermiona Granger!\n");
                strcpy(gracz.answer, "Hermiona Granger");
            }

            else if(cat2==3)
            {
                printf("Twoja postac to Luke Skywalker!\n");
                strcpy(gracz.answer, "Luke Skywalker");
            }

            else if(cat2==4)
            {
                printf("Twoja postac to Beth Harmon!\n");
                strcpy(gracz.answer, "Beth Harmon");
            }

            else if(cat2==5)
            {
                printf("Twoja postac to Isaac Clarke!\n");
                strcpy(gracz.answer, "Isaac Clarke");
            }

            else if(cat2==6)
            {
                printf("Twoja postac to Dovakhiin!\n");
                strcpy(gracz.answer, "Dovakhiin");
            }

            else if(cat2==7)
            {
                printf("Twoja postac to Thorin Debowa Tarcza!\n");
                strcpy(gracz.answer, "Thorin Debowa Tarcza");
            }

            else if(cat2==8)
            {
                printf("Twoja postac to Rey Skywalker!\n");
                strcpy(gracz.answer, "Rey Skywalker");
            }
        }

        else if(cat1==4) // kategoria: kreatury fikcyjne
        {
            printf("\nPytanie czwarte: czy twoja postac jest mala?\n");
            scanf("%s", &question);
            secondary_memory[0]=converter(question);

            printf("\n\nPytanie piate: czy twoja postac jest zielona?\n");
            scanf("%s", &question);
            secondary_memory[1]=converter(question);

            printf("\n\nPytanie szoste: czy twoja postac pochodzi z bajki?\n");
            scanf("%s", &question);
            secondary_memory[2]=converter(question);

            printf("\n\nPytanie siodme: czy twoja postac to mem?\n");
            scanf("%s", &question);
            secondary_memory[3]=converter(question);

            printf("\n\nPytanie osme: czy twoja postac jest znana w kulturze?\n");
            scanf("%s", &question);
            secondary_memory[4]=converter(question);

            printf("\n\nPytanie dziewiate: czy twoja postac jest straszna?\n");
            scanf("%s", &question);
            secondary_memory[5]=converter(question);

            printf("\n\nPytanie dziesiate: czy twoja postac zyje w morzu?\n");
            scanf("%s", &question);
            secondary_memory[6]=converter(question);

            printf("\n\nPytanie jedenaste: czy twoja postac umie wejsc do wentylacji?\n");
            scanf("%s", &question);
            secondary_memory[7]=converter(question);

            printf("\n\nPytanie dwunaste: czy twoja postac mieszka w ananasie?\n");
            scanf("%s", &question);
            secondary_memory[8]=converter(question);

            cat2=fake_thing(secondary_memory, len2);

            if(cat2==1)
            {
                printf("Twoja postac to Creeper!\n");
                strcpy(gracz.answer, "Creeper");
            }

            else if(cat2==2)
            {
                printf("Twoja postac to Pepe The Frog!\n");
                strcpy(gracz.answer, "Pepe The Frog");
            }

            else if(cat2==3)
            {
                printf("Twoja postac to Kraken!\n");
                strcpy(gracz.answer, "Kraken");
            }

            else if(cat2==4)
            {
                printf("Twoja postac to Elf!\n");
                strcpy(gracz.answer, "Elf");
            }

            else if(cat2==5)
            {
                printf("Twoja postac to Spongebob Kanciastoporty!\n");
                strcpy(gracz.answer, "Spongebob Kanciastoporty");
            }

            else if(cat2==6)
            {
                printf("Twoja postac to Among Us!\n");
                strcpy(gracz.answer, "Among Us");
            }

            else if(cat2==7)
            {
                printf("Twoja postac to Shrek!\n");
                strcpy(gracz.answer, "Shrek");
            }

            else if(cat2==8)
            {
                printf("Twoja postac to Krasnolud!\n");
                strcpy(gracz.answer, "Krasnolud");
            }
        }

        clock_t end = clock(); // zatrzymanie zegara
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC; // obliczenie czasu
        printf("Twoj czas gry: %f\n", time_spent);
        gracz.gametime = time_spent; // wpisanie czasu gry do struktury

        FILE *gameinfo; // pliki pliki pliki...
        gameinfo = fopen("game.txt", "w+"); // otwarcie pliku

        fprintf(gameinfo, "%s\n%s\n%f\n", gracz.nick, gracz.answer, gracz.gametime); // wypisanie wartosci ze struktury do pliku

        fclose(gameinfo); // zamkniecie pliku
    }

    else // jesli nie chcemy grac, program konczy sie
    {
        printf("\nSzkoda\n");
    }

    sleep(10); // w przypadku skompilowanego pliku exe daje 10sec na zobaczenie wyniku

    return 0; //koniec, ponad 12 godzin roboty lacznie, nie polecam
}
