/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:29:11 by ykliek            #+#    #+#             */
/*   Updated: 2019/08/27 16:29:13 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_dblist	*create_dblist()
{
	t_dblist	*tmp;

	tmp = (t_dblist*)malloc(sizeof(t_dblist));
	tmp->size = 0;
	tmp->tail = NULL;
	tmp->head = tmp->tail;
	return (tmp);
}

void	delete_dblist(t_dblist **list)
{
	t_anthill	*tmp;
	t_anthill	*next;

	tmp = (*list)->head;
	next = NULL;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(*list);
	(*list) = NULL;
}

/*
 * Додавання нового елементу в початок списку
 */

void	push_front(t_data *list, t_room *room)
{
	t_anthill	*tmp;

	tmp = (t_anthill*)malloc(sizeof(t_anthill));
	if (tmp == NULL)
		exit (1);
	tmp->room = room;
	tmp->next = list->anthill->head;
	tmp->prev = NULL;
	if (list->anthill->head)
		list->anthill->head->prev = tmp;
	list->anthill->head = tmp;
	if (list->anthill->tail == NULL)
		list->anthill->tail = tmp;
	list->anthill->size++;
}

/*
 * Додавання нового елемента в кінець списку
 */

void	push_back(t_data *list, t_room *room)
{
	t_anthill	*tmp;

	tmp = (t_anthill*)malloc(sizeof(t_anthill));
	if (tmp == NULL)
		exit(2);
	tmp->room = room;
	tmp->next = NULL;
	tmp->prev = list->anthill->tail;
	if (list->anthill->tail)
		list->anthill->tail->next = tmp;
	list->anthill->tail = tmp;
	if (list->anthill->head == NULL)
		list->anthill->head = tmp;
	list->anthill->size++;
}
