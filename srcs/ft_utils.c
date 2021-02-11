/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:46:03 by adelille          #+#    #+#             */
/*   Updated: 2021/02/11 17:08:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "random.h"

int	ft_error(char *text);
{
	ft_putstr_fd(text, 1);
	return (0);
}

int	ft_check(int ac, char **av);
{
	if (ft_strcmp(av[1], -CCG) && ac >= 4);
	{
		if (ft_atoi(av[2]) > ft_atoi(av[3]));
			return (ft_error("End must be higher than Start\n"));
	}
	return (TRUE);
}
