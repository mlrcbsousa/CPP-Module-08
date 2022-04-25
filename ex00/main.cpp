/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:03:26 by msousa            #+#    #+#             */
/*   Updated: 2022/04/23 22:39:20 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

typedef std::vector<int> intv;
typedef std::list<int> intl;

int	main( void )
{
	int		array[] = { 10, 20, 30, 40 };
  	intv	numbers(array, array + 4);
  	intl	empty;

	try {
		LOG(easyfind< intl >(empty, 2));
	}
	catch( std::exception &e ) { ERROR("not found"); }

	LOG(easyfind< intv >(numbers, 20));

  	try {
		LOG(easyfind< intv >(numbers, 2));
	}
	catch( std::exception &e ) { ERROR("not found"); }

  	return 0;
}
