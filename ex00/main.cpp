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

#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main(void)
{
	// easyfind returns the pointer at the position where it first found the occurrence
	// 1.way to fill vector insert x times y value
	// std::vector<int> arr(10, 10); // first count of elements, second value of all elements

	// 2. way to fill vector, push manually to the vector
	// std::vector<int> arr;
	// arr.push_back(30);
	// arr.push_back(20);
	// arr.push_back(10);

	// 3. way to fill vector, do it via array
	int temp[] = {30, 20, 10};
	std::vector<int> arr(temp, temp + 3);
	try
	{
		int search_and_found = 10;
		std::vector<int>::const_iterator it = easyfind(arr, search_and_found);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const NotFoundException& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	int search_no_found = 40;

	try
	{
		std::vector<int>::const_iterator it = easyfind(arr, search_no_found);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const NotFoundException& e)
	{
		std::cout << "Occurrence: " << search_no_found << e.what() << std::endl;
	}
	return 0;

}
