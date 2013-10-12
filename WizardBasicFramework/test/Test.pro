# параметры сборки, специфичные для окружения
ANNA_GRAPHICS_INCLUDES_PATH = /home/istarstein/AnnaGraphics/includes
ANNA_GRAPHICS_LIBS_PATH = /home/istarstein/AnnaGraphics/libs

# общие настройки
CONFIG += console
CONFIG += warn_on
CONFIG -= qt

# файлы внешних библиотек
INCLUDEPATH += ./../release/includes/
LIBS += -L./../release/libs/ -lwbf -L$$ANNA_GRAPHICS_LIBS_PATH -lAnnaGraphics -lGL

# файлы проекта
SOURCES += \
	main.cpp

# флаги компилятора
unix | win32-g++ {
	QMAKE_CXXFLAGS += -std=c++98 -pedantic -Wall -W -O2
}
win32-g++ {
	QMAKE_CXXFLAGS += -U__STRICT_ANSI__
}
