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

struct Color
{
	enum Code
	{
		RESET   = 0,
		RED     = 31,
		GREEN   = 32,
		YELLOW  = 33,
		BLUE    = 34,
		MAGENTA = 35,
		CYAN    = 36,
		WHITE   = 37,
		// Bright (bold) versions
		BRIGHT_MAGENTA = 95,
	};
};

void printColor(const std::string &msg, Color::Code color)
{
	std::cout << "\033[" << color << "m"
		<< msg
		<< "\033[0m";
}

void	test_valid_range()
{
	printColor("=== Test valid range === \n", Color::YELLOW);
	try
	{
		std::vector<int> vec;
		vec.reserve(5);
		for (int i = 0; i < 5; i++)
		{
			vec.push_back(i);
		}
		Span sp = Span(5);
		sp.addNumber(vec.begin(), vec.end());
		printColor("span elements: ", Color::BLUE);
		sp.printSpan();
		printColor("shortest span: ", Color::BLUE);
		std::cout << sp.shortestSpan() << std::endl;
		printColor("longest span: ", Color::BLUE);
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const Span::OverMaxCapacity &e)
	{
		printColor(e.what(), Color::RED);
	}
	std::cout << std::endl;
}

void	test_invalid_range()
{
	printColor("=== Test invalid range === \n", Color::YELLOW);
	try
	{
		std::vector<int> vec;
		vec.reserve(5);
		for (int i = 0; i < 5; i++)
		{
			vec.push_back(i);
		}
		printColor("Tried to copy a (filled) vector size 5 to a span with capacity 4 \n ", Color::BLUE);
		Span sp = Span(4);
		sp.addNumber(vec.begin(), vec.end());
	}
	catch (const Span::OverMaxCapacity &e)
	{
		printColor(e.what(), Color::RED);
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void test_empty_range()
{
	printColor("=== Test empty range === \n", Color::YELLOW);
	try
	{
		Span sp(5);
		std::vector<int> emptyVec;
		sp.addNumber(emptyVec.begin(), emptyVec.end());

		printColor("span elements: ", Color::BLUE);
		sp.printSpan();
		std::cout << "size should be 0" << std::endl;
	}
	catch (const std::exception &e)
	{
		printColor(e.what(), Color::RED);
	}
	std::cout << std::endl;
}

void test_random_numbers()
{
	printColor("=== Test random numbers === \n", Color::YELLOW);
	try
	{
		Span sp(10);
		sp.addRandomNumbers(10);
		printColor("span elements: ", Color::BLUE);
		sp.printSpan();
		printColor("shortest span: ", Color::BLUE);
		std::cout << sp.shortestSpan() << std::endl;
		printColor("longest span: ", Color::BLUE);
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const Span::OverMaxCapacity &e)
	{
		printColor(e.what(), Color::RED);
	}
	std::cout << std::endl;
}

void test_large_random_span()
{
	printColor("=== Test large random span === \n", Color::YELLOW);
	try
	{
		const int N = 10000;
		Span sp(N);
		sp.addRandomNumbers(N);
		printColor("span elements: ", Color::BLUE);
		sp.printSpan();
		printColor("shortest span: ", Color::BLUE);
		std::cout << sp.shortestSpan() << std::endl;
		printColor("longest span: ", Color::BLUE);
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		printColor(e.what(), Color::RED);
	}
	std::cout << std::endl;
}

void test_copy_and_assignment()
{
	printColor("=== Test copy constructor & assignment === \n", Color::YELLOW);
	try
	{
		Span sp1(5);
		sp1.addNumber(1);
		sp1.addNumber(3);
		sp1.addNumber(5);

		Span sp2 = sp1; // copy constructor
		Span sp3(5);
		sp3 = sp1; // assignment operator

		printColor("original span: ", Color::BLUE);
		sp1.printSpan();
		printColor("copy span: ", Color::BLUE);
		sp2.printSpan();
		printColor("assigned span: ", Color::BLUE);
		sp3.printSpan();
	}
	catch (const std::exception &e)
	{
		printColor(e.what(), Color::RED);
	}
	std::cout << std::endl;
}

void test_copy_and_assignment_and_modify()
{
	printColor("=== Test copy constructor & assignment and modify=== \n", Color::YELLOW);
	try
	{
		Span sp1(5);
		sp1.addNumber(1);
		sp1.addNumber(3);
		sp1.addNumber(5);

		Span sp2 = sp1; // copy constructor
		sp2.addNumber(2);
		Span sp3(5);
		sp3 = sp2; // assignment operator
		sp3.addNumber(4);

		printColor("original span: ", Color::BLUE);
		sp1.printSpan();
		printColor("copy span: ", Color::BLUE);
		sp2.printSpan();
		printColor("assigned span: ", Color::BLUE);
		sp3.printSpan();
	}
	catch (const std::exception &e)
	{
		printColor(e.what(), Color::RED);
	}
	std::cout << std::endl;
}

void test_no_span_possible()
{
	printColor("=== Test not enough elements === \n", Color::YELLOW);
	try
	{
		Span sp(2);
		sp.addNumber(10);
		printColor("span elements: ", Color::BLUE);
		sp.printSpan();
		printColor("shortest span: ", Color::BLUE);
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (const Span::NoSpanPossible &e)
	{
		printColor(e.what(), Color::RED);
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void test_large_span_iterators()
{
	printColor("=== Test large span using iterators === \n", Color::YELLOW);
	try
	{
		std::vector<int> v;
		v.reserve(1000);
		for (size_t i = 0; i < 1000; i++)
			v.push_back(i);

		Span sp(1000);
		sp.addNumber(v.begin(), v.end());
		printColor("span elements: ", Color::BLUE);
		sp.printSpan();
		printColor("shortest span: ", Color::BLUE);
		std::cout << sp.shortestSpan() << std::endl;
		printColor("longest span: ", Color::BLUE);
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		printColor(e.what(), Color::RED);
	}
	std::cout << std::endl;
}

void test_duplicates()
{
	printColor("=== Test adding duplicate numbers === \n", Color::YELLOW);
	try
	{
		Span sp(6);
		sp.addNumber(5);
		sp.addNumber(5);
		sp.addNumber(10);
		sp.addNumber(10);
		sp.addNumber(5);
		sp.addNumber(10);

		printColor("span elements: ", Color::BLUE);
		sp.printSpan();
		printColor("shortest span: ", Color::BLUE);
		std::cout << sp.shortestSpan() << std::endl;
		printColor("longest span: ", Color::BLUE);
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		printColor(e.what(), Color::RED);
	}
	std::cout << std::endl;
}

int main(void)
{
	std::srand(time(NULL));
	test_random_numbers();
	// test_large_random_span(); // should test seperately
	test_valid_range();
	test_invalid_range();
	test_empty_range();
	test_copy_and_assignment();
	test_copy_and_assignment_and_modify();
	test_no_span_possible();
	test_large_span_iterators();
	test_duplicates();
	// test_duplicates_generic(); // only for testing other Span implementations
}
