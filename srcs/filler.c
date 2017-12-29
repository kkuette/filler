/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 02:09:45 by tdenion           #+#    #+#             */
/*   Updated: 2016/11/03 07:13:07 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/filler.h"

int		main(void)
{
	t_env	*l;

	l = NULL;
	l = init_env();
	l = parse_arg(l);
	return (0);
}

void	delay(void)
{
	int	j;
	int	k;
	int	i;

	i = 0;
	j = 0;
	k = 0;
	while (++i < 400)
	{
		while (++j < 500)
		{
			while (k < 600)
				k++;
			k = 0;
		}
		j = 0;
	}
}

t_env	*parse_arg(t_env *l)
{
	int		i;
	char	*s;

	s = parse_s();
	i = 0;
	l->parse = ft_strsplit(s, '\n');
	free(s);
	while (++i < 4)
	{
		if (!ft_strncmp("$$$", l->parse[l->r_parse], 3))
			l = select_carac(select_player(l->parse[l->r_parse]), l);
		if (!ft_strncmp("Plateau", l->parse[l->r_parse], 7))
			l = parse_map(l);
		if (!ft_strncmp("Piece", l->parse[l->r_parse], 5))
			solve(parse_piece(l));
		l->r_parse++;
	}
	return (l);
}

t_env	*select_carac(int player, t_env *l)
{
	if (player == 1)
	{
		l->carac = 'O';
		l->last_p = 'o';
		l->adv = 'X';
		l->last_adv = 'x';
	}
	if (player == 2)
	{
		l->carac = 'X';
		l->last_p = 'x';
		l->adv = 'O';
		l->last_adv = 'o';
	}
	return (l);
}

int		select_player(char *s)
{
	int		i;

	i = 0;
	while (s[i] != 'p')
		i++;
	if (s[++i] == '1')
		return (1);
	else
		return (2);
}
