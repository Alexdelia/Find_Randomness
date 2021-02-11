/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_period.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:05:16 by adelille          #+#    #+#             */
/*   Updated: 2021/02/11 16:02:32 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "random.h"

// this function will find find the period of repetition of
// Xn+1 = (a * Xn + c) % m
// seed_n+1 = (mul * seed_n + inc) % mod
unsigned long long	ft_find_period(t_map map)
{
	unsigned long long	period;
	unsigned long long	base_seed;
	unsigned long long	current_seed;
	
	period = 0;
	current_seed = base_seed;
	while (current_seed != base_seed && period > 0)
	{
		current_seed = (map.mul * current_seed + map.inc) % map.mod;
		period++;
	}
	return (period);
}

void					ft_init_map(t_map *map);
{
	map->mul = START;
	map->inc = START;
	map->mod = START;
	map->period = END + 1;
}

// test 5 seeds, save the average period
t_map					ft_best_map(t_map *map)
{
	t_map	best;

	best.mul = map.mul;
	best.inc = map.inc;
	best.mod = map.mod;
	best.period = 0;
	while (map.mul < map.end)
	{
		while (map.inc < map.end)
		{
			while (map.mod < map.end)
			{
				map.period = ((ft_find_period(map, SEED1) +
								ft_find_period(map, SEED2) +
								ft_find_period(map, SEED3) +
								ft_find_period(map, SEED4) +
								ft_find_period(map, SEED5)) / 5);
				if (map.period > best.period)
					best.period = map.period;
				map.mod++;
			}
			map.inc++;
		}
		map.mul++;
		printf("\rLoop: [%d%%]", (map.mull * 100) / map.end);
	}
	return (best);
}

int						ft_map(int ac, char **av)
{
	t_map				map;

	ft_init_map(&map);
	if (ac == 4)
	{
		map.start = ft_atoi(av[2]);
		map.start = ft_atoi(av[3]);
	}
	printf("\t\tStarting CCG\n");
	ft_best_map(&map);
	printf("The best CCG between %d and %d is:\n", map.start, map.end);
	printf("\n\tMul: %d'\n\tInc: %d\n\tMod: %d\n",
				map.mul, map.inc, map.mod);
	printf("For a Score of: %d\n", map.period);
	return (0);
}
