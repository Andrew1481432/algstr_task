#include <iostream>
#include <bitset>
#include <fstream>

#include "../Task.h"

#include "../../Utils/Utils.h"

using namespace std;
namespace zero2Task{
	#define BITSPERWORD 32
	#define SHIFT 5
	#define maska 0x1F
	#define N 20

	class Zero2Task : public Task{
		virtual std::string getName() override;

		virtual string getId() override;

		int execute() override;
	};
}
