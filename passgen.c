#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int getchar_urand() {

  int byte_count = 1;
  char buff[1];
  FILE *fp;
  fp = fopen("/dev/urandom", "r");
  fread(buff, 1, byte_count, fp);
  fclose(fp);
  return (int)buff[0];

}

int get_rand_range(int min, int max) {

  const float RAND_MAX_F = RAND_MAX;
  srand(getchar_urand());
  return (rand() / RAND_MAX_F) * (max - min) + min;

}

void main(int argc, char** argv) {

  typedef unsigned short BOOL;

  BOOL upper_chars = 0, lower_chars = 0, count_numbers = 0;
  unsigned int passwd_length = 0;

  if(argc > 1) {

     

  }


  char a1 = 0;
  for (int i = 0; i < 60; i++) {
    a1 = get_rand_range(65, 90);
    printf("%c", a1);
}
    printf("\n");

}
