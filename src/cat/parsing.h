#ifndef SRC_CAT_PARSING_H_
#define SRC_CAT_PARSING_H_

int identification_position_flags_names(int position, char **flags_names,
                                        int *flag_exist_file);
void flag_short(char *str_flag, int *arr_flag, int *flag_error);
void flag_long(char *str_flag, int *arr_flag, int *flag_error);

#endif  //  SRC_CAT_PARSING_H_
