/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:11:14 by tbui-quo          #+#    #+#             */
/*   Updated: 2025/04/24 17:44:30 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>


void	test_valid_range() {
	std::cout << "=== Test valid range ===" << std::endl;
	try {
		std::vector<int> vec;
		vec.reserve(5);
		for (int i = 0; i < 5; i++) {
			vec.push_back(i);
		}
		Span sp = Span(5);
		sp.addNumber(vec.begin(), vec.end());
		sp.printSpan();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int main(void)
{
	// int temp[] = {5, 3 , 9, 10, 1, 0};
	// std::vector<int> s1(temp, temp + 6);

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.printSpan();
	sp.sortPrintSpan();
	int shortestspanres = sp.shortestSpan();
	std::cout << "shortest span: " << shortestspanres << std::endl;
	int longspanres = sp.longestSpan();
	std::cout << "longest span: " << longspanres << std::endl;
	test_valid_range();
}
