
#include <iostream>
#include <stdexcept>
#include <Poco/Exception.h>

// class AggregateException : public Poco::Exception
// {
// public:
// 	AggregateException(const std::string &message)
// 			: Poco::Exception(message)
// 	{
// 	}
// };

typedef Poco::Exception AggregateException;

int main()
{
	try
	{
		// Code that may throw multiple exceptions
		// int a = 10;
		// int b = 0;
		// if (b == 0)
		// {
		// 	throw std::runtime_error("Divide by zero exception");
		// }
		throw Poco::NullPointerException("testing null pointer exception");

		// Other code that may throw different exceptions
		// ...

		// You can aggregate these exceptions into a single one
		// throw AggregateException("Multiple exceptions occurred");
	}
	catch (const AggregateException &e)
	{
		std::cerr << "Caught AggregateException: " << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught a standard exception: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Caught an unknown exception." << std::endl;
	}

	return 0;
}
