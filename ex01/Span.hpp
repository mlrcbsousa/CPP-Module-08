/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:37:27 by msousa            #+#    #+#             */
/*   Updated: 2022/04/24 23:32:14 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN_H__
# define __SPAN_H__

# include <iostream>
# include <algorithm>
# include <list>
# include <vector>

# define LOG(x) std::cout << x << std::endl
# define ERROR(x) std::cerr << x << std::endl

typedef std::list<int>	ints_t;

// ************************************************************************** //
//                               Span Class                             	  //
// ************************************************************************** //

class Span {

public:

	class ListFullException : public std::exception {
	public:
		virtual const char*	what( void ) const throw();
	};

	class NoSpanFoundException : public std::exception {
	public:
		virtual const char*	what( void ) const throw();
	};

	Span( void );
	Span( Span const & src );
	~Span( void );
	Span &	operator = ( Span const & rhs );
	Span( uint N );

	uint	getN( void ) const;
	ints_t	getList( void ) const;

	void	addNumber( int n );
	int		shortestSpan( void );
	int		longestSpan( void );

	template< typename Range >
	void	addNumber( Range range )
	{
		if (list.size() + range.size() > N)
			throw Span::ListFullException();

		list.insert(list.end(), range.begin(), range.end());
	}

private:

	ints_t	list;
	uint	N;

};

std::ostream &	operator << ( std::ostream & o, Span const & i );

#endif /* __SPAN_H__ */
