// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!! This file is auto-generated by Reflang. !!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include "static-methods.gen.hpp"

#include <algorithm>
#include <cassert>
#include <stdexcept>
#include <type_traits>

namespace reflang
{


const int Class<MyClass>::FieldCount;
const int Class<MyClass>::StaticFieldCount;
const int Class<MyClass>::MethodCount;
const int Class<MyClass>::StaticMethodCount;

int Class<MyClass>::GetFieldCount() const
{
	return FieldCount;
}

int Class<MyClass>::GetStaticFieldCount() const
{
	return StaticFieldCount;
}

int Class<MyClass>::GetMethodCount() const
{
	return MethodCount;
}

int Class<MyClass>::GetStaticMethodCount() const
{
	return StaticMethodCount;
}

static const std::string MyClass_name = "MyClass";

const std::string& Class<MyClass>::GetName() const
{
	return MyClass_name;
}



}  // namespace reflang
