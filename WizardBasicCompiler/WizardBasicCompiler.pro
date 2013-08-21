# параметры сборки, специфичные для окружения
win32:BOOST_PATH = E:\\boost_1_54_0

# общие настройки
TARGET = wbc
CONFIG += console
CONFIG += warn_on
CONFIG -= qt

# файлы проекта
HEADERS += \
	source/thewizardplusplus/wizard_basic/exceptions/WizardBasicException.h \
	source/thewizardplusplus/wizard_basic/parser/exceptions/CodePosition.h \
	source/thewizardplusplus/wizard_basic/parser/exceptions/ParsingException.h \
	source/thewizardplusplus/wizard_basic/parser/WizardBasicGrammarRule.h \
	source/thewizardplusplus/wizard_basic/parser/UnsignedRealParserPolicies.h \
	source/thewizardplusplus/wizard_basic/parser/WizardBasicGrammar.h \
	source/thewizardplusplus/wizard_basic/parser/Parser.h \
	source/thewizardplusplus/wizard_basic/translator/exceptions/TranslateException.h \
	source/thewizardplusplus/wizard_basic/translator/exceptions/DuplicateLabelsException.h \
	source/thewizardplusplus/wizard_basic/translator/exceptions/IncorrectOrderOfLabelsException.h \
	source/thewizardplusplus/wizard_basic/translator/exceptions/DuplicateVariablesException.h \
	source/thewizardplusplus/wizard_basic/translator/exceptions/JumpsToNonexsistentLabelsExceptions.h \
	source/thewizardplusplus/wizard_basic/translator/exceptions/UndefinedIdentifierException.h \
	source/thewizardplusplus/wizard_basic/translator/exceptions/IllegalOperationException.h \
	source/thewizardplusplus/wizard_basic/translator/exceptions/IllegalAdditionOperationException.h \
	source/thewizardplusplus/wizard_basic/translator/exceptions/IllegalMultiplicationOperationException.h \
	source/thewizardplusplus/wizard_basic/translator/exceptions/IllegalArrayAccessOperationException.h \
	source/thewizardplusplus/wizard_basic/translator/exceptions/IllegalAssignOperationException.h \
	source/thewizardplusplus/wizard_basic/translator/exceptions/IllegalConditionOperationException.h \
	source/thewizardplusplus/wizard_basic/translator/Variable.h \
	source/thewizardplusplus/wizard_basic/translator/NumberVariable.h \
	source/thewizardplusplus/wizard_basic/translator/IndexVariable.h \
	source/thewizardplusplus/wizard_basic/translator/ArrayVariable.h \
	source/thewizardplusplus/wizard_basic/translator/StringVariable.h \
	source/thewizardplusplus/wizard_basic/translator/VariableList.h \
	source/thewizardplusplus/wizard_basic/translator/ValueType.h \
	source/thewizardplusplus/wizard_basic/translator/Expression.h \
	source/thewizardplusplus/wizard_basic/translator/AdditionType.h \
	source/thewizardplusplus/wizard_basic/translator/AdditionExpression.h \
	source/thewizardplusplus/wizard_basic/translator/MultiplicationType.h \
	source/thewizardplusplus/wizard_basic/translator/ParenthesesExpression.h \
	source/thewizardplusplus/wizard_basic/translator/MultiplicationExpression.h \
	source/thewizardplusplus/wizard_basic/translator/RealConstantExpression.h \
	source/thewizardplusplus/wizard_basic/translator/IdentifierExpression.h \
	source/thewizardplusplus/wizard_basic/translator/ArrayAccessExpression.h \
	source/thewizardplusplus/wizard_basic/translator/FunctionCallExpression.h \
	source/thewizardplusplus/wizard_basic/translator/ConditionType.h \
	source/thewizardplusplus/wizard_basic/translator/Program.h \
	source/thewizardplusplus/wizard_basic/translator/Translator.h \
	source/thewizardplusplus/wizard_basic/utils/assert.h
SOURCES += \
	source/thewizardplusplus/wizard_basic/exceptions/WizardBasicException.cpp \
	source/thewizardplusplus/wizard_basic/parser/exceptions/CodePosition.cpp \
	source/thewizardplusplus/wizard_basic/parser/exceptions/ParsingException.cpp \
	source/thewizardplusplus/wizard_basic/parser/WizardBasicGrammarRule.cpp \
	source/thewizardplusplus/wizard_basic/parser/Parser.cpp \
	source/thewizardplusplus/wizard_basic/translator/exceptions/TranslateException.cpp \
	source/thewizardplusplus/wizard_basic/translator/exceptions/DuplicateLabelsException.cpp \
	source/thewizardplusplus/wizard_basic/translator/exceptions/IncorrectOrderOfLabelsException.cpp \
	source/thewizardplusplus/wizard_basic/translator/exceptions/DuplicateVariablesException.cpp \
	source/thewizardplusplus/wizard_basic/translator/exceptions/JumpsToNonexsistentLabelsExceptions.cpp \
	source/thewizardplusplus/wizard_basic/translator/exceptions/UndefinedIdentifierException.cpp \
	source/thewizardplusplus/wizard_basic/translator/exceptions/IllegalOperationException.cpp \
	source/thewizardplusplus/wizard_basic/translator/exceptions/IllegalAdditionOperationException.cpp \
	source/thewizardplusplus/wizard_basic/translator/exceptions/IllegalMultiplicationOperationException.cpp \
	source/thewizardplusplus/wizard_basic/translator/exceptions/IllegalArrayAccessOperationException.cpp \
	source/thewizardplusplus/wizard_basic/translator/exceptions/IllegalAssignOperationException.cpp \
	source/thewizardplusplus/wizard_basic/translator/exceptions/IllegalConditionOperationException.cpp \
	source/thewizardplusplus/wizard_basic/translator/Variable.cpp \
	source/thewizardplusplus/wizard_basic/translator/NumberVariable.cpp \
	source/thewizardplusplus/wizard_basic/translator/IndexVariable.cpp \
	source/thewizardplusplus/wizard_basic/translator/ArrayVariable.cpp \
	source/thewizardplusplus/wizard_basic/translator/StringVariable.cpp \
	source/thewizardplusplus/wizard_basic/translator/VariableList.cpp \
	source/thewizardplusplus/wizard_basic/translator/ValueType.cpp \
	source/thewizardplusplus/wizard_basic/translator/Expression.cpp \
	source/thewizardplusplus/wizard_basic/translator/AdditionType.cpp \
	source/thewizardplusplus/wizard_basic/translator/AdditionExpression.cpp \
	source/thewizardplusplus/wizard_basic/translator/MultiplicationType.cpp \
	source/thewizardplusplus/wizard_basic/translator/ParenthesesExpression.cpp \
	source/thewizardplusplus/wizard_basic/translator/MultiplicationExpression.cpp \
	source/thewizardplusplus/wizard_basic/translator/RealConstantExpression.cpp \
	source/thewizardplusplus/wizard_basic/translator/IdentifierExpression.cpp \
	source/thewizardplusplus/wizard_basic/translator/ArrayAccessExpression.cpp \
	source/thewizardplusplus/wizard_basic/translator/FunctionCallExpression.cpp \
	source/thewizardplusplus/wizard_basic/translator/ConditionType.cpp \
	source/thewizardplusplus/wizard_basic/translator/Program.cpp \
	source/thewizardplusplus/wizard_basic/translator/Translator.cpp \
	source/thewizardplusplus/wizard_basic/main.cpp

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
