#pragma once

#include <ostream>
#include <vector>
#include "linked-list.hpp"

std::ostream & operator<<(std::ostream & os, std::vector<int> const & vec)
{
	os << "[";
	for (size_t i = 0; i < vec.size(); ++i) {
		os << vec[i];
		if (i != vec.size() - 1) os << ",";
	}
	os << "]";
	return os;
}

std::ostream & operator<<(std::ostream & os, std::vector<std::vector<int>> const & vec)
{
	os << "[";
	for (size_t i = 0; i < vec.size(); ++i) {
		os << vec[i];
		if (i != vec.size() - 1) os << ",";
	}
	os << "]";
	return os;
}

std::ostream & operator<<(std::ostream & os, std::vector<std::string> const & vec)
{
	os << "[";
	for (size_t i = 0; i < vec.size(); ++i) {
		os << vec[i];
		if (i != vec.size() - 1) os << ",";
	}
	os << "]";
	return os;
}

std::ostream & operator<<(std::ostream & os, std::shared_ptr<ListNode const> const & list)
{
	os << "[";
	auto curr = list;
	while (curr) {
		os << curr->val;
		if ((curr = curr->next)) {
			os << ",";
		}
	}
	os << "]";
	return os;
}