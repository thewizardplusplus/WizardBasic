SOURCE_BASE = source/thewizardplusplus/wizard-basic-2/compiler/
COMPILER_SOURCE = $(SOURCE_BASE)compiler/
COMPILER_EXCEPTIONS_SOURCE = $(COMPILER_SOURCE)exceptions/
PARSER_SOURCE = $(SOURCE_BASE)parser/
PARSER_EXCEPTIONS_SOURCE = $(PARSER_SOURCE)exceptions/
TRANSLATOR_SOURCE = $(SOURCE_BASE)translator/
TRANSLATOR_EXCEPTIONS_SOURCE = $(TRANSLATOR_SOURCE)exceptions/
OBJECTS = \
	$(SOURCE_BASE)compiler/Compiler.o \
	$(COMPILER_EXCEPTIONS_SOURCE)CompilerException.o \
	$(COMPILER_EXCEPTIONS_SOURCE)FailedOpenTemporaryFileException.o \
	$(COMPILER_EXCEPTIONS_SOURCE)AssemblingOrLinkingException.o \
	$(SOURCE_BASE)exceptions/WizardBasicCompilerException.o \
	$(PARSER_SOURCE)WizardBasicGrammarRule.o \
	$(PARSER_SOURCE)Parser.o \
	$(PARSER_EXCEPTIONS_SOURCE)CodePosition.o \
	$(PARSER_EXCEPTIONS_SOURCE)ParsingException.o \
	$(TRANSLATOR_SOURCE)Variable.o \
	$(TRANSLATOR_SOURCE)NumberVariable.o \
	$(TRANSLATOR_SOURCE)ArrayVariable.o \
	$(TRANSLATOR_SOURCE)StringVariable.o \
	$(TRANSLATOR_SOURCE)VariableList.o \
	$(TRANSLATOR_SOURCE)ValueType.o \
	$(TRANSLATOR_SOURCE)Expression.o \
	$(TRANSLATOR_SOURCE)AdditionType.o \
	$(TRANSLATOR_SOURCE)AdditionExpression.o \
	$(TRANSLATOR_SOURCE)MultiplicationType.o \
	$(TRANSLATOR_SOURCE)ParenthesesExpression.o \
	$(TRANSLATOR_SOURCE)MultiplicationExpression.o \
	$(TRANSLATOR_SOURCE)RealConstantExpression.o \
	$(TRANSLATOR_SOURCE)IdentifierExpression.o \
	$(TRANSLATOR_SOURCE)ArrayAccessExpression.o \
	$(TRANSLATOR_SOURCE)FunctionCallExpression.o \
	$(TRANSLATOR_SOURCE)ConditionType.o \
	$(TRANSLATOR_SOURCE)FunctionParameter.o \
	$(TRANSLATOR_SOURCE)Function.o \
	$(TRANSLATOR_SOURCE)FunctionList.o \
	$(TRANSLATOR_SOURCE)Program.o \
	$(TRANSLATOR_SOURCE)Translator.o \
	$(TRANSLATOR_EXCEPTIONS_SOURCE)TranslateException.o \
	$(TRANSLATOR_EXCEPTIONS_SOURCE)DuplicateLabelsException.o \
	$(TRANSLATOR_EXCEPTIONS_SOURCE)IncorrectOrderOfLabelsException.o \
	$(TRANSLATOR_EXCEPTIONS_SOURCE)DuplicateVariablesException.o \
	$(TRANSLATOR_EXCEPTIONS_SOURCE)JumpsToNonexsistentLabelsExceptions.o \
	$(TRANSLATOR_EXCEPTIONS_SOURCE)UndefinedVariableException.o \
	$(TRANSLATOR_EXCEPTIONS_SOURCE)IllegalOperationException.o \
	$(TRANSLATOR_EXCEPTIONS_SOURCE)IllegalAdditionOperationException.o \
	$(TRANSLATOR_EXCEPTIONS_SOURCE)IllegalMultiplicationOperationException.o \
	$(TRANSLATOR_EXCEPTIONS_SOURCE)IllegalArrayAccessOperationException.o \
	$(TRANSLATOR_EXCEPTIONS_SOURCE)IllegalAssignOperationException.o \
	$(TRANSLATOR_EXCEPTIONS_SOURCE)IllegalConditionOperationException.o \
	$(TRANSLATOR_EXCEPTIONS_SOURCE)IllegalFunctionCallOperationException.o \
	$(TRANSLATOR_EXCEPTIONS_SOURCE)UnknownFunctionException.o \
	$(SOURCE_BASE)main.o
BUILD_BINARIES = ../build/binaries/
CXXFLAGS += -std=c++03 -Wpedantic -Wall -Wextra -O2

.PHONY: clean

main: $(OBJECTS)
	mkdir -p $(BUILD_BINARIES)
	$(CXX) $(OBJECTS) -o $(BUILD_BINARIES)wb2c

clean:
	find . -name "*.o" -type f -delete
