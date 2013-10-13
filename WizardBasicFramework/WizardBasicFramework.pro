# параметры сборки, специфичные для окружения
win32:BOOST_PATH = E:\\boost_1_54_0
ANNA_GRAPHICS_INCLUDES_PATH = E:\\projects\\current\\AnnaGraphics\\release\\includes
ANNA_GRAPHICS_LIBS_PATH = E:\\projects\\current\\AnnaGraphics\\release\\libs

# общие настройки
TARGET = wbf
TEMPLATE = lib
CONFIG += staticlib
#CONFIG += console
CONFIG += warn_on
CONFIG -= qt

# файлы проекта
HEADERS += \
	source/thewizardplusplus/wizard_basic/framework/utils/Converter.h \
	source/thewizardplusplus/wizard_basic/framework/exceptions/WizardBasicFrameworkException.h \
	source/thewizardplusplus/wizard_basic/framework/base/exceptions/BaseException.h \
	source/thewizardplusplus/wizard_basic/framework/base/exceptions/OutOfBoundsException.h \
	source/thewizardplusplus/wizard_basic/framework/base/Array.h \
	source/thewizardplusplus/wizard_basic/framework/system/exceptions/SystemException.h \
	source/thewizardplusplus/wizard_basic/framework/system/exceptions/InvalidOpenFileModeException.h \
	source/thewizardplusplus/wizard_basic/framework/system/exceptions/OpenFileException.h \
	source/thewizardplusplus/wizard_basic/framework/system/exceptions/InvalidFileIdException.h \
	source/thewizardplusplus/wizard_basic/framework/system/os.h \
	source/thewizardplusplus/wizard_basic/framework/system/SystemModulePrivate.h \
	source/thewizardplusplus/wizard_basic/framework/system/SystemModule.h \
	source/thewizardplusplus/wizard_basic/framework/graphics/exceptions/GraphicsException.h \
	source/thewizardplusplus/wizard_basic/framework/graphics/exceptions/OpenObjectFileException.h \
	source/thewizardplusplus/wizard_basic/framework/graphics/exceptions/InvalidObjectIdException.h \
	source/thewizardplusplus/wizard_basic/framework/graphics/GraphicsModulePrivate.h \
	source/thewizardplusplus/wizard_basic/framework/graphics/GraphicsModule.h
SOURCES += \
	#source/thewizardplusplus/wizard_basic/framework/main.cpp \
	source/thewizardplusplus/wizard_basic/framework/exceptions/WizardBasicFrameworkException.cpp \
	source/thewizardplusplus/wizard_basic/framework/base/exceptions/BaseException.cpp \
	source/thewizardplusplus/wizard_basic/framework/base/exceptions/OutOfBoundsException.cpp \
	source/thewizardplusplus/wizard_basic/framework/base/Array.cpp \
	source/thewizardplusplus/wizard_basic/framework/system/exceptions/SystemException.cpp \
	source/thewizardplusplus/wizard_basic/framework/system/exceptions/InvalidOpenFileModeException.cpp \
	source/thewizardplusplus/wizard_basic/framework/system/exceptions/OpenFileException.cpp \
	source/thewizardplusplus/wizard_basic/framework/system/exceptions/InvalidFileIdException.cpp \
	source/thewizardplusplus/wizard_basic/framework/system/SystemModulePrivate.cpp \
	source/thewizardplusplus/wizard_basic/framework/system/SystemModule.cpp \
	source/thewizardplusplus/wizard_basic/framework/graphics/exceptions/GraphicsException.cpp \
	source/thewizardplusplus/wizard_basic/framework/graphics/exceptions/OpenObjectFileException.cpp \
	source/thewizardplusplus/wizard_basic/framework/graphics/exceptions/InvalidObjectIdException.cpp \
	source/thewizardplusplus/wizard_basic/framework/graphics/GraphicsModulePrivate.cpp \
	source/thewizardplusplus/wizard_basic/framework/graphics/GraphicsModule.cpp

# файлы внешних библиотек
INCLUDEPATH += $$ANNA_GRAPHICS_INCLUDES_PATH
win32:INCLUDEPATH += $$BOOST_PATH
#LIBS += -L$$ANNA_GRAPHICS_LIBS_PATH -lAnnaGraphics
#unix:LIBS += -lGL
#win32:LIBS += -lopengl32 -lgdi32

# флаги компилятора
unix | win32-g++ {
	QMAKE_CXXFLAGS += -std=c++98 -pedantic -Wall -W -O2
}
win32-g++ {
	QMAKE_CXXFLAGS += -U__STRICT_ANSI__
}
