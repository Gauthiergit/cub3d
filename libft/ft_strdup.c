/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:02:54 by gpeyre            #+#    #+#             */
/*   Updated: 2023/10/03 11:02:54 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char	*src)
{
	char	*newstr;
	int		str_len;
	int		i;

	i = 0;
	str_len = ft_strlen(src);
	newstr = malloc(sizeof(char) * (str_len + 1));
	if (newstr == NULL)
		return (NULL);
	while (i < str_len)
	{
		newstr[i] = src[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}


/* char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
} */
/*#include <stdio.h>
int	main(void)
{
	char	src[] = "Je suis vengeance";
	char* dest = ft_strdup(src);

	printf("%s\n", dest);

	free(dest);
	return (0);
}*/