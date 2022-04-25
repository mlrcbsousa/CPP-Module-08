/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:37:20 by msousa            #+#    #+#             */
/*   Updated: 2022/04/24 23:01:56 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* Exceptions */
const char*	Span::ListFullException::what( void ) const throw()
{ return "list is full"; }

const char*	Span::NoSpanFoundException::what( void ) const throw()
{ return "no span found"; }

/* Constructors */
Span::Span( void ) : N(0) { /* no-op */ }
Span::Span( uint N ): N(N) { /* no-op */ }
Span::Span( Span const & src ) { *this = src; }

/* Destructor */
Span::~Span( void ) { /* no-op */ }

/* Assignment operator */
Span &	Span::operator = ( Span const & rhs )
{
	if (this != &rhs) {
		N = rhs.getN();
		list = ints_t(rhs.getList());
	}
	return *this;
}

uint	Span::getN( void ) const { return N; }
ints_t	Span::getList( void ) const { return list; }

void	Span::addNumber( int n )
{
	if (list.size() == N)
		throw Span::ListFullException();

	list.push_back(n);
}

int		Span::shortestSpan( void )
{
	if (list.size() < 2)
		throw Span::NoSpanFoundException();

	ints_t 				sorted(list);
	sorted.sort();

	int 				previous = sorted.front();
	ints_t::iterator 	it = sorted.begin();
	it++;
	int 				span = *it - previous;

	for (; it != sorted.end(); it++) {
		if (*it - previous < span)
			span = *it - previous;
		previous = *it;
    }

	return span;
}

int		Span::longestSpan( void )
{
	if (list.size() < 2)
		throw Span::NoSpanFoundException();

	ints_t	sorted(list);
	sorted.sort();

	return sorted.back() - sorted.front();
}

/* ostream override */
std::ostream &	operator << ( std::ostream & o, Span const & span )
{
	ints_t				list = span.getList();

	o << "[ ";

	if (list.size()) {
		ints_t::iterator	end = list.end();
		ints_t::iterator	it = list.begin();

		end--;
		for (; it != end; it++)
			o << *it << ", ";
		o << list.back();
	}

	o << " ]";

	return o;
}
