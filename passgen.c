#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

#define TRUE 1
#define FALSE 0
#define NOP 1 == 1

#define DEBUG(line) printf(line)

extern char* optarg;
extern int opterr;

// Get one char from /dev/urandom for init srand().
int getchar_urand() {

  int byte_count = 1;
  char buff[1];
  FILE *fp;
  fp = fopen("/dev/urandom", "r");
  fread(buff, 1, byte_count, fp);
  fclose(fp);
  return (int)buff[0];

}
// Get random number from range "min" "max-1".
int get_rand_range(int min, int max) {

  const float RAND_MAX_F = RAND_MAX;
  srand(getchar_urand());
  return (rand() / RAND_MAX_F) * (max - min) + min;

}

////////////////////////////////////__MAIN__////////////////////////////////////
int main(int argc, char** argv) {

  typedef unsigned short BOOL;

  BOOL set_upper_char = FALSE, set_lower_char = FALSE, set_numbers = FALSE;
  unsigned int passwd_length = 0, passwd_counts = 0;

  if(argc > 1) {
    char* opts = "ULNl:c:h";
    int opt = 0;
    while((opt = getopt(argc, argv, opts)) != -1 ) {
//    if(opterr != 0)
//      return 1;
      switch(opt) {
        case 'U':
          set_upper_char = TRUE;
          break;
        case 'L':
          set_lower_char = TRUE;
          break;
        case 'N':
          set_numbers = TRUE;
          break;
        case 'l':
          passwd_length = atoi(optarg);
          break;
        case 'c':
          passwd_counts = atoi(optarg);
          break;
        case 'h':
          printf("Usage: \n   -U - enable upper chars\n   -L - enable lower chars\n");
          printf("   -N - enable numbers\n   -l - password length\n   -c - count of passwords\n");
          printf("   -h - help\n");
          return 0;
        case '?':
          printf("Invalid option.\n");
          return 1;
        case ':':
          printf("Invalid argument.\n");
          return 1;

//        default:
//        printf("Invalid option.\n");

/*        default:
          DEBUG("DEBUG_default\n");
          set_upper_char = TRUE;
          set_lower_char = TRUE;
          set_numbers = TRUE;
*/
      }
    }
  }
  else {

  //  DEBUG("DEBUG_1\n");

    passwd_counts ? NOP : (passwd_counts = 10);
    passwd_length ? NOP : (passwd_length = 8);
    set_upper_char = TRUE;
    set_lower_char = TRUE;
    set_numbers = TRUE;
  }

  passwd_counts ? NOP : (passwd_counts = 10);
  passwd_length ? NOP : (passwd_length = 8);



  for(; passwd_counts > 0; passwd_counts--) {
    for(int i = passwd_length; i > 0; i--) {

      switch (get_rand_range(0, 3)) {
        case 0:  //If set upper chars.
          if(set_upper_char) {
            char c = get_rand_range(65, 91);
            printf("%c", c);
            break;
          }
          else {
            i++;
            break;
          }
        case 1: //If set lower chars.
          if(set_lower_char) {
            char c = get_rand_range(97, 123);
            printf("%c", c);
            break;
          }
          else {
            i++;
            break;
          }
        case 2: //If set numbers.
          if(set_numbers) {
            char c = get_rand_range(48, 58);
            printf("%c", c);
            break;
          }
          else {
            i++;
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
