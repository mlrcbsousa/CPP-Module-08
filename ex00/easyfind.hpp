/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:36:20 by msousa            #+#    #+#             */
/*   Updated: 2022/04/23 22:33:54 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASYFIND_H__
# define __EASYFIND_H__

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>

# define LOG(x) std::cout << x << std::endl
# define ERROR(x) std::cerr << x << std::endl

template< typename T >
int &	easyfind(T & container, int n)
{
	typename T::iterator it;

	it = find(container.begin(), container.end(), n);

	if (it == container.end())
		throw std::exception();

	return *it;
}

#endif
