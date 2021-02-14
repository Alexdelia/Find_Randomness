/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:05:06 by adelille          #+#    #+#             */
/*   Updated: 2021/02/11 21:26:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "random.h"

int	main(int ac, char **av)
{
	if (ft_check(ac, av) == FALSE)
		return (0);
	if (!(ft_strcmp(av[1], "-LCG")))
		ft_map(ac, av);
	return (0);
}

// plan to do a very improved version of the LCG finder, and add a visualisation of point found.
