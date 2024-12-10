#include "array.h"

extern int id_count;

static void copy_elements(struct task* from, struct task* to, int size)
{
    for (int i = 0; i < size; i++)
    {
        to[i] = from[i];
    }   
}

static void resize_array(struct task_dynamic_array * array)
{
    struct task* ptr = array->ptr;

    array->capacity = array->capacity * GOLD + 1;
    array->ptr = (struct task*)calloc(sizeof(struct task), array->capacity);
    
    copy_elements(ptr, array->ptr, array->size);
    free(ptr);

#if DEBUG
    printf("Array resized. Capacity: %d\n", array->capacity);
#endif

}

struct task_dynamic_array * create_dynamic_array(int capacity)
{
    struct task_dynamic_array* array = (struct task_dynamic_array*)malloc(sizeof(struct task_dynamic_array));
    array->ptr = (struct task*)calloc(sizeof(struct task), capacity);
    array->size = 0;
    array->capacity = capacity;

#if DEBUG
    printf("Array created. Capacity: %d\n", capacity);
#endif

    return array;
}

void free_task_array(struct task_dynamic_array* array)
{

    free(array->ptr);
    free(array);
}

struct task_dynamic_array * add_to_array(struct task_dynamic_array * array, struct task* new_task)
{
    if(array->size == array->capacity)
    {
        resize_array(array);
    }
    array->ptr[array->size] = *new_task;
    array->size += 1;
    return array;
}

int find(struct task_dynamic_array * array, int id)
{
    for (int i = 0; i < array->size; i++)
    {
        if(array->ptr[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

int delete_from_array(struct task_dynamic_array * array, int id)
{
    int index = find(array, id);
    if(index == -1)
    {
        return index;
    }
    array->size -= 1;

    // offset
    for (int i = index; i < array->size; i++)
    {
        array->ptr[i] = array->ptr[i+1];
    } 
    return id;
}

void show_array(struct task_dynamic_array * array)
{
    printf("ID\t%*s\t%*s\t%*s\n",
      PRIORITY_LENGHT, "Priority",
      NAME_SIZE, "Name",
      DESCRIPTION_SIZE, "Description");
    for (int i = 0; i < array->size; i++)
    {
        print_task(&array->ptr[i]);
    }  
}

int write_to_file(char * filename, struct task_dynamic_array * array)
{
    FILE *file = fopen(filename, "w");
    if(file == NULL)
    {
        printf("Error opening file\n");
        return EXIT_FAILURE;
    }
    fprintf(file, "%d\n", id_count);
    for (int i = 0; i < array->size; i++)
    {
        fprintf(file, "%s", task_to_str(&array->ptr[i]));
    }
    fclose(file);
}

int read_from_file(char * filename, struct task_dynamic_array * array)
{
    FILE *file = fopen(filename, "r");
    if(file == NULL)
    {
        printf("Error opening file\n");
        return EXIT_FAILURE;
    }
    char line[256];
    if(fgets(line, sizeof(line), file) != NULL)
    {
        id_count = strtol(line, NULL, 10);
    }
    while(fgets(line, sizeof(line), file) != NULL)
    {
        add_to_array(array, parse(line));
    }
    fclose(file);
}
