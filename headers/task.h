#include <stdio.h>
#include <string.h>
#include "utils.h"

#define NAME_SIZE 30
#define DESCRIPTION_SIZE 130
#define PRIORITY_LENGHT 20

enum Priority 
{
    LOW,
    BELOW_MEDIUM,
    MEDIUM,
    ABOVE_MEDIUM,
    HIGH,
};

struct task
{
    int id;
    char name[NAME_SIZE];
    char description[DESCRIPTION_SIZE];
    enum Priority priority;
};

static const char* priority_to_string(enum Priority priority);
static void make_priority(struct task * task);

struct task * create_task();
void print_task(struct task * task);
void change_task_fields(struct task * current_task);
