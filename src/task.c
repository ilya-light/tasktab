#include "task.h"

extern int id_count;

static const char* priority_to_string(enum Priority priority)
{
    switch (priority)
    {
        case LOW: return "LOW";
        case BELOW_MEDIUM: return "BELOW_MEDIUM";
        case MEDIUM: return "MEDIUM";
        case ABOVE_MEDIUM: return "ABOVE_MEDIUM";
        case HIGH: return "HIGH";
        default: return "UNDEFINED";
    }
}

static void make_priority(struct task * task)
{
    while(1)
    {
        printf("Enter priority:\n"
        "0 - LOW\n"
        "1 - BELOW MEDIUM\n"
        "2 - MEDIUM\n"
        "3 - ABOVE MEDIUM\n"
        "4 - HIGH\n");
        task->priority = get_number();
        while(check_error("Enter correct priority\n"))
        {
            task->priority = get_number();
        }
        if(task->priority > 4 || task->priority < 0)
        {
            printf("Wrong priority. Try again.\n");
            continue;
        }
        break;
    }
}

struct task * create_task()
{
    struct task* new_task = (struct task*)malloc(sizeof(struct task));
    new_task->id = id_count;
    id_count++;

    make_priority(new_task);

    printf("Enter name task\n");
    fgets(new_task->name, sizeof(new_task->name), stdin);
    new_task->name[strcspn(new_task->name, "\n")] = 0;
    
    printf("Enter description\n");
    fgets(new_task->description, sizeof(new_task->description), stdin);
    new_task->description[strcspn(new_task->description, "\n")] = 0;
    
    return new_task;
    
}

void print_task(struct task * task)
{

    printf("%d\t%*s\t%*s\t%*s\n",
        task->id,
        PRIORITY_LENGHT, priority_to_string(task->priority),
        NAME_SIZE, task->name,
        DESCRIPTION_SIZE, task->description);
}

void change_task_fields(struct task * current_task)
{
    make_priority(current_task);

    char buffer_name[NAME_SIZE];
    printf("Enter new name or press enter to skip\n");
    fgets(buffer_name, sizeof(buffer_name), stdin);
    if(buffer_name[0] != '\n')
    {
        printf("Name changed\n");
        strcpy(current_task->name, buffer_name);
        current_task->name[strcspn(current_task->name, "\n")] = 0;
    }

    char buffer_description[DESCRIPTION_SIZE];
    printf("Enter new description or press enter to skip\n");
    fgets(buffer_description, sizeof(buffer_description), stdin);
    if(buffer_description[0] != '\n')
    {
        printf("Description changed\n");
        strcpy(current_task->description, buffer_description);
        current_task->description[strcspn(current_task->description, "\n")] = 0;
    }
}
