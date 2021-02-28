/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:10:26 by adelille          #+#    #+#             */
/*   Updated: 2021/02/28 17:57:36 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_H
# define RANDOM_H

# include "../libft/libft.h"

# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

// For getrusage
//# include <sys/time.h>
//# include <sys/resource.h>

# define TRUE 1
# define FALSE 0

# define SEEDA 2147483647
# define SEEDB 991372845907
# define SEEDC 284103856433
# define SEEDD 83052976562
# define SEEDE 4

# define START 2
# define END 200
# define PERF 1000

# define dlcg(seed, mul, inc, mod) (((mul) * (seed) + (inc)) % (mod))

typedef struct				s_map
{
	unsigned long long		seed;
	unsigned long long		mul;
	unsigned long long		inc;
	unsigned long long		mod;
	unsigned long long		period;
	unsigned long long		start;
	unsigned long long		end;
}							t_map;

typedef struct				s_arg_data
{
	int						bol;
	unsigned long long		start;
	unsigned long long		end;
	t_map					map;
}							t_ad;

typedef struct				s_arg
{
	t_ad					lcg;
	t_ad					perf;
	t_ad					debug;
	t_ad					mem;
	t_ad					bin;

}							t_arg;

int					ft_arg(t_arg *arg, int ac, char **av);

unsigned long long	ft_lcg_empty(t_map map, unsigned long long seed);

unsigned long long	ft_find_period(t_map map, unsigned long long base_seed);
void				ft_init_map(t_map *map);
t_map				ft_best_map(t_map *map);
t_map				ft_map(t_arg arg);
t_map				ft_map_perf(t_arg arg);

void				ft_map_debug(t_map map, t_arg arg);

int					ft_strcmp(char *str, char *cmp);
int					ft_error(char *text);
int					ft_check(t_arg arg, int ac, char **av);

void				ft_binary_show(t_map map);

#endif
