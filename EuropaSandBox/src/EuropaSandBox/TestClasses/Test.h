#pragma once

#include<EuropaEngine.h>

namespace EuropaSandBox
{
	class Test
	{
	public:
		Test(int myInt)
			:
			m_Int(myInt)
		{
			std::cout << "Constructor!" << std::endl;
		}
		Test(Test&& other) noexcept
			:
			m_Int(other.m_Int)
		{
			std::cout << "Variable MoveCopy Constructor" << std::endl;
			other.m_Int = 0;
		}
		Test(const Test& other)
			:
			m_Int(other.m_Int)
		{
			std::cout << "Variable HardCopy Constructor" << std::endl;
		}
		Test& operator=(const Test& other)
		{
			if (this == &other)
			{
				return *this;
			}
			m_Int = other.m_Int;
			return *this;
		}
	public:
		int m_Int = 10;
	};
	std::ostream& operator<<(std::ostream& os, const Test& ref)
	{
		os << ref.m_Int;
		return os;
	}
}
