
#pragma once

#include "../core/player.h"

#ifndef BattleStage
class BattleStage;
#endif

// *******************
// Player (paddle) for battle mode
// Also defines inventory item types (pickups)
// *******************

namespace BattleInventory
{
	enum Inventory
	{
		INVENTORY_NONE = 0,
		INVENTORY_FIREBALL,
		INVENTORY_TRIFIRE,
		INVENTORY_HOMING,
		INVENTORY_FREEZE,
		INVENTORY_REVERSE_BALL_VERT,
		INVENTORY_REVERSE_BALL_HORZ,
		INVENTORY_PADDLE_INCREASE,
		INVENTORY_PADDLE_DECREASE,
		INVENTORY_PADDLE_REVERSE_CONTROLS,
		INVENTORY_PADDLE_EOL
	};
}

class BattlePlayer : private Player
{
	private:
		BattleStage* currentArena;
		void setFreezeColour();

	public:
		bool IsNetworkPlayer;

		int MaxHealth;

		int TargetSize;
		int SizeDelay;

		float Health;
		int TargetHealth;

		BattleInventory::Inventory Inventory[3];

		bool SendPressed;
		bool Inv1Pressed;
		bool Inv2Pressed;
		bool Inv3Pressed;

		int FreezeLevel;
		int FreezeTime;

		int ReverseControlTime;

		BattlePlayer( Arena* PlayArena, Vector2* StartPosition, int MinimumY, int MaximumY );
		~BattlePlayer();

		virtual void Update();
		// virtual void Render(); // Not needed

		void Freeze();
		void Burn();
		void MissBall();
		void TakeDamage( int Amount );
		void UseInventory( int Slot );
		void SendInventory( int Slot );

};
