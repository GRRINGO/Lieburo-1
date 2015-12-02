#ifndef PROJECTILE_HH
#define PROJECTILE_HH

#include "Entity.hpp"

class Projectile : public Entity {
public:
	Projectile() = default;
	~Projectile(){}

	virtual void update(sf::Time) = 0;
	virtual void startContact(int id, Entity*) = 0;

protected:
	sf::Sprite mExplosionSprite;
	sf::Texture mExplosionTexture;
	bool exploses = false;
	int explosionClock = 0; //Times for how many update cyckles the explosion sprite will be shown.
	int explosionTime;
	bool hasFragmented = false;

};


#endif