#include <iostream>
#include <stdexcept>
#include <cstdlib>


#include "HelloTriangleApplication.h"

int main()
{
	HelloTriangleApplication app;

	try
	{
		app.Run();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

// TUTORIAL LEFT AT:
// Validation Layers: Message Callback