#include <iostream>
#include "GameApplication.hpp"

int main()
{
	RiskApplication* app = GameApplication::getApplication();

	int result = app->run();

	RiskApplication::cleanUpApplication();

	return result;
}
