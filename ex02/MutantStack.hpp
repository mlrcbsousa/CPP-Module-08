/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:57:20 by msousa            #+#    #+#             */
/*   Updated: 2022/04/26 20:21:36 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANT_STACK_H__
# define __MUTANT_STACK_H__

# include <iostream>
# include <stack>
# include <list>

# define LOG(x) std::cout << x << std::endl
# define ERROR(x) std::cerr << x << std::endl

// ************************************************************************** //
//                              MutantStack Class                             //
// ************************************************************************** //

// https://www.fluentcpp.com/2018/05/08/std-iterator-deprecated/
// https://stackoverflow.com/questions/525365/does-stdstack-expose-iterators
// https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_stack.h.html

template < typename T >
class MutantStack : public std::stack<T> {

public:

	MutantStack( void ) { /* no-op */ }
	MutantStack( MutantStack const & src ) { *this = src; }
	~MutantStack( void ) { /* no-op */ }
	MutantStack &	operator = ( MutantStack const & rhs )
	{
        this->std::stack<T> = rhs;
        return *this;
    }

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin( void ) { return this->c.begin(); };
    iterator end( void ) { return this->c.end(); };

};

#endif /* __MUTANT_STACK_H__ */
