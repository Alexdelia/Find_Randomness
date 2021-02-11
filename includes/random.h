/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:10:26 by adelille          #+#    #+#             */
/*   Updated: 2021/02/11 17:20:16 by user42           ###   ########.fr       */
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

# define SEED1 2147483647
# define SEED2 991372845907
# define SEED3 284103856433
# define SEED4 83052976562
# define SEED5 4

# define START 300000000
# define END 900000000

typedef struct				s_map
{
	unsigned long long		mul;
	unsigned long long		inc;
	unsigned long long		mod;
	unsigned long long		period;
}							t_map;

unsigned long long	ft_find_period(t_map map);
void				ft_init_map(t_map *map);
t_map				ft_best_map(t_map *map, unsigned long long base_seed);
int					ft_map(int ac, char **av);

int					ft_strcmp(char *str, char *cmp);
int					ft_error(char *text);
int					ft_check(int ac, char **av);

#endif
