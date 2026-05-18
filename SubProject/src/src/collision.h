#pragma once

#include <Dxlib.h>
// dotPos
// squarePos
// width
// height
// @return

class CHit
{
public:

	//“¯Žm‚Ì“–‚½‚è”»’è
	static bool CheckHitBoxToBox(VECTOR Pos1, VECTOR Size1,
		VECTOR Pos2, VECTOR Size2);

	static bool CheckHitSphereToSphere(VECTOR spherePos1, int radius1,
		VECTOR spherePos2, int radius2);


};
