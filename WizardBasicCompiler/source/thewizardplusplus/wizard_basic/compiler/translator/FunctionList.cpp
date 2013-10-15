#include "FunctionList.h"
#include "exceptions/UnknownFunctionException.h"
#include <boost/assign/list_of.hpp>
#include <algorithm>

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
		(Function(ValueType::VOID, "PRINT", "SystemModule::getInstance().trace",
			list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::VOID, "PRINT", "SystemModule::getInstance().trace",
			list_of
			(FunctionParameter(ValueType::ARRAY))))
		(Function(ValueType::NUMBER, "OPEN", "SystemModule::getInstance()."
			"fileOpen", list_of
			(FunctionParameter(ValueType::ARRAY))
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "INPUT", "SystemModule::getInstance()."
			"fileInput", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::VOID, "PRINT", "SystemModule::getInstance()."
			"fileOutput", list_of
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::VOID, "PRINT", "SystemModule::getInstance()."
			"fileOutput", list_of
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::ARRAY))))
		(Function(ValueType::VOID, "CLOSE", "SystemModule::getInstance()."
			"fileClose", list_of
			(FunctionParameter(ValueType::NUMBER))))
		// graphics module
		(Function(ValueType::VOID, "POSITION_CAMERA", "GraphicsModule::"
			"getInstance().setCameraPosition", list_of
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::VOID, "ROTATION_CAMERA", "GraphicsModule::"
			"getInstance().setCameraRotation", list_of
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::VOID, "FOG", "GraphicsModule::getInstance()."
			"setFogMode", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::VOID, "FOG_COLOR", "GraphicsModule::getInstance()."
			"setFogColor", list_of
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::VOID, "FOG_DENSITY", "GraphicsModule::"
			"getInstance().setFogDensity", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::VOID, "FOG_DEPTH", "GraphicsModule::getInstance()."
			"setFogDepth", list_of
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "LOAD_OBJECT", "GraphicsModule::"
			"getInstance().loadObject", list_of
			(FunctionParameter(ValueType::ARRAY))))
		(Function(ValueType::VOID, "POSITION_OBJECT", "GraphicsModule::"
			"getInstance().setObjectPosition", list_of
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::VOID, "ROTATION_OBJECT", "GraphicsModule::"
			"getInstance().setObjectRotation", list_of
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::VOID, "SCALE_OBJECT", "GraphicsModule::"
			"getInstance().setObjectScale", list_of
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::VOID, "PLAY_OBJECT", "GraphicsModule::"
			"getInstance().playObjectAnimation", list_of
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::VOID, "STOP_OBJECT", "GraphicsModule::"
			"getInstance().pauseObjectAnimation", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "KEYSTATE", "GraphicsModule::getInstance()"
			".isKeyPressed", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "MOUSECLICK", "GraphicsModule::"
			"getInstance().getButtons"))
		(Function(ValueType::NUMBER, "MOUSEX", "GraphicsModule::getInstance()."
			"getPointerPositionX"))
		(Function(ValueType::NUMBER, "MOUSEY", "GraphicsModule::getInstance()."
			"getPointerPositionY"))
		(Function(ValueType::VOID, "POSITION_MOUSE", "GraphicsModule::"
			"getInstance().setPointerPosition", list_of
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::VOID, "SYNC", "GraphicsModule::getInstance()."
			"update"));
}

Function FunctionList::getFunctionBySample(const Function& sample_function)
	const
{
	SimpleFunctionList::const_iterator end = functions.end();
	SimpleFunctionList::const_iterator finded = std::find(functions.begin(),
		end, sample_function);
	if (finded != end) {
		Function finded_function = *finded;
		finded_function.getParameters() = sample_function.getParameters();
		return finded_function;
	} else {
		SimpleFunctionList finded_functions;
		SimpleFunctionList::const_iterator i = functions.begin();
		for (; i != functions.end(); ++i) {
			Function function = *i;
			if (function.getName() == sample_function.getName()) {
				finded_functions.push_back(function);
			}
		}

		throw UnknownFunctionException(sample_function, finded_functions);
	}
}
