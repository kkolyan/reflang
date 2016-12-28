// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!! This file is auto-generated by Reflang. !!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#ifndef REFLANG_METADATA_VOID_NOARGS_GEN_HPP
#define REFLANG_METADATA_VOID_NOARGS_GEN_HPP

#include <string>

#include "lib/reflang.hpp"
#include "void-noargs.src.hpp"

namespace reflang
{


template <>
class Function<void(), ns::NamespacedFunction> : public IFunction
{
	int GetParameterCount() const override;

	const std::string& GetName() const override;

	Object Invoke(const std::vector<Object>& args) override;
};



template <>
class Function<void(), GlobalFunction> : public IFunction
{
	int GetParameterCount() const override;

	const std::string& GetName() const override;

	Object Invoke(const std::vector<Object>& args) override;
};


}  // namespace reflang

#endif //REFLANG_METADATA_VOID_NOARGS_GEN_HPP
