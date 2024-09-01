#include "read_and_processing.h"

#include <stdio.h>

void open_cat_file(char *filename, int *arr_flag) {
  FILE *myfile;
  myfile = fopen(filename, "r");
  if (myfile != NULL) {
    int number_line = 1;
    int count_n = 0;
    int new_line = 1;
    int c_flag = 0;
    int c = fgetc(myfile);
    while (c != EOF) {
      if (c == 10 && new_line == 1) {
        count_n++;
      } else {
        count_n = 0;
      }
      flag_s(myfile, arr_flag, &count_n, &c);
      flag_b(arr_flag, count_n, new_line, &number_line);
      flag_n(arr_flag, new_line, &number_line, &c);
      if (c == 10) {
        new_line = 1;
      } else {
        new_line = 0;
      }
      flag_T(arr_flag, &c);
      flag_E(arr_flag, &c);
      flag_t(arr_flag, &c, &c_flag);
      flag_e(arr_flag, &c, &c_flag);
      if (c_flag == 0 && c != -1) {
        printf("%c", c);
      }
      c = fgetc(myfile);
      c_flag = 0;
    }
    fclose(myfile);
  } else {
    printf("no such file, durling :(\n");
  }
}

void flag_b(int *arr_flag, int count_n, int new_line, int *number_line) {
  if (arr_flag[0] == 1 && count_n == 0 && new_line == 1) {
    printf("%6d\t", *number_line);
    *number_line = *number_line + 1;
  }
}

void flag_n(int *arr_flag, int new_line, int *number_line, int *c) {
  if (arr_flag[2] == 1 && new_line == 1 && arr_flag[0] == 0 && *c != -1) {
    printf("%6d\t", *number_line);
    *number_line = *number_line + 1;
  }
}

void flag_s(FILE *myfile, int *arr_flag, int *count_n, int *c) {
  if (*count_n > 1 && arr_flag[3] == 1) {
    while (*c == '\n') {
      *c = fgetc(myfile);
      *count_n = 0;
    }
  }
}

void flag_T(int *arr_flag, int *c) {
  if (arr_flag[4] == 1 && arr_flag[5] == 0 && *c == 9) {
    printf("^I");
    *c = 'I';
  }
}

void flag_E(int *arr_flag, int *c) {
  if (arr_flag[1] == 1 && arr_flag[5] == 0 && *c == 10) {
    printf("$");
  }
}

void flag_t(int *arr_flag, int *c, int *c_flag) {
  if (arr_flag[4] == 1 && arr_flag[5] == 1) {
    if ((*c >= 127 || *c < 32) && *c != 9 && *c != 10 && *c != -1) {
      converting(c, c_flag);
    }
    if (*c == 9) {
      printf("^");
      *c = 'I';
    }
  }
}

void flag_e(int *arr_flag, int *c, int *c_flag) {
  if (arr_flag[1] == 1 && arr_flag[5] == 1) {
    if ((*c >= 127 || *c < 32) && *c != 10 && *c != 9 && *c != -1) {
      converting(c, c_flag);
    }
    if (*c == 10) {
      printf("$");
    }
  }
}

void converting(int *c, int *c_flag) {
  if (*c < 32 && *c != 10 && *c != 9) {
    printf("^");
    *c = *c + 64;
  } else if (*c == 127 && *c_flag == 0) {
    printf("^?");
    *c_flag = *c_flag + 1;
  } else if (*c > 127) {
    *c = *c % 128;
    if (*c < 32) {
      printf("M-^");
      *c = *c + 64;
    } else if (*c == 127) {
      printf("M-^?");
    } else {
      printf("M-");
    }
  }
}
