# параметры сборки, специфичные для окружения
win32:BOOST_PATH = E:\\boost_1_54_0

# общие настройки
TARGET = wbc
CONFIG += console
CONFIG += warn_on
CONFIG -= qt

# файлы проекта
HEADERS += \
	source/thewizardplusplus/wizard_basic/compiler/parser/exceptions/CodePosition.h \
	source/thewizardplusplus/wizard_basic/compiler/parser/exceptions/ParsingException.h \
	source/thewizardplusplus/wizard_basic/compiler/parser/WizardBasicGrammarRule.h \
	source/thewizardplusplus/wizard_basic/compiler/parser/UnsignedRealParserPolicies.h \
	source/thewizardplusplus/wizard_basic/compiler/parser/WizardBasicGrammar.h \
	source/thewizardplusplus/wizard_basic/compiler/parser/Parser.h \
	source/thewizardplusplus/wizard_basic/compiler/translator/exceptions/TranslateException.h \
	source/thewizardplusplus/wizard_basic/compiler/translator/exceptions/DuplicateLabelsException.h \
	source/thewizardplusplus/wizard_basic/compiler/translator/exceptions/IncorrectOrderOfLabelsException.h \
	source/thewizardplusplus/wizard_basic/compiler/translator/exceptions/DuplicateVariablesException.h \
	source/thewizardplusplus/wizard_basic/compiler/translator/exceptions/JumpsToNonexsistentLabelsExceptions.h \
	source/thewizardplusplus/wizard_basic/compiler/translator/exceptions/UndefinedVariableException.h \
	source/thewizardplusplus/wizard_basic/compiler/translator/exceptions/IllegalOperationException.h \
	source/thewizardplusplus/wizard_basic/compiler/translator/exceptions/IllegalAdditionOperationException.h \
	source/thewizardplusplus/wizard_basic/compiler/translator/exceptions/IllegalMultiplicationOperationException.h \
	source/thewizardplusplus/wizard_basic/compiler/translator/exceptions/IllegalArrayAccessOperationException.h \
	source/thewizardplusplus/wizard_basic/compiler/translator/exceptions/IllegalAssignOperationException.h \
	source/thewizardplusplus/wizard_basic/compiler/translator/exceptions/IllegalConditionOperationException.h \
	source/thewizardplusplus/wizard_basic/compiler/translator/Variable.h \
	source/thewizardplusplus/wizard_basic/compiler/translator/NumberVariable.h \
	source/thewizardplusplus/wizard_basic/compiler/translator/ArrayVariable.h \
	source/thewizardplusplus/wizard_basic/compiler/translator/StringVariable.h \
	source/thewizardplusplus/wizard_basic/compiler/translator/VariableList.h \
	source/thewizardplusplus/wizard_basic/compiler/translator/ValueType.h \
	source/thewizardplusplus/wizard_basic/compiler/translator/Expression.h \
	source/thewizardplusplus/wizard_basic/compiler/translator/AdditionType.h \
	source/thewizardplusplus/wizard_basic/compiler/translator/AdditionExpression.h \
	source/thewizardplusplus/wizard_basic/compiler/translator/MultiplicationType.h \
	source/thewizardplusplus/wizard_basic/compiler/translator/ParenthesesExpression.h \
	source/thewizardplusplus/wizard_basic/compiler/translator/MultiplicationExpression.h \
	source/thewizardplusplus/wizard_basic/compiler/translator/RealConstantExpression.h \
	source/thewizardplusplus/wizard_basic/compiler/translator/IdentifierExpression.h \
	source/thewizardplusplus/wizard_basic/compiler/translator/ArrayAccessExpression.h \
	source/thewizardplusplus/wizard_basic/compiler/translator/FunctionCallExpression.h \
	source/thewizardplusplus/wizard_basic/compiler/translator/ConditionType.h \
	source/thewizardplusplus/wizard_basic/compiler/translator/Program.h \
	source/thewizardplusplus/wizard_basic/compiler/translator/Translator.h \
	source/thewizardplusplus/wizard_basic/compiler/utils/assert.h \
    source/thewizardplusplus/wizard_basic/compiler/exceptions/WizardBasicCompilerException.h \
    source/thewizardplusplus/wizard_basic/compiler/translator/FunctionParameter.h \
    source/thewizardplusplus/wizard_basic/compiler/translator/exceptions/IllegalFunctionCallOperationException.h \
    source/thewizardplusplus/wizard_basic/compiler/translator/Function.h \
    source/thewizardplusplus/wizard_basic/compiler/translator/FunctionList.h \
    source/thewizardplusplus/wizard_basic/compiler/translator/exceptions/IncorrectTypesOfFunctionParameterException.h \
    source/thewizardplusplus/wizard_basic/compiler/translator/exceptions/UnknownFunctionException.h \
    source/thewizardplusplus/wizard_basic/compiler/translator/exceptions/IncorrectNumberOfFunctionParametersException.h
SOURCES += \
	source/thewizardplusplus/wizard_basic/compiler/parser/exceptions/CodePosition.cpp \
	source/thewizardplusplus/wizard_basic/compiler/parser/exceptions/ParsingException.cpp \
	source/thewizardplusplus/wizard_basic/compiler/parser/WizardBasicGrammarRule.cpp \
	source/thewizardplusplus/wizard_basic/compiler/parser/Parser.cpp \
	source/thewizardplusplus/wizard_basic/compiler/translator/exceptions/TranslateException.cpp \
	source/thewizardplusplus/wizard_basic/compiler/translator/exceptions/DuplicateLabelsException.cpp \
	source/thewizardplusplus/wizard_basic/compiler/translator/exceptions/IncorrectOrderOfLabelsException.cpp \
	source/thewizardplusplus/wizard_basic/compiler/translator/exceptions/DuplicateVariablesException.cpp \
	source/thewizardplusplus/wizard_basic/compiler/translator/exceptions/JumpsToNonexsistentLabelsExceptions.cpp \
	source/thewizardplusplus/wizard_basic/compiler/translator/exceptions/UndefinedVariableException.cpp \
	source/thewizardplusplus/wizard_basic/compiler/translator/exceptions/IllegalOperationException.cpp \
	source/thewizardplusplus/wizard_basic/compiler/translator/exceptions/IllegalAdditionOperationException.cpp \
	source/thewizardplusplus/wizard_basic/compiler/translator/exceptions/IllegalMultiplicationOperationException.cpp \
	source/thewizardplusplus/wizard_basic/compiler/translator/exceptions/IllegalArrayAccessOperationException.cpp \
	source/thewizardplusplus/wizard_basic/compiler/translator/exceptions/IllegalAssignOperationException.cpp \
	source/thewizardplusplus/wizard_basic/compiler/translator/exceptions/IllegalConditionOperationException.cpp \
	source/thewizardplusplus/wizard_basic/compiler/translator/Variable.cpp \
	source/thewizardplusplus/wizard_basic/compiler/translator/NumberVariable.cpp \
	source/thewizardplusplus/wizard_basic/compiler/translator/ArrayVariable.cpp \
	source/thewizardplusplus/wizard_basic/compiler/translator/StringVariable.cpp \
	source/thewizardplusplus/wizard_basic/compiler/translator/VariableList.cpp \
	source/thewizardplusplus/wizard_basic/compiler/translator/ValueType.cpp \
	source/thewizardplusplus/wizard_basic/compiler/translator/Expression.cpp \
	source/thewizardplusplus/wizard_basic/compiler/translator/AdditionType.cpp \
	source/thewizardplusplus/wizard_basic/compiler/translator/AdditionExpression.cpp \
	source/thewizardplusplus/wizard_basic/compiler/translator/MultiplicationType.cpp \
	source/thewizardplusplus/wizard_basic/compiler/translator/ParenthesesExpression.cpp \
	source/thewizardplusplus/wizard_basic/compiler/translator/MultiplicationExpression.cpp \
	source/thewizardplusplus/wizard_basic/compiler/translator/RealConstantExpression.cpp \
	source/thewizardplusplus/wizard_basic/compiler/translator/IdentifierExpression.cpp \
	source/thewizardplusplus/wizard_basic/compiler/translator/ArrayAccessExpression.cpp \
	source/thewizardplusplus/wizard_basic/compiler/translator/FunctionCallExpression.cpp \
	source/thewizardplusplus/wizard_basic/compiler/translator/ConditionType.cpp \
	source/thewizardplusplus/wizard_basic/compiler/translator/Program.cpp \
	source/thewizardplusplus/wizard_basic/compiler/translator/Translator.cpp \
	source/thewizardplusplus/wizard_basic/compiler/main.cpp \
    source/thewizardplusplus/wizard_basic/compiler/exceptions/WizardBasicCompilerException.cpp \
    source/thewizardplusplus/wizard_basic/compiler/translator/FunctionParameter.cpp \
    source/thewizardplusplus/wizard_basic/compiler/translator/exceptions/IllegalFunctionCallOperationException.cpp \
    source/thewizardplusplus/wizard_basic/compiler/translator/Function.cpp \
    source/thewizardplusplus/wizard_basic/compiler/translator/FunctionList.cpp \
    source/thewizardplusplus/wizard_basic/compiler/translator/exceptions/IncorrectTypesOfFunctionParameterException.cpp \
    source/thewizardplusplus/wizard_basic/compiler/translator/exceptions/UnknownFunctionException.cpp \
    source/thewizardplusplus/wizard_basic/compiler/translator/exceptions/IncorrectNumberOfFunctionParametersException.cpp

# файлы внешних библиотек
win32 {
	INCLUDEPATH += $$BOOST_PATH
}

# флаги компилятора
unix | win32-g++ {
	QMAKE_CXXFLAGS += -std=c++98 -pedantic -Wall -W -O3
}
win32-g++ {
	QMAKE_CXXFLAGS += -U__STRICT_ANSI__
}
