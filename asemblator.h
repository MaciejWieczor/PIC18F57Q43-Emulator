#define CODE_MEMORY 256

typedef struct Linia_kodu {
  int numer_linii;
  int dlugosc_linii;
  int ilosc_slow;
  unsigned char typ;
  char * tekst;
  char * opcode;
  int liczba_arg;
  char ** args;
} Linia_kodu;

typedef struct Etykieta {
  int id;
  int adres;
  char * tekst;
} Etykieta;

typedef struct Tekst_programu {
  unsigned long liczba_linii;
  unsigned long faktyczna_liczba_linii;
  char * nazwa_pliku;
  Linia_kodu * linie;
  Etykieta * etykiety;
} Tekst_programu;

int CzytajZPliku(Tekst_programu * Kod, char * nazwa_pliku);
int redukuj_indeksy(Tekst_programu * Kod);
