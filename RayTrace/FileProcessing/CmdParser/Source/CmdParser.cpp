#include "../CmdParser.hpp"

#include <stdexcept>


CmdParser::CmdParser(const std::uint32_t argc, const char* const argv[])
	: m_ArgsCount{ argc }, m_Args{ argv }
{
	CheckArgs(sizeof(argv));

	CheckSource();
	CheckGoalFormat();
	CheckOutput();
}

const std::string& CmdParser::GetSourceName() const noexcept(false)
{
	if (!m_SourceName)
	{
		CalculateSource();
	}

	return m_SourceName.value();
}

const std::string& CmdParser::GetSourceFormat() const noexcept(false)
{
	if (!m_SourceFormat)
	{
		CalculateSource();
	}

	return m_SourceFormat.value();
}

const std::string& CmdParser::GetGoalFormat() const noexcept(false)
{
	if (!m_GoalFormat)
	{
		CalculateFormat();
	}

	return m_GoalFormat.value();
}

const std::string& CmdParser::GetOutput() const noexcept(false)
{
	if (!m_Output)
	{
		CalculateOutput();
	}

	return m_Output.value();
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

void CmdParser::CheckArgs(const std::uint32_t argsCount) const noexcept(false)
{
	if (m_ArgsCount < 3 || m_ArgsCount != argsCount)
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
