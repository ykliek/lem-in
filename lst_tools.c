/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 11:57:12 by ykliek            #+#    #+#             */
/*   Updated: 2019/05/12 11:57:14 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_links		*create_list()
{
	t_links	*lt;

	lt = (t_links *)malloc(sizeof(t_links));
	lt->size = 0;
	lt->head = NULL;
	lt->tail = lt->head;
	return (lt);
}

void		list_push(t_links *lt, t_link link)
{
	t_links_node	*node;

	node = (t_links_node *)malloc(sizeof(t_links_node));
	node->link = link;
	node->next = lt->head;
	lt->head = node;
	lt->size += 1;
}

void		list_push_back(t_links *lt, t_link link)
{
	t_links_node	*node;

	node = (t_links_node *)malloc(sizeof(t_links_node));
	node->link = link;
	if(lt->tail != NULL)
		lt->tail->next = node;
	else
		lt->head = node;
	lt->tail = node;
	lt->size += 1;
}
