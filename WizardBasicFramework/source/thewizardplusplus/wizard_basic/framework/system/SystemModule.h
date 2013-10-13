#ifndef SYSTEM_H
#define SYSTEM_H

#include "../base/Array.h"
#include <cstdio>
#include <list>
#include <memory>

namespace thewizardplusplus {
namespace wizard_basic {
namespace framework {
namespace system {

class SystemModulePrivate;

class SystemModule {
public:
	static void trace(float number);
	static void trace(const base::Array& string);
	static SystemModule& getInstance(void);

	float getRandomNumber(void) const;
	float getTimeFromStartInS(void) const;
	float fileOpen(const base::Array& filename, float mode);
	float fileInput(float file_id) const;
	void fileOutput(float file_id, float number) const;
	void fileOutput(float file_id, const base::Array& string) const;
	void fileClose(float file_id);

private:
	typedef std::list<FILE*> FileList;

	std::auto_ptr<SystemModulePrivate> private_realization;
	FileList                           files;

	SystemModule(void);
	SystemModule(const SystemModule& sample);
	SystemModule& operator=(const SystemModule& sample);
	FILE* getFileById(float file_id) const;
};

}
}
}
}
#endif
