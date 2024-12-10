#include "task_parser.h"

static char * copy_to_delimeter(char ** str, const char * delimeter)
{
    int len = strcspn(*str, delimeter);

#if DEBUG

    printf("Len is %d\n", len);

#endif

    char* part = malloc(sizeof(char) * (len + 1));
    strncpy(part, *str, len);
    part[len] = '\0';
    *str += len + 1;

    return part;
}



struct task * parse(char * str)
{
    char * str_id = copy_to_delimeter(&str, ";");
    char * str_priority = copy_to_delimeter(&str, ";");
    char * name = copy_to_delimeter(&str, ";");
    char * description = copy_to_delimeter(&str, "\n");

#if DEBUG

    printf("%s\n", str_id);
    printf("%s\n", str_priority);
    printf("%s\n", name);
    printf("%s\n", description);

#endif

    int id = strtol(str_id, NULL, 10);
    int priority = strtol(str_priority, NULL, 10);
    
    struct task * task = malloc(sizeof(struct task));
    task->id = id;
    task->priority = priority;
    strcpy(task->name, name);
    strcpy(task->description, description);
    
    free(str_id);
    free(str_priority);
    free(name);
    free(description);
    
    return task;
}

char * task_to_str(struct task * task)
{
    char * str = malloc(sizeof(char) * 200);
    sprintf(str, "%d;%d;%s;%s\n", task->id, task->priority, task->name, task->description);
    return str;
}