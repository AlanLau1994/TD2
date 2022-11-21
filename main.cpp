#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

const char kWindowTitle[] = "GC1C_22_リュウ_チョウリン";
typedef struct Boss 
{
	float posX;
	float posY;
	float width;
	float height;
	float speedx;
	float speedy;
	int hp;
	int frame;
	float moveX;
    float moveY;
};
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 700,800);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};
	float theta = 0.0f;
	int over=0;
	Boss boss
	{
		300.0,
		200.0,
		128.0,
		64.0,
		3.0,
		3.0,
		3,
		0,
		cosf(M_PI),
		sinf(theta),
	};
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		if (boss.hp > 0) 
		{
			boss.posX += boss.speedx;
			
			if (boss.posX < 30 || boss.posX>450)
			    {
				boss.speedx *= -1;
			    }	
		 if (boss.hp > 4 && boss.hp < 8)
		 {
				boss.posY += boss.speedy;
				if(boss.posY<0||boss.posY>200)
					{
						boss.speedy *= -1;
					}
		 }
		 else if(boss.hp<5)
		 {
			 boss.posY = 100;

		 }
		 

		}
		else
		{
			if (over<5)
			{
				if (boss.frame < 50) 
				{
					over += 1;
					boss.frame = 0;
				}
			}
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		Novice::DrawBox(boss.posX, boss.posY, boss.width, boss.height, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(600, 0, 100, 800, 0.0f, BLACK, kFillModeSolid);
		Novice::ScreenPrintf(10, 10, "posX%f", boss.posX);
		Novice::ScreenPrintf(10, 25, "posY%f", boss.posY);
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
