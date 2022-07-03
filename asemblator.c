#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "asemblator.h"

#define CODE_MEMORY 256

//r = czytaj z pliku (read)
//s = struktury
//
//typy 
//0 - dyrektywa
//1 - instrukcja 
//2 - etykieta

int Ile_Linii(FILE * fp){
  int linie = 0;
  char *bufor;
  size_t rozmiar_bufora = 1024;
  size_t liczba_znakow;

  bufor = (char*)malloc(rozmiar_bufora * sizeof(char));
  while(1){
    int liczba_znakow = getline(&bufor, &rozmiar_bufora, fp);

    //sprawdzenie czy to koniec linii kodu
    if((int)liczba_znakow < 0) break;
    liczba_znakow--;
    linie++;
    bufor[liczba_znakow] = '\0';
    printf("%s, %d\n", bufor, (int)liczba_znakow);

  }
  //powrót do początku pliku, ale teraz znana jest ilość linii
  fseek(fp, 0, SEEK_SET);
  free(bufor);
  return linie;
}

int Skip_spacje(int i, int j, Tekst_programu * Kod){
  while(Kod->linie[i].tekst[j] == ' ' && j < Kod->linie[i].dlugosc_linii){
    j++;
  }
  return j;
}

int Licz_operand_znaki(int i, int j, Tekst_programu * Kod, int operand_znaki){
  while(Kod->linie[i].tekst[j] != ',' && Kod->linie[i].tekst[j] != '\n' && Kod->linie[i].tekst[j] != '\0' && Kod->linie[i].tekst[j] != ';'){
    operand_znaki++;
    j++;
  }
  return operand_znaki;
}

//funkcja sprawdza czy dana linia to komentarz, albo znaki spacja/nowa linia/tabulator
char Czy_ominac(char * bufor, int rozmiar_bufora, int liczba_znakow){
  for(int i = 0 ; i < liczba_znakow ; i++){
    if(bufor[i] == '\n' || bufor[i] == ' ' || bufor[i] == '\t'){
    }
    else
    if(bufor[i] == ';'){
      return 1;
    }
    else
    return 0;
  }
  return 1;
}

int CzytajZPliku(Tekst_programu * Kod, char * nazwa_pliku) { 
  //Otwieranie pliku i zapis tekstu
  //--------------------------------------------------------------------//
  Kod->nazwa_pliku = nazwa_pliku;

  FILE * fp;
  fp = fopen(Kod->nazwa_pliku, "r");

  if(!fp){
    printf("Plik o nazwie %s nie istnieje!\n", Kod->nazwa_pliku);
    return -1;
  }
  //--------------------------------------------------------------------//
  //Policz linie kodu
  //--------------------------------------------------------------------//
  char *bufor;
  size_t rozmiar_bufora = 1024;
  size_t liczba_znakow;

  bufor = (char*)malloc(rozmiar_bufora * sizeof(char));

  int whitespace_counter = 0;
  int liczba_linii = Ile_Linii(fp);
  //--------------------------------------------------------------------//

  //teraz możliwe jest zaalokowanie pamięci by zapisać sformatowany
  //tekst wczytywanego programu
  Kod->linie = (Linia_kodu*)malloc(sizeof(Linia_kodu) * liczba_linii);
  for(int i = 0 ; i < liczba_linii ; i++){
    liczba_znakow = getline(&bufor, &rozmiar_bufora, fp);

    //szybkie wykrycie czy linia nie jest przypadkiem pełna komentarzy albo 
    //whitespace'u
    
    char test = Czy_ominac(bufor, (int)rozmiar_bufora, liczba_znakow);

    //sprawdzenie czy to koniec linii kodu i wypełnieni 
    //pól struktur dotyczących linii kodu
    if(test){
      whitespace_counter++;
    }
    else{
      if((int)liczba_znakow < 0) break;
      liczba_znakow--;
      bufor[liczba_znakow] = '\0';
      Kod->linie[i - whitespace_counter].numer_linii = i - whitespace_counter;
      Kod->linie[i - whitespace_counter].dlugosc_linii = (int)liczba_znakow;

      //tu można zaalokować miejsce na napis w strukturze Linia_kodu
      //i skopiować go tam z bufora
      Kod->linie[i - whitespace_counter].tekst = (char*)malloc(sizeof(char) * Kod->linie[i - whitespace_counter].dlugosc_linii);
      strcpy(Kod->linie[i - whitespace_counter].tekst, bufor);

    //--------------------------------------------------------------------//
      printf("%s| %d, %d\n", Kod->linie[i - whitespace_counter].tekst, Kod->linie[i - whitespace_counter].numer_linii, Kod->linie[i - whitespace_counter].dlugosc_linii);
    }

  }

  //po podliczeniu linii które nie mają żadnego znaczenia 
  //trzeba zaktualizować liczbę faktycznych linii kodu
  liczba_linii = liczba_linii - whitespace_counter;
  Kod->liczba_linii = liczba_linii;
  //--------------------------------------------------------------------//
  //Tutaj można przetworzyć linie tekstu mając już informacje o długości linii oraz  
  //ilości linii 
  //Wydobycie poszczególnych słów z danej linii
  //Pierwsze słowo to OPCODE albo ETYKIETA
  //Kolejne słowa to OPERANDY
  //Jeśli pierwsze słowo kończy się dwukropkiem to jest 
  //to adres, a nie rozkaz

  for(int i = 0 ; i < liczba_linii ; i++){
    //tutaj trzeba policzyć słowa w każdej linii
    int liczba_slow = 0;
    int j = 0;

    //kasowanie spacji przed rozkazem
    while(1){
      if(Kod->linie[i].tekst[j] == ' '){
        j++;
      }
      else{
        break;
      }
    }
    int k = j;
    //j = początek instrukcji
    //k = początek instrukcji
    //policz litery rozkazu żeby potem go skopiować do struktury
    
    //Skopiowanie opcode'u do struktury
    //--------------------------------------------------------------------//
    int opcode_znaki = 0;
    int operand_znaki = 0;
    int liczba_operand = 0;
    //policzenie ile znaków ma opcode bez spacji jeśli są jakieś argumenty
    while(Kod->linie[i].tekst[j] != ' ' && Kod->linie[i].tekst[j] != '\n' && Kod->linie[i].tekst[j] != '\0'){
      opcode_znaki++;
      j++;
    }
    j = k;
    Kod->linie[i].opcode = (char*)malloc(sizeof(char) * opcode_znaki);
    memcpy(Kod->linie[i].opcode, &Kod->linie[i].tekst[j], opcode_znaki);
    //--------------------------------------------------------------------//
    //tekst opcode'u zapisany w strukturze
    
    if(Kod->linie[i].opcode[opcode_znaki-1] == ':'){
      Kod->linie[i].typ = 2;
    }
    else
    if(strcmp(Kod->linie[i].opcode, "EQU") == 0){
      Kod->linie[i].typ = 0;
    }
    else{
      Kod->linie[i].typ = 1;
    }

    k = k + opcode_znaki + 1;
    j = k;
    //k = pozycja pierwszego operandu
    //j = k
    
    //Przeglądanie argumentów rozkazu
    //--------------------------------------------------------------------//
    //jeśli np rozkaz nie ma operandów to wypisz
    if(j >= Kod->linie[i].dlugosc_linii) {
      printf("LINIA KODU, %s, typu %d\n", Kod->linie[i].tekst, Kod->linie[i].typ);
      //printf("LICZBA ZNAKÓW OPCODE, LICZBA ZNAKÓW OPERANDY, LICZBA OPERANDÓW, TEKST ROZKAZU, J %d, %d, %d, %s, %d\n", opcode_znaki, operand_znaki, liczba_operand, Kod->linie[i].opcode, j);
      //printf("DLUGOSC LINII, %d\n", Kod->linie[i].dlugosc_linii);
      Kod->linie[i].liczba_arg = 0;
    }
    
    //w pętli spisuję słowa aż dotrę do końca linii by wiedzieć ile jest operandów, 
    //ile zajmują miejsca
    while(j < Kod->linie[i].dlugosc_linii){
      //wyzerowanie licznika długości operandu
      operand_znaki = 0;

      //jeśli rozkaz ma > 1 operand to będzie ,
      //jeśli rozkaz ma 1 operand to doliczy do końca linii 
      liczba_operand++;
      operand_znaki = Licz_operand_znaki(i, j, Kod, operand_znaki);
      while(Kod->linie[i].tekst[j] != ',' && Kod->linie[i].tekst[j] != '\n' && Kod->linie[i].tekst[j] != '\0' && Kod->linie[i].tekst[j] != ';'){
        operand_znaki++;
        j++;
      }

      printf("LINIA KODU, %s, typu %d\n", Kod->linie[i].tekst, Kod->linie[i].typ);
      //printf("LICZBA ZNAKÓW OPCODE, LICZBA ZNAKÓW OPERANDY, LICZBA OPERANDÓW, TEKST ROZKAZU, J %d, %d, %d, %s, %d\n", opcode_znaki, operand_znaki, liczba_operand, Kod->linie[i].opcode, j);
      //printf("DLUGOSC LINII, %d\n", Kod->linie[i].dlugosc_linii);
      //jeśli pętla została przerwana bo koniec linii albo komentarz 
      //to przerwij też pętlę główną dla danej linii
      if(Kod->linie[i].tekst[j] == '\n' || Kod->linie[i].tekst[j] == '\0' || Kod->linie[i].tekst[j] == ';'){
        break;
      }

      //robię skok o literę do przodu na wypadek gdyby program 
      //utknął na przecinku
      j++;
      //skip spacje
      j = Skip_spacje(i, j, Kod);
    }

    //teraz można zapisać operandy w osobne miejsca w strukturze
    //bo wiadomo ile ich jest
    Kod->linie[i].liczba_arg = liczba_operand;
    Kod->linie[i].args = (char**)malloc(sizeof(char*) * liczba_operand);
    j = k;

    liczba_operand = 0;
    while(j < Kod->linie[i].dlugosc_linii){
      //wyzerowanie licznika długości operandu
      operand_znaki = 0;

      //jeśli rozkaz ma > 1 operand to będzie ,
      //jeśli rozkaz ma 1 operand to doliczy do końca linii 
      liczba_operand++;
      while(Kod->linie[i].tekst[j] != ',' && Kod->linie[i].tekst[j] != '\n' && Kod->linie[i].tekst[j] != '\0' && Kod->linie[i].tekst[j] != ';'){
        operand_znaki++;
        j++;
      }

      //tutaj można zaalokować miejsce na napisy
      Kod->linie[i].args[liczba_operand-1] = (char*)malloc(sizeof(char) * operand_znaki);
      strncpy(Kod->linie[i].args[liczba_operand-1], &Kod->linie[i].tekst[j - operand_znaki], operand_znaki);


      if(Kod->linie[i].tekst[j] == '\n' || Kod->linie[i].tekst[j] == '\0' || Kod->linie[i].tekst[j] == ';'){
        break;
      }

      //robię skok o literę do przodu na wypadek gdyby program 
      //utknął na przecinku
      j++;
      //skip spacje
      j = Skip_spacje(i, j, Kod);
    }
    //wypisz opcody żeby sprawdzić czy wszystko w porządku
    for(int z = 0 ; z < Kod->linie[i].liczba_arg ; z++){
      printf("OPCODE nr.%d, %s\n", z, Kod->linie[i].args[z]);
    }
  }
  //--------------------------------------------------------------------//
    return 0;
}

//funkcja która jeśli napotka etykiete zmniejszy indeksy wszystkich następnych instrukcji 
//żeby etykieta wskazywała nie na puste miejsce ale na kolejną linię kodu
//Jednocześnie alokowane jest tu miejsce żeby zapisać etykiety do osobnej struktury
int redukuj_indeksy(Tekst_programu * Kod){
  int faktyczna_liczba_linii = Kod->liczba_linii;
  printf("-----------------------------------\n");
  for(int i = 0 ; i < Kod->liczba_linii ; i++){
    if(Kod->linie[i].typ == 2){
      faktyczna_liczba_linii--;
      for(int j = i+1 ; j < Kod->liczba_linii ; j++){
        Kod->linie[j].numer_linii--;
      }
    }
    printf("%s| %d, %d\n", Kod->linie[i].tekst, Kod->linie[i].numer_linii, Kod->linie[i].dlugosc_linii);
  }
  Kod->faktyczna_liczba_linii = faktyczna_liczba_linii;
  int liczba_etykiet = faktyczna_liczba_linii - Kod->liczba_linii;
  //tutaj tworzone jest miejsce na osobne zapisanie etykiet 
  //pomaga to potem
  Kod->etykiety = (Etykieta *)malloc(sizeof(Etykieta) * liczba_etykiet);
  return 0;
}
