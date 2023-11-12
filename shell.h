#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define DELIM " \t\n"

extern char **environ;

int main(int ca, char **arg);
char *getRead_line(void);
char *string_dupl(const char *str);
int string_cmpr(char *str_1, char *str_2);
int string_line(char *p);
char *string_cat(char *dst, char *sc);
char *string_cpy(char *dst, char *sc);
char **token_line(char *line_cmd);
void array_string(char **array);
int _Execute_line(char **command_line, char **arg, int index);
char *_Get_Env(char *var_env);
char *_Get_Path(char *command);
void print_ero(char *name, char *command, int index);
char *_it_oa(int n);
void inverse_string(char *string, int car);
int positive_nbr(char *string_nbr);
int at_oi(char *string_nbr);
int _is_built(char *command);
void hand_built(char **command, char **arg, int *stat, int index);
void exit_shell(char **command, char **arg, int *stat, int index);
void print_ev(char **command, int *stat);
#endif
