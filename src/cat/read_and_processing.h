#include <stdio.h>
#ifndef SRC_CAT_READ_AND_PROCESSING_H_
#define SRC_CAT_READ_AND_PROCESSING_H_

void open_cat_file(char *filename, int *arr_flag);
void flag_s(FILE *myfile, int *arr_flag, int *count_n, int *c);
void flag_b(int *arr_flag, int count_n, int new_line, int *number_line);
void flag_n(int *arr_flag, int new_line, int *number_line, int *c);
void flag_T(int *arr_flag, int *c);
void flag_E(int *arr_flag, int *c);
void flag_t(int *arr_flag, int *c, int *c_flag);
void flag_e(int *arr_flag, int *c, int *c_flag);
void converting(int *c, int *c_flag);

#endif  //  SRC_CAT_READ_AND_PROCESSING_H_
