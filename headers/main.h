#include <stdio.h>
#include "array.h"

int show_tasks(struct task_dynamic_array* task_array);
int add_task(struct task_dynamic_array* task_array);
int delete_task(struct task_dynamic_array* task_array);
int edit_task(struct task_dynamic_array* task_array);
void print_options();