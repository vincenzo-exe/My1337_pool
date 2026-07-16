/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 11:58:49 by vincenzo          #+#    #+#             */
/*   Updated: 2026/07/14 11:58:53 by vincenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	i;

	if (min >= max)
		return (NULL);
	array = malloc(sizeof(int) * (max - min));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < max - min)
	{
		array[i] = min + i;
		i++;
	}
	return (array);
}
