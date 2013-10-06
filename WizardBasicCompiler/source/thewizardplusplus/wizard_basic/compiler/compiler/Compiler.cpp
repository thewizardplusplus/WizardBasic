#include "Compiler.h"
#include "exceptions/FailedOpenTemporaryFileException.h"
#include "exceptions/AssemblingOrLinkingException.h"
#include <boost/format.hpp>
#include <cstdio>
#include <fstream>

using namespace thewizardplusplus::wizard_basic::compiler::compiler;
using namespace thewizardplusplus::wizard_basic::compiler::compiler::exceptions;
using namespace boost;

void Compiler::compile(const std::string& translated_code, const std::string&
	output_filename)
{
	std::string temporary_filename = std::string(std::tmpnam(NULL)) + ".cpp";
	std::ofstream out(temporary_filename.c_str());
	if (!out.is_open()) {
		throw FailedOpenTemporaryFileException(temporary_filename);
	}
	out << translated_code;
	out.close();

	std::string command = (format("g++ -I./framework/includes -Wl,-subsystem,"
		"console -o %1% %2% -L./framework/libs -lwbf") % output_filename %
		temporary_filename).str();
	int result = std::system(command.c_str());
	if (result) {
		throw AssemblingOrLinkingException();
	}

	remove(temporary_filename.c_str());
}
