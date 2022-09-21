#include <iostream>
#include <bitset>

#include "../Task.h"
#include "../../Utils/Utils.h"

using namespace std;
namespace first2Task{
	class First2Task : public Task{
		virtual std::string getName() override;

		virtual string getId() override;

		int execute() override;
	};
}
