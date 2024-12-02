#include <menu_helper.h>

int get_1st_level_pos(int id)
{
    return id % 10;
}

int get_2nd_level_pos(int id)
{
    if (id < 10)
    {
        return -1;
    }

    id /= 10;
    return id % 10;
}

int get_3rd_level_pos(int id)
{
    if (id < 100)
    {
        return -1;
    }

    id /= 100;
    return id % 10;
}

int get_4th_level_pos(int id)
{
    if (id < 1000)
    {
        return -1;
    }

    id /= 1000;
    return id % 10;
}

int get_5th_level_pos(int id)
{
    if (id < 10000)
    {
        return -1;
    }

    id /= 10000;
    return id % 10;
}

int get_last_level_pos(int id)
{
    while (id > 10)
    {
        id /= 10;
    }

    return id % 10;
}
