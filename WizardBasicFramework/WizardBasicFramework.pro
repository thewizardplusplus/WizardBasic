# параметры сборки, специфичные для окружения
win32:BOOST_PATH = E:\\boost_1_54_0
win32:ANNA_GRAPHICS_INCLUDES_PATH = E:\\projects\\current\\AnnaGraphics\\release\\includes
win32:ANNA_GRAPHICS_LIBS_PATH = E:\\projects\\current\\AnnaGraphics\\release\\libs

# общие настройки
TARGET = wbf
#TEMPLATE = lib
#CONFIG += staticlib
CONFIG += console
CONFIG += warn_on
CONFIG -= qt

# файлы проекта
HEADERS += \
	source/thewizardplusplus/wizard_basic/framework/utils/Converter.h \
	source/thewizardplusplus/wizard_basic/framework/exceptions/WizardBasicFrameworkException.h \
	source/thewizardplusplus/wizard_basic/framework/base/exceptions/BaseException.h \
	source/thewizardplusplus/wizard_basic/framework/base/exceptions/OutOfBoundsException.h \
	source/thewizardplusplus/wizard_basic/framework/base/Array.h \
	source/thewizardplusplus/wizard_basic/framework/system/os.h \
	source/thewizardplusplus/wizard_basic/framework/system/SystemModulePrivate.h \
	source/thewizardplusplus/wizard_basic/framework/system/SystemModule.h \
	source/thewizardplusplus/wizard_basic/framework/graphics/GraphicsModule.h \
	source/thewizardplusplus/wizard_basic/framework/graphics/GraphicsModulePrivate.h
SOURCES += \
	#source/thewizardplusplus/wizard_basic/framework/main.cpp \
	source/thewizardplusplus/wizard_basic/framework/exceptions/WizardBasicFrameworkException.cpp \
	source/thewizardplusplus/wizard_basic/framework/base/exceptions/BaseException.cpp \
	source/thewizardplusplus/wizard_basic/framework/base/exceptions/OutOfBoundsException.cpp \
	source/thewizardplusplus/wizard_basic/framework/base/Array.cpp \
	source/thewizardplusplus/wizard_basic/framework/system/SystemModulePrivate.cpp \
	source/thewizardplusplus/wizard_basic/framework/system/SystemModule.cpp \
	source/thewizardplusplus/wizard_basic/framework/graphics/GraphicsModule.cpp \
	source/thewizardplusplus/wizard_basic/framework/graphics/GraphicsModulePrivate.cpp

# файлы внешних библиотек
win32 {
	INCLUDEPATH += $$BOOST_PATH $$ANNA_GRAPHICS_INCLUDES_PATH
	LIBS += -L$$ANNA_GRAPHICS_LIBS_PATH -lAnnaGraphics
}

# флаги компилятора
unix | win32-g++ {
	QMAKE_CXXFLAGS += -std=c++98 -pedantic -Wall -W -O2
}
win32-g++ {
	QMAKE_CXXFLAGS += -U__STRICT_ANSI__
}
