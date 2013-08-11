#include "parser/Parser.h"
#include "parser/WizardBasicGrammar.h"
#include "exceptions/WizardBasicException.h"
#include <boost/spirit/home/classic/tree/tree_to_xml.hpp>

using namespace thewizardplusplus::wizard_basic;
using namespace thewizardplusplus::wizard_basic::parser;
using namespace thewizardplusplus::wizard_basic::exceptions;

int main(void) {
	std::string code =
		"10  REM Quick sort.\n"
		"20  REM Based on public-domain C implementation by Darel Rex Finley:\n"
		"30  REM     http://alienryderflex.com/quicksort/\n"
		"40\n"
		"50  DIM array[10]\n"
		"60  LET i = 0\n"
		"70      LET array[i] = Random(1, 10)\n"
		"80      LET i = i + 1\n"
		"90      IF i < Length(array) THEN 70\n"
		"100\n"
		"110 DIM starts[300]\n"
		"120 DIM ends[300]\n"
		"130 LET ends[0] = Length(array)\n"
		"140 LET i = 0\n"
		"150     IF i < 0 THEN 570\n"
		"160     LET left = starts[i]\n"
		"170     LET right = ends[i] - 1\n"
		"180     IF left < right THEN 210\n"
		"190     LET i = i - 1\n"
		"200     GOTO 150\n"
		"210     LET piv = array[left]\n"
		"220         IF left < right THEN 240\n"
		"230         GOTO 430\n"
		"240             IF array[right] < piv THEN 290\n"
		"250             IF left > right THEN 290\n"
		"260             IF left = right THEN 290\n"
		"270             LET right = right - 1\n"
		"280             GOTO 240\n"
		"290         IF left > right THEN 330\n"
		"300         IF left = right THEN 330\n"
		"310         LET array[left] = array[right]\n"
		"320         LET left = left + 1\n"
		"330             IF array[left] > piv THEN 380\n"
		"340             IF left > right THEN 380\n"
		"350             IF left = right THEN 380\n"
		"360             LET left = left + 1\n"
		"370             GOTO 330\n"
		"380         IF left > right THEN 430\n"
		"390         IF left = right THEN 430\n"
		"400         LET array[right] = array[left]\n"
		"410         LET right = right - 1\n"
		"420         GOTO 220\n"
		"430     LET array[left] = piv\n"
		"440     LET starts[i + 1] = left + 1\n"
		"450     LET ends[i + 1] = ends[i]\n"
		"460     LET ends[i] = left\n"
		"470     LET i = i + 1\n"
		"480     IF ends[i] - starts[i] > ends[i - 1] - starts[i - 1] THEN "
			"500\n"
		"490     GOTO 560\n"
		"500     LET temporary = starts[i]\n"
		"510     LET starts[i] = starts[i - 1]\n"
		"520     LET starts[i - 1] = temporary\n"
		"530     LET temporary = ends[i]\n"
		"540     LET ends[i] = ends[i - 1]\n"
		"550     LET ends[i - 1] = temporary\n"
		"560     GOTO 150\n"
		"570\n"
		"580 DIM MESSAGE_ITEM_SEPARATOR = \", \"\n"
		"590 DIM message = \"Array: [\"\n"
		"600 LET i = 0\n"
		"610     IF i = 0 THEN 630\n"
		"620     LET message = message + MESSAGE_ITEM_SEPARATOR\n"
		"630     LET message = message + ToString(array[i])\n"
		"640     LET i = i + 1\n"
		"650     IF i < Length(array) THEN 610\n"
		"660 DIM END_OF_MESSAGE = \"].\n\"\n"
		"670 Show(message + END_OF_MESSAGE)\n";

	try {
		Parser::ParseTree parse_tree = Parser().parse(code);
		tree_to_xml(std::cout, parse_tree, code, WizardBasicGrammarRule::NAMES);
	} catch (const WizardBasicException& exception) {
		std::cout << exception.what() << std::endl;
	}
}
