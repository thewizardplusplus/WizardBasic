# параметры сборки, специфичные для окружения
win32:BOOST_PATH = E:\\boost_1_54_0

# общие настройки
TARGET = wbf
CONFIG += console
CONFIG += warn_on
CONFIG -= qt

# файлы проекта
HEADERS += \
	source/thewizardplusplus/wizard_basic/framework/exceptions/WizardBasicFrameworkException.h \
	source/thewizardplusplus/wizard_basic/framework/base/exceptions/BaseException.h \
	source/thewizardplusplus/wizard_basic/framework/base/exceptions/OutOfBoundsException.h \
	source/thewizardplusplus/wizard_basic/framework/base/Array.h
SOURCES += \
	source/thewizardplusplus/wizard_basic/framework/main.cpp \
	source/thewizardplusplus/wizard_basic/framework/exceptions/WizardBasicFrameworkException.cpp \
	source/thewizardplusplus/wizard_basic/framework/base/exceptions/BaseException.cpp \
	source/thewizardplusplus/wizard_basic/framework/base/exceptions/OutOfBoundsException.cpp \
	source/thewizardplusplus/wizard_basic/framework/base/Array.cpp

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
