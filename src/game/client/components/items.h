/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef GAME_CLIENT_COMPONENTS_ITEMS_H
#define GAME_CLIENT_COMPONENTS_ITEMS_H
#include <game/client/component.h>
#include <game/generated/protocol.h>

class CProjectileData;

class CItems : public CComponent
{
	void RenderProjectile(const CProjectileData *pCurrent, int ItemID);
	void RenderPickup(const CNetObj_Pickup *pPrev, const CNetObj_Pickup *pCurrent, bool IsPredicted = false);
	void RenderFlag(const CNetObj_Flag *pPrev, const CNetObj_Flag *pCurrent, const CNetObj_GameData *pPrevGameData, const CNetObj_GameData *pCurGameData);
	void RenderLaser(const struct CNetObj_Laser *pCurrent, bool IsPredicted = false);

	int m_ItemsQuadContainerIndex;

public:
	virtual int Sizeof() const override { return sizeof(*this); }
	virtual void OnRender() override;
	virtual void OnInit() override;

	void ReconstructSmokeTrail(const CProjectileData *pCurrent, int DestroyTick);

private:
	int m_BlueFlagOffset;
	int m_RedFlagOffset;
	int m_PickupHealthOffset;
	int m_PickupArmorOffset;
	int m_PickupWeaponOffset[NUM_WEAPONS];
	int m_PickupNinjaOffset;
	int m_PickupWeaponArmorOffset[4];
	int m_ProjectileOffset[NUM_WEAPONS];
	int m_ParticleSplatOffset[3];
};

#endif
