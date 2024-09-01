#ifndef SRC_GREP_PARSING_H_
#define SRC_GREP_PARSING_H_

int identification_position_template_flags_names(int position,
                                                 char **flags_template_names,
                                                 int *flag_exist_file,
                                                 int *flag_template);
void flags(char *str_flag, int *arr_flag, int *flag_error);

#endif  //  SRC_GREP_PARSING_H_
