/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_period.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:05:16 by adelille          #+#    #+#             */
/*   Updated: 2021/02/14 22:50:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "random.h"

int					ft_not_in_memory(unsigned long long current_seed,
										unsigned long long *mem,
										unsigned long long period)
{
	unsigned long long	i;

	i = 0;
	if (period > 0)
	{
		while (i < period && mem[i] && mem[i] != current_seed)
		{
			i++;
		}
		if (mem[i] == current_seed)
			return (FALSE);
	}
	return (TRUE);
}

// this function will find find the period of repetition of
// Xn+1 = (a * Xn + c) % m
// seed_n+1 = (mul * seed_n + inc) % mod
unsigned long long	ft_find_period(t_map map, unsigned long long base_seed)
{
	unsigned long long	period;
	unsigned long long	current_seed;
	unsigned long long	mem[map.end];
	
	period = 0;
	current_seed = base_seed;
	while (ft_not_in_memory(current_seed, &*mem, period) == TRUE && period < map.mod)
	{
		mem[period] = current_seed;
		//printf("period: %llu, seed: %llu, mul %llu, inc %llu, mod %llu\n", period, current_seed, map.mul, map.inc, map.mod);
		current_seed = (map.mul * current_seed + map.inc) % map.mod;
		period++;
	}
	return (period);
}

void					ft_init_map(t_map *map)
{
	map->mul = START;
	map->inc = START;
	map->mod = START;
	map->period = END + 1;
}

// test 5 seeds, save the average period
t_map					ft_best_map(t_map *map)
{
	t_map				best;
	
	best.period = 0;
	while (map->mul < map->end)
	{
		map->inc = map->start;
		while (map->inc < map->end)
		{
			printf("\rLoop: [%llu%%]", (map->mul * 100) / (map->end -1));
			map->mod = map->start;
			while (map->mod < map->end)
			{
				map->period = ((ft_find_period(*map, SEEDA) +
								ft_find_period(*map, SEEDB) +
								ft_find_period(*map, SEEDC) +
								ft_find_period(*map, SEEDD) +
								ft_find_period(*map, SEEDE)) / 5);
				//printf("%llu - %llu\n", map->period, best.period);
				if (map->period > best.period)
				{
					best.period = map->period;
					best.mul = map->mul;
					best.inc = map->inc;
					best.mod = map->mod;
				}
				map->mod++;
			}
			map->inc++;
		}
		map->mul++;
	}
	best.start = map->start;
	best.end = map->end;
	return (best);
}

int						ft_map(t_arg arg)
{
	t_map				map;
	unsigned long long	start;

	ft_init_map(&map);
	if (arg.lcg.bol == TRUE)
	{
		start = arg.lcg.start;
		map.start = start;
		map.end = arg.lcg.end;
		map.mul = start;
		map.inc = start;
		map.mod = start;
	}
	printf("\t\tStarting LCG\n");
	map = ft_best_map(&map);
	printf("\nThe best LCG between %llu and %llu is:\n", map.start, map.end);
	printf("\n\tMul: %llu\n\tInc: %llu\n\tMod: %llu\n",
				map.mul, map.inc, map.mod);
	printf("For a Score of: %llu%%\n", (map.period + 1) * 100 / map.end);
	if (arg.debug.bol == TRUE)
		ft_map_debug(map, arg);
	return (0);
}
