// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!! This file is auto-generated by Reflang. !!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include "empty-enum.gen.hpp"

#include <algorithm>
#include <cassert>
#include <stdexcept>
#include <type_traits>

namespace reflang
{


Enum<EmptyEnum>::ConstIterator::ConstIterator(bool is_last)
:	last_(true)
{
}

Enum<EmptyEnum>::EnumType Enum<EmptyEnum>::ConstIterator::operator*()
{
	return value_;
}

Enum<EmptyEnum>::ConstIterator& Enum<EmptyEnum>::ConstIterator::operator++()
{
	assert(false);
	return *this;
}

Enum<EmptyEnum>::ConstIterator Enum<EmptyEnum>::ConstIterator::operator++(int)
{
	auto tmp = *this;
	operator++();
	return tmp;
}

Enum<EmptyEnum>::ConstIterator& Enum<EmptyEnum>::ConstIterator::operator--()
{
	assert(false);
	return *this;
}

Enum<EmptyEnum>::ConstIterator Enum<EmptyEnum>::ConstIterator::operator--(int)
{
	auto tmp = *this;
	operator--();
	return tmp;
}

bool Enum<EmptyEnum>::ConstIterator::operator==(const ConstIterator& o) const
{
	return ((last_ && o.last_) ||
		(!last_ && !o.last_ && value_ == o.value_));
}

bool Enum<EmptyEnum>::ConstIterator::operator!=(const ConstIterator& o) const
{
	return !(*this == o);
}

Enum<EmptyEnum>::ConstIterator Enum<EmptyEnum>::IteratorContainer::begin() const
{
	return ConstIterator(false);
}

Enum<EmptyEnum>::ConstIterator Enum<EmptyEnum>::IteratorContainer::end() const
{
	return ConstIterator(true);
}

Enum<EmptyEnum>::IteratorContainer Enum<EmptyEnum>::Iterate()
{
	return IteratorContainer();
}

bool Enum<EmptyEnum>::TryTranslate(const std::string& s, EnumType& value)
{
	return false;
}

std::string Enum<EmptyEnum>::Translate(EnumType e)
{
	return std::string();
}

static const std::string EmptyEnum_name = "EmptyEnum";

const std::string& Enum<EmptyEnum>::GetName() const
{
	return EmptyEnum_name;
}

std::vector<std::string> Enum<EmptyEnum>::GetStringValues() const
{
	std::vector<std::string> values;
	values.reserve(0);
	for (const auto& value : this->Iterate())
	{
		values.push_back(this->Translate(value));
	}
	return values;
}

std::vector<int> Enum<EmptyEnum>::GetIntValues() const
{
	std::vector<int> values;
	values.reserve(0);
	for (const auto& value : this->Iterate())
	{
		values.push_back(static_cast<int>(value));
	}
	return values;
}

bool Enum<EmptyEnum>::TryTranslate(const std::string& value, int& out)
{
	EnumType tmp;
	bool result = this->TryTranslate(value, tmp);
	if (result)
	{
		out = static_cast<int>(tmp);
	}
	return result;
}

bool Enum<EmptyEnum>::TryTranslate(int value, std::string& out)
{
	return false;
}

namespace
{
	struct EmptyEnum_registrar
	{
		EmptyEnum_registrar()
		{
			::reflang::registry::internal::Register(
				std::make_unique<Enum<EmptyEnum>>());
		}
	} EmptyEnum_instance;
}



Enum<EmptyCEnum>::ConstIterator::ConstIterator(bool is_last)
:	last_(true)
{
}

Enum<EmptyCEnum>::EnumType Enum<EmptyCEnum>::ConstIterator::operator*()
{
	return value_;
}

Enum<EmptyCEnum>::ConstIterator& Enum<EmptyCEnum>::ConstIterator::operator++()
{
	assert(false);
	return *this;
}

Enum<EmptyCEnum>::ConstIterator Enum<EmptyCEnum>::ConstIterator::operator++(int)
{
	auto tmp = *this;
	operator++();
	return tmp;
}

Enum<EmptyCEnum>::ConstIterator& Enum<EmptyCEnum>::ConstIterator::operator--()
{
	assert(false);
	return *this;
}

Enum<EmptyCEnum>::ConstIterator Enum<EmptyCEnum>::ConstIterator::operator--(int)
{
	auto tmp = *this;
	operator--();
	return tmp;
}

bool Enum<EmptyCEnum>::ConstIterator::operator==(const ConstIterator& o) const
{
	return ((last_ && o.last_) ||
		(!last_ && !o.last_ && value_ == o.value_));
}

bool Enum<EmptyCEnum>::ConstIterator::operator!=(const ConstIterator& o) const
{
	return !(*this == o);
}

Enum<EmptyCEnum>::ConstIterator Enum<EmptyCEnum>::IteratorContainer::begin() const
{
	return ConstIterator(false);
}

Enum<EmptyCEnum>::ConstIterator Enum<EmptyCEnum>::IteratorContainer::end() const
{
	return ConstIterator(true);
}

Enum<EmptyCEnum>::IteratorContainer Enum<EmptyCEnum>::Iterate()
{
	return IteratorContainer();
}

bool Enum<EmptyCEnum>::TryTranslate(const std::string& s, EnumType& value)
{
	return false;
}

std::string Enum<EmptyCEnum>::Translate(EnumType e)
{
	return std::string();
}

static const std::string EmptyCEnum_name = "EmptyCEnum";

const std::string& Enum<EmptyCEnum>::GetName() const
{
	return EmptyCEnum_name;
}

std::vector<std::string> Enum<EmptyCEnum>::GetStringValues() const
{
	std::vector<std::string> values;
	values.reserve(0);
	for (const auto& value : this->Iterate())
	{
		values.push_back(this->Translate(value));
	}
	return values;
}

std::vector<int> Enum<EmptyCEnum>::GetIntValues() const
{
	std::vector<int> values;
	values.reserve(0);
	for (const auto& value : this->Iterate())
	{
		values.push_back(static_cast<int>(value));
	}
	return values;
}

bool Enum<EmptyCEnum>::TryTranslate(const std::string& value, int& out)
{
	EnumType tmp;
	bool result = this->TryTranslate(value, tmp);
	if (result)
	{
		out = static_cast<int>(tmp);
	}
	return result;
}

bool Enum<EmptyCEnum>::TryTranslate(int value, std::string& out)
{
	return false;
}

namespace
{
	struct EmptyCEnum_registrar
	{
		EmptyCEnum_registrar()
		{
			::reflang::registry::internal::Register(
				std::make_unique<Enum<EmptyCEnum>>());
		}
	} EmptyCEnum_instance;
}


}  // namespace reflang