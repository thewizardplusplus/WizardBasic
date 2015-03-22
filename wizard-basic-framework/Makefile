SOURCE_BASE = source/thewizardplusplus/wizard-basic-2/framework/
BASE_SOURCE = $(SOURCE_BASE)base/
BASE_EXCEPTIONS_SOURCE = $(BASE_SOURCE)exceptions/
GRAPHICS_SOURCE = $(SOURCE_BASE)graphics/
GRAPHICS_EXCEPTIONS_SOURCE = $(GRAPHICS_SOURCE)exceptions/
SOUND_SOURCE = $(SOURCE_BASE)sound/
SOUND_EXCEPTIONS_SOURCE = $(SOUND_SOURCE)exceptions/
SYSTEM_SOURCE = $(SOURCE_BASE)system/
SYSTEM_EXCEPTIONS_SOURCE = $(SYSTEM_SOURCE)exceptions/
OBJECTS = \
	$(BASE_SOURCE)Array.o \
	$(BASE_EXCEPTIONS_SOURCE)BaseException.o \
	$(BASE_EXCEPTIONS_SOURCE)OutOfBoundsException.o \
	$(SOURCE_BASE)exceptions/WizardBasicFrameworkException.o \
	$(GRAPHICS_SOURCE)GraphicsModule.o \
	$(GRAPHICS_SOURCE)GraphicsModulePrivate.o \
	$(GRAPHICS_EXCEPTIONS_SOURCE)GraphicsException.o \
	$(GRAPHICS_EXCEPTIONS_SOURCE)InvalidObjectIdException.o \
	$(SOUND_SOURCE)SoundModule.o \
	$(SOUND_SOURCE)SoundModulePrivate.o \
	$(SOUND_EXCEPTIONS_SOURCE)InvalidSoundIdException.o \
	$(SOUND_EXCEPTIONS_SOURCE)SoundException.o \
	$(SYSTEM_SOURCE)SystemModule.o \
	$(SYSTEM_SOURCE)SystemModulePrivate.o \
	$(SYSTEM_EXCEPTIONS_SOURCE)InvalidFileIdException.o \
	$(SYSTEM_EXCEPTIONS_SOURCE)InvalidOpenFileModeException.o \
	$(SYSTEM_EXCEPTIONS_SOURCE)OpenFileException.o \
	$(SYSTEM_EXCEPTIONS_SOURCE)SystemException.o
BUILD = ../build/framework/
BUILD_HEADERS = $(BUILD)headers/wizard_basic_2_framework/
BUILD_LIBRARIES = $(BUILD)libraries/wizard_basic_2_framework/
CXXFLAGS += -std=c++03 -Wpedantic -Wall -Wextra -O2

.PHONY: clean

main: $(OBJECTS)
	mkdir -p $(BUILD_LIBRARIES)
	$(AR) crs $(BUILD_LIBRARIES)libwb2f.a $(OBJECTS)

	rm -rf $(BUILD_HEADERS)
	mkdir -p $(BUILD_HEADERS)
	rsync -r --include="*/" --include="*.h" --exclude="*" $(SOURCE_BASE) $(BUILD_HEADERS)

clean:
	find . -name "*.o" -type f -delete
