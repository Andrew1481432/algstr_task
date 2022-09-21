#ifndef CIAOD_FIVETASK_H
#define CIAOD_FIVETASK_H

#include <iostream>
#include "../Task.h"

#include "../../Utils/Utils.h"

using namespace std;

namespace TaskFive {
	class FiveTask: public Task {
		virtual std::string getName() override;

		virtual string getId() override;

		int execute() override;
	};
}


#endif //CIAOD_FIVETASK_H
