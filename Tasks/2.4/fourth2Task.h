#include <iostream>

#include "../Task.h"
#include "../../Utils/Utils.h"

using namespace std;
namespace fourth2Task{
	class Fourth2Task : public Task{
		virtual std::string getName() override;

		virtual string getId() override;

		int execute() override;
	};
}
