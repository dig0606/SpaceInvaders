#include "Ending.h"

Ending::Ending(void) : m_Count(0)
{
	RectEx r = Utils::ClientRectEx();
	m_Imgs.Init(1, 1, r.W, r.H, 0, 0, std::string("./Resources/Sequence/Ending.png"));
	Utils::SoundPlay("Ending", DX_PLAYTYPE_BACK, TRUE);
}

void Ending::Refresh()
{
	if(m_Count > 300 && m_End == false)
	{
		m_End = true;
		m_NextSequence = Sequence::TITLE;
	}
	else
	{
		Utils::DrawImg(m_Imgs.NowImgHandle(NULL), Utils::ClientRectEx());
		m_Count++;
	}
}