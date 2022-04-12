#include <iostream>
#include "../Task.h"
#include <cmath>

using namespace std;

namespace TaskThird {
	class ThirdTask: public Task{

		virtual std::string getName() override;

		virtual int getId() override;

		void execute() override;
	};
}
