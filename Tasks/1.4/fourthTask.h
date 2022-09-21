#ifndef CIAOD_FOURTHTASK_H
#define CIAOD_FOURTHTASK_H

#include <iostream>
#include "../Task.h"

#include <fstream>
#include <sstream>
#include <vector>

#include "../../Utils/Utils.h"

using namespace std;

namespace TaskFourth
{
	class FourthTask : public Task
	{
		virtual std::string getName() override;

		virtual string getId() override;

		int execute() override;
	};
}


#endif //CIAOD_FOURTHTASK_H
