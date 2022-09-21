#include <iostream>
#include "../Task.h"

using namespace std;

class FirstTask: public Task {

    virtual std::string getName() override;

    virtual string getId() override;

    int execute() override;
};
