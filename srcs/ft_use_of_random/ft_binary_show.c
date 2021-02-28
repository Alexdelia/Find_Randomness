/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_show.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 16:43:33 by adelille          #+#    #+#             */
/*   Updated: 2021/02/28 17:41:39 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "random.h"

void	ft_binary_show(t_map map)
{
	unsigned long long	right;
	unsigned long long	left;
	int					i;

	ft_ps("\tStarting binary visualization\n");
	ft_ps("  0\t\t  1\n");
	right = 0;
	left = 0;
	i = 100;
	while (--i)
	{
		if (map.seed % 1)
			right++;
		else
			left++;
		printf("\r%lld\t%c-%c\t%lld\t\t%llu", left,
				(map.seed % 1 ? ' ' : '<'),
				(map.seed % 1 ? '>' : ' '),
				right, map.seed);
		map.seed = dlcg(map.seed, map.mul, map.inc, map.mod);
		sleep(0.4);
		printf("\r\t - \t\t\t\t                 ");
	}
	printf("\nDone\n");
}
