#include "FunctionList.h"
#include "exceptions/UnknownFunctionException.h"
#include <boost/assign/list_of.hpp>

using namespace thewizardplusplus::wizard_basic::compiler::translator;
using namespace thewizardplusplus::wizard_basic::compiler::translator::
	exceptions;
using namespace boost::assign;

FunctionList::FunctionList(void) {
	functions = list_of
		// math module
		(Function(ValueType::NUMBER, "SIN", "std::sin", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "COS", "std::cos", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "TAN", "std::tan", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "ATN", "std::atan", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "EXP", "std::exp", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "LOG", "std::log", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "SQR", "std::sqrt", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "ABS", "std::abs", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "INT", "std::floor", list_of
			(FunctionParameter(ValueType::NUMBER))))
		// system module
		(Function(ValueType::NUMBER, "RND", "SystemModule::getInstance()."
			"getRandomNumber"))
		(Function(ValueType::NUMBER, "TIMER", "SystemModule::getInstance()."
			"getTimeFromStartInS"))
		(Function(ValueType::VOID, "PRINTN", "SystemModule::getInstance()."
			"trace", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::VOID, "PRINTS", "SystemModule::getInstance()."
			"trace", list_of
			(FunctionParameter(ValueType::ARRAY))))
		(Function(ValueType::NUMBER, "OPEN", "SystemModule::getInstance()."
			"fileOpen", list_of
			(FunctionParameter(ValueType::ARRAY))
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "INPUT", "SystemModule::getInstance()."
			"fileInput", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::VOID, "PRINTNF", "SystemModule::getInstance()."
			"fileOutput", list_of
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::VOID, "PRINTSF", "SystemModule::getInstance()."
			"fileOutput", list_of
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::ARRAY))))
		(Function(ValueType::VOID, "CLOSE", "SystemModule::getInstance()."
			"fileClose", list_of
			(FunctionParameter(ValueType::NUMBER))))
		// graphics module
		(Function(ValueType::NUMBER, "CAMPOSX", "GraphicsModule::getInstance()."
			"getCameraPositionX"))
		(Function(ValueType::NUMBER, "CAMPOSY", "GraphicsModule::getInstance()."
			"getCameraPositionY"))
		(Function(ValueType::NUMBER, "CAMPOSZ", "GraphicsModule::getInstance()."
			"getCameraPositionZ"))
		(Function(ValueType::VOID, "CAMPOS", "GraphicsModule::getInstance()."
			"setCameraPosition", list_of
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "CAMROTX", "GraphicsModule::getInstance()."
			"getCameraRotationX"))
		(Function(ValueType::NUMBER, "CAMROTY", "GraphicsModule::getInstance()."
			"getCameraRotationY"))
		(Function(ValueType::NUMBER, "CAMROTZ", "GraphicsModule::getInstance()."
			"getCameraRotationZ"))
		(Function(ValueType::VOID, "CAMROT", "GraphicsModule::getInstance()."
			"setCameraRotation", list_of
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::VOID, "FOG", "GraphicsModule::getInstance()."
			"setFogMode", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::VOID, "FOGPRM", "GraphicsModule::getInstance()."
			"setFogParameters", list_of
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "OBJLD", "GraphicsModule::getInstance()."
			"loadObject", list_of
			(FunctionParameter(ValueType::ARRAY))))
		(Function(ValueType::NUMBER, "OBJPOSX", "GraphicsModule::getInstance()."
			"getObjectPositionX", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "OBJPOSY", "GraphicsModule::getInstance()."
			"getObjectPositionY", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "OBJPOSZ", "GraphicsModule::getInstance()."
			"getObjectPositionZ", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::VOID, "OBJPOS", "GraphicsModule::getInstance()."
			"setObjectPosition", list_of
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "OBJROTX", "GraphicsModule::getInstance()."
			"getObjectRotationX", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "OBJROTY", "GraphicsModule::getInstance()."
			"getObjectRotationY", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "OBJROTZ", "GraphicsModule::getInstance()."
			"getObjectRotationZ", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::VOID, "OBJROT", "GraphicsModule::getInstance()."
			"setObjectRotation", list_of
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "OBJSCX", "GraphicsModule::getInstance()."
			"getObjectScaleX", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "OBJSCY", "GraphicsModule::getInstance()."
			"getObjectScaleY", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "OBJSCZ", "GraphicsModule::getInstance()."
			"getObjectScaleZ", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::VOID, "OBJSC", "GraphicsModule::getInstance()."
			"setObjectScale", list_of
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::VOID, "OBJPL", "GraphicsModule::getInstance()."
			"playObjectAnimation", list_of
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::VOID, "OBJPS", "GraphicsModule::getInstance()."
			"pauseObjectAnimation", list_of
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "ISKEY", "GraphicsModule::getInstance()."
			"isKeyPressed", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "ISBTN", "GraphicsModule::getInstance()."
			"isButtonPressed", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "PTPOSX", "GraphicsModule::getInstance()."
			"getPointerPositionX"))
		(Function(ValueType::NUMBER, "PTPOSY", "GraphicsModule::getInstance()."
			"getPointerPositionY"))
		(Function(ValueType::VOID, "PTPOS", "GraphicsModule::getInstance()."
			"setPointerPosition", list_of
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::VOID, "UPDATE", "GraphicsModule::getInstance()."
			"update"));
}

Function FunctionList::getFunctionByAlias(const std::string& alias) const {
	FunctionInnerList::const_iterator i = functions.begin();
	for (; i != functions.end(); ++i) {
		Function function = *i;
		if (function.getAlias() == alias) {
			return function;
		}
	}

	throw UnknownFunctionException();
}
