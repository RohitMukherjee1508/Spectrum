#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Spectrum {
	class SPECTRUM_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}


//Core Log Macros
#define SP_CORE_TRACE(...)   ::Spectrum::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SP_CORE_INFO(...)    ::Spectrum::Log::GetCoreLogger()->info(__VA_ARGS__) 
#define SP_CORE_WARN(...)    ::Spectrum::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SP_CORE_ERROR(...)   ::Spectrum::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SP_CORE_CRITICAL(...)::Spectrum::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Client Log Macros

#define SP_TRACE(...)        ::Spectrum::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SP_INFO(...)         ::Spectrum::Log::GetClientLogger()->info(__VA_ARGS__) 
#define SP_WARN(...)         ::Spectrum::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SP_ERROR(...)        ::Spectrum::Log::GetClientLogger()->error(__VA_ARGS__)
#define SP_CRITICAL(...)     ::Spectrum::Log::GetClientLogger()->critical(__VA_ARGS__)