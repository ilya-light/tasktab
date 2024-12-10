#include "utils.h"

int CAST_ERROR = 0;

int check_error(const char * message)
{
    if(CAST_ERROR == 1)
    {
        printf("%s", message);
        return 1;
    }
    return 0;
}

int check_scanf(int symbols_read, int symbols_need)
{
    if(symbols_need != symbols_read)
    {
        abort();
    }
}

int get_number()
{
    CAST_ERROR = 0;
    char buffer[256];
    fgets(buffer, sizeof(buffer), stdin);
    char * endptr;
    int number = strtol(buffer, &endptr, 10);
    if(endptr == buffer)
    {
        CAST_ERROR = 1;
        return 0;
    }
    else
    {
        return number;
    }
}
