#pragma  once

#include "object3D.h"
#include "object3Dcube.h"
#include "object3Dcylinder.h"
#include "object3Dsphere.h"

#include <algorithm>


enum RelationType
{
	Stranger = 0,		// not even close
	Ambiguous = 1,		// collide
	FallInLove = 2,		// center of one is inside another
	Breaking = 3,		// overlap right now but getting far away
};

enum CollisionFreeStuckType
{
	BothFree = 0,
	Stuck1st = 1,
	Stuck2nd = 2,
	BothStuck = 3
};

enum CubeFace
{
	XPos = 0,
	XNeg = 1,
	YPos = 2,
	YNeg = 3,
	ZPos = 4,
	ZNeg = 5,
};

struct CollisionInfo {

	RelationType relation;
	glm::vec3 v1After;
	glm::vec3 v2After;

	glm::vec3 angularImpulse1;
	glm::vec3 angularImpulse2;

	CubeFace collideFace;	// cube

	glm::vec3 collidePos;
	glm::vec3 relativeSpeed;
	glm::vec3 yzstarSpeed;

};


CollisionInfo CollideSph2Sph(Object3Dsphere * obj1, Object3Dsphere * obj2, bool autoDeal);
CollisionInfo CollideSph2Sph(std::vector<Object3Dsphere*> &spheres, bool autoDeal);
CollisionInfo CollideSph2Sph(Object3Dcylinder * sph1, Object3Dsphere * sph2, bool autoDeal);
CollisionInfo CollideSph2Sph(std::vector<Object3Dcylinder*> &spheres1, std::vector<Object3Dsphere*> &spheres2, bool autoDeal);
CollisionInfo CollideSph2Sph(Object3Dcylinder * sph1, Object3Dcylinder * sph2, bool autoDeal);
CollisionInfo CollideSph2Sph(std::vector<Object3Dcylinder*> &spheres, bool autoDeal);

CollisionInfo CollideSph2Cube(Object3Dsphere * sphere, Object3Dcube * cube, bool autoDeal, bool isStuckY);
CollisionInfo CollideSph2Cube(std::vector<Object3Dsphere*> &spheres, std::vector<Object3Dcube*> &cubes, bool autoDeal, bool isStuckY);

void CollideSph2Ground(Object3Dsphere * sphere, Object3Dcube * ground);
void CollideSph2Ground(std::vector<Object3Dsphere*> &spheres, Object3Dcube * ground);
CollisionInfo CollideSph2Wall(Object3Dcylinder * sphere, Object3Dcube * wall, bool autoDeal);
CollisionInfo CollideSph2Wall(std::vector<Object3Dcylinder*> &spheres, std::vector<Object3Dcube*> &walls, bool autoDeal);

void DealCollision(Object3D * obj1, Object3D * obj2, CollisionInfo cInfo);



CollisionInfo SimpleCollideSph2Wall(Object3Dsphere * sph, Object3Dcube * wall);
CollisionInfo SimpleCollideSph2Wall(std::vector<Object3Dsphere*> &spheres, std::vector<Object3Dcube*> &walls);
CollisionInfo SimpleCollideCy2Wall(Object3Dcylinder * sph, Object3Dcube * wall);
CollisionInfo SimpleCollideCy2Wall(std::vector<Object3Dcylinder*> &spheres, std::vector<Object3Dcube*> &walls);