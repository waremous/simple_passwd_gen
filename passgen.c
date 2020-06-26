#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

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

  BOOL set_upper_char = FALSE, set_lower_char = FALSE, set_numbers = FALSE;
  unsigned int passwd_length = 8, passwd_counts = 10;

  for(; passwd_counts > 0; passwd_counts--) {
    for(int i = passwd_length; i > 0; i--) {

      if(argc == 1) {
        passwd_length = 8;
        set_upper_char = TRUE;
        set_lower_char = TRUE;
        set_numbers = TRUE;
      }

      switch (get_rand_range(0, 3)) {
        case 0:  //If set upper chars.
          if(set_upper_char) {
            char c = get_rand_range(65, 91);
            printf("%c", c);
            break;
          }
          else {
            passwd_length++;
            break;
          }
        case 1: //If set lower chars.
          if(set_lower_char) {
            char c = get_rand_range(97, 123);
            printf("%c", c);
            break;
          }
          else {
            passwd_length++;
            break;
          }
        case 2: //If set numbers.
          if(set_numbers) {
            char c = get_rand_range(48, 58);
            printf("%c", c);
            break;
          }
          else {
            passwd_length++;
            break;
          }

      }

    }
    printf("\n");
  }


/*  char a1 = 0;
  for (int i = 0; i < 8; i++) {
    a1 = get_rand_range(65, 90);
    printf("%c", a1);
}
    printf("\n");
*/
}
