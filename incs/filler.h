/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 02:08:12 by tdenion           #+#    #+#             */
/*   Updated: 2016/11/03 07:35:55 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../lib/includes/get_next_line.h"
# include "../lib/includes/ft_printf.h"
# include "../lib/includes/libft.h"

typedef	struct	s_env
{
	int			map_x;
	int			map_y;
	int			piece_x;
	int			piece_y;
	int			r_parse;
	int			adv_last_x;
	int			adv_last_y;
	char		last_p;
	char		carac;
	char		**parse;
	char		**map;
	char		**last_map;
	char		**piece;
	char		adv;
	char		last_adv;
}				t_env;

t_env			*init_env();
void			destroy_env(t_env *l);
int				select_player(char *s);
t_env			*select_carac(int player, t_env *l);
t_env			*parse_map(t_env *l);
t_env			*parse_piece(t_env *l);
void			print_coord(int x, int y);
int				check_place(t_env *l, int x, int y);
void			solve(t_env *l);
t_env			*parse_arg(t_env *l);
void			destroy_2dim(char **s);
t_env			*search_adv_last(t_env *l);
void			search_start(t_env *l);
void			x_y_up_solve(t_env *l);
void			x_y_low_solve(t_env *l);
void			x_up_y_low_solve(t_env *l);
void			x_low_y_up_solve(t_env *l);
char			**map_cpy(char **s, t_env *l);
t_env			*f_parse(t_env *l);
char			*parse_s();
void			delay();

#endif
