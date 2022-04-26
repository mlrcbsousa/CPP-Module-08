/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:03:26 by msousa            #+#    #+#             */
/*   Updated: 2022/04/26 20:27:01 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main( void )
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	LOG(mstack.top());

	mstack.pop();

	LOG(mstack.size());

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		LOG(*it);
		++it;
	}
	std::stack<int> s(mstack);

	LOG("===========================================");

	MutantStack<std::string> strings;

	strings.push("Hello");
	strings.push("world");
	strings.push("!");

	MutantStack<std::string>::iterator it_s = strings.begin();
	MutantStack<std::string>::iterator ite_s = strings.end();
	++it_s;
	--it_s;
	while (it_s != ite_s)
	{
		LOG(*it_s);
		++it_s;
	}
	std::stack<std::string> strs(strings);

	LOG("===========================================");

	std::list<int> list;

	list.push_back(5);
	list.push_back(17);

	LOG(list.size());

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	//[...]
	list.push_back(0);

	std::list<int>::iterator it_l = list.begin();
	std::list<int>::iterator ite_l = list.end();
	++it_l;
	--it_l;
	while (it_l != ite_l)
	{
		LOG(*it_l);
		++it_l;
	}
	std::list<int> l(list);

  	return 0;
}
