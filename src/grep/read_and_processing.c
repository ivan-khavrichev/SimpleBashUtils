#include "read_and_processing.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void grep_file(char *filename, int *argc, int *arr_flag, int *number_flags,
               regex_t regex) {
  FILE *myfile;
  myfile = fopen(filename, "r");
  if (myfile != NULL) {
    char *line_file = NULL;
    size_t len_line = 0;
    ssize_t read;
    read = getline(&line_file, &len_line, myfile);
    int hit_counter = 0;
    int number_line = 1;
    int flag_file = 0;
    while (read != EOF) {
      int flag_concurrence = regexec(&regex, line_file, 0, NULL, 0);
      int len_line_file = strlen(line_file);
      flag_e_i_h(filename, argc, arr_flag, &number_flags, &flag_concurrence,
                 &len_line_file, line_file);
      flag_v(filename, argc, arr_flag, &number_flags, &flag_concurrence,
             &len_line_file, line_file);
      if (arr_flag[3] == 1 && flag_concurrence == 0) {  //  flag -c
        hit_counter++;
      }
      flag_l(filename, arr_flag, &flag_concurrence, &flag_file);
      flag_n(filename, argc, arr_flag, &number_flags, &flag_concurrence,
             &number_line, &len_line_file, line_file);
      read = getline(&line_file, &len_line, myfile);
      number_line++;
    }
    free(line_file);
    fclose(myfile);
    flag_c(filename, argc, arr_flag, number_flags, &hit_counter);
  } else if (arr_flag[7] == 0) {  //  flag -s
    printf("%s: no such file, durling :(\n", filename);
  }
}

void flag_f(char *file_name, char *f_file_template) {
  FILE *f_file;
  f_file = fopen(file_name, "r");
  if (f_file != NULL) {
    char *f_line_file = NULL;
    size_t f_len_line = 0;
    ssize_t f_read;
    int offset = 0;
    f_read = getline(&f_line_file, &f_len_line, f_file);
    f_len_line = strlen(f_line_file);
    while (f_read != EOF) {
      f_len_line = strlen(f_line_file);
      if (f_len_line > 1) {
        if (f_line_file[f_len_line - 1] == '\n') {
          f_line_file[f_len_line - 1] = '|';
        }
        strcpy(f_file_template + offset, f_line_file);
        offset += f_len_line;
      } else {
        f_file_template[offset] = '.';
        offset++;
        f_file_template[offset] = '|';
        offset++;
      }
      f_read = getline(&f_line_file, &f_len_line, f_file);
    }
    if (f_file_template[offset - 1] == '|') {
      f_file_template[offset - 1] = '\0';
    }
    free(f_line_file);
    fclose(f_file);
  }
}

void flag_s(int *flag_exist_file, int *arr_flag) {
  if (*flag_exist_file == 1 && arr_flag[7] == 0) {
    printf("no such file, durling :(\n");
  }
}

void flag_e_i_h(char *filename, int *argc, int *arr_flag, int **number_flags,
                int *flag_concurrence, int *len_line_file, char *line_file) {
  if (arr_flag[2] == 0 && arr_flag[3] == 0 && arr_flag[4] == 0 &&
      arr_flag[5] == 0 && *flag_concurrence == 0) {
    if (((*argc >= 4 && **number_flags == 0) ||
         (*argc >= 5 && **number_flags == 1)) &&
        arr_flag[6] != 1) {
      printf("%s:%s", filename, line_file);
      if (line_file[*len_line_file - 1] != '\n') {
        printf("\n");
      }
    } else {
      printf("%s", line_file);
      if (line_file[*len_line_file - 1] != '\n') {
        printf("\n");
      }
    }
  }
}

void flag_v(char *filename, int *argc, int *arr_flag, int **number_flags,
            int *flag_concurrence, int *len_line_file, char *line_file) {
  if (arr_flag[2] == 1 && *flag_concurrence != 0) {
    if ((*argc == 4 && **number_flags == 1)) {
      printf("%s", line_file);
      if (line_file[*len_line_file - 1] != '\n') {
        printf("\n");
      }
    } else {
      printf("%s:%s", filename, line_file);
      if (line_file[*len_line_file - 1] != '\n') {
        printf("\n");
      }
    }
  }
}

void flag_l(char *filename, int *arr_flag, int *flag_concurrence,
            int *flag_file) {
  if (arr_flag[4] == 1 && *flag_concurrence == 0 && *flag_file == 0) {
    printf("%s\n", filename);
    *flag_file = 1;
  }
}

void flag_n(char *filename, int *argc, int *arr_flag, int **number_flags,
            int *flag_concurrence, int *number_line, int *len_line_file,
            char *line_file) {
  if (arr_flag[5] == 1 && *flag_concurrence == 0) {
    if ((*argc >= 4 && **number_flags == 0) ||
        (*argc >= 5 && **number_flags == 1)) {
      printf("%s:%d:%s", filename, *number_line, line_file);
      if (line_file[*len_line_file - 1] != '\n') {
        printf("\n");
      }
    } else {
      printf("%d:%s", *number_line, line_file);
      if (line_file[*len_line_file - 1] != '\n') {
        printf("\n");
      }
    }
  }
}

void flag_c(char *filename, int *argc, int *arr_flag, int *number_flags,
            int *hit_counter) {
  if (arr_flag[3] == 1) {
    if (*argc == 4 && *number_flags == 1) {
      printf("%d\n", *hit_counter);
    } else {
      printf("%s:%d\n", filename, *hit_counter);
    }
  }
}
