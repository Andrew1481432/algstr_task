#include <iostream>

#include "../Task.h"
#include "../../Utils/Utils.h"

using namespace std;

namespace seven2Task{
	class Seven2Task : public Task{
		virtual std::string getName() override;

		virtual string getId() override;

		int execute() override;
	};
}
