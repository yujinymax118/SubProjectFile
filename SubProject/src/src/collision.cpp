#include "collision.h"


bool CHit::CheckHitBoxToBox(VECTOR CirclePos1, VECTOR CircleSize1,
	VECTOR CirclePos2, VECTOR CircleSize2)
{
	//矩形の上下左右それぞれの座標を計算する
	float up1 = CirclePos1.y - CircleSize1.y * 0.5f;
	float down1 = CirclePos1.y + CircleSize1.y * 0.5f;
	float left1 = CirclePos1.x - CircleSize1.x * 0.5f;
	float right1 = CirclePos1.x + CircleSize1.x * 0.5f;
	float front1 = CirclePos1.z - CircleSize1.z * 0.5f;
	float back1 = CirclePos1.z + CirclePos1.z * 0.5f;


	float up2 = CirclePos2.y - CircleSize2.y * 0.5f;
	float down2 = CirclePos2.y + CircleSize2.y * 0.5f;
	float left2 = CirclePos2.x - CircleSize2.x * 0.5f;
	float right2 = CirclePos2.x + CircleSize2.x * 0.5f;
	float front2 = CirclePos2.z - CircleSize2.z * 0.5f;
	float back2 = CirclePos2.z + CirclePos2.z * 0.5f;


	//4つの端をそれぞれチェックして、すべての条件を満たしたらヒット！
	if (left1 <= right2 && right1 >= left2
		&& up1 <= down2 && down1 >= up2
		&& front1 <= back2 && back1 >= front2)
	{
		return true;
	}
	else return false;
}

//------------------------------------------------------------
//               球同士の当たり判定
//------------------------------------------------------------

bool CHit::CheckHitSphereToSphere(VECTOR spherePos1, int radius1,
	VECTOR spherePos2, int radius2)
{
	// 球1から球2までの距離を計算
	float lengthX = spherePos1.x - spherePos2.x;	//2乗するとマイナスが消えるので、順番はどうでもいい
	lengthX *= lengthX;
	float lengthY = spherePos1.y - spherePos2.y;	//2乗するとマイナスが消えるので、順番はどうでもいい
	lengthY *= lengthY;
	float lengthZ = spherePos1.z - spherePos2.z;	//2乗するとマイナスが消えるので、順番はどうでもいい
	lengthZ *= lengthZ;
	float length = lengthX + lengthY + lengthZ;		// aの2乗＋bの2乗

	// 2つの円の半径を加算し、2乗する
	float lengthRadius = (float)(radius1 + radius2);
	lengthRadius *= lengthRadius;

	// 以下の条件を満たせばヒットする！
	if (lengthRadius >= length)
	{
		return true;
	}
	else return false;
}
