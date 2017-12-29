/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_place.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 23:43:45 by tdenion           #+#    #+#             */
/*   Updated: 2016/11/03 07:03:32 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/filler.h"

int		check_place(t_env *l, int x, int y)
{
	int		p_x;
	int		p_y;
	int		t;

	t = 0;
	p_x = -1;
	p_y = -1;
	while (++p_y < l->piece_y && (p_y + y) < l->map_y)
	{
		while (++p_x < l->piece_x && (p_x + x) < l->map_x)
		{
			if (l->piece[p_y][p_x] == '*' &&
					(l->map[y + p_y][x + p_x] == l->carac
				|| l->map[y + p_y][x + p_x] == l->last_p))
				t++;
			if (l->piece[p_y][p_x] == '*' && (l->map[y + p_y][x + p_x] == l->adv
				|| l->map[y + p_y][x + p_x] == l->last_adv))
				return (0);
		}
		p_x = -1;
	}
	if (t != 1)
		return (0);
	return (1);
}

void	x_up_y_low_solve(t_env *l)
{
	int	x;
	int	y;

	y = -1;
	while (++y <= l->map_y - l->piece_y)
	{
		x = l->map_x - l->piece_x;
		while (x > -1)
		{
			if (check_place(l, x, y))
			{
				destroy_env(l);
				print_coord(x, y);
				parse_arg(l);
				return ;
			}
			x--;
		}
	}
	print_coord(0, 0);
	exit(0);
}

void	x_low_y_up_solve(t_env *l)
{
	int	x;
	int	y;

	y = l->map_y - l->piece_y;
	while (y > -1)
	{
		x = -1;
		while (++x <= l->map_x - l->piece_x)
		{
			if (check_place(l, x, y))
			{
				destroy_env(l);
				print_coord(x, y);
				parse_arg(l);
				return ;
			}
		}
		y--;
	}
	print_coord(0, 0);
	exit(0);
}

void	x_y_up_solve(t_env *l)
{
	int	x;
	int	y;

	y = l->map_y - l->piece_y;
	while (y > -1)
	{
		x = l->map_x - l->piece_x;
		while (x > -1)
		{
			if (check_place(l, x, y))
			{
				destroy_env(l);
				print_coord(x, y);
				parse_arg(l);
				return ;
			}
			x--;
		}
		y--;
	}
	print_coord(0, 0);
	exit(0);
}

void	x_y_low_solve(t_env *l)
{
	int	x;
	int	y;

	y = -1;
	while (++y <= l->map_y - l->piece_y)
	{
		x = -1;
		while (++x <= l->map_x - l->piece_x)
		{
			if (check_place(l, x, y))
			{
				destroy_env(l);
				print_coord(x, y);
				parse_arg(l);
				return ;
			}
		}
	}
	print_coord(0, 0);
	exit(0);
}
