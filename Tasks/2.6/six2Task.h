#include <iostream>

#include "../Task.h"
#include "../../Utils/Utils.h"

using namespace std;

namespace six2Task{
	class Six2Task : public Task{
		virtual std::string getName() override;

		virtual string getId() override;

		int execute() override;
	};
}
