/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 13:15:47 by vincenzo          #+#    #+#             */
/*   Updated: 2026/07/11 13:29:49 by vincenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	draw_line(int x, char first, char middle, char last)
{
	int	col;

	col = 0;
	while (col < x)
	{
		if (col == 0)
			ft_putchar(first);
		else if (col == x - 1)
			ft_putchar(last);
		else
			ft_putchar(middle);
		col++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	row;

	if (x <= 0 || y <= 0)
		return ;
	row = 0;
	while (row < y)
	{
		if (row == 0 || row == y - 1)
			draw_line(x, 'A', 'B', 'C');
		else
			draw_line(x, 'B', ' ', 'B');
		row++;
	}
}
