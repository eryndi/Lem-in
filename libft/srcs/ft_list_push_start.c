/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_start.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 19:23:17 by dhadley           #+#    #+#             */
/*   Updated: 2017/12/01 19:28:01 by dhadley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_start(t_list **begin_list, void *content)
{
	t_list *new_head;
	
	new_head = ft_list_new_elem(content);
	new_head->next = *begin_list;
	*begin_list = new_head;
}
