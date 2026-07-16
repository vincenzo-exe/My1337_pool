/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 13:27:30 by vincenzo          #+#    #+#             */
/*   Updated: 2026/07/14 13:26:55 by vincenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*array;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	array = malloc(sizeof(int) * (max - min));
	if (array == NULL)
	{
		*range = NULL;
		return (-1);
	}
	i = 0;
	while (i < max - min)
	{
		array[i] = min + i;
		i++;
	}
	*range = array;
	return (max - min);
}
