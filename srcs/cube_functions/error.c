#include "cube.h"

void        ft_error(t_struct_m *main)
{
    // main->place.error_c_n++; //makes it so no error isn't given afterwards
    //problem with input
    if (main->place.error_c == 1)
    {
        printf("Error\n");   
        main->place.error_c = 0;
    }
    if (main->place.error_c == 1)
    {
        printf("you got double lines, fix your map\n");//putstr
        main->place.check_double = 0;
    }
    else if (main->place.error_c == 2)
        printf("unknown line in map, fix your map\n");
    else if (main->place.error_c == 3)
        printf("unacceptable command in line R, fix your map\n");
    else if (main->place.error_c == 4)
        printf("unacceptable command in line NO, fix your map\n");
    else if (main->place.error_c == 5)
        printf("unacceptable command in line EA, fix your map\n");
    else if (main->place.error_c == 6)
        printf("unacceptable command in line S, fix your map\n");
    else if (main->place.error_c == 7)
        printf("unacceptable command in line SO, fix your map\n");
    else if (main->place.error_c == 8)
        printf("unacceptable command in line WE, fix your map\n");
    else if (main->place.error_c == 9)
        printf("unacceptable command in line F, fix your map\n");
    else if (main->place.error_c == 10)
        printf("unacceptable command in line C, fix your map\n");
    else if (main->place.error_c == 11)
        printf("INCORRECT input of position input, fix your map\n");
    else if (main->place.error_c == 12)
        printf("double inputs after inputs or wrong input, fix your map\n");
    else if (main->place.error_c == 12)
        printf("wrong input in map, can't read map, fix your map\n");
    else if (main->place.error_c == 13)
        printf("problem in malloc, try again\n");
    else if (main->place.error_c == 14)
        printf("problem in functions, line is NULL\n");
    main->place.error_c = 0;
    //come sin ehre, error shoudl only happen once
}