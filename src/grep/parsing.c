#include "parsing.h"

#include <string.h>

int identification_position_template_flags_names(int position,
                                                 char **flags_template_names,
                                                 int *flag_exist_file,
                                                 int *flag_template) {
  int flag_identification = 0;
  if (flags_template_names[position][0] != '-' && *flag_template == 1) {
    flag_identification = 3;  //  file_name
    *flag_exist_file = 0;
  }
  if (flags_template_names[position][0] == '-') {
    flag_identification = 1;  //  flags
  } else if (flags_template_names[position][0] != '-' &&
             *flag_exist_file == 1) {
    flag_identification = 2;  //  template
    *flag_template = 1;
  }
  return flag_identification;
}

void flags(char *str_flag, int *arr_flag, int *flag_error) {
  int len = strlen(str_flag);
  for (int i = 1; i < len; i++) {
    if (str_flag[i] == 'e') {
      arr_flag[0] = 1;  //  -e / 0
    } else if (str_flag[i] == 'i') {
      arr_flag[1] = 1;  //  -i / 1
    } else if (str_flag[i] == 'v') {
      arr_flag[2] = 1;  //  -v / 2
    } else if (str_flag[i] == 'c') {
      arr_flag[3] = 1;  //  -c / 3
    } else if (str_flag[i] == 'l') {
      arr_flag[4] = 1;  //  -l / 4
    } else if (str_flag[i] == 'n') {
      arr_flag[5] = 1;  //  -n / 5
    } else if (str_flag[i] == 'h') {
      arr_flag[6] = 1;  //  -h / 6
    } else if (str_flag[i] == 's') {
      arr_flag[7] = 1;  //  -s / 7
    } else if (str_flag[i] == 'f') {
      arr_flag[8] = 1;  //  -f / 8
    } else if (str_flag[i] == 'o') {
      arr_flag[9] = 1;  //  -o / 9
    } else {
      *flag_error = 1;
    }
  }
}
