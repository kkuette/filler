/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 02:36:25 by tdenion           #+#    #+#             */
/*   Updated: 2016/11/03 07:02:52 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/filler.h"

t_env	*init_env(void)
{
	t_env	*l;

	if (!(l = (t_env*)malloc(sizeof(t_env))))
		exit(0);
	l->parse = NULL;
	l->map = NULL;
	l->last_map = NULL;
	l->piece = NULL;
	l->map_x = 0;
	l->map_y = 0;
	l->piece_x = 0;
	l->piece_y = 0;
	l->r_parse = 0;
	return (l);
}

void	destroy_2dim(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	s = NULL;
}

char	**map_cpy(char **s, t_env *l)
{
	int		i;
	char	**tmp;

	i = 0;
	if (!(tmp = (char**)malloc(sizeof(char*) * l->map_y + 1)))
		exit(0);
	while (s[i])
	{
		tmp[i] = ft_strdup(s[i]);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

void	destroy_env(t_env *l)
{
	if (l->last_map != NULL)
		destroy_2dim(l->last_map);
	l->last_map = map_cpy(l->map, l);
	destroy_2dim(l->map);
	destroy_2dim(l->piece);
	l->r_parse = 0;
}
