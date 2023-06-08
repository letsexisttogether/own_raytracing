#pragma once

#include <string>
#include <optional>

class CmdParser
{
public:
	CmdParser() = delete;
	CmdParser(const CmdParser&) = default;
	CmdParser(CmdParser&&) = default;
	
	CmdParser(const std::uint32_t argc, const char* const argv[]);

	~CmdParser() = default;

	const std::string& GetSecondArgument() noexcept(false);
	const std::string& GetSecondArgumentType() noexcept(false);
	
	const std::string& GetGoalFormat() noexcept(false);
	const std::string& GetOutput() noexcept(false);

	inline const std::string& GetCorrectSource() const noexcept { return s_CorrectSource; }
	inline const std::string& GetCorrectScene() const noexcept { return s_CorrectScene; }
 
	CmdParser& operator = (const CmdParser&) = delete;
	CmdParser& operator = (CmdParser&&) = delete;

private:
	void CalculateSecondArgument() noexcept(false);
	void CalculateOutput() noexcept(false);

	bool IsParameterCorrect(const std::string& correct, const char* parameter)
		const noexcept;

	void CheckArgs() const noexcept(false);
	void CheckSecondArgument() noexcept(false);
	void CheckOutput() const noexcept(false);

private:
	const static inline std::string s_CorrectSource{ "--source=" };
	const static inline std::string s_CorrectScene{ "--scene=" };
	const static inline std::string s_CorrectOutput{"--output=" };

private:
	const std::uint32_t m_ArgsCount;
	const char* const* const m_Args;
	
	std::optional<std::string> m_SecondArgument;
	std::optional<std::string> m_SecondArgumentType;

	std::optional<std::string> m_GoalFormat;
	std::optional<std::string> m_Output;
};
