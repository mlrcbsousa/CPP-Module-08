/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:03:26 by msousa            #+#    #+#             */
/*   Updated: 2022/04/25 17:51:38 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main( void )
{
	Span sp = Span(7);

	try { sp.shortestSpan(); }
	catch( Span::NoSpanFoundException &e ) { ERROR(e.what()); }

	sp.addNumber(6);

	try { sp.longestSpan(); }
	catch( Span::NoSpanFoundException &e ) { ERROR(e.what()); }

	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	LOG(sp.shortestSpan());
	LOG(sp.longestSpan());
	LOG(sp);

	std::vector<int>	vector(2, 30);

	sp.addNumber(vector);
	LOG(sp);

	try { sp.addNumber(11); }
	catch( Span::ListFullException &e ) { ERROR(e.what()); }

	std::vector<int> 	zeroes(10000, 0);

	sp = Span(11000);
	sp.addNumber(zeroes);
	LOG(sp);

  	return 0;
}
