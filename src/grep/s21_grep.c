#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

#include "parsing.h"
#include "read_and_processing.h"

int main(int argc, char *argv[]) {
  int i = 1;
  int arr_flag[10] = {0};
  int flag_error = 0;
  int flag_exist_file = 1;
  int flag_template = 0;
  int number_flags = 0;
  char f_file_template[999] = {'\0'};
  regex_t regex;
  while (i != argc) {
    int flag_identification = identification_position_template_flags_names(
        i, argv, &flag_exist_file, &flag_template);
    if (flag_identification == 1) {  // flags
      flags(argv[i], arr_flag, &flag_error);
      number_flags++;
    } else if (flag_identification == 2) {  //  template
      if (arr_flag[1] == 1) {               //  flag -i
        regcomp(&regex, argv[i], REG_ICASE);
      } else if (arr_flag[8] == 1) {
        flag_f(argv[i], f_file_template);
        regcomp(&regex, f_file_template, REG_EXTENDED);
      } else {
        regcomp(&regex, argv[i], 0);
      }
    } else if (flag_identification == 3) {  //  file_name
      if (flag_error == 0) {
        grep_file(argv[i], &argc, arr_flag, &number_flags, regex);
      } else {
        printf("this flag is not exists, dear ;(\n");
      }
    }
    i++;
  }
  flag_s(&flag_exist_file, arr_flag);
  regfree(&regex);
  return 0;
}
