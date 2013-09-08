# параметры сборки, специфичные для окружения
win32:BOOST_PATH = E:\\boost_1_54_0
win32:IRRLICHT_INCLUDES_PATH = E:\\irrlicht-1.8\\include
win32:IRRLICHT_LIB_PATH = E:\\irrlicht-1.8\\lib\\Win32-gcc

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
	source/thewizardplusplus/wizard_basic/framework/base/Array.h \
	source/thewizardplusplus/wizard_basic/framework/system/os.h \
	source/thewizardplusplus/wizard_basic/framework/system/SystemModule.h \
	source/thewizardplusplus/wizard_basic/framework/system/system_functions.h \
	source/thewizardplusplus/wizard_basic/framework/graphics/MouseButton.h \
	source/thewizardplusplus/wizard_basic/framework/graphics/EventReceiver.h \
	source/thewizardplusplus/wizard_basic/framework/graphics/Graphics.h \
	source/thewizardplusplus/wizard_basic/framework/graphics/graphics_functions.h
SOURCES += \
	source/thewizardplusplus/wizard_basic/framework/main.cpp \
	source/thewizardplusplus/wizard_basic/framework/exceptions/WizardBasicFrameworkException.cpp \
	source/thewizardplusplus/wizard_basic/framework/base/exceptions/BaseException.cpp \
	source/thewizardplusplus/wizard_basic/framework/base/exceptions/OutOfBoundsException.cpp \
	source/thewizardplusplus/wizard_basic/framework/base/Array.cpp \
	source/thewizardplusplus/wizard_basic/framework/system/SystemModule.cpp \
	source/thewizardplusplus/wizard_basic/framework/system/system_functions.cpp \
	source/thewizardplusplus/wizard_basic/framework/graphics/EventReceiver.cpp \
	source/thewizardplusplus/wizard_basic/framework/graphics/Graphics.cpp \
	source/thewizardplusplus/wizard_basic/framework/graphics/graphics_functions.cpp

# файлы внешних библиотек
win32 {
	INCLUDEPATH += $$BOOST_PATH $$IRRLICHT_INCLUDES_PATH
	LIBS += -L$$IRRLICHT_LIB_PATH -lirrlicht
}

# флаги компилятора
unix | win32-g++ {
	QMAKE_CXXFLAGS += -std=c++98 -pedantic -Wall -W -O3
}
win32-g++ {
	QMAKE_CXXFLAGS += -U__STRICT_ANSI__
}

DEFINES += DEBUG
