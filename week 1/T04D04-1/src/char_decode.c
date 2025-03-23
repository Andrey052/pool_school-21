#include <math.h>
#include <stdio.h>

void code(void);
void decode(void);

int main() {
  int flag;
  scanf("%d", &flag);
  if (flag == 1) {
    code();
    printf("\n");
  } else if (flag == 0) {
    decode();
    printf("\n");
  } else {
    printf("n/a\n");
  }
  return 0;
}

void decode(void) {
  char letter;
  char space;
  scanf("%c", &letter);
  scanf("%c", &letter);
  scanf("%c", &space);
  // printf("%d", letter);
  while (1) {
    if ((int)space == 10) {
      printf("%x ", letter);
      break;
    } else {
      if (space == 32) {
        printf("%x ", letter);
        scanf("%c", &letter);
        scanf("%c", &space);
      } else {
        printf("n/a");
        break;
      }
    }
  }
}

void code(void) {
  int letter;
  scanf("%x", &letter);
  // printf("%x", letter);
  while (1) {
    if (letter > 0xff) {
      printf("n/a");
      break;
    } else if (getchar() == '\n') {
      printf("%c ", letter);
      break;
    } else {
      printf("%c ", letter);
      scanf("%x", &letter);
    }
  }
}