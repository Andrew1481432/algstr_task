#include <iostream>
#include "../Task.h"

using namespace std;

namespace TaskSecond {
	class SecondTask : public Task {
		virtual std::string getName() override;

		virtual string getId() override;

		int execute() override;
	};
}
