#include<stdio.h>
#include<stdlib.h>

#include "asemblator.h"

int main(){
    Tekst_programu Kod;
    int test = CzytajZPliku(&Kod, "program.txt");
    int test_2 = redukuj_indeksy(&Kod);
    return 0;
}
