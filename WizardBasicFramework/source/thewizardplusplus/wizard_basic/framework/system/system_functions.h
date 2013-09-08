#ifndef SYSTEM_FUNCTIONS_H
#define SYSTEM_FUNCTIONS_H

#include <string>

namespace thewizardplusplus {
namespace wizard_basic {
namespace framework {
namespace system {

float GetRandomNumber(void);
float GetTimeFromStartInS(void);
void Trace(float number);
void Trace(const std::string& string);

}
}
}
}
#endif
