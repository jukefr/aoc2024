/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjullien <kjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 21:03:01 by kjullien          #+#    #+#             */
/*   Updated: 2024/12/01 23:18:44 by kjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	t_list	*list;
	t_list	*current;
	size_t	counter;
	int		*left;
	int		*right;
	int		*extracted;
	int		total;

	list = NULL;
	read_file_to_list("input", &list);
	current = list;
	counter = 0;
	left = malloc(sizeof(int) * list_length(&list));
	right = malloc(sizeof(int) * list_length(&list));
	while (counter < list_length(&list))
	{
		extracted = get_numbers_from_line(current->content);
		left[counter] = extracted[0];
		right[counter] = extracted[1];
		free(extracted);
		current = current->next;
		counter++;
	}
	qsort(left, list_length(&list), sizeof(int), compare);
	qsort(right, list_length(&list), sizeof(int), compare);
	counter = 0;
	total = 0;
	while (counter < list_length(&list))
	{
		if (left[counter] > right[counter])
			total += left[counter] - right[counter];
		else
			total += right[counter] - left[counter];
		counter++;
	}
	printf("%i\n", total);
	return (0);
}
