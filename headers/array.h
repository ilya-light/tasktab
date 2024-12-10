#include <stdio.h>
#include "task_parser.h"

#define GOLD 1.62

struct task_dynamic_array
{
    int size;
    int capacity;
    struct task* ptr; 
};

static void copy_elements(struct task* from, struct task * to, int size);
static void resize_array(struct task_dynamic_array * array);

struct task_dynamic_array * create_dynamic_array(int capacity);
void free_task_array(struct task_dynamic_array * array);
struct task_dynamic_array * add_to_array(struct task_dynamic_array * array, struct task* new_task);
int find(struct task_dynamic_array * array, int id);
int delete_from_array(struct task_dynamic_array * array, int id);
void show_array(struct task_dynamic_array * array);

int write_to_file(char * filename, struct task_dynamic_array * array);
int read_from_file(char * filename, struct task_dynamic_array * array);

