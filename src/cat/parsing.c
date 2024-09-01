#include "parsing.h"

#include <string.h>

int identification_position_flags_names(int position, char **flags_names,
                                        int *flag_exist_file) {
  int flag_identification = 0;
  if (flags_names[position][0] == '-') {
    flag_identification = 1;  //  flags -...
    if (flags_names[position][1] == '-') {
      flag_identification = 2;  //  flafs --...
    }
  } else {
    flag_identification = 3;  //  names
    *flag_exist_file = 0;
  }
  return flag_identification;
}

void flag_short(char *str_flag, int *arr_flag, int *flag_error) {
  int len = strlen(str_flag);
  for (int i = 1; i < len; i++) {
    if (str_flag[i] == 'b') {
      arr_flag[0] = 1;  //  -b / 0
    } else if (str_flag[i] == 'e') {
      arr_flag[1] = 1;  //  -e / 1
      arr_flag[5] = 1;  //  -v / 5
    } else if (str_flag[i] == 'E') {
      arr_flag[1] = 1;  //  -e / 2
    } else if (str_flag[i] == 'n') {
      arr_flag[2] = 1;  //  -n / 2
    } else if (str_flag[i] == 's') {
      arr_flag[3] = 1;  //  -s / 3
    } else if (str_flag[i] == 't') {
      arr_flag[4] = 1;  //  -t / 4
      arr_flag[5] = 1;  //  -v / 5
    } else if (str_flag[i] == 'T') {
      arr_flag[4] = 1;  //  -v / 5
    } else {
      *flag_error = 1;
    }
  }
}

void flag_long(char *str_flag, int *arr_flag, int *flag_error) {
  char str0[32] = "--number-nonblank";
  char str2[32] = "--number";
  char str3[32] = "--squeeze-blank";
  if (strcmp(str_flag, str0) == 0) {
    arr_flag[0] = 1;  //  -b / 0
  } else if (strcmp(str_flag, str2) == 0) {
    arr_flag[2] = 1;  //  -n / 2
  } else if (strcmp(str_flag, str3) == 0) {
    arr_flag[3] = 1;  //  -s / 3
  } else {
    *flag_error = 1;
  }
}
