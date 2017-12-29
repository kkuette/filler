/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 06:03:19 by tdenion           #+#    #+#             */
/*   Updated: 2016/11/02 10:42:34 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/filler.h"

t_env	*parse_piece(t_env *l)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_strsplit(l->parse[l->r_parse], ' ');
	l->piece_x = ft_atoi(tmp[2]);
	l->piece_y = ft_atoi(tmp[1]);
	destroy_2dim(tmp);
	l->r_parse++;
	if (!(l->piece = (char**)malloc(sizeof(char*) * (l->piece_y + 1))))
		exit(0);
	while (i < l->piece_y)
	{
		l->piece[i] = ft_strdup(l->parse[l->r_parse]);
		i++;
		l->r_parse++;
	}
	l->piece[i] = NULL;
	destroy_2dim(l->parse);
	return (l);
}
