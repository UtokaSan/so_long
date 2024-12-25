/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:21:41 by fboulbes          #+#    #+#             */
/*   Updated: 2024/11/19 15:02:39 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_element;
	void	*content;

	new_list = NULL;
	while (lst != NULL)
	{
		content = f(lst->content);
		if (!content)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_element = ft_lstnew(content);
		if (!new_element)
		{
			del(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_element);
		lst = lst->next;
	}
	return (new_list);
}

/*
void	print_list(t_list *lst)
{
	while (lst != NULL)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

void	del_content(void *content)
{
	free(content);
}

void	*to_lower(void *content)
{
	char	*str;
	int		i;
	char	*new_str;

	str = (char *)content;
	new_str = ft_strdup(str);
	if (!new_str)
		return (NULL);
	i = 0;
	while (new_str[i] != '\0')
	{
		new_str[i] = ft_tolower(str[i]);
		i++;
	}
	return (new_str);
}

int	main(void)
{
	t_list	*lst;
	t_list	*new_lst;

	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("SS")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("TEST")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("JE SAIS")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("PAS")));
	printf("lst :");
	print_list(lst);
	new_lst = ft_lstmap(lst, to_lower, del_content);
	printf("nw_lst : ");
	print_list(new_lst);
	ft_lstclear(&lst, del_content);
	ft_lstclear(&new_lst, del_content);
}
*/
