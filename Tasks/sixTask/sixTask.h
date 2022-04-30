#ifndef CIAOD_SIXTASK_H
#define CIAOD_SIXTASK_H

#include <iostream>
#include "../Task.h"

#include "../../Utils/Utils.h"

using namespace std;

namespace TaskSix {
	class SixTask: public Task {
		virtual std::string getName() override;

		virtual int getId() override;

		void execute() override;
	};
}


#endif //CIAOD_SIXTASK_H
