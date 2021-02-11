/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:10:26 by adelille          #+#    #+#             */
/*   Updated: 2021/02/11 21:07:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_H
# define RANDOM_H

# include "../libft/libft.h"

# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE 0

# define SEEDA 2147483647
# define SEEDB 991372845907
# define SEEDC 284103856433
# define SEEDD 83052976562
# define SEEDE 4

# define START 30
# define END 53

typedef struct				s_map
{
	unsigned long long		mul;
	unsigned long long		inc;
	unsigned long long		mod;
	unsigned long long		period;
	unsigned long long		start;
	unsigned long long		end;
}							t_map;

unsigned long long	ft_lcg_empty(t_map map, unsigned long long seed);

unsigned long long	ft_find_period(t_map map, unsigned long long base_seed);
void				ft_init_map(t_map *map);
t_map				ft_best_map(t_map *map);
int					ft_map(int ac, char **av);

void				ft_map_debug(t_map map, char **av);

int					ft_strcmp(char *str, char *cmp);
int					ft_error(char *text);
int					ft_check(int ac, char **av);

#endif
