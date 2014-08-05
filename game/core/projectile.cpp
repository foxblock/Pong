
#include "projectile.h"

Projectile::Projectile(Arena* PlayArena, Vector2* StartPosition, Angle* StartDirection, float StartSpeed)
{
	currentArena = PlayArena;
	Position = new Vector2( StartPosition );
	Direction = StartDirection;
	Speed = StartSpeed;
	Radius = 1;
	Colour = al_map_rgb( 255, 255, 255 );
}

Projectile::~Projectile()
{
	delete Position;
	delete Direction;
}

void Projectile::Update()
{
	bool moveToTarget = true;

	Vector2* target = Direction->ToVector();
	target->Multiply( Speed );
	target->Add( Position );

	currentArena->ProcessProjectileCollisions( this, target, &moveToTarget );
	if( moveToTarget )
	{
		Position->X = target->X;
		Position->Y = target->Y;
	}
	delete target;
}

void Projectile::Render()
{
	al_draw_filled_rectangle( Position->X - Radius, Position->Y - Radius, Position->X + Radius, Position->Y + Radius, Colour );
}

void Projectile::RenderTrace()
{
	for (std::vector<Vector2*>::const_iterator I = Waypoints.begin(); I != Waypoints.end(); ++I)
	{
		//
	}
}


void Projectile::OnCollision( Player* WithPlayer )
{
}

void Projectile::OnCollisionPlayersWall( Player* WithPlayer )
{
}

void Projectile::AddWaypoint()
{
	Waypoints.push_back(new Vector2(Position));
}

void Projectile::ResetWaypoints()
{
	for (std::vector<Vector2*>::iterator I = Waypoints.begin(); I != Waypoints.end(); ++I)
		delete *I;
	Waypoints.clear();
}

