/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_info_parser_check.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/03 11:30:34 by ybakker       #+#    #+#                 */
/*   Updated: 2020/07/08 12:00:49 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static void	ft_check_parser_if_there(t_struct_m *main)
{
	if (main->doublle.d_r != 1)
		ft_putstr("R is not found");
	if (main->doublle.d_so != 1)
		ft_putstr("so is not found");
	if (main->doublle.d_s != 1)
		ft_putstr("S is not found");
	if (main->doublle.d_f != 1)
		ft_putstr("F is not found");
	if (main->doublle.d_no != 1)
		ft_putstr("NO is not found");
	if (main->doublle.d_ea != 1)
		ft_putstr("EA is not found");
	if (main->doublle.d_we != 1)
		ft_putstr("WE is not found");
	if (main->doublle.d_c != 1)
		ft_putstr("C is not found");
}

int			ft_info_parser_check(t_struct_m *main)
{
	int		i;

	i = 0;
	ft_check_parser_if_there(main);
	if (main->doublle.d_r != 1 || main->doublle.d_no != 1
	|| main->doublle.d_so != 1 || main->doublle.d_ea != 1
	|| main->doublle.d_s != 1 || main->doublle.d_we != 1
	|| main->doublle.d_f != 1 || main->doublle.d_c != 1)
	{
		ft_putstr(" not enough information");
		ft_end_function(main);
	}
	i = 1;
	return (0);
}
