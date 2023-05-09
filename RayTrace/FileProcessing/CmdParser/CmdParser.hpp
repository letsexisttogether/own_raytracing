#pragma once

#include <string_view>
#include <optional>
#include <vector>

class CmdParser
{
public:
	CmdParser() = delete;
	CmdParser(const CmdParser&) = default;
	CmdParser(CmdParser&&) = default;
	
	CmdParser(const std::uint32_t argc, const char* const argv[]);

	~CmdParser() = default;

	const std::string& GetSourceName() const noexcept(false);
	const std::string& GetSourceFormat() const noexcept(false);
	
	const std::string& GetGoalFormat() const noexcept(false);
	const std::string& GetOutput() const noexcept(false);
 
	CmdParser& operator = (const CmdParser&) = delete;
	CmdParser& operator = (CmdParser&&) = delete;

private:
	void CalculateSource() const noexcept(false);
	void CalculateFormat() const noexcept(false);
	void CalculateOutput() const noexcept(false);

	bool IsParameterCorrect(const std::string& correct, const char* parameter)
		const noexcept;

	void CheckArgs(const std::uint32_t argsCount) const noexcept(false);
	void CheckSource() const noexcept(false);
	void CheckGoalFormat() const noexcept(false);
	void CheckOutput() const noexcept(false);

private:
	const static inline std::string s_CorrectSource{ "--source=" };
	const static inline std::string s_CorrectGoalFormat{ "--goal-format=" };
	const static inline std::string s_CorrectOutput{"--output=" };

private:
	const std::uint32_t m_ArgsCount;
	const char* const* const m_Args;
	
	std::optional<std::string> m_SourceName;
	std::optional<std::string> m_SourceFormat;
	std::optional<std::string> m_GoalFormat;
	std::optional<std::string> m_Output;
};
