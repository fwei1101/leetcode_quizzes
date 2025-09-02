#pragma once

#include <yaml-cpp/yaml.h>
#include <optional>

namespace YAML
{
template<>
struct convert<std::optional<int>>
{
	static Node encode(std::optional<int> const & rhs)
	{
		return rhs ? Node(*rhs) : Node("null");
	}
	static bool decode(Node const & node, std::optional<int> & rhs)
	{
		if(node.IsNull() || !node.IsDefined())
		{
			rhs = std::nullopt;
			return true;
		}
		try
		{
			rhs = node.as<int>();
		}
		catch(...)
		{
			rhs = std::nullopt;
		}
		return true;
	}
};
}