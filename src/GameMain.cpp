#include <iostream>
#include <cstdio>

#include "GameApplication.hpp"

int main()
{
    RiskApplication * app = GameApplication::getApplication();
    int answer = app->run();
    app->cleanUpApplication();
    return answer;
}
