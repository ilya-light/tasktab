#include "main.h"

int id_count = 0;

int show_tasks(struct task_dynamic_array* task_array)
{
    printf("=======SHOW TASKS=======\n");
    show_array(task_array);
}

int add_task(struct task_dynamic_array* task_array)
{
    printf("=======ADD TASK=======\n");
    struct task* new_task = create_task();
    add_to_array(task_array, new_task);
}

int delete_task(struct task_dynamic_array* task_array)
{
    printf("=======DELETE TASK=======\n");
    printf("Enter id task for delete\n");
    
    int id = get_number();
    while(check_error("Enter correct id\n"))
    {
        id = get_number();
    }

    if(delete_from_array(task_array, id) != -1)
    {
        printf("Task %d deleted succesfully\n", id);
        return id;
    }
    else
    {
        printf("No task with id %d\n", id);
        return -1;
    }
}

int edit_task(struct task_dynamic_array* task_array)
{
    printf("=======EDIT TASK=======\n");
    printf("Enter id task for edit\n");


    int id = get_number();
    while(check_error("Enter correct id\n"))
    {
        id = get_number();
    }    
    
    int index = find(task_array, id);
    if(index == -1)
    {
        printf("No task with id %d\n", id);
        return -1;
    }
    struct task* current_task = &task_array->ptr[find(task_array, id)];
    print_task(current_task);

    change_task_fields(current_task);
    return id;
}

void print_options()
{
    printf("1 - show tasks\n"
            "2 - add task\n"
            "3 - edit task\n"
            "4 - delete task\n"
            "0 - exit\n");
}

//Обработать ситуацию с переполнение буффера
int main()
{
    int option = 0;
    int input = 0;
    struct task_dynamic_array* task_array = create_dynamic_array(2);
    if(read_from_file("resourses/tasks.txt", task_array) == 1)
    {
        printf("Something went wrong during reading from file\n");
        return 1;
    }
    for(;;)
    {
        print_options();
        option = get_number();
        if(check_error("Enter correct option\n"))
        {
            continue;
        }
        printf("You've chosen option %d\n", option);

        switch (option)
        {
        case 1:
            show_tasks(task_array);
            break;
        case 2:
            add_task(task_array);
            break;
        case 3:
            edit_task(task_array);
            break;
        case 4:
            delete_task(task_array);
            break;
        case 0:
            if(write_to_file("tasks.txt", task_array) == 1)
            {
                printf("Something went wrong during writing to file\n");
                return 1;
            }
            free_task_array(task_array);
            return 0;
        default:
            printf("Wrong option\n");
            print_options();
            break;
        }
    }
}
