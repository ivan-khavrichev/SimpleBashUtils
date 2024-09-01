#include <stdio.h>

#include "parsing.h"
#include "read_and_processing.h"

int main(int argc, char *argv[]) {
  int i = 1;
  int arr_flag[6] = {0};
  int flag_error = 0;
  int flag_exist_file = 1;
  while (i != argc) {
    int flag_identification =
        identification_position_flags_names(i, argv, &flag_exist_file);
    if (flag_identification == 1) {
      flag_short(argv[i], arr_flag, &flag_error);
    } else if (flag_identification == 2) {
      flag_long(argv[i], arr_flag, &flag_error);
    } else if (flag_identification == 3) {
      if (flag_error == 0) {
        open_cat_file(argv[i], arr_flag);
      } else {
        printf("this flag is not exists, dear ;(\n");
      }
    }
    i++;
  }
  if (flag_exist_file == 1) {
    printf("no such file, durling :(\n");
  }
  return 0;
}
