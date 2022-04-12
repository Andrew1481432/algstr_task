#include <iostream>
#include "../Task.h"

using namespace std;

class FirstTask: public Task {

    virtual std::string getName() override;

    virtual int getId() override;

    void execute() override;
};
