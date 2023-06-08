#include "../CmdParser.hpp"

#include <stdexcept>
#include <string_view>

CmdParser::CmdParser(const std::uint32_t argc, const char* const argv[])
	: m_ArgsCount{ argc }, m_Args{ argv }
{
	CheckArgs();
	CheckSecondArgument();
	CheckOutput();
}


const std::string& CmdParser::GetSecondArgument() noexcept(false)
{
	if (!m_SecondArgument)
	{
		CalculateSecondArgument();
	}

	return m_SecondArgument.value();
}

const std::string& CmdParser::GetSecondArgumentType() noexcept(false)
{
	return m_SecondArgumentType.value();
}

const std::string& CmdParser::GetGoalFormat() noexcept(false)
{
	if (!m_GoalFormat)
	{
		CalculateOutput();
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

void CmdParser::CalculateSecondArgument() noexcept(false)
{
	m_SecondArgument = std::string{};
	std::string& secondArgument = m_SecondArgument.value();

	for (const char* i = m_Args[1] + m_SecondArgumentType.value().length(); *i != '\0'; ++i)
	{
		secondArgument += *i;
	}

	if (secondArgument.empty())
	{
		throw std::invalid_argument("The goal format was passed incorrectly");
	}
}

void CmdParser::CalculateOutput() noexcept(false)
{
	std::string_view temp{ m_Args[2] };

	m_Output = std::string{};
	std::string& output = m_Output.value();

	m_GoalFormat = std::string{};
	std::string& goalFormat = m_GoalFormat.value();

	for (auto rIter{ temp.rbegin() }; rIter != temp.rend() && *rIter != '.'; ++rIter)
	{
		goalFormat += *rIter;
	}
	std::reverse(goalFormat.begin(), goalFormat.end());

	const std::int32_t sourceNameLength = temp.length() - goalFormat.length();

	if (goalFormat.empty() || !sourceNameLength)
	{
		throw std::invalid_argument{ "The output format was passed incorrectly" };
	}

	for (std::int32_t i = s_CorrectSource.size(); i < sourceNameLength - 1; ++i)
	{
		output += temp[i];
	}

	if (output.empty())
	{
		throw std::invalid_argument{ "The output name was passed incorrectly" };
	}
}

bool CmdParser::IsParameterCorrect(const std::string& correct, const char* parameter)
	const noexcept
{
	const char* iter = parameter;
	for (std::uint32_t i = 0; iter && i < correct.length(); ++i)
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
	if (m_ArgsCount != 3)
	{
		throw std::invalid_argument{ "The count of current arguments does not satisfy the needed amount" };
	}
}

void CmdParser::CheckSecondArgument() noexcept(false)
{
	if (IsParameterCorrect(s_CorrectSource, m_Args[1]))
	{
		m_SecondArgumentType = s_CorrectSource;
	}
	else if (IsParameterCorrect(s_CorrectScene, m_Args[1]))
	{
		m_SecondArgumentType = s_CorrectScene;
	}
	else 
	{
		throw std::invalid_argument{ "The first command was written incorrectly" };
	}
}

void CmdParser::CheckOutput() const noexcept(false)
{
	if (!IsParameterCorrect(s_CorrectOutput, m_Args[2]))
	{
		throw std::invalid_argument{ "The command \"--output=\" was written incorrectly" };
	}
}
