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

int get_level(int id)
{
    if (id < 10)
    {
        return 1;
    }

    if (id < 100)
    {
        return 2;
    }

    if (id < 1000)
    {
        return 3;
    }

    if (id < 10000)
    {
        return 4;
    }

    return 5;
}

int compare_paths(int id1, int id2)
{
    if (get_level(id1) != get_level(id2))
    {
        return 0;
    }

    switch(get_level(id1))
    {
        case 1:
            return 1;
        case 2:
            if (get_1st_level_pos(id1) == get_1st_level_pos(id2))
            {
                return 1;
            }
            return 0;
        case 3:
            if (get_1st_level_pos(id1) == get_1st_level_pos(id2) &&
                get_2nd_level_pos(id1) == get_2nd_level_pos(id2))
            {
                return 1;
            }
            return 0;
    }
}