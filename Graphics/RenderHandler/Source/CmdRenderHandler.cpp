#include "../CmdRenderHandler.hpp"

// CmdRenderHandler::CmdRenderHandler(const Screen& screen)
// 	: RenderHandler{ screen }, m_Pixels{ m_Screen.GetHeigth(), std::vector<char>(m_Screen.GetWidth(), 0) }
// {}
// 
// void CmdRenderHandler::HandlePixel(const Screen::Resolution i, const Screen::Resolution j, const Vector3d& color) noexcept(false)
// {
// 	m_Pixels.at(i).at(j) = LightTrace(color.GetLength());
// }
// 
// void CmdRenderHandler::ExecuteRenderResult() const noexcept(false)
// {
// 	for (Screen::Resolution i = m_Screen.GetHeigth() - 1; i >= 0; --i)
// 	{
// 		for (Screen::Resolution j = 0; j < m_Screen.GetWidth(); ++j)
// 		{
// 			std::cout << m_Pixels[i][j];
// 		}
// 		std::cout << '\n';
// 	}
// 
// 	std::cout << std::endl;
// }
//  
// char CmdRenderHandler::LightTrace(const float dotResult) const noexcept
// {
// 	if (dotResult <= 0) return ' ';
// 	else if (dotResult > 0 && dotResult <= 0.2) return '.';
// 	else if (dotResult > 0.2 && dotResult <= 0.5) return '*';
// 	else if (dotResult > 0.5 && dotResult <= 0.8) return 'O';
// 	return '#';
// }