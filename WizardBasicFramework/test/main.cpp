#include <SystemModule.h>
#include <exceptions/WizardBasicFrameworkException.h>
#include <iostream>

using namespace thewizardplusplus::wizard_basic::framework::base;
using namespace thewizardplusplus::wizard_basic::framework::system;
using namespace thewizardplusplus::wizard_basic::framework::exceptions;

int main(void) {
	try {
		WIZARD_BASIC_STRING(filename1, "test");
		WIZARD_BASIC_STRING(filename2, "new");
		WIZARD_BASIC_STRING(test_string, "Test!");

		float file1 = SystemModule::getInstance().fileOpen(filename1, 0);
		float file2 = SystemModule::getInstance().fileOpen(filename2, 1);
		while (true) {
			float symbol = SystemModule::getInstance().fileInput(file1);
			if (symbol == -1.0f) {
				break;
			}

			SystemModule::getInstance().fileOutput(file2, symbol);
		}

		SystemModule::getInstance().fileClose(file1);
		SystemModule::getInstance().fileClose(file2);

		float file3 = SystemModule::getInstance().fileOpen(filename2, 2);
		SystemModule::getInstance().fileOutput(file3, test_string);
		SystemModule::getInstance().fileClose(file3);
	} catch (const WizardBasicFrameworkException& exception) {
		std::cerr << exception.what() << std::endl;
	}
}
