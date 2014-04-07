#include <iostream>
#include "GameApplication.h"

int main()
{
	RiskApplication* app = GameApplication::getApplication();

	int result = app->run();

	RiskApplication::cleanUpApplication();

	return result;
}
