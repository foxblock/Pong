
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
	if (!Waypoints.empty())
	{
		ALLEGRO_COLOR col = Colour;
		col.a *= 0.5;

		// go through past waypoints (every point where the direction changed)
		// and connect these with a line
		for (std::vector<Vector2*>::const_reverse_iterator I = Waypoints.rbegin(); I != Waypoints.rend(); ++I)
		{
			Vector2 *target, *temp;
			if (I == Waypoints.rbegin())
				target = Position;
			else
				target = *(I-1);

			// calculate thickness of the line by calculating the slope between the points
			// There might be a better way to do this...
			temp = new Vector2( target );
			temp->Subtract( *I );
			Angle *angle = temp->ToAngle();
			float thickness = fabs( 2 * Radius * angle->Sine() ) + fabs( 2 * Radius * angle->Cosine() );
			float val = 0; //sqrt( 2.0f * Radius * Radius );
			al_draw_line( (*I)->X - val * angle->Sine(), (*I)->Y - val * angle->Cosine(), target->X + val * angle->Sine(), target->Y + val * angle->Cosine(), col, thickness );
			delete angle;
			delete temp;
		}
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

