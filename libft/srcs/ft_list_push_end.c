/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 19:25:26 by dhadley           #+#    #+#             */
/*   Updated: 2017/12/04 14:46:32 by dhadley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_end(t_list **begin_list, void *content)
{
	t_list	*new_elem;

	new_elem = ft_list_new_elem(content);
	if (*begin_list == NULL)
		*begin_list = new_elem;
	else
		ft_list_find_end(*begin_list)->next = new_elem;
}
