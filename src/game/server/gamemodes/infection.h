#ifndef GAME_SERVER_GAMEMODES_INFECTION_H
#define GAME_SERVER_GAMEMODES_INFECTION_H

#include <game/server/gamecontroller.h>
#include <game/server/teams.h>
#include <game/server/entities/door.h>

#include <vector>
#include <map>

class CGameControllerInfection : public IGameController
{
public:
	CGameControllerInfection(class CGameContext* pGameServer);

	virtual void DoWincheck();

	virtual void OnCharacterSpawn(class CCharacter* pChr);

	virtual int OnCharacterDeath(class CCharacter* pVictim, class CPlayer* pKiller, int Weapon);

	virtual void PostReset();

	int m_BroadcastTime;
	CGameTeams m_Teams;

	std::map<int, std::vector<vec2> > m_TeleOuts;
	std::map<int, std::vector<vec2> > m_TeleCheckOuts;
	std::shared_ptr<CScoreInitResult> m_pInitResult;

	void InitTeleporter();
};

#endif // GAME_SERVER_GAMEMODES_INFECTION_H
