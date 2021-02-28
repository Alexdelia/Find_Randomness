/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:46:03 by adelille          #+#    #+#             */
/*   Updated: 2021/02/28 16:59:27 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "random.h"

int	ft_strcmp(char *str, char *cmp)
{
	int	i;

	i = 0;
	while (str[i] && cmp[i] && str[i] == cmp[i])
		i++;
	return (str[i] - cmp[i]);
}

int	ft_error(char *text)
{
	ft_putstr_fd(text, 1);
	return (0);
}

int	ft_check(t_arg arg, int ac, char **av)
{
	(void)ac;
	(void)av;
	if (arg.lcg.bol == 1 && arg.lcg.start > arg.lcg.end)
		return (ft_error("End must be higher than Start\n"));
	if (arg.perf.end < 30)
		return (ft_error("Value under 30 for performance version will give very bad result.\nPlease, use something near or way over 1000 for better result.\n"));
	if (arg.perf.end < 100)
		ft_putstr_fd("!!!\tValue under 100, the program might have a floating point exception\t!!!\n", 1);
	return (TRUE);
}
