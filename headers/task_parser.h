#include "task.h"

static char * copy_to_delimeter(char ** str, const char * delimeter);

struct task * parse(char * str);
char * task_to_str(struct task * task);
