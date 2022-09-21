#include <iostream>
#include "../Task.h"
#include <cmath>

using namespace std;

namespace TaskThird {
	class ThirdTask: public Task{

		virtual string getName() override;

		virtual string getId() override;

		int execute() override;
	};
}
