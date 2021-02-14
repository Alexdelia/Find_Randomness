/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <adelille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 21:14:52 by user42            #+#    #+#             */
/*   Updated: 2021/02/14 22:16:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_map_perf(t_arg arg)
{
	t_map	map;

	ft_init_map(&map);
	if (arg.perf.bol == TRUE)
		map.end = arg.perf.end;
	map.mul = arg.perf.end * (1 / 3);
	map.inc = 2;
	map.mod = arg.perf.end;
	ft_putstr_fd("\t\tStarting LCG performance\n", 1);
	map = ft_best_map_perf(&map);
	ft_putstr_fd("\nThe best LCG found is:\n", 1);
	printf("\n\tMul: %llu\n\tInc: %llu\n\tMod: %llu\n",
				map.mul, map.inc, map.mod);
	printf("For a Score of: %llu%%\n", (map.period + 1) * 100 / map.end);
	if (arg.debug.bol == TRUE)
		ft_map_debug(map);
	return (0);
}
