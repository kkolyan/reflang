// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!! This file is auto-generated by Reflang. !!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include "fields.gen.hpp"

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

Reference Class<MyClass>::GetField(const Reference& r, const std::string& name) const
{
	if (r.IsT<MyClass>())
	{
		MyClass& o = r.GetT<MyClass>();
		if (name == "field")
		{
			return Reference(o.field);
		}
		if (name == "const_field")
		{
			return Reference(o.const_field);
		}
		if (name == "pointer_field")
		{
			return Reference(o.pointer_field);
		}
		if (name == "const_pointer_field")
		{
			return Reference(o.const_pointer_field);
		}
		if (name == "const_pointer_const_field")
		{
			return Reference(o.const_pointer_const_field);
		}
		if (name == "ref_field")
		{
			return Reference(o.ref_field);
		}
		if (name == "const_ref_field")
		{
			return Reference(o.const_ref_field);
		}
		if (name == "complex")
		{
			return Reference(o.complex);
		}
		if (name == "const_complex")
		{
			return Reference(o.const_complex);
		}
		if (name == "pointer_complex")
		{
			return Reference(o.pointer_complex);
		}
		if (name == "const_pointer_complex")
		{
			return Reference(o.const_pointer_complex);
		}
		if (name == "const_pointer_const_complex")
		{
			return Reference(o.const_pointer_const_complex);
		}
		if (name == "ref_complex")
		{
			return Reference(o.ref_complex);
		}
		if (name == "const_ref_complex")
		{
			return Reference(o.const_ref_complex);
		}
	}
	else if (r.IsT<const MyClass>())
	{
		const MyClass& o = r.GetT<const MyClass>();
		if (name == "field")
		{
			return Reference(o.field);
		}
		if (name == "const_field")
		{
			return Reference(o.const_field);
		}
		if (name == "pointer_field")
		{
			return Reference(o.pointer_field);
		}
		if (name == "const_pointer_field")
		{
			return Reference(o.const_pointer_field);
		}
		if (name == "const_pointer_const_field")
		{
			return Reference(o.const_pointer_const_field);
		}
		if (name == "ref_field")
		{
			return Reference(o.ref_field);
		}
		if (name == "const_ref_field")
		{
			return Reference(o.const_ref_field);
		}
		if (name == "complex")
		{
			return Reference(o.complex);
		}
		if (name == "const_complex")
		{
			return Reference(o.const_complex);
		}
		if (name == "pointer_complex")
		{
			return Reference(o.pointer_complex);
		}
		if (name == "const_pointer_complex")
		{
			return Reference(o.const_pointer_complex);
		}
		if (name == "const_pointer_const_complex")
		{
			return Reference(o.const_pointer_const_complex);
		}
		if (name == "ref_complex")
		{
			return Reference(o.ref_complex);
		}
		if (name == "const_ref_complex")
		{
			return Reference(o.const_ref_complex);
		}
	}
	else
	{
		throw Exception("Invalid Reference passed to GetField().");
	}
	throw Exception("Invalid name passed to GetField().");
}

int Class<MyClass>::GetStaticFieldCount() const
{
	return StaticFieldCount;
}

Reference Class<MyClass>::GetStaticField(const std::string& name) const
{
	throw Exception("Invalid name passed to GetStaticField().");
}

int Class<MyClass>::GetMethodCount() const
{
	return MethodCount;
}

std::vector<std::unique_ptr<IMethod>> Class<MyClass>::GetMethod(const std::string& name) const
{
	std::vector<std::unique_ptr<IMethod>> results;

	return results;
}

std::vector<std::unique_ptr<IField>> Class<MyClass>::GetFields() const
{
	std::vector<std::unique_ptr<IField>> results;
	results.push_back(std::make_unique<Field<decltype(&MyClass::field), &MyClass::field>>());
	results.push_back(std::make_unique<Field<decltype(&MyClass::const_field), &MyClass::const_field>>());
	results.push_back(std::make_unique<Field<decltype(&MyClass::pointer_field), &MyClass::pointer_field>>());
	results.push_back(std::make_unique<Field<decltype(&MyClass::const_pointer_field), &MyClass::const_pointer_field>>());
	results.push_back(std::make_unique<Field<decltype(&MyClass::const_pointer_const_field), &MyClass::const_pointer_const_field>>());
	results.push_back(std::make_unique<ReferenceField<decltype(MyClass::ref_field)>>());
	results.push_back(std::make_unique<ReferenceField<decltype(MyClass::const_ref_field)>>());
	results.push_back(std::make_unique<Field<decltype(&MyClass::complex), &MyClass::complex>>());
	results.push_back(std::make_unique<Field<decltype(&MyClass::const_complex), &MyClass::const_complex>>());
	results.push_back(std::make_unique<Field<decltype(&MyClass::pointer_complex), &MyClass::pointer_complex>>());
	results.push_back(std::make_unique<Field<decltype(&MyClass::const_pointer_complex), &MyClass::const_pointer_complex>>());
	results.push_back(std::make_unique<Field<decltype(&MyClass::const_pointer_const_complex), &MyClass::const_pointer_const_complex>>());
	results.push_back(std::make_unique<ReferenceField<decltype(MyClass::ref_complex)>>());
	results.push_back(std::make_unique<ReferenceField<decltype(MyClass::const_ref_complex)>>());

	return results;
}

int Class<MyClass>::GetStaticMethodCount() const
{
	return StaticMethodCount;
}

std::vector<std::unique_ptr<IFunction>> Class<MyClass>::GetStaticMethod(
		const std::string& name) const
{
	std::vector<std::unique_ptr<IFunction>> results;

	return results;
}

static const std::string MyClass_name = "MyClass";

const std::string& Class<MyClass>::GetName() const
{
	return MyClass_name;
}

// MyClass fields definitions.
static std::string MyClass_field_name = "field";
static std::string MyClass_field_type = "int";

const std::string& Field<decltype(&MyClass::field), &MyClass::field>::GetName() const
{
	return MyClass_field_name;
}

const std::string& Field<decltype(&MyClass::field), &MyClass::field>::GetType() const
{
    return MyClass_field_type;
}


Reference Field<decltype(&MyClass::field), &MyClass::field>::Resolve(const Reference& r) const
{
	if (r.IsT<MyClass>())
	{
		MyClass& o = r.GetT<MyClass>();
        return Reference(o.field);
	}
	if (r.IsT<const MyClass>())
	{
		const MyClass& o = r.GetT<const MyClass>();
        return Reference(o.field);
	}
    throw Exception("Invalid Reference passed to Resolve().");
}

static std::string MyClass_const_field_name = "const_field";
static std::string MyClass_const_field_type = "const int";

const std::string& Field<decltype(&MyClass::const_field), &MyClass::const_field>::GetName() const
{
	return MyClass_const_field_name;
}

const std::string& Field<decltype(&MyClass::const_field), &MyClass::const_field>::GetType() const
{
    return MyClass_const_field_type;
}


Reference Field<decltype(&MyClass::const_field), &MyClass::const_field>::Resolve(const Reference& r) const
{
	if (r.IsT<MyClass>())
	{
		MyClass& o = r.GetT<MyClass>();
        return Reference(o.const_field);
	}
	if (r.IsT<const MyClass>())
	{
		const MyClass& o = r.GetT<const MyClass>();
        return Reference(o.const_field);
	}
    throw Exception("Invalid Reference passed to Resolve().");
}

static std::string MyClass_pointer_field_name = "pointer_field";
static std::string MyClass_pointer_field_type = "int *";

const std::string& Field<decltype(&MyClass::pointer_field), &MyClass::pointer_field>::GetName() const
{
	return MyClass_pointer_field_name;
}

const std::string& Field<decltype(&MyClass::pointer_field), &MyClass::pointer_field>::GetType() const
{
    return MyClass_pointer_field_type;
}


Reference Field<decltype(&MyClass::pointer_field), &MyClass::pointer_field>::Resolve(const Reference& r) const
{
	if (r.IsT<MyClass>())
	{
		MyClass& o = r.GetT<MyClass>();
        return Reference(o.pointer_field);
	}
	if (r.IsT<const MyClass>())
	{
		const MyClass& o = r.GetT<const MyClass>();
        return Reference(o.pointer_field);
	}
    throw Exception("Invalid Reference passed to Resolve().");
}

static std::string MyClass_const_pointer_field_name = "const_pointer_field";
static std::string MyClass_const_pointer_field_type = "const int *";

const std::string& Field<decltype(&MyClass::const_pointer_field), &MyClass::const_pointer_field>::GetName() const
{
	return MyClass_const_pointer_field_name;
}

const std::string& Field<decltype(&MyClass::const_pointer_field), &MyClass::const_pointer_field>::GetType() const
{
    return MyClass_const_pointer_field_type;
}


Reference Field<decltype(&MyClass::const_pointer_field), &MyClass::const_pointer_field>::Resolve(const Reference& r) const
{
	if (r.IsT<MyClass>())
	{
		MyClass& o = r.GetT<MyClass>();
        return Reference(o.const_pointer_field);
	}
	if (r.IsT<const MyClass>())
	{
		const MyClass& o = r.GetT<const MyClass>();
        return Reference(o.const_pointer_field);
	}
    throw Exception("Invalid Reference passed to Resolve().");
}

static std::string MyClass_const_pointer_const_field_name = "const_pointer_const_field";
static std::string MyClass_const_pointer_const_field_type = "const int *const";

const std::string& Field<decltype(&MyClass::const_pointer_const_field), &MyClass::const_pointer_const_field>::GetName() const
{
	return MyClass_const_pointer_const_field_name;
}

const std::string& Field<decltype(&MyClass::const_pointer_const_field), &MyClass::const_pointer_const_field>::GetType() const
{
    return MyClass_const_pointer_const_field_type;
}


Reference Field<decltype(&MyClass::const_pointer_const_field), &MyClass::const_pointer_const_field>::Resolve(const Reference& r) const
{
	if (r.IsT<MyClass>())
	{
		MyClass& o = r.GetT<MyClass>();
        return Reference(o.const_pointer_const_field);
	}
	if (r.IsT<const MyClass>())
	{
		const MyClass& o = r.GetT<const MyClass>();
        return Reference(o.const_pointer_const_field);
	}
    throw Exception("Invalid Reference passed to Resolve().");
}

static std::string MyClass_ref_field_name = "ref_field";
static std::string MyClass_ref_field_type = "int &";

const std::string& ReferenceField<decltype(MyClass::ref_field)>::GetName() const
{
	return MyClass_ref_field_name;
}

const std::string& ReferenceField<decltype(MyClass::ref_field)>::GetType() const
{
    return MyClass_ref_field_type;
}


Reference ReferenceField<decltype(MyClass::ref_field)>::Resolve(const Reference& r) const
{
	if (r.IsT<MyClass>())
	{
		MyClass& o = r.GetT<MyClass>();
        return Reference(o.ref_field);
	}
	if (r.IsT<const MyClass>())
	{
		const MyClass& o = r.GetT<const MyClass>();
        return Reference(o.ref_field);
	}
    throw Exception("Invalid Reference passed to Resolve().");
}

static std::string MyClass_const_ref_field_name = "const_ref_field";
static std::string MyClass_const_ref_field_type = "const int &";

const std::string& ReferenceField<decltype(MyClass::const_ref_field)>::GetName() const
{
	return MyClass_const_ref_field_name;
}

const std::string& ReferenceField<decltype(MyClass::const_ref_field)>::GetType() const
{
    return MyClass_const_ref_field_type;
}


Reference ReferenceField<decltype(MyClass::const_ref_field)>::Resolve(const Reference& r) const
{
	if (r.IsT<MyClass>())
	{
		MyClass& o = r.GetT<MyClass>();
        return Reference(o.const_ref_field);
	}
	if (r.IsT<const MyClass>())
	{
		const MyClass& o = r.GetT<const MyClass>();
        return Reference(o.const_ref_field);
	}
    throw Exception("Invalid Reference passed to Resolve().");
}

static std::string MyClass_complex_name = "complex";
static std::string MyClass_complex_type = "MyClass::ComplexType";

const std::string& Field<decltype(&MyClass::complex), &MyClass::complex>::GetName() const
{
	return MyClass_complex_name;
}

const std::string& Field<decltype(&MyClass::complex), &MyClass::complex>::GetType() const
{
    return MyClass_complex_type;
}


Reference Field<decltype(&MyClass::complex), &MyClass::complex>::Resolve(const Reference& r) const
{
	if (r.IsT<MyClass>())
	{
		MyClass& o = r.GetT<MyClass>();
        return Reference(o.complex);
	}
	if (r.IsT<const MyClass>())
	{
		const MyClass& o = r.GetT<const MyClass>();
        return Reference(o.complex);
	}
    throw Exception("Invalid Reference passed to Resolve().");
}

static std::string MyClass_const_complex_name = "const_complex";
static std::string MyClass_const_complex_type = "const MyClass::ComplexType";

const std::string& Field<decltype(&MyClass::const_complex), &MyClass::const_complex>::GetName() const
{
	return MyClass_const_complex_name;
}

const std::string& Field<decltype(&MyClass::const_complex), &MyClass::const_complex>::GetType() const
{
    return MyClass_const_complex_type;
}


Reference Field<decltype(&MyClass::const_complex), &MyClass::const_complex>::Resolve(const Reference& r) const
{
	if (r.IsT<MyClass>())
	{
		MyClass& o = r.GetT<MyClass>();
        return Reference(o.const_complex);
	}
	if (r.IsT<const MyClass>())
	{
		const MyClass& o = r.GetT<const MyClass>();
        return Reference(o.const_complex);
	}
    throw Exception("Invalid Reference passed to Resolve().");
}

static std::string MyClass_pointer_complex_name = "pointer_complex";
static std::string MyClass_pointer_complex_type = "MyClass::ComplexType *";

const std::string& Field<decltype(&MyClass::pointer_complex), &MyClass::pointer_complex>::GetName() const
{
	return MyClass_pointer_complex_name;
}

const std::string& Field<decltype(&MyClass::pointer_complex), &MyClass::pointer_complex>::GetType() const
{
    return MyClass_pointer_complex_type;
}


Reference Field<decltype(&MyClass::pointer_complex), &MyClass::pointer_complex>::Resolve(const Reference& r) const
{
	if (r.IsT<MyClass>())
	{
		MyClass& o = r.GetT<MyClass>();
        return Reference(o.pointer_complex);
	}
	if (r.IsT<const MyClass>())
	{
		const MyClass& o = r.GetT<const MyClass>();
        return Reference(o.pointer_complex);
	}
    throw Exception("Invalid Reference passed to Resolve().");
}

static std::string MyClass_const_pointer_complex_name = "const_pointer_complex";
static std::string MyClass_const_pointer_complex_type = "const MyClass::ComplexType *";

const std::string& Field<decltype(&MyClass::const_pointer_complex), &MyClass::const_pointer_complex>::GetName() const
{
	return MyClass_const_pointer_complex_name;
}

const std::string& Field<decltype(&MyClass::const_pointer_complex), &MyClass::const_pointer_complex>::GetType() const
{
    return MyClass_const_pointer_complex_type;
}


Reference Field<decltype(&MyClass::const_pointer_complex), &MyClass::const_pointer_complex>::Resolve(const Reference& r) const
{
	if (r.IsT<MyClass>())
	{
		MyClass& o = r.GetT<MyClass>();
        return Reference(o.const_pointer_complex);
	}
	if (r.IsT<const MyClass>())
	{
		const MyClass& o = r.GetT<const MyClass>();
        return Reference(o.const_pointer_complex);
	}
    throw Exception("Invalid Reference passed to Resolve().");
}

static std::string MyClass_const_pointer_const_complex_name = "const_pointer_const_complex";
static std::string MyClass_const_pointer_const_complex_type = "const MyClass::ComplexType *const";

const std::string& Field<decltype(&MyClass::const_pointer_const_complex), &MyClass::const_pointer_const_complex>::GetName() const
{
	return MyClass_const_pointer_const_complex_name;
}

const std::string& Field<decltype(&MyClass::const_pointer_const_complex), &MyClass::const_pointer_const_complex>::GetType() const
{
    return MyClass_const_pointer_const_complex_type;
}


Reference Field<decltype(&MyClass::const_pointer_const_complex), &MyClass::const_pointer_const_complex>::Resolve(const Reference& r) const
{
	if (r.IsT<MyClass>())
	{
		MyClass& o = r.GetT<MyClass>();
        return Reference(o.const_pointer_const_complex);
	}
	if (r.IsT<const MyClass>())
	{
		const MyClass& o = r.GetT<const MyClass>();
        return Reference(o.const_pointer_const_complex);
	}
    throw Exception("Invalid Reference passed to Resolve().");
}

static std::string MyClass_ref_complex_name = "ref_complex";
static std::string MyClass_ref_complex_type = "MyClass::ComplexType &";

const std::string& ReferenceField<decltype(MyClass::ref_complex)>::GetName() const
{
	return MyClass_ref_complex_name;
}

const std::string& ReferenceField<decltype(MyClass::ref_complex)>::GetType() const
{
    return MyClass_ref_complex_type;
}


Reference ReferenceField<decltype(MyClass::ref_complex)>::Resolve(const Reference& r) const
{
	if (r.IsT<MyClass>())
	{
		MyClass& o = r.GetT<MyClass>();
        return Reference(o.ref_complex);
	}
	if (r.IsT<const MyClass>())
	{
		const MyClass& o = r.GetT<const MyClass>();
        return Reference(o.ref_complex);
	}
    throw Exception("Invalid Reference passed to Resolve().");
}

static std::string MyClass_const_ref_complex_name = "const_ref_complex";
static std::string MyClass_const_ref_complex_type = "const MyClass::ComplexType &";

const std::string& ReferenceField<decltype(MyClass::const_ref_complex)>::GetName() const
{
	return MyClass_const_ref_complex_name;
}

const std::string& ReferenceField<decltype(MyClass::const_ref_complex)>::GetType() const
{
    return MyClass_const_ref_complex_type;
}


Reference ReferenceField<decltype(MyClass::const_ref_complex)>::Resolve(const Reference& r) const
{
	if (r.IsT<MyClass>())
	{
		MyClass& o = r.GetT<MyClass>();
        return Reference(o.const_ref_complex);
	}
	if (r.IsT<const MyClass>())
	{
		const MyClass& o = r.GetT<const MyClass>();
        return Reference(o.const_ref_complex);
	}
    throw Exception("Invalid Reference passed to Resolve().");
}

// End of MyClass fields definitions.


namespace
{
	// Object to auto-register MyClass.
	struct MyClass_registrar
	{
		MyClass_registrar()
		{
			::reflang::registry::internal::Register(
					std::make_unique<Class<MyClass>>());
		}
	} MyClass_instance;
}

}  // namespace reflang
