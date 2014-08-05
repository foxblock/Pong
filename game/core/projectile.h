
#pragma once

#include "../../framework/includes.h"
#include "../../library/vector2.h"
#include "../../library/angle.h"
#include "arena.h"
#include <vector>

#ifndef Player
class Player;
#endif

class Projectile
{

	protected:
		Arena* currentArena;

	public:
		Vector2* Position;
		Angle* Direction;
		float Speed;
		int Radius;
		std::vector<Vector2*> Waypoints;
		ALLEGRO_COLOR Colour;

		Projectile( Arena* PlayArena, Vector2* StartPosition, Angle* StartDirection, float StartSpeed );
		~Projectile();

		virtual void Update();
		virtual void Render();
		virtual void RenderTrace();
		virtual void OnCollision( Player* WithPlayer );
		virtual void OnCollisionPlayersWall( Player* WithPlayer );

		virtual void AddWaypoint();
		virtual void ResetWaypoints();

};
