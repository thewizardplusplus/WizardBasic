# параметры сборки, специфичные для окружения
ANNA_GRAPHICS_LIBS_PATH = E:\\projects\\current\\AnnaGraphics\\release\\libs
ANNA_SOUND_LIBS_PATH = E:\\projects\\current\\AnnaSound\\release\\libs
win32:OPENAL_LIB_PATH = E:\\openal\\lib\\Win32

# общие настройки
CONFIG += console
CONFIG += warn_on
CONFIG -= qt

# файлы внешних библиотек
INCLUDEPATH += ./../release/includes/
LIBS += -L./../release/libs/ -lwbf -L$$ANNA_GRAPHICS_LIBS_PATH -lAnnaGraphics -L$$ANNA_SOUND_LIBS_PATH -lAnnaSound
unix:LIBS += -lGL
win32:LIBS += -lopengl32 -lgdi32 -L$$OPENAL_LIB_PATH -lopenal32

# файлы проекта
SOURCES += \
	main.cpp

# флаги компилятора
unix | win32-g++ {
	QMAKE_CXXFLAGS += -std=c++03 -pedantic -Wall -W -O2
}
win32-g++ {
	QMAKE_CXXFLAGS += -U__STRICT_ANSI__
}
