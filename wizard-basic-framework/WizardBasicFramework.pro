# параметры сборки, специфичные для окружения
win32:BOOST_PATH = E:\\boost_1_54_0
ANNA_GRAPHICS_INCLUDES_PATH = E:\\projects\\current\\AnnaGraphics\\release\\includes
ANNA_GRAPHICS_LIBS_PATH = E:\\projects\\current\\AnnaGraphics\\release\\libs
ANNA_SOUND_INCLUDES_PATH = E:\\projects\\current\\AnnaSound\\release\\includes
ANNA_SOUND_LIBS_PATH = E:\\projects\\current\\AnnaSound\\release\\libs
win32:OPENAL_LIB_PATH = E:\\openal\\lib\\Win32

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
	source/thewizardplusplus/wizard_basic/framework/utils/os.h \
	source/thewizardplusplus/wizard_basic/framework/exceptions/WizardBasicFrameworkException.h \
	source/thewizardplusplus/wizard_basic/framework/base/exceptions/BaseException.h \
	source/thewizardplusplus/wizard_basic/framework/base/exceptions/OutOfBoundsException.h \
	source/thewizardplusplus/wizard_basic/framework/base/Array.h \
	source/thewizardplusplus/wizard_basic/framework/system/exceptions/SystemException.h \
	source/thewizardplusplus/wizard_basic/framework/system/exceptions/InvalidOpenFileModeException.h \
	source/thewizardplusplus/wizard_basic/framework/system/exceptions/OpenFileException.h \
	source/thewizardplusplus/wizard_basic/framework/system/exceptions/InvalidFileIdException.h \
	source/thewizardplusplus/wizard_basic/framework/system/SystemModulePrivate.h \
	source/thewizardplusplus/wizard_basic/framework/system/SystemModule.h \
	source/thewizardplusplus/wizard_basic/framework/graphics/exceptions/GraphicsException.h \
	source/thewizardplusplus/wizard_basic/framework/graphics/exceptions/InvalidObjectIdException.h \
	source/thewizardplusplus/wizard_basic/framework/graphics/GraphicsModulePrivate.h \
	source/thewizardplusplus/wizard_basic/framework/graphics/GraphicsModule.h \
	source/thewizardplusplus/wizard_basic/framework/sound/exceptions/SoundException.h \
	source/thewizardplusplus/wizard_basic/framework/sound/exceptions/InvalidSoundIdException.h \
	source/thewizardplusplus/wizard_basic/framework/sound/SoundModulePrivate.h \
	source/thewizardplusplus/wizard_basic/framework/sound/SoundModule.h
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
	source/thewizardplusplus/wizard_basic/framework/graphics/exceptions/InvalidObjectIdException.cpp \
	source/thewizardplusplus/wizard_basic/framework/graphics/GraphicsModulePrivate.cpp \
	source/thewizardplusplus/wizard_basic/framework/graphics/GraphicsModule.cpp \
	source/thewizardplusplus/wizard_basic/framework/sound/exceptions/SoundException.cpp \
	source/thewizardplusplus/wizard_basic/framework/sound/exceptions/InvalidSoundIdException.cpp \
	source/thewizardplusplus/wizard_basic/framework/sound/SoundModulePrivate.cpp \
	source/thewizardplusplus/wizard_basic/framework/sound/SoundModule.cpp

# файлы внешних библиотек
INCLUDEPATH += $$ANNA_GRAPHICS_INCLUDES_PATH $$ANNA_SOUND_INCLUDES_PATH
win32:INCLUDEPATH += $$BOOST_PATH
#LIBS += -L$$ANNA_GRAPHICS_LIBS_PATH -lAnnaGraphics -L$$ANNA_SOUND_LIBS_PATH -lAnnaSound
#unix:LIBS += -lGL
#win32:LIBS += -lopengl32 -lgdi32  -L$$OPENAL_LIB_PATH -lopenal32

# флаги компилятора
unix | win32-g++ {
	QMAKE_CXXFLAGS += -std=c++03 -pedantic -Wall -W -O2
}
win32-g++ {
	QMAKE_CXXFLAGS += -U__STRICT_ANSI__
}
