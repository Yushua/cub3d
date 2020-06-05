#include "cube.h"

void        ft_error(t_struct_m *main)
{
    // main->place.error_c_n++; //makes it so no error isn't given afterwards
    //problem with input
    if (main->place.error_c == 1)
    {
        ft_putstr("Error");   
        main->place.error_c = 0;
    }
    if (main->place.error_c == 1)
    {
        ft_putstr("you got double lines, fix your map");//putstr
        main->place.check_double = 0;
    }
    else if (main->place.error_c == 2)
        ft_putstr("unknown line in map, fix your map");
    else if (main->place.error_c == 3)
        ft_putstr("unacceptable command in line R, fix your map");
    else if (main->place.error_c == 4)
        ft_putstr("unacceptable command in line NO, fix your map");
    else if (main->place.error_c == 5)
        ft_putstr("unacceptable command in line EA, fix your map");
    else if (main->place.error_c == 6)
        ft_putstr("unacceptable command in line S, fix your map");
    else if (main->place.error_c == 7)
        ft_putstr("unacceptable command in line SO, fix your map");
    else if (main->place.error_c == 8)
        ft_putstr("unacceptable command in line WE, fix your map");
    else if (main->place.error_c == 9)
        ft_putstr("unacceptable command in line F, fix your map");
    else if (main->place.error_c == 10)
        ft_putstr("unacceptable command in line C, fix your map");
    else if (main->place.error_c == 11)
        ft_putstr("INCORRECT input of position input, fix your map");
    else if (main->place.error_c == 12)
        ft_putstr("double inputs after inputs or wrong input, fix your map");
    else if (main->place.error_c == 12)
        ft_putstr("wrong input in map, can't read map, fix your map");
    else if (main->place.error_c == 13)
        ft_putstr("problem in malloc, try again");
    else if (main->place.error_c == 14)
        ft_putstr("problem in functions, line is NULL");
    else if (main->place.error_c == 15)
        ft_putstr("map incorrect, not surroudned by 1's, top or bottom wrong");
    else if (main->place.error_c == 16)
        ft_putstr("map incorrect, not surroudned by 1's, left side wrong");
    else if (main->place.error_c == 17)
        ft_putstr("map incorrect, not surroudned by 1's, right side wrong");
    main->place.error_c = 0;
    //come sin ehre, error shoudl only happen once
}