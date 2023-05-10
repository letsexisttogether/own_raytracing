#include "../CmdParser.hpp"

#include <stdexcept>
#include <string_view>

CmdParser::CmdParser(const std::uint32_t argc, const char* const argv[])
	: m_ArgsCount{ argc }, m_Args{ argv }
{
	CheckArgs();

	CheckSource();
	CheckGoalFormat();
	CheckOutput();
}

const std::string& CmdParser::GetSourceName() noexcept(false)
{
	if (!m_SourceName)
	{
		CalculateSource();
	}

	return m_SourceName.value();
}

const std::string& CmdParser::GetSourceFormat() noexcept(false)
{
	if (!m_SourceFormat)
	{
		CalculateSource();
	}

	return m_SourceFormat.value();
}

const std::string& CmdParser::GetGoalFormat() noexcept(false)
{
	if (!m_GoalFormat)
	{
		CalculateGoalFormat();
	}

	return m_GoalFormat.value();
}

const std::string& CmdParser::GetOutput() noexcept(false)
{
	if (!m_Output)
	{
		CalculateOutput();
	}

	return m_Output.value();
}

void CmdParser::CalculateSource() noexcept(false)
{
	std::string_view temp{ m_Args[1] };

	m_SourceName = std::string{};
	std::string& sourceName = m_SourceName.value();

	m_SourceFormat = std::string{};
	std::string& sourceFormat = m_SourceFormat.value();

	for (auto rIter{ temp.rbegin() }; rIter != temp.rend() && *rIter != '.'; ++rIter)
	{
		sourceFormat += *rIter;
	}
	std::reverse(sourceFormat.begin(), sourceFormat.end());
	
	const std::int32_t sourceNameLength = temp.length() - sourceFormat.length();

	if (sourceFormat.empty() || !(sourceNameLength - s_CorrectSource.size()))
	{
		throw std::invalid_argument{ "The source format was passed incorrectly" };
	}
	
	for (std::uint32_t i = s_CorrectSource.size(); i < sourceNameLength - 1; ++i)
	{
		sourceName += temp[i];
	}

	if (sourceName.empty())
	{
		throw std::invalid_argument{ "The source name was passed incorrectly" };
	}
}

void CmdParser::CalculateGoalFormat() noexcept(false)
{
	m_GoalFormat = std::string{};
	std::string& goalFormat = m_GoalFormat.value();

	for (const char* i = m_Args[2] + s_CorrectGoalFormat.length(); *i != '\0'; ++i)
	{
		goalFormat += *i;
	}

	if (goalFormat.empty())
	{
		throw std::invalid_argument("The goal format was passed incorrectly");
	}
}

void CmdParser::CalculateOutput() noexcept(false)
{
	m_Output = std::string{};
	std::string& output = m_Output.value();

	if (m_ArgsCount < 4)
	{
		output = GetSourceName();
		return;
	}
	
	for (const char* i = m_Args[3] + s_CorrectOutput.length(); *i != '\0'; ++i)
	{
		output += *i;
	}

	if (output.empty())
	{
		throw std::invalid_argument("The output was passed incorrectly");
	}
}

bool CmdParser::IsParameterCorrect(const std::string& correct, const char* parameter)
	const noexcept
{
	for (std::uint32_t i = 0; i < correct.length(); ++i)
	{
		if (correct[i] != parameter[i])
		{
			return false;
		}
	}

	return true;
}

void CmdParser::CheckArgs() const noexcept(false)
{
	if (m_ArgsCount < 3)
	{
		throw std::invalid_argument{ "The count of current arguments does not satisfy the needed amount" };
	}
}


void CmdParser::CheckSource() const noexcept(false)
{

	if (!IsParameterCorrect(s_CorrectSource, m_Args[1]))
	{
		throw std::invalid_argument{ "The command \"--source=\" was written incorrectly" };
	}
}

void CmdParser::CheckGoalFormat() const noexcept(false)
{

	if (!IsParameterCorrect(s_CorrectGoalFormat, m_Args[2]))
	{
		throw std::invalid_argument{ "The command \"--goal-format=\" was written incorrectly" };
	}
}

void CmdParser::CheckOutput() const noexcept(false)
{
	if (m_ArgsCount == 3)
	{
		return;
	}

	if (!IsParameterCorrect(s_CorrectOutput, m_Args[3]))
	{
		throw std::invalid_argument{ "The command \"--output=\" was written incorrectly" };
	}
}
