#include "Compiler.h"
#include "exceptions/FailedOpenTemporaryFileException.h"
#include "../utils/os.h"
#include "exceptions/AssemblingOrLinkingException.h"
#include <boost/format.hpp>
#include <cstdio>
#include <fstream>

using namespace thewizardplusplus::wizard_basic_2::compiler::compiler;
using namespace thewizardplusplus::wizard_basic_2::compiler::compiler::exceptions;
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

	#ifdef OS_LINUX
	std::string command = (format("g++ -I./framework/includes -o %1% %2% "
		"-L./framework/libs -lwbf -lAnnaGraphics -lGL -lAnnaSound -lopenal") %
		output_filename % temporary_filename).str();
	#elif defined(OS_WINDOWS)
	std::string command = (format("g++ -I./framework/includes -Wl,-subsystem,"
		"console -o %1% %2% -L./framework/libs -lwbf -lAnnaGraphics -lopengl32 "
		"-lgdi32 -lAnnaSound -lopenal32") % output_filename %
		temporary_filename).str();
	#endif
	int result = std::system(command.c_str());
	if (result) {
		throw AssemblingOrLinkingException();
	}

	remove(temporary_filename.c_str());
}
