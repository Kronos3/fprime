#ifndef SVC_TEXT_LOGGER_IMPL_HPP
#define SVC_TEXT_LOGGER_IMPL_HPP

#include <Svc/PassiveConsoleTextLogger/PassiveTextLoggerComponentAc.hpp>

namespace Svc {

	class ConsoleTextLoggerImpl final : public PassiveTextLoggerComponentBase  {

	public:

		// Only called by derived class
		ConsoleTextLoggerImpl(const char* compName);
		~ConsoleTextLoggerImpl();

	private:

		// downcalls for input ports
		void TextLogger_handler(FwIndexType portNum, FwEventIdType id, Fw::Time &timeTag, const Fw::LogSeverity& severity, Fw::TextLogString &text);
	};

}

#endif
