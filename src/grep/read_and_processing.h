#include <regex.h>
#ifndef SRC_GREP_READ_AND_PROCESSING_H_
#define SRC_GREP_READ_AND_PROCESSING_H_

void grep_file(char *filename, int *argc, int *arr_flag, int *number_flags,
               regex_t regex);
void flag_c(char *filename, int *argc, int *arr_flag, int *number_flags,
            int *hit_counter);
void flag_n(char *filename, int *argc, int *arr_flag, int **number_flags,
            int *flag_concurrence, int *number_line, int *len_line_file,
            char *line_file);
void flag_l(char *filename, int *arr_flag, int *flag_concurrence,
            int *flag_file);
void flag_v(char *filename, int *argc, int *arr_flag, int **number_flags,
            int *flag_concurrence, int *len_line_file, char *line_file);
void flag_e_i_h(char *filename, int *argc, int *arr_flag, int **number_flags,
                int *flag_concurrence, int *len_line_file, char *line_file);
void flag_s(int *flag_exist_file, int *arr_flag);
void flag_f(char *file_name, char *f_file_template);

#endif  //  SRC_GREP_READ_AND_PROCESSING_H_
