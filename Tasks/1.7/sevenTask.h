#ifndef CIAOD_SEVENTASK_H
#define CIAOD_SEVENTASK_H

#include <iostream>
#include "../Task.h"

#include "../../Utils/Utils.h"

#include "list/List.h"
#include "list/Node.h"

using namespace std;

namespace TaskSeven {
	class SevenTask: public Task {
		virtual std::string getName() override;

		virtual string getId() override;

		int execute() override;
	};
}


#endif //CIAOD_SEVENTASK_H
