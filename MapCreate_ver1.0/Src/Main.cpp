#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <DirectXMath.h>
#include <vector>
#include <time.h>
#include <mmsystem.h>
#include "Window.h"
#include "DirectGraphics.h"
#include "FbxMeshFile.h"
#define FBXSDK_SHARED
#pragma comment(lib, "winmm.lib")
#include "DXTK11Lib.h"
#include "input.h"

#include "SaveLoadMap.h"
#include<Shlwapi.h>


using namespace DXTK11LIB;

int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmpLine,
	INT       nCmdShow)
{
	Window window("MapCreate", 960+300, 540);

	// ウィンドウを作成
	if (window.Create() == false)
	{
		//return 0;
	}

	//キー入力初期化
	InitInput(hInstance, FindWindow(Window::ClassName, nullptr));


	if (DirectGraphics::GetInstance()->Init() == false)
	{
		//return 0;
	}

	InitDXTK11Lib();

	
	MapTip map;
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 16; x++) {
			map.map[y][x] = 0;
		}
	}

	Image* mapIm;

	int mapTipNum = 0;//マップチップの個数になる
	//ファイルがあるか確認してロードする
	while (true) {
		char imagePath[50];
		sprintf(imagePath, "Image/%d.png",mapTipNum);
		
	   if (PathFileExists(imagePath)) {
			
		}
		else {
			break;
		}	
		mapTipNum++;
	}
	mapIm = new Image[mapTipNum];
	for (int i = 0; i < mapTipNum; i++) {
		char imagePath[50];
		sprintf(imagePath, "Image/%d.png", i);
		mapIm[i].Load(imagePath);
	}
	

	int nowMapTip = 0;
	int backMapTip = 0;
	int forwardMapTip = 0;


	Image cursorIm(L"Image/cursor.png");
	int cursorX = 0;
	int cursorY = 0;

	
	int saveStrCount = 0;
	Image saveIm(L"Image/save.png");

	//SaveMap(map, "save.dat");

	//LoadMap(&map, "save.dat");
	while (true)
	{
		MSG msg;

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			UpdateInput();//入力処理更新
			KeyInput* KEY= KeyInput::GetInstance();

			//描画前処理
			DirectGraphics::GetInstance()->StartRendering();
			DirectGraphics::GetInstance()->SetUpContext(nullptr, nullptr);
			//入力処理

			
				//カーソル移動
				if (KEY->key[DIK_A] == 1|| KEY->key[DIK_A] > 30) {
					if (cursorX > 0)
						cursorX--;
				}
				if (KEY->key[DIK_D] == 1|| KEY->key[DIK_D]>30) {
					if (cursorX < 15)
						cursorX++;
				}
				if (KEY->key[DIK_S] == 1 || KEY->key[DIK_S] > 30) {

					if (cursorY < 8)
						cursorY++;
				}
				if (KEY->key[DIK_W] == 1|| KEY->key[DIK_W] > 30) {
					if (cursorY > 0)
						cursorY--;
				}
			

				//マップチップ変更
				if (KEY->key[DIK_LEFT] == 1 ) {
					nowMapTip--;
				}
				if (KEY->key[DIK_RIGHT] == 1) {
					nowMapTip++;
				}
			

			if (KEY->key[DIK_RETURN]) {
				map.map[cursorY][cursorX] = nowMapTip;
			}

			if (KEY->key[DIK_LCONTROL] && KEY->key[DIK_S] == 1) {
				int saveNum=0;
				while (true) {
					if (saveNum == 4) {
						break;
					}
					char savePath[50];
					sprintf(savePath, "Save/save%d.dat", saveNum);

					if (PathFileExists(savePath)) {

					}
					else {
						saveStrCount++;
						SaveMap(map, savePath);
						break;
					}
					saveNum++;
				}
			}
			//まっぷ描画
			for (int iy = 0; iy < 9; iy++) {
				for (int ix = 0; ix < 16; ix++) {
					
					mapIm[map.map[iy][ix]].Draw(ix * 60, iy * 60, 0.0, 1.0, 1.0, 0);
				}
			}

			//マップチップ選択UI描画
			if (nowMapTip < 0) {
				nowMapTip = mapTipNum-1;
			}
			if (nowMapTip > mapTipNum-1) {
				nowMapTip = 0;
			}

			backMapTip = nowMapTip - 1;
			if (backMapTip < 0) {
				backMapTip = mapTipNum-1;
			}
			forwardMapTip = nowMapTip + 1;
			if (forwardMapTip >mapTipNum-1) {
				forwardMapTip = 0;
			}
			
			mapIm[nowMapTip].Draw(960 + 150, 60*2);
			mapIm[backMapTip].Draw(960 + 150 - 90, 60 * 2, 0, 0.75);
			mapIm[forwardMapTip].Draw(960 + 150 + 90, 60 * 2, 0, 0.75);

			//カーソルUI
			cursorIm.Draw(60 * cursorX, 60 * cursorY, 0, 1, 1, 0);

			
			if (saveStrCount) {
				saveIm.Draw(0, 0, 0, 1, 1, 0);

				saveStrCount++;
				if (saveStrCount > 120) {
					saveStrCount = 0;
				}
			}


			DirectGraphics::GetInstance()->FinishRendering();//描画する毎回の処理

		}
	}
	UninitInput();
	
	DirectGraphics::GetInstance()->Release();

	return 0;
}
