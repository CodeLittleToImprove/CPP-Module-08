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
#include <vector> // for vector container
#include <list> // for vector container
#include <iostream>

// Helper function to test searching
template <typename Container, typename T>
void test_search(Container &c, T &value)
{
	try
	{
		typename Container::iterator it = easyfind(c, value);
		std::cout << "Found " << value << " at position "
				  << std::distance(c.begin(), it) << std::endl;
	}
	catch (const NotFoundException& e)
	{
		std::cout << "Value " << value << " not found: " << e.what() << std::endl;
	}
}

//overload for helper function const containers
template <typename Container, typename T>
void test_search(const Container &c, const T &value)
{
	try
	{
		typename Container::const_iterator it = easyfind(c, value);
		std::cout << "Found " << value << " at position "
				  << std::distance(c.begin(), it) << std::endl;
	}
	catch (const NotFoundException& e)
	{
		std::cout << "Value: " << value << e.what() << std::endl;
	}
}

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
	std::vector<int> vec_arr(temp, temp + 3);

	test_search(vec_arr, 10);   // should find
	test_search(vec_arr, 40);   // not found

	std::vector<int> emptyVec;
	test_search(emptyVec, 40); // empty container

	// --- char example ---
	char temp2[] = {'a', 'b', 'c'};
	std::list<char> charList(temp2, temp2 + 3);
	test_search(charList, 'b'); // should find
	test_search(charList, 'z'); // not found

	int temp3[] = {10, 20, 30};
	const std::vector<int> constVec(temp, temp3 + 3);
	test_search(constVec, 10);

}
