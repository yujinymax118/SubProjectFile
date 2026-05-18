#include "SceneManager.h"
//#include "../src/SoundManager.h"

SceneManager::SceneManager()
{
	m_sceneID = TITLE;

	//ƒQ[ƒ€ŠJn‚ÉÄ¶‚Æ‰Šú‰»
	//CSoundManager::Init();
	//CSoundManager::Load();
}

SceneManager::~SceneManager()
{
	//CSoundManager::Exit();
}

int SceneManager::Loop()
{
	int Ret = 0;

	switch (m_sceneID)
	{
	case SceneManager::TITLE:
		if (cTitle.Loop() != 0)
		{
			m_sceneID = GAME;
		}

		break;
	case SceneManager::GAME:
		if (cPlayScene.Loop() != 0)
		{
			m_sceneID = RESULT;
		}
		break;
	case SceneManager::RESULT:
		if (cResult.Loop() != 0)
		{
			m_sceneID = TITLE;
		}

		break;
	}

	return Ret;
}

void SceneManager::Draw()
{
	switch (m_sceneID)
	{
	case SceneManager::TITLE:
		cTitle.Draw();
		break;
	case SceneManager::GAME:
		cPlayScene.Draw();
		break;
	case SceneManager::RESULT:
		cResult.Draw();
		break;
	}
}
