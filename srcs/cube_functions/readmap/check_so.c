#include "../cube.h"

int     check_SO(t_struct_m *main, char *map, int i)
{
    int     r;

    r = 0;
    if (main->Double.D_SO > 0)
        return (1);
    else if (main->Double.D_SO == 0)
    {
        if (map[i] != 'O')
        {
            main->place.error = 7;
            ft_error(main);
            return (0);      
        }
        main->Double.D_SO++;
        i++;
        while (map[i] == ' ')
            i++;
        if (map[i] != ' ')
        {
            r = ft_strleng(map, i);
            main->place.SO = ft_substr(map, i, r);
            i = i + r;
            r = 1;
        }
        if (map[i] != '\0')
        {
            main->place.error = 7;
            ft_error(main);    
        }
    }
    return (0);
}