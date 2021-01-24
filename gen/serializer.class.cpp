#include "serializer.class.hpp"

#include <map>
#include <sstream>
#include <vector>

#include "serializer.function.hpp"
#include "serializer.util.hpp"

using namespace std;
using namespace reflang;

namespace
{
	string IterateFields(const Class& c)
	{
		stringstream tmpl;

		for (const auto& field : c.Fields)
		{
			tmpl << "	t(c." << field.Name << ");\n";
		}

		return tmpl.str();
	}

	string IterateStaticFields(const Class& c)
	{
		stringstream tmpl;

		for (const auto& field : c.StaticFields)
		{
			tmpl << "	t(" << c.GetFullName() << "::" << field.Name << ");\n";
		}

		return tmpl.str();
	}

	string MethodDeclaration(const Class& c, const Function& m)
	{
		stringstream tmpl;
		tmpl << R"(template <>
class Method<decltype(%name%), %name%> : public IMethod
{
public:
	const std::string& GetName() const override;
	int GetParameterCount() const override;
	Object Invoke(const Reference& o, const std::vector<Object>& args) override;
};

)";
		return serializer::ReplaceAll(
				tmpl.str(),
				{
					{"%name%", "&" + c.GetFullName() + "::" + m.Name},
				});
	}
    string FieldDeclaration(const Class& c, const NamedObject& m)
    {
        stringstream tmpl;
        if (m.Type.find('&') == std::string::npos) {

            tmpl << R"(template <>
class Field<decltype(%name%), %name%> : public IField
{
public:
	const std::string& GetName() const override;
	const std::string& GetType() const override;
    Reference Resolve(const Reference& o) const override;
};

)";
            return serializer::ReplaceAll(
                    tmpl.str(),
                    {
                            {"%name%", "&" + c.GetFullName() + "::" + m.Name},
                    });
        } else {

            tmpl << R"(template <>
class ReferenceField<decltype(%name%)> : public IField
{
public:
	const std::string& GetName() const override;
	const std::string& GetType() const override;
    Reference Resolve(const Reference& o) const override;
};

)";
            return serializer::ReplaceAll(
                    tmpl.str(),
                    {
                            {"%name%", c.GetFullName() + "::" + m.Name},
                    });
        }
    }

	string MethodsDeclarations(const Class& c)
	{
		if (c.Methods.empty())
		{
			return string();
		}

		stringstream tmpl;
		tmpl << "// " << c.GetFullName() << " methods metadata.\n";

		for (const auto& method : c.Methods)
		{
			tmpl << MethodDeclaration(c, method);
		}

		tmpl << "// End of " << c.GetFullName() << " methods metadata.\n";

		return tmpl.str();
	}

    string FieldsDeclarations(const Class& c)
    {
        if (c.Fields.empty())
        {
            return string();
        }

        stringstream tmpl;
        tmpl << "// " << c.GetFullName() << " methods metadata.\n";

        for (const auto& field : c.Fields)
        {
            tmpl << FieldDeclaration(c, field);
        }

        tmpl << "// End of " << c.GetFullName() << " methods metadata.\n";

        return tmpl.str();
    }

	string StaticMethodsDeclarations(const Class& c)
	{
		if (c.StaticMethods.empty())
		{
			return string();
		}

		stringstream tmpl;
		tmpl << "// " << c.GetFullName() << " static methods metadata.\n";

		for (const auto& method : c.StaticMethods)
		{
			serializer::SerializeFunctionHeader(tmpl, method);
		}

		tmpl << "// End of " << c.GetFullName() << " static methods metadata.\n";

		return tmpl.str();
	}

	string GetCallArgs(const Function& m)
	{
		stringstream tmpl;
		for (size_t i = 0; i < m.Arguments.size(); ++i)
		{
			tmpl << "args[" << i << "].GetT<std::decay_t<"
				<< m.Arguments[i].Type << ">>()";
			if (i != m.Arguments.size() - 1)
			{
				tmpl << ", ";
			}
		}
		return tmpl.str();
	}

	string MethodDefinition(const Class& c, const Function& m)
	{
		stringstream tmpl;
		tmpl << R"(static std::string %escaped_name%_name = "%name%";

const std::string& Method<decltype(%pointer%), %pointer%>::GetName() const
{
	return %escaped_name%_name;
}

int Method<decltype(%pointer%), %pointer%>::GetParameterCount() const
{
	return %param_count%;
}

Object Method<decltype(%pointer%), %pointer%>::Invoke(
		const Reference& o, const std::vector<Object>& args)
{
	if (args.size() != %param_count%)
	{
		throw Exception("Invoke(): bad argument count.");
	}
)";
		if (m.ReturnType == "void")
		{
			tmpl << R"(	((o.GetT<%class_name%>()).*(%pointer%))(%call_args%);
	return Object();
)";
		}
		else
		{
			tmpl << R"(	return Object(((o.GetT<%class_name%>()).*(%pointer%))(%call_args%));
)";
		}
		tmpl << R"(}

)";
		return serializer::ReplaceAll(
			tmpl.str(),
			{
				{"%class_name%", c.GetFullName()},
				{"%pointer%", "&" + c.GetFullName() + "::" + m.Name},
				{"%name%", m.Name},
				{
					"%escaped_name%",
					serializer::GetNameWithoutColons(
							c.GetFullName()) + "_" + m.Name
				},
				{"%param_count%", to_string(m.Arguments.size())},
				{"%call_args%", GetCallArgs(m)}
			});
	}

	string MethodsDefinitions(const Class& c)
	{
		if (c.Methods.empty())
		{
			return string();
		}

		stringstream tmpl;
		tmpl << "// " << c.GetFullName() << " methods definitions.\n";

		for (const auto& method : c.Methods)
		{
			tmpl << MethodDefinition(c, method);
		}

		tmpl << "// End of " << c.GetFullName() << " methods definitions.\n";

		return tmpl.str();
	}

    string FieldDefinition(const Class& c, const NamedObject& m)
    {
        stringstream tmpl;
        tmpl << R"(static std::string %escaped_name%_name = "%name%";
static std::string %escaped_name%_type = "%type%";

const std::string& %instance_expression%::GetName() const
{
	return %escaped_name%_name;
}

const std::string& %instance_expression%::GetType() const
{
    return %escaped_name%_type;
}


Reference %instance_expression%::Resolve(const Reference& r) const
{
	if (r.IsT<%class_name%>())
	{
		%class_name%& o = r.GetT<%class_name%>();
        return Reference(o.%name%);
	}
	if (r.IsT<const %class_name%>())
	{
		const %class_name%& o = r.GetT<const %class_name%>();
        return Reference(o.%name%);
	}
    throw Exception("Invalid Reference passed to Resolve().");
)";
        tmpl << R"(}

)";
        unsigned long long int i = m.Type.find('&');
        auto ptrPrefix =
                (i != std::string::npos)
                ? "ReferenceField<decltype(" + c.GetFullName() + "::" + m.Name + ")>"
                : "Field<decltype(&" + c.GetFullName() + "::" + m.Name + "), &" + c.GetFullName() + "::" + m.Name + ">";
        std::cout << m.Name << " : " << m.Type << ", " << i << std::endl;
        return serializer::ReplaceAll(
                tmpl.str(),
                {
                        {"%class_name%", c.GetFullName()},
                        {"%pointer%", ptrPrefix + c.GetFullName() + "::" + m.Name},
                        {"%instance_expression%", ptrPrefix},
                        {"%name%", m.Name},
                        {"%type%", m.Type},
                        {
                         "%escaped_name%",
                                serializer::GetNameWithoutColons(
                                        c.GetFullName()) + "_" + m.Name
                        }
                });
    }

    string FieldsDefinitions(const Class& c)
    {
        if (c.Fields.empty())
        {
            return string();
        }

        stringstream tmpl;
        tmpl << "// " << c.GetFullName() << " fields definitions.\n";

        for (const auto& field : c.Fields)
        {
            tmpl << FieldDefinition(c, field);
        }

        tmpl << "// End of " << c.GetFullName() << " fields definitions.\n";

        return tmpl.str();
    }

	map<string, vector<Function>> GetMethodsByName(
			const Class::MethodList& methods)
	{
		map<string, vector<Function>> methods_by_name;
		for (const auto& method : methods)
		{
			methods_by_name[method.Name].push_back(method);
		}
		return methods_by_name;
	}

	string GetMethodImpl(const Class& c)
	{
		map<string, vector<Function>> methods_by_name = GetMethodsByName(
				c.Methods);

		stringstream tmpl;
		bool first = true;
		for (const auto& methods : methods_by_name)
		{
			tmpl << "	";
			if (first)
			{
				first = false;
			}
			else
			{
				tmpl << "else ";
			}
			tmpl << "if (name == \"" << methods.first << "\")\n";
			tmpl << "	{\n";
			for (const auto& method : methods.second)
			{
				string name = "&" + c.GetFullName() + "::" + methods.first;
				tmpl << "		results.push_back(std::make_unique<Method<decltype("
					<< name << "), " << name << ">>());\n";
			}
			tmpl << "	}\n";
		}
		return tmpl.str();
	}

	string GetFieldsImpl(const Class& c)
	{
        stringstream tmpl;
        for (const auto& field : c.Fields)
        {
            if (field.Type.find('&') == std::string::npos) {
                string name = "&" + c.GetFullName() + "::" + field.Name;
                tmpl << "	results.push_back(std::make_unique<Field<decltype("
                     << name << "), " << name << ">>());\n";
            } else {
                string name = c.GetFullName() + "::" + field.Name;
                tmpl << "	results.push_back(std::make_unique<ReferenceField<decltype("
                     << name << ")>>());\n";
            }
        }
        return tmpl.str();
	}

	string GetStaticMethodImpl(const Class& c)
	{
		map<string, vector<Function>> methods_by_name = GetMethodsByName(
				c.StaticMethods);

		stringstream tmpl;
		bool first = true;
		for (const auto& methods : methods_by_name)
		{
			tmpl << "	";
			if (first)
			{
				first = false;
			}
			else
			{
				tmpl << "else ";
			}
			tmpl << "if (name == \"" << methods.first << "\")\n";
			tmpl << "	{\n";
			for (const auto& method : methods.second)
			{
				string name = c.GetFullName() + "::" + methods.first;
				tmpl << "		results.push_back(std::make_unique<Function<"
					<< serializer::GetFunctionSignature(method) << ", " << name
					<< ">>());\n";
			}
			tmpl << "	}\n";
		}
		return tmpl.str();
	}

	string StaticMethodsDefinitions(const Class& c)
	{
		if (c.StaticMethods.empty())
		{
			return string();
		}

		stringstream tmpl;
		tmpl << "// " << c.GetFullName() << " static methods definitions.\n";

		for (const auto& method : c.StaticMethods)
		{
			serializer::SerializeFunctionSources(tmpl, method);
		}

		tmpl << "// End of " << c.GetFullName()
			<< " static methods definitions.\n";

		return tmpl.str();
	}

	string GetFieldImpl(
			const Class::FieldList& fields, const string& field_prefix)
	{
		stringstream tmpl;
		for (const auto& field : fields)
		{
			tmpl << "		if (name == \"" << field.Name << "\")\n";
			tmpl << "		{\n";
			tmpl << "			return Reference("
				<< field_prefix << field.Name << ");\n";
			tmpl << "		}\n";
		}
		return tmpl.str();
	}
}

void serializer::SerializeClassHeader(ostream& o, const Class& c)
{
	stringstream tmpl;
	tmpl << R"(
template <>
class Class<%name%> : public IClass
{
public:
	static const constexpr int FieldCount = %field_count%;
	static const constexpr int StaticFieldCount = %static_field_count%;
	static const constexpr int MethodCount = %method_count%;
	static const constexpr int StaticMethodCount = %static_method_count%;

	int GetFieldCount() const override;
	Reference GetField(
			const Reference& o, const std::string& name) const override;

    std::vector<std::unique_ptr<IField>> GetFields() const override;

	int GetStaticFieldCount() const override;
	Reference GetStaticField(const std::string& name) const override;

	int GetMethodCount() const override;
	std::vector<std::unique_ptr<IMethod>> GetMethod(
			const std::string& name) const override;

	int GetStaticMethodCount() const override;
	std::vector<std::unique_ptr<IFunction>> GetStaticMethod(
			const std::string& name) const override;

	const std::string& GetName() const override;

	// Calls T::operator() on each field of '%name%'.
	// Works well with C++14 generic lambdas.
	template <typename T>
	static void IterateFields(const %name%& c, T t);

	template <typename T>
	static void IterateFields(%name%& c, T t);

	template <typename T>
	static void IterateStaticFields(T t);
};

template <typename T>
void Class<%name%>::IterateFields(const %name%& c, T t)
{
%iterate_fields%}

template <typename T>
void Class<%name%>::IterateFields(%name%& c, T t)
{
%iterate_fields%}

template <typename T>
void Class<%name%>::IterateStaticFields(T t)
{
%iterate_static_fields%}

%methods_decl%%static_methods_decl%%fields_decl%
)";

	o << ReplaceAll(
			tmpl.str(),
			{
				{"%name%", c.GetFullName()},
				{"%iterate_fields%", IterateFields(c)},
				{"%iterate_static_fields%", IterateStaticFields(c)},
				{"%field_count%", to_string(c.Fields.size())},
				{"%static_field_count%", to_string(c.StaticFields.size())},
				{"%method_count%", to_string(c.Methods.size())},
                {"%methods_decl%", MethodsDeclarations(c)},
				{"%static_method_count%", to_string(c.StaticMethods.size())},
				{"%static_methods_decl%", StaticMethodsDeclarations(c)},
                {"%fields_decl%", FieldsDeclarations(c)}
			});
}

void serializer::SerializeClassSources(ostream& o, const Class& c)
{
	stringstream tmpl;
	tmpl << R"(
const int Class<%name%>::FieldCount;
const int Class<%name%>::StaticFieldCount;
const int Class<%name%>::MethodCount;
const int Class<%name%>::StaticMethodCount;

int Class<%name%>::GetFieldCount() const
{
	return FieldCount;
}

Reference Class<%name%>::GetField(const Reference& r, const std::string& name) const
{)";
	if (!c.Fields.empty())
	{
		tmpl << R"(
	if (r.IsT<%name%>())
	{
		%name%& o = r.GetT<%name%>();
%get_field_impl%	}
	else if (r.IsT<const %name%>())
	{
		const %name%& o = r.GetT<const %name%>();
%get_field_impl%	}
	else
	{
		throw Exception("Invalid Reference passed to GetField().");
	})";
	}
	tmpl << R"(
	throw Exception("Invalid name passed to GetField().");
}

int Class<%name%>::GetStaticFieldCount() const
{
	return StaticFieldCount;
}

Reference Class<%name%>::GetStaticField(const std::string& name) const
{
%get_static_field_impl%	throw Exception("Invalid name passed to GetStaticField().");
}

int Class<%name%>::GetMethodCount() const
{
	return MethodCount;
}

std::vector<std::unique_ptr<IMethod>> Class<%name%>::GetMethod(const std::string& name) const
{
	std::vector<std::unique_ptr<IMethod>> results;
%get_method_impl%
	return results;
}

std::vector<std::unique_ptr<IField>> Class<%name%>::GetFields() const
{
	std::vector<std::unique_ptr<IField>> results;
%get_fields_impl%
	return results;
}

int Class<%name%>::GetStaticMethodCount() const
{
	return StaticMethodCount;
}

std::vector<std::unique_ptr<IFunction>> Class<%name%>::GetStaticMethod(
		const std::string& name) const
{
	std::vector<std::unique_ptr<IFunction>> results;
%get_static_method_impl%
	return results;
}

static const std::string %escaped_name%_name = "%name%";

const std::string& Class<%name%>::GetName() const
{
	return %escaped_name%_name;
}

%method_definitions%%field_definitions%%static_method_definitions%

namespace
{
	// Object to auto-register %name%.
	struct %escaped_name%_registrar
	{
		%escaped_name%_registrar()
		{
			::reflang::registry::internal::Register(
					std::make_unique<Class<%name%>>());
		}
	} %escaped_name%_instance;
})";

	o << ReplaceAll(
			tmpl.str(),
			{
				{"%name%", c.GetFullName()},
				{"%get_field_impl%", GetFieldImpl(c.Fields, "o.")},
				{
					"%get_static_field_impl%",
					GetFieldImpl(c.StaticFields, c.GetFullName() + "::")
				},
				{"%field_count%", to_string(c.Fields.size())},
				{"%escaped_name%", GetNameWithoutColons(c.GetFullName())},
                {"%method_definitions%", MethodsDefinitions(c)},
                {"%field_definitions%", FieldsDefinitions(c)},
				{"%get_method_impl%", GetMethodImpl(c)},
                {"%get_fields_impl%", GetFieldsImpl(c)},
				{"%static_method_definitions%", StaticMethodsDefinitions(c)},
				{"%get_static_method_impl%", GetStaticMethodImpl(c)}
			});
}
