/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:04:01 by sleonard          #+#    #+#             */
/*   Updated: 2019/10/23 15:37:04 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btrees.h"

void	btree_insert_data(t_btree **root, void *item, int (*cmpfunc)(void *, void *))
{
	if (!root)
		return ;
	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	if (cmpfunc(item, (*root)->data) >= 0)
		btree_insert_data(&((*root)->right), item, cmpfunc);
	else
		btree_insert_data(&((*root)->left), item, cmpfunc);
}
