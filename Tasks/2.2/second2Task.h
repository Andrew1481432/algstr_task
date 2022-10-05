#include <iostream>

#include "../Task.h"
#include "../../Utils/Utils.h"

using namespace std;
namespace second2Task{
	class Second2Task : public Task{
		virtual std::string getName() override;

		virtual string getId() override;

		int execute() override;
	};
}
