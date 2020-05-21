#include "../cube.h"

int     check_NO(t_struct_m *main, char *map, int i)
{
    int     r;

    r = 0;
    if (main->Double.D_NO > 0)
        return (1);
    else if (main->Double.D_NO == 0)
    {
        if (map[i] != 'O')
        {
            main->place.error = 4;
            ft_error(main);
            return (0);      
        }
        main->Double.D_NO = 1;
        i++;
        while (map[i] == ' ')
            i++;
        if (map[i] != ' ')
        {
            r = ft_strleng(map, i);
            main->place.NO = ft_substr(map, i, r);
            i = i + r;
        }
        if (map[i] != '\0')
        {
            main->place.error = 5;
            ft_error(main);    
        }
    }
    return (0);
}