/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjullien <kjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:38:52 by kjullien          #+#    #+#             */
/*   Updated: 2024/12/02 22:59:10 by kjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include <stdio.h>
#include <stdlib.h>

int	get_number_amount(int numbers[20])
{
	int	counter;

	counter = 0;
	while (numbers[counter])
		counter++;
	return (counter);
}

int	check_ascending(int numbers[20])
{
	int	counter;
	int	numbers_amount;

	counter = 0;
	numbers_amount = get_number_amount(numbers);
	while (counter < numbers_amount - 1)
	{
		if (!(numbers[counter] < numbers[counter + 1] && numbers[counter + 1]
				- numbers[counter] <= 3))
			return (0);
		counter++;
	}
	return (1);
}

int	check_descending(int numbers[20])
{
	int	counter;
	int	numbers_amount;

	counter = 0;
	numbers_amount = get_number_amount(numbers);
	while (counter < numbers_amount - 1)
	{
		if (!(numbers[counter] > numbers[counter + 1] && numbers[counter]
				- numbers[counter + 1] <= 3))
			return (0);
		counter++;
	}
	return (1);
}

int	main(void)
{
	FILE	*file;
	char	*numbers[1000] = {0};
	int		counter;
	int		counter2;
	char	*line;
	size_t	line_len;
	int		numbers2[1000][20] = {0};
	char	*string;
	int		total;

	file = fopen("input", "r");
	counter = 0;
	while (counter < 1000)
	{
		getline(&line, &line_len, file);
		numbers[counter] = strdup(line);
		counter++;
	}
	counter = 0;
	while (counter < 1000)
	{
		counter2 = 0;
		string = strtok(strdup(numbers[counter]), " \n");
		while (string != NULL)
		{
			numbers2[counter][counter2] = strtol(string, NULL, 10);
			string = strtok(NULL, " \n");
			counter2++;
		}
		counter++;
	}
	counter = 0;
	total = 0;
	while (counter < 1000)
	{
		total += check_ascending(numbers2[counter]);
		total += check_descending(numbers2[counter]);
		counter++;
	}
	printf("[Part 1] %i", total);
}
