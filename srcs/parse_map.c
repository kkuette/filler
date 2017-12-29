/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 04:36:40 by tdenion           #+#    #+#             */
/*   Updated: 2016/11/03 07:07:17 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/filler.h"

t_env	*f_parse(t_env *l)
{
	char	**tmp;

	tmp = ft_strsplit(l->parse[l->r_parse], ' ');
	l->map_x = ft_atoi(tmp[2]);
	l->map_y = ft_atoi(tmp[1]);
	destroy_2dim(tmp);
	return (l);
}

t_env	*parse_map(t_env *l)
{
	char	**tmp;
	int		i;
	int		j;

	j = -1;
	i = -1;
	l = f_parse(l);
	if (!(l->map = (char**)malloc(sizeof(char*) * (l->map_y + 1))))
		exit(0);
	while (++j != l->map_y + 2)
	{
		if (ft_strchr(l->parse[l->r_parse], '.') ||
			ft_strchr(l->parse[l->r_parse], l->carac)
		|| ft_strchr(l->parse[l->r_parse], l->adv))
		{
			tmp = ft_strsplit(l->parse[l->r_parse], ' ');
			l->map[++i] = ft_strdup(tmp[1]);
			destroy_2dim(tmp);
		}
		l->r_parse++;
	}
	l->map[++i] = NULL;
	return (l);
}
