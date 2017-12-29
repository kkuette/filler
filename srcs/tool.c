/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 09:58:53 by tdenion           #+#    #+#             */
/*   Updated: 2016/11/03 07:35:20 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/filler.h"

char	*parse_s(void)
{
	char	buf[24001];
	int		ret;
	char	*s;

	s = NULL;
	delay();
	while ((ret = read(0, buf, 24000)))
	{
		buf[ret] = '\0';
		s = ft_strfjoin(s, buf);
		if (ret < 24000)
			break ;
	}
	return (s);
}

void	solve(t_env *l)
{
	l = search_adv_last(l);
	search_start(l);
}

void	search_start(t_env *l)
{
	int		x;
	int		y;

	x = l->map_x - l->adv_last_x;
	y = l->map_y - l->adv_last_y;
	if (x <= (l->map_x / 2) && y <= (l->map_y / 2))
		x_y_up_solve(l);
	else if (x <= (l->map_x / 2) && y >= (l->map_y / 2))
		x_up_y_low_solve(l);
	else if (x >= (l->map_x / 2) && y <= (l->map_y / 2))
		x_low_y_up_solve(l);
	else if (x >= (l->map_x / 2) && y >= (l->map_y / 2))
		x_y_low_solve(l);
}

t_env	*search_adv_last(t_env *l)
{
	l->adv_last_y = 0;
	while (l->map[l->adv_last_y])
	{
		l->adv_last_x = 0;
		while (l->map[l->adv_last_y][l->adv_last_x])
		{
			if (l->last_map)
			{
				if (l->map[l->adv_last_y][l->adv_last_x] == l->adv &&
						l->last_map[l->adv_last_y][l->adv_last_x] == '.')
					return (l);
			}
			else if (l->map[l->adv_last_y][l->adv_last_x] == l->adv)
				return (l);
			l->adv_last_x++;
		}
		l->adv_last_y++;
	}
	return (l);
}
