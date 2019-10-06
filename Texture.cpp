#include "Texture.h"
#include "main.h"

void InitTexture1()
{
	Sceen1TPTeamVertex[0].X = Sceen1TPTeamPosX - Sceen1TPTeamSizeX / 2;
	Sceen1TPTeamVertex[0].Y = Sceen1TPTeamPosY - Sceen1TPTeamSizeY / 2;
	Sceen1TPTeamVertex[0].Z = 0;
	Sceen1TPTeamVertex[1].X = Sceen1TPTeamPosX + Sceen1TPTeamSizeX / 2;
	Sceen1TPTeamVertex[1].Y = Sceen1TPTeamPosY - Sceen1TPTeamSizeY / 2;
	Sceen1TPTeamVertex[1].Z = 0;
	Sceen1TPTeamVertex[2].X = Sceen1TPTeamPosX - Sceen1TPTeamSizeX / 2;
	Sceen1TPTeamVertex[2].Y = Sceen1TPTeamPosY + Sceen1TPTeamSizeY / 2;
	Sceen1TPTeamVertex[2].Z = 0;
	Sceen1TPTeamVertex[3].X = Sceen1TPTeamPosX + Sceen1TPTeamSizeX / 2;
	Sceen1TPTeamVertex[3].Y = Sceen1TPTeamPosY + Sceen1TPTeamSizeY / 2;
	Sceen1TPTeamVertex[3].Z = 0;
	Sceen1TPTeamVertex[0].rhw = 1.0f;
	Sceen1TPTeamVertex[1].rhw = 1.0f;
	Sceen1TPTeamVertex[2].rhw = 1.0f;
	Sceen1TPTeamVertex[3].rhw = 1.0f;
	Sceen1TPTeamVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen1TPTeamVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen1TPTeamVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen1TPTeamVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen1TPTeamVertex[0].u = 0.0f;
	Sceen1TPTeamVertex[0].v = 0.0f;
	Sceen1TPTeamVertex[1].u = 1.0f;
	Sceen1TPTeamVertex[1].v = 0.0f;
	Sceen1TPTeamVertex[2].u = 0.0f;
	Sceen1TPTeamVertex[2].v = 1.0f;
	Sceen1TPTeamVertex[3].u = 1.0f;
	Sceen1TPTeamVertex[3].v = 1.0f;
}
void InitTexture2()
{
	Sceen2TitleVertex[0].X = Sceen2TitlePosX - Sceen2TitleSizeX / 2;
	Sceen2TitleVertex[0].Y = Sceen2TitlePosY - Sceen2TitleSizeY / 2;
	Sceen2TitleVertex[0].Z = 0;
	Sceen2TitleVertex[1].X = Sceen2TitlePosX + Sceen2TitleSizeX / 2;
	Sceen2TitleVertex[1].Y = Sceen2TitlePosY - Sceen2TitleSizeY / 2;
	Sceen2TitleVertex[1].Z = 0;
	Sceen2TitleVertex[2].X = Sceen2TitlePosX - Sceen2TitleSizeX / 2;
	Sceen2TitleVertex[2].Y = Sceen2TitlePosY + Sceen2TitleSizeY / 2;
	Sceen2TitleVertex[2].Z = 0;
	Sceen2TitleVertex[3].X = Sceen2TitlePosX + Sceen2TitleSizeX / 2;
	Sceen2TitleVertex[3].Y = Sceen2TitlePosY + Sceen2TitleSizeY / 2;
	Sceen2TitleVertex[3].Z = 0;
	Sceen2TitleVertex[0].rhw = 1.0f;
	Sceen2TitleVertex[1].rhw = 1.0f;
	Sceen2TitleVertex[2].rhw = 1.0f;
	Sceen2TitleVertex[3].rhw = 1.0f;
	Sceen2TitleVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2TitleVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2TitleVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2TitleVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2TitleVertex[0].u = 0.0f;
	Sceen2TitleVertex[0].v = 0.0f;
	Sceen2TitleVertex[1].u = 1.0f;
	Sceen2TitleVertex[1].v = 0.0f;
	Sceen2TitleVertex[2].u = 0.0f;
	Sceen2TitleVertex[2].v = 1.0f;
	Sceen2TitleVertex[3].u = 1.0f;
	Sceen2TitleVertex[3].v = 1.0f;
}
void InitTexture3()
{
	Sceen2OnePlayerHighlightVertex[0].X = Sceen2OnePlayerHighlightPosX - Sceen2OnePlayerHighlightSizeX / 2;
	Sceen2OnePlayerHighlightVertex[0].Y = Sceen2OnePlayerHighlightPosY - Sceen2OnePlayerHighlightSizeY / 2;
	Sceen2OnePlayerHighlightVertex[0].Z = 0;
	Sceen2OnePlayerHighlightVertex[1].X = Sceen2OnePlayerHighlightPosX + Sceen2OnePlayerHighlightSizeX / 2;
	Sceen2OnePlayerHighlightVertex[1].Y = Sceen2OnePlayerHighlightPosY - Sceen2OnePlayerHighlightSizeY / 2;
	Sceen2OnePlayerHighlightVertex[1].Z = 0;
	Sceen2OnePlayerHighlightVertex[2].X = Sceen2OnePlayerHighlightPosX - Sceen2OnePlayerHighlightSizeX / 2;
	Sceen2OnePlayerHighlightVertex[2].Y = Sceen2OnePlayerHighlightPosY + Sceen2OnePlayerHighlightSizeY / 2;
	Sceen2OnePlayerHighlightVertex[2].Z = 0;
	Sceen2OnePlayerHighlightVertex[3].X = Sceen2OnePlayerHighlightPosX + Sceen2OnePlayerHighlightSizeX / 2;
	Sceen2OnePlayerHighlightVertex[3].Y = Sceen2OnePlayerHighlightPosY + Sceen2OnePlayerHighlightSizeY / 2;
	Sceen2OnePlayerHighlightVertex[3].Z = 0;
	Sceen2OnePlayerHighlightVertex[0].rhw = 1.0f;
	Sceen2OnePlayerHighlightVertex[1].rhw = 1.0f;
	Sceen2OnePlayerHighlightVertex[2].rhw = 1.0f;
	Sceen2OnePlayerHighlightVertex[3].rhw = 1.0f;
	Sceen2OnePlayerHighlightVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2OnePlayerHighlightVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2OnePlayerHighlightVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2OnePlayerHighlightVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2OnePlayerHighlightVertex[0].u = 0.0f;
	Sceen2OnePlayerHighlightVertex[0].v = 0.0f;
	Sceen2OnePlayerHighlightVertex[1].u = 1.0f;
	Sceen2OnePlayerHighlightVertex[1].v = 0.0f;
	Sceen2OnePlayerHighlightVertex[2].u = 0.0f;
	Sceen2OnePlayerHighlightVertex[2].v = 1.0f;
	Sceen2OnePlayerHighlightVertex[3].u = 1.0f;
	Sceen2OnePlayerHighlightVertex[3].v = 1.0f;
}
void InitTexture4()
{
	Sceen2OnePlayerLowlightVertex[0].X = Sceen2OnePlayerLowlightPosX - Sceen2OnePlayerLowlightSizeX / 2;
	Sceen2OnePlayerLowlightVertex[0].Y = Sceen2OnePlayerLowlightPosY - Sceen2OnePlayerLowlightSizeY / 2;
	Sceen2OnePlayerLowlightVertex[0].Z = 0;
	Sceen2OnePlayerLowlightVertex[1].X = Sceen2OnePlayerLowlightPosX + Sceen2OnePlayerLowlightSizeX / 2;
	Sceen2OnePlayerLowlightVertex[1].Y = Sceen2OnePlayerLowlightPosY - Sceen2OnePlayerLowlightSizeY / 2;
	Sceen2OnePlayerLowlightVertex[1].Z = 0;
	Sceen2OnePlayerLowlightVertex[2].X = Sceen2OnePlayerLowlightPosX - Sceen2OnePlayerLowlightSizeX / 2;
	Sceen2OnePlayerLowlightVertex[2].Y = Sceen2OnePlayerLowlightPosY + Sceen2OnePlayerLowlightSizeY / 2;
	Sceen2OnePlayerLowlightVertex[2].Z = 0;
	Sceen2OnePlayerLowlightVertex[3].X = Sceen2OnePlayerLowlightPosX + Sceen2OnePlayerLowlightSizeX / 2;
	Sceen2OnePlayerLowlightVertex[3].Y = Sceen2OnePlayerLowlightPosY + Sceen2OnePlayerLowlightSizeY / 2;
	Sceen2OnePlayerLowlightVertex[3].Z = 0;
	Sceen2OnePlayerLowlightVertex[0].rhw = 1.0f;
	Sceen2OnePlayerLowlightVertex[1].rhw = 1.0f;
	Sceen2OnePlayerLowlightVertex[2].rhw = 1.0f;
	Sceen2OnePlayerLowlightVertex[3].rhw = 1.0f;
	Sceen2OnePlayerLowlightVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2OnePlayerLowlightVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2OnePlayerLowlightVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2OnePlayerLowlightVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2OnePlayerLowlightVertex[0].u = 0.0f;
	Sceen2OnePlayerLowlightVertex[0].v = 0.0f;
	Sceen2OnePlayerLowlightVertex[1].u = 1.0f;
	Sceen2OnePlayerLowlightVertex[1].v = 0.0f;
	Sceen2OnePlayerLowlightVertex[2].u = 0.0f;
	Sceen2OnePlayerLowlightVertex[2].v = 1.0f;
	Sceen2OnePlayerLowlightVertex[3].u = 1.0f;
	Sceen2OnePlayerLowlightVertex[3].v = 1.0f;
}
void InitTexture5()
{
	Sceen2TwoPlayerHighlightVertex[0].X = Sceen2TwoPlayerHighlightPosX - Sceen2TwoPlayerHighlightSizeX / 2;
	Sceen2TwoPlayerHighlightVertex[0].Y = Sceen2TwoPlayerHighlightPosY - Sceen2TwoPlayerHighlightSizeY / 2;
	Sceen2TwoPlayerHighlightVertex[0].Z = 0;
	Sceen2TwoPlayerHighlightVertex[1].X = Sceen2TwoPlayerHighlightPosX + Sceen2TwoPlayerHighlightSizeX / 2;
	Sceen2TwoPlayerHighlightVertex[1].Y = Sceen2TwoPlayerHighlightPosY - Sceen2TwoPlayerHighlightSizeY / 2;
	Sceen2TwoPlayerHighlightVertex[1].Z = 0;
	Sceen2TwoPlayerHighlightVertex[2].X = Sceen2TwoPlayerHighlightPosX - Sceen2TwoPlayerHighlightSizeX / 2;
	Sceen2TwoPlayerHighlightVertex[2].Y = Sceen2TwoPlayerHighlightPosY + Sceen2TwoPlayerHighlightSizeY / 2;
	Sceen2TwoPlayerHighlightVertex[2].Z = 0;
	Sceen2TwoPlayerHighlightVertex[3].X = Sceen2TwoPlayerHighlightPosX + Sceen2TwoPlayerHighlightSizeX / 2;
	Sceen2TwoPlayerHighlightVertex[3].Y = Sceen2TwoPlayerHighlightPosY + Sceen2TwoPlayerHighlightSizeY / 2;
	Sceen2TwoPlayerHighlightVertex[3].Z = 0;
	Sceen2TwoPlayerHighlightVertex[0].rhw = 1.0f;
	Sceen2TwoPlayerHighlightVertex[1].rhw = 1.0f;
	Sceen2TwoPlayerHighlightVertex[2].rhw = 1.0f;
	Sceen2TwoPlayerHighlightVertex[3].rhw = 1.0f;
	Sceen2TwoPlayerHighlightVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2TwoPlayerHighlightVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2TwoPlayerHighlightVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2TwoPlayerHighlightVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2TwoPlayerHighlightVertex[0].u = 0.0f;
	Sceen2TwoPlayerHighlightVertex[0].v = 0.0f;
	Sceen2TwoPlayerHighlightVertex[1].u = 1.0f;
	Sceen2TwoPlayerHighlightVertex[1].v = 0.0f;
	Sceen2TwoPlayerHighlightVertex[2].u = 0.0f;
	Sceen2TwoPlayerHighlightVertex[2].v = 1.0f;
	Sceen2TwoPlayerHighlightVertex[3].u = 1.0f;
	Sceen2TwoPlayerHighlightVertex[3].v = 1.0f;
}
void InitTexture6()
{
	Sceen2TwoPlayerLowlightVertex[0].X = Sceen2TwoPlayerLowlightPosX - Sceen2TwoPlayerLowlightSizeX / 2;
	Sceen2TwoPlayerLowlightVertex[0].Y = Sceen2TwoPlayerLowlightPosY - Sceen2TwoPlayerLowlightSizeY / 2;
	Sceen2TwoPlayerLowlightVertex[0].Z = 0;
	Sceen2TwoPlayerLowlightVertex[1].X = Sceen2TwoPlayerLowlightPosX + Sceen2TwoPlayerLowlightSizeX / 2;
	Sceen2TwoPlayerLowlightVertex[1].Y = Sceen2TwoPlayerLowlightPosY - Sceen2TwoPlayerLowlightSizeY / 2;
	Sceen2TwoPlayerLowlightVertex[1].Z = 0;
	Sceen2TwoPlayerLowlightVertex[2].X = Sceen2TwoPlayerLowlightPosX - Sceen2TwoPlayerLowlightSizeX / 2;
	Sceen2TwoPlayerLowlightVertex[2].Y = Sceen2TwoPlayerLowlightPosY + Sceen2TwoPlayerLowlightSizeY / 2;
	Sceen2TwoPlayerLowlightVertex[2].Z = 0;
	Sceen2TwoPlayerLowlightVertex[3].X = Sceen2TwoPlayerLowlightPosX + Sceen2TwoPlayerLowlightSizeX / 2;
	Sceen2TwoPlayerLowlightVertex[3].Y = Sceen2TwoPlayerLowlightPosY + Sceen2TwoPlayerLowlightSizeY / 2;
	Sceen2TwoPlayerLowlightVertex[3].Z = 0;
	Sceen2TwoPlayerLowlightVertex[0].rhw = 1.0f;
	Sceen2TwoPlayerLowlightVertex[1].rhw = 1.0f;
	Sceen2TwoPlayerLowlightVertex[2].rhw = 1.0f;
	Sceen2TwoPlayerLowlightVertex[3].rhw = 1.0f;
	Sceen2TwoPlayerLowlightVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2TwoPlayerLowlightVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2TwoPlayerLowlightVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2TwoPlayerLowlightVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2TwoPlayerLowlightVertex[0].u = 0.0f;
	Sceen2TwoPlayerLowlightVertex[0].v = 0.0f;
	Sceen2TwoPlayerLowlightVertex[1].u = 1.0f;
	Sceen2TwoPlayerLowlightVertex[1].v = 0.0f;
	Sceen2TwoPlayerLowlightVertex[2].u = 0.0f;
	Sceen2TwoPlayerLowlightVertex[2].v = 1.0f;
	Sceen2TwoPlayerLowlightVertex[3].u = 1.0f;
	Sceen2TwoPlayerLowlightVertex[3].v = 1.0f;
}
void InitTexture7()
{
	Sceen2SelectArrowVertex[0].X = Sceen2SelectArrowPosX - Sceen2SelectArrowSizeX / 2;
	Sceen2SelectArrowVertex[0].Y = Sceen2SelectArrowPosY - Sceen2SelectArrowSizeY / 2;
	Sceen2SelectArrowVertex[0].Z = 0;
	Sceen2SelectArrowVertex[1].X = Sceen2SelectArrowPosX + Sceen2SelectArrowSizeX / 2;
	Sceen2SelectArrowVertex[1].Y = Sceen2SelectArrowPosY - Sceen2SelectArrowSizeY / 2;
	Sceen2SelectArrowVertex[1].Z = 0;
	Sceen2SelectArrowVertex[2].X = Sceen2SelectArrowPosX - Sceen2SelectArrowSizeX / 2;
	Sceen2SelectArrowVertex[2].Y = Sceen2SelectArrowPosY + Sceen2SelectArrowSizeY / 2;
	Sceen2SelectArrowVertex[2].Z = 0;
	Sceen2SelectArrowVertex[3].X = Sceen2SelectArrowPosX + Sceen2SelectArrowSizeX / 2;
	Sceen2SelectArrowVertex[3].Y = Sceen2SelectArrowPosY + Sceen2SelectArrowSizeY / 2;
	Sceen2SelectArrowVertex[3].Z = 0;
	Sceen2SelectArrowVertex[0].rhw = 1.0f;
	Sceen2SelectArrowVertex[1].rhw = 1.0f;
	Sceen2SelectArrowVertex[2].rhw = 1.0f;
	Sceen2SelectArrowVertex[3].rhw = 1.0f;
	Sceen2SelectArrowVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2SelectArrowVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2SelectArrowVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2SelectArrowVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2SelectArrowVertex[0].u = 0.0f;
	Sceen2SelectArrowVertex[0].v = 0.0f;
	Sceen2SelectArrowVertex[1].u = 0.25f;
	Sceen2SelectArrowVertex[1].v = 0.0f;
	Sceen2SelectArrowVertex[2].u = 0.0f;
	Sceen2SelectArrowVertex[2].v = 1.0f;
	Sceen2SelectArrowVertex[3].u = 0.25f;
	Sceen2SelectArrowVertex[3].v = 1.0f;
}
void InitTexture8()
{
	Sceen2BgPicVertex[0].X = Sceen2BgPicPosX - Sceen2BgPicSizeX / 2;
	Sceen2BgPicVertex[0].Y = Sceen2BgPicPosY - Sceen2BgPicSizeY / 2;
	Sceen2BgPicVertex[0].Z = 0;
	Sceen2BgPicVertex[1].X = Sceen2BgPicPosX + Sceen2BgPicSizeX / 2;
	Sceen2BgPicVertex[1].Y = Sceen2BgPicPosY - Sceen2BgPicSizeY / 2;
	Sceen2BgPicVertex[1].Z = 0;
	Sceen2BgPicVertex[2].X = Sceen2BgPicPosX - Sceen2BgPicSizeX / 2;
	Sceen2BgPicVertex[2].Y = Sceen2BgPicPosY + Sceen2BgPicSizeY / 2;
	Sceen2BgPicVertex[2].Z = 0;
	Sceen2BgPicVertex[3].X = Sceen2BgPicPosX + Sceen2BgPicSizeX / 2;
	Sceen2BgPicVertex[3].Y = Sceen2BgPicPosY + Sceen2BgPicSizeY / 2;
	Sceen2BgPicVertex[3].Z = 0;
	Sceen2BgPicVertex[0].rhw = 1.0f;
	Sceen2BgPicVertex[1].rhw = 1.0f;
	Sceen2BgPicVertex[2].rhw = 1.0f;
	Sceen2BgPicVertex[3].rhw = 1.0f;
	Sceen2BgPicVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2BgPicVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2BgPicVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2BgPicVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2BgPicVertex[0].u = 0.0f;
	Sceen2BgPicVertex[0].v = 0.0f;
	Sceen2BgPicVertex[1].u = 1.0f;
	Sceen2BgPicVertex[1].v = 0.0f;
	Sceen2BgPicVertex[2].u = 0.0f;
	Sceen2BgPicVertex[2].v = 1.0f;
	Sceen2BgPicVertex[3].u = 1.0f;
	Sceen2BgPicVertex[3].v = 1.0f;
}
void InitTexture9()
{
	Sceen2SunVertex[0].X = Sceen2SunPosX - Sceen2SunSizeX / 2;
	Sceen2SunVertex[0].Y = Sceen2SunPosY - Sceen2SunSizeY / 2;
	Sceen2SunVertex[0].Z = 0;
	Sceen2SunVertex[1].X = Sceen2SunPosX + Sceen2SunSizeX / 2;
	Sceen2SunVertex[1].Y = Sceen2SunPosY - Sceen2SunSizeY / 2;
	Sceen2SunVertex[1].Z = 0;
	Sceen2SunVertex[2].X = Sceen2SunPosX - Sceen2SunSizeX / 2;
	Sceen2SunVertex[2].Y = Sceen2SunPosY + Sceen2SunSizeY / 2;
	Sceen2SunVertex[2].Z = 0;
	Sceen2SunVertex[3].X = Sceen2SunPosX + Sceen2SunSizeX / 2;
	Sceen2SunVertex[3].Y = Sceen2SunPosY + Sceen2SunSizeY / 2;
	Sceen2SunVertex[3].Z = 0;
	Sceen2SunVertex[0].rhw = 1.0f;
	Sceen2SunVertex[1].rhw = 1.0f;
	Sceen2SunVertex[2].rhw = 1.0f;
	Sceen2SunVertex[3].rhw = 1.0f;
	Sceen2SunVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2SunVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2SunVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2SunVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2SunVertex[0].u = 0.0f;
	Sceen2SunVertex[0].v = 0.0f;
	Sceen2SunVertex[1].u = 1.0f;
	Sceen2SunVertex[1].v = 0.0f;
	Sceen2SunVertex[2].u = 0.0f;
	Sceen2SunVertex[2].v = 1.0f;
	Sceen2SunVertex[3].u = 1.0f;
	Sceen2SunVertex[3].v = 1.0f;
}
void InitTexture10()
{
	Sceen2Seagull1Vertex[0].X = Sceen2Seagull1PosX - Sceen2Seagull1SizeX / 2;
	Sceen2Seagull1Vertex[0].Y = Sceen2Seagull1PosY - Sceen2Seagull1SizeY / 2;
	Sceen2Seagull1Vertex[0].Z = 0;
	Sceen2Seagull1Vertex[1].X = Sceen2Seagull1PosX + Sceen2Seagull1SizeX / 2;
	Sceen2Seagull1Vertex[1].Y = Sceen2Seagull1PosY - Sceen2Seagull1SizeY / 2;
	Sceen2Seagull1Vertex[1].Z = 0;
	Sceen2Seagull1Vertex[2].X = Sceen2Seagull1PosX - Sceen2Seagull1SizeX / 2;
	Sceen2Seagull1Vertex[2].Y = Sceen2Seagull1PosY + Sceen2Seagull1SizeY / 2;
	Sceen2Seagull1Vertex[2].Z = 0;
	Sceen2Seagull1Vertex[3].X = Sceen2Seagull1PosX + Sceen2Seagull1SizeX / 2;
	Sceen2Seagull1Vertex[3].Y = Sceen2Seagull1PosY + Sceen2Seagull1SizeY / 2;
	Sceen2Seagull1Vertex[3].Z = 0;
	Sceen2Seagull1Vertex[0].rhw = 1.0f;
	Sceen2Seagull1Vertex[1].rhw = 1.0f;
	Sceen2Seagull1Vertex[2].rhw = 1.0f;
	Sceen2Seagull1Vertex[3].rhw = 1.0f;
	Sceen2Seagull1Vertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2Seagull1Vertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2Seagull1Vertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2Seagull1Vertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2Seagull1Vertex[0].u = 0.0f;
	Sceen2Seagull1Vertex[0].v = 0.0f;
	Sceen2Seagull1Vertex[1].u = 1.0f;
	Sceen2Seagull1Vertex[1].v = 0.0f;
	Sceen2Seagull1Vertex[2].u = 0.0f;
	Sceen2Seagull1Vertex[2].v = 1.0f;
	Sceen2Seagull1Vertex[3].u = 1.0f;
}

void InitTexture11()
{
	Sceen2Seagull2Vertex[0].X = Sceen2Seagull2PosX - Sceen2Seagull2SizeX / 2;
	Sceen2Seagull2Vertex[0].Y = Sceen2Seagull2PosY - Sceen2Seagull2SizeY / 2;
	Sceen2Seagull2Vertex[0].Z = 0;
	Sceen2Seagull2Vertex[1].X = Sceen2Seagull2PosX + Sceen2Seagull2SizeX / 2;
	Sceen2Seagull2Vertex[1].Y = Sceen2Seagull2PosY - Sceen2Seagull2SizeY / 2;
	Sceen2Seagull2Vertex[1].Z = 0;
	Sceen2Seagull2Vertex[2].X = Sceen2Seagull2PosX - Sceen2Seagull2SizeX / 2;
	Sceen2Seagull2Vertex[2].Y = Sceen2Seagull2PosY + Sceen2Seagull2SizeY / 2;
	Sceen2Seagull2Vertex[2].Z = 0;
	Sceen2Seagull2Vertex[3].X = Sceen2Seagull2PosX + Sceen2Seagull2SizeX / 2;
	Sceen2Seagull2Vertex[3].Y = Sceen2Seagull2PosY + Sceen2Seagull2SizeY / 2;
	Sceen2Seagull2Vertex[3].Z = 0;
	Sceen2Seagull2Vertex[0].rhw = 1.0f;
	Sceen2Seagull2Vertex[1].rhw = 1.0f;
	Sceen2Seagull2Vertex[2].rhw = 1.0f;
	Sceen2Seagull2Vertex[3].rhw = 1.0f;
	Sceen2Seagull2Vertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2Seagull2Vertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2Seagull2Vertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2Seagull2Vertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen2Seagull2Vertex[0].u = 0.0f;
	Sceen2Seagull2Vertex[0].v = 0.0f;
	Sceen2Seagull2Vertex[1].u = 1.0f;
	Sceen2Seagull2Vertex[1].v = 0.0f;
	Sceen2Seagull2Vertex[2].u = 0.0f;
	Sceen2Seagull2Vertex[2].v = 1.0f;
	Sceen2Seagull2Vertex[3].u = 1.0f;
	Sceen2Seagull2Vertex[3].v = 1.0f;
}
void InitTexture12()
{
	Sceen3BgPicVertex[0].X = Sceen3BgPicPosX - Sceen3BgPicSizeX / 2;
	Sceen3BgPicVertex[0].Y = Sceen3BgPicPosY - Sceen3BgPicSizeY / 2;
	Sceen3BgPicVertex[0].Z = 0;
	Sceen3BgPicVertex[1].X = Sceen3BgPicPosX + Sceen3BgPicSizeX / 2;
	Sceen3BgPicVertex[1].Y = Sceen3BgPicPosY - Sceen3BgPicSizeY / 2;
	Sceen3BgPicVertex[1].Z = 0;
	Sceen3BgPicVertex[2].X = Sceen3BgPicPosX - Sceen3BgPicSizeX / 2;
	Sceen3BgPicVertex[2].Y = Sceen3BgPicPosY + Sceen3BgPicSizeY / 2;
	Sceen3BgPicVertex[2].Z = 0;
	Sceen3BgPicVertex[3].X = Sceen3BgPicPosX + Sceen3BgPicSizeX / 2;
	Sceen3BgPicVertex[3].Y = Sceen3BgPicPosY + Sceen3BgPicSizeY / 2;
	Sceen3BgPicVertex[3].Z = 0;
	Sceen3BgPicVertex[0].rhw = 1.0f;
	Sceen3BgPicVertex[1].rhw = 1.0f;
	Sceen3BgPicVertex[2].rhw = 1.0f;
	Sceen3BgPicVertex[3].rhw = 1.0f;
	Sceen3BgPicVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen3BgPicVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen3BgPicVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen3BgPicVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen3BgPicVertex[0].u = 0.0f;
	Sceen3BgPicVertex[0].v = 0.0f;
	Sceen3BgPicVertex[1].u = 1.0f;
	Sceen3BgPicVertex[1].v = 0.0f;
	Sceen3BgPicVertex[2].u = 0.0f;
	Sceen3BgPicVertex[2].v = 1.0f;
	Sceen3BgPicVertex[3].u = 1.0f;
	Sceen3BgPicVertex[3].v = 1.0f;
}
void InitTexture13()
{
	Sceen3SelectBoxVertex[0].X = Sceen3SelectBoxPosX - Sceen3SelectBoxSizeX / 2;
	Sceen3SelectBoxVertex[0].Y = Sceen3SelectBoxPosY - Sceen3SelectBoxSizeY / 2;
	Sceen3SelectBoxVertex[0].Z = 0;
	Sceen3SelectBoxVertex[1].X = Sceen3SelectBoxPosX + Sceen3SelectBoxSizeX / 2;
	Sceen3SelectBoxVertex[1].Y = Sceen3SelectBoxPosY - Sceen3SelectBoxSizeY / 2;
	Sceen3SelectBoxVertex[1].Z = 0;
	Sceen3SelectBoxVertex[2].X = Sceen3SelectBoxPosX - Sceen3SelectBoxSizeX / 2;
	Sceen3SelectBoxVertex[2].Y = Sceen3SelectBoxPosY + Sceen3SelectBoxSizeY / 2;
	Sceen3SelectBoxVertex[2].Z = 0;
	Sceen3SelectBoxVertex[3].X = Sceen3SelectBoxPosX + Sceen3SelectBoxSizeX / 2;
	Sceen3SelectBoxVertex[3].Y = Sceen3SelectBoxPosY + Sceen3SelectBoxSizeY / 2;
	Sceen3SelectBoxVertex[3].Z = 0;
	Sceen3SelectBoxVertex[0].rhw = 1.0f;
	Sceen3SelectBoxVertex[1].rhw = 1.0f;
	Sceen3SelectBoxVertex[2].rhw = 1.0f;
	Sceen3SelectBoxVertex[3].rhw = 1.0f;
	Sceen3SelectBoxVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen3SelectBoxVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen3SelectBoxVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen3SelectBoxVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen3SelectBoxVertex[0].u = 0.0f;
	Sceen3SelectBoxVertex[0].v = 0.0f;
	Sceen3SelectBoxVertex[1].u = 1.0f;
	Sceen3SelectBoxVertex[1].v = 0.0f;
	Sceen3SelectBoxVertex[2].u = 0.0f;
	Sceen3SelectBoxVertex[2].v = 1.0f;
	Sceen3SelectBoxVertex[3].u = 1.0f;
	Sceen3SelectBoxVertex[3].v = 1.0f;
}
void InitTexture14()
{
	Sceen3Stage1Vertex[0].X = Sceen3Stage1PosX - Sceen3Stage1SizeX / 2;
	Sceen3Stage1Vertex[0].Y = Sceen3Stage1PosY - Sceen3Stage1SizeY / 2;
	Sceen3Stage1Vertex[0].Z = 0;
	Sceen3Stage1Vertex[1].X = Sceen3Stage1PosX + Sceen3Stage1SizeX / 2;
	Sceen3Stage1Vertex[1].Y = Sceen3Stage1PosY - Sceen3Stage1SizeY / 2;
	Sceen3Stage1Vertex[1].Z = 0;
	Sceen3Stage1Vertex[2].X = Sceen3Stage1PosX - Sceen3Stage1SizeX / 2;
	Sceen3Stage1Vertex[2].Y = Sceen3Stage1PosY + Sceen3Stage1SizeY / 2;
	Sceen3Stage1Vertex[2].Z = 0;
	Sceen3Stage1Vertex[3].X = Sceen3Stage1PosX + Sceen3Stage1SizeX / 2;
	Sceen3Stage1Vertex[3].Y = Sceen3Stage1PosY + Sceen3Stage1SizeY / 2;
	Sceen3Stage1Vertex[3].Z = 0;
	Sceen3Stage1Vertex[0].rhw = 1.0f;
	Sceen3Stage1Vertex[1].rhw = 1.0f;
	Sceen3Stage1Vertex[2].rhw = 1.0f;
	Sceen3Stage1Vertex[3].rhw = 1.0f;
	Sceen3Stage1Vertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen3Stage1Vertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen3Stage1Vertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen3Stage1Vertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen3Stage1Vertex[0].u = 0.0f;
	Sceen3Stage1Vertex[0].v = 0.0f;
	Sceen3Stage1Vertex[1].u = 1.0f;
	Sceen3Stage1Vertex[1].v = 0.0f;
	Sceen3Stage1Vertex[2].u = 0.0f;
	Sceen3Stage1Vertex[2].v = 1.0f;
	Sceen3Stage1Vertex[3].u = 1.0f;
	Sceen3Stage1Vertex[3].v = 1.0f;
}

void InitTexture15()
{
	Sceen3Stage2Vertex[0].X = Sceen3Stage2PosX - Sceen3Stage2SizeX / 2;
	Sceen3Stage2Vertex[0].Y = Sceen3Stage2PosY - Sceen3Stage2SizeY / 2;
	Sceen3Stage2Vertex[0].Z = 0;
	Sceen3Stage2Vertex[1].X = Sceen3Stage2PosX + Sceen3Stage2SizeX / 2;
	Sceen3Stage2Vertex[1].Y = Sceen3Stage2PosY - Sceen3Stage2SizeY / 2;
	Sceen3Stage2Vertex[1].Z = 0;
	Sceen3Stage2Vertex[2].X = Sceen3Stage2PosX - Sceen3Stage2SizeX / 2;
	Sceen3Stage2Vertex[2].Y = Sceen3Stage2PosY + Sceen3Stage2SizeY / 2;
	Sceen3Stage2Vertex[2].Z = 0;
	Sceen3Stage2Vertex[3].X = Sceen3Stage2PosX + Sceen3Stage2SizeX / 2;
	Sceen3Stage2Vertex[3].Y = Sceen3Stage2PosY + Sceen3Stage2SizeY / 2;
	Sceen3Stage2Vertex[3].Z = 0;
	Sceen3Stage2Vertex[0].rhw = 1.0f;
	Sceen3Stage2Vertex[1].rhw = 1.0f;
	Sceen3Stage2Vertex[2].rhw = 1.0f;
	Sceen3Stage2Vertex[3].rhw = 1.0f;
	Sceen3Stage2Vertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen3Stage2Vertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen3Stage2Vertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen3Stage2Vertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen3Stage2Vertex[0].u = 0.0f;
	Sceen3Stage2Vertex[0].v = 0.0f;
	Sceen3Stage2Vertex[1].u = 1.0f;
	Sceen3Stage2Vertex[1].v = 0.0f;
	Sceen3Stage2Vertex[2].u = 0.0f;
	Sceen3Stage2Vertex[2].v = 1.0f;
	Sceen3Stage2Vertex[3].u = 1.0f;
	Sceen3Stage2Vertex[3].v = 1.0f;
}
void InitTexture16()
{
	Sceen3Stage3Vertex[0].X = Sceen3Stage3PosX - Sceen3Stage3SizeX / 2;
	Sceen3Stage3Vertex[0].Y = Sceen3Stage3PosY - Sceen3Stage3SizeY / 2;
	Sceen3Stage3Vertex[0].Z = 0;
	Sceen3Stage3Vertex[1].X = Sceen3Stage3PosX + Sceen3Stage3SizeX / 2;
	Sceen3Stage3Vertex[1].Y = Sceen3Stage3PosY - Sceen3Stage3SizeY / 2;
	Sceen3Stage3Vertex[1].Z = 0;
	Sceen3Stage3Vertex[2].X = Sceen3Stage3PosX - Sceen3Stage3SizeX / 2;
	Sceen3Stage3Vertex[2].Y = Sceen3Stage3PosY + Sceen3Stage3SizeY / 2;
	Sceen3Stage3Vertex[2].Z = 0;
	Sceen3Stage3Vertex[3].X = Sceen3Stage3PosX + Sceen3Stage3SizeX / 2;
	Sceen3Stage3Vertex[3].Y = Sceen3Stage3PosY + Sceen3Stage3SizeY / 2;
	Sceen3Stage3Vertex[3].Z = 0;
	Sceen3Stage3Vertex[0].rhw = 1.0f;
	Sceen3Stage3Vertex[1].rhw = 1.0f;
	Sceen3Stage3Vertex[2].rhw = 1.0f;
	Sceen3Stage3Vertex[3].rhw = 1.0f;
	Sceen3Stage3Vertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen3Stage3Vertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen3Stage3Vertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen3Stage3Vertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen3Stage3Vertex[0].u = 0.0f;
	Sceen3Stage3Vertex[0].v = 0.0f;
	Sceen3Stage3Vertex[1].u = 1.0f;
	Sceen3Stage3Vertex[1].v = 0.0f;
	Sceen3Stage3Vertex[2].u = 0.0f;
	Sceen3Stage3Vertex[2].v = 1.0f;
	Sceen3Stage3Vertex[3].u = 1.0f;
	Sceen3Stage3Vertex[3].v = 1.0f;
}
void InitTexture17()
{
	Sceen3Stage4Vertex[0].X = Sceen3Stage4PosX - Sceen3Stage4SizeX / 2;
	Sceen3Stage4Vertex[0].Y = Sceen3Stage4PosY - Sceen3Stage4SizeY / 2;
	Sceen3Stage4Vertex[0].Z = 0;
	Sceen3Stage4Vertex[1].X = Sceen3Stage4PosX + Sceen3Stage4SizeX / 2;
	Sceen3Stage4Vertex[1].Y = Sceen3Stage4PosY - Sceen3Stage4SizeY / 2;
	Sceen3Stage4Vertex[1].Z = 0;
	Sceen3Stage4Vertex[2].X = Sceen3Stage4PosX - Sceen3Stage4SizeX / 2;
	Sceen3Stage4Vertex[2].Y = Sceen3Stage4PosY + Sceen3Stage4SizeY / 2;
	Sceen3Stage4Vertex[2].Z = 0;
	Sceen3Stage4Vertex[3].X = Sceen3Stage4PosX + Sceen3Stage4SizeX / 2;
	Sceen3Stage4Vertex[3].Y = Sceen3Stage4PosY + Sceen3Stage4SizeY / 2;
	Sceen3Stage4Vertex[3].Z = 0;
	Sceen3Stage4Vertex[0].rhw = 1.0f;
	Sceen3Stage4Vertex[1].rhw = 1.0f;
	Sceen3Stage4Vertex[2].rhw = 1.0f;
	Sceen3Stage4Vertex[3].rhw = 1.0f;
	Sceen3Stage4Vertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen3Stage4Vertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen3Stage4Vertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen3Stage4Vertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen3Stage4Vertex[0].u = 0.0f;
	Sceen3Stage4Vertex[0].v = 0.0f;
	Sceen3Stage4Vertex[1].u = 1.0f;
	Sceen3Stage4Vertex[1].v = 0.0f;
	Sceen3Stage4Vertex[2].u = 0.0f;
	Sceen3Stage4Vertex[2].v = 1.0f;
	Sceen3Stage4Vertex[3].u = 1.0f;
	Sceen3Stage4Vertex[3].v = 1.0f;
}
void InitTexture18()
{
	CharacterAVertex[0].X = CharacterAPosX - CharacterASizeX / 2;
	CharacterAVertex[0].Y = CharacterAPosY - CharacterASizeY / 2;
	CharacterAVertex[0].Z = 0;
	CharacterAVertex[1].X = CharacterAPosX + CharacterASizeX / 2;
	CharacterAVertex[1].Y = CharacterAPosY - CharacterASizeY / 2;
	CharacterAVertex[1].Z = 0;
	CharacterAVertex[2].X = CharacterAPosX - CharacterASizeX / 2;
	CharacterAVertex[2].Y = CharacterAPosY + CharacterASizeY / 2;
	CharacterAVertex[2].Z = 0;
	CharacterAVertex[3].X = CharacterAPosX + CharacterASizeX / 2;
	CharacterAVertex[3].Y = CharacterAPosY + CharacterASizeY / 2;
	CharacterAVertex[3].Z = 0;
	CharacterAVertex[0].rhw = 1.0f;
	CharacterAVertex[1].rhw = 1.0f;
	CharacterAVertex[2].rhw = 1.0f;
	CharacterAVertex[3].rhw = 1.0f;
	CharacterAVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	CharacterAVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	CharacterAVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	CharacterAVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	CharacterAVertex[0].u = 0.0f;
	CharacterAVertex[0].v = 0.0f;
	CharacterAVertex[1].u = 33.0f / 132.0f;
	CharacterAVertex[1].v = 0.0f;
	CharacterAVertex[2].u = 0.0f;
	CharacterAVertex[2].v = 32.0f / 224.0f;
	CharacterAVertex[3].u = 33.0f / 132.0f;
	CharacterAVertex[3].v = 32.0f / 224.0f;
}
void InitTexture19()
{
	Sceen3SelectTileVertex[0].X = Sceen3SelectTilePosX -Sceen3SelectTileSizeX / 2;
	Sceen3SelectTileVertex[0].Y = Sceen3SelectTilePosY -Sceen3SelectTileSizeY / 2;
	Sceen3SelectTileVertex[0].Z = 0;
	Sceen3SelectTileVertex[1].X = Sceen3SelectTilePosX + Sceen3SelectTileSizeX / 2;
	Sceen3SelectTileVertex[1].Y = Sceen3SelectTilePosY - Sceen3SelectTileSizeY / 2;
	Sceen3SelectTileVertex[1].Z = 0;
	Sceen3SelectTileVertex[2].X = Sceen3SelectTilePosX - Sceen3SelectTileSizeX / 2;
	Sceen3SelectTileVertex[2].Y = Sceen3SelectTilePosY + Sceen3SelectTileSizeY / 2;
	Sceen3SelectTileVertex[2].Z = 0;
	Sceen3SelectTileVertex[3].X = Sceen3SelectTilePosX + Sceen3SelectTileSizeX / 2;
	Sceen3SelectTileVertex[3].Y = Sceen3SelectTilePosY + Sceen3SelectTileSizeY / 2;
	Sceen3SelectTileVertex[3].Z = 0;
	Sceen3SelectTileVertex[0].rhw = 1.0f;
	Sceen3SelectTileVertex[1].rhw = 1.0f;
	Sceen3SelectTileVertex[2].rhw = 1.0f;
	Sceen3SelectTileVertex[3].rhw = 1.0f;
	Sceen3SelectTileVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen3SelectTileVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen3SelectTileVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen3SelectTileVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen3SelectTileVertex[0].u = 0.0f;
	Sceen3SelectTileVertex[0].v = 0.0f;
	Sceen3SelectTileVertex[1].u = 1.0f;
	Sceen3SelectTileVertex[1].v = 0.0f;
	Sceen3SelectTileVertex[2].u = 0.0f;
	Sceen3SelectTileVertex[2].v = 1.0f;
	Sceen3SelectTileVertex[3].u = 1.0f;
	Sceen3SelectTileVertex[3].v = 1.0f;
}
void InitTexture20()
{
	GroundBoxVertex[0].X = GroundBoxPosX - GroundBoxSizeX / 2;
	GroundBoxVertex[0].Y = GroundBoxPosY - GroundBoxSizeY / 2;
	GroundBoxVertex[0].Z = 0;
	GroundBoxVertex[1].X = GroundBoxPosX + GroundBoxSizeX / 2;
	GroundBoxVertex[1].Y = GroundBoxPosY - GroundBoxSizeY / 2;
	GroundBoxVertex[1].Z = 0;
	GroundBoxVertex[2].X = GroundBoxPosX - GroundBoxSizeX / 2;
	GroundBoxVertex[2].Y = GroundBoxPosY + GroundBoxSizeY / 2;
	GroundBoxVertex[2].Z = 0;
	GroundBoxVertex[3].X = GroundBoxPosX + GroundBoxSizeX / 2;
	GroundBoxVertex[3].Y = GroundBoxPosY + GroundBoxSizeY / 2;
	GroundBoxVertex[3].Z = 0;
	GroundBoxVertex[0].rhw = 1.0f;
	GroundBoxVertex[1].rhw = 1.0f;
	GroundBoxVertex[2].rhw = 1.0f;
	GroundBoxVertex[3].rhw = 1.0f;
	GroundBoxVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	GroundBoxVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	GroundBoxVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	GroundBoxVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	GroundBoxVertex[0].u = 0.0f;
	GroundBoxVertex[0].v = 0.0f;
	GroundBoxVertex[1].u = 1.0f;
	GroundBoxVertex[1].v = 0.0f;
	GroundBoxVertex[2].u = 0.0f;
	GroundBoxVertex[2].v = 1.0f;
	GroundBoxVertex[3].u = 1.0f;
	GroundBoxVertex[3].v = 1.0f;
}
void InitTexture21()
{
	Sceen3HouseVertex[0].X = Sceen3HousePosX - Sceen3HouseSizeX / 2;
	Sceen3HouseVertex[0].Y = Sceen3HousePosY - Sceen3HouseSizeY / 2;
	Sceen3HouseVertex[0].Z = 0;
	Sceen3HouseVertex[1].X = Sceen3HousePosX + Sceen3HouseSizeX / 2;
	Sceen3HouseVertex[1].Y = Sceen3HousePosY - Sceen3HouseSizeY / 2;
	Sceen3HouseVertex[1].Z = 0;
	Sceen3HouseVertex[2].X = Sceen3HousePosX - Sceen3HouseSizeX / 2;
	Sceen3HouseVertex[2].Y = Sceen3HousePosY + Sceen3HouseSizeY / 2;
	Sceen3HouseVertex[2].Z = 0;
	Sceen3HouseVertex[3].X = Sceen3HousePosX + Sceen3HouseSizeX / 2;
	Sceen3HouseVertex[3].Y = Sceen3HousePosY + Sceen3HouseSizeY / 2;
	Sceen3HouseVertex[3].Z = 0;
	Sceen3HouseVertex[0].rhw = 1.0f;
	Sceen3HouseVertex[1].rhw = 1.0f;
	Sceen3HouseVertex[2].rhw = 1.0f;
	Sceen3HouseVertex[3].rhw = 1.0f;
	Sceen3HouseVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen3HouseVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen3HouseVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen3HouseVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen3HouseVertex[0].u = 0.0f;
	Sceen3HouseVertex[0].v = 0.0f;
	Sceen3HouseVertex[1].u = 1.0f;
	Sceen3HouseVertex[1].v = 0.0f;
	Sceen3HouseVertex[2].u = 0.0f;
	Sceen3HouseVertex[2].v = 1.0f;
	Sceen3HouseVertex[3].u = 1.0f;
	Sceen3HouseVertex[3].v = 1.0f;
}
void InitTexture22()
{
	for (int i = 0; i < GEMMAX; i++)
	{
		GemPosX[i] = -1000;
		GemPosY[i] = -1000;
		GemSizeX[i] = 100;
		GemSizeY[i] = 100;

		GemVertex[i][0].X = GemPosX[i] - GemSizeX[i] / 2;
		GemVertex[i][0].Y = GemPosY[i] - GemSizeY[i] / 2;
		GemVertex[i][0].Z = 0;
		GemVertex[i][1].X = GemPosX[i] + GemSizeX[i] / 2;
		GemVertex[i][1].Y = GemPosY[i] - GemSizeY[i] / 2;
		GemVertex[i][1].Z = 0;
		GemVertex[i][2].X = GemPosX[i] - GemSizeX[i] / 2;
		GemVertex[i][2].Y = GemPosY[i] + GemSizeY[i] / 2;
		GemVertex[i][2].Z = 0;
		GemVertex[i][3].X = GemPosX[i] + GemSizeX[i] / 2;
		GemVertex[i][3].Y = GemPosY[i] + GemSizeY[i] / 2;
		GemVertex[i][3].Z = 0;
		GemVertex[i][0].rhw = 1.0f;
		GemVertex[i][1].rhw = 1.0f;
		GemVertex[i][2].rhw = 1.0f;
		GemVertex[i][3].rhw = 1.0f;
		GemVertex[i][0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		GemVertex[i][1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		GemVertex[i][2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		GemVertex[i][3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		GemVertex[i][0].u = 0.0f / 75.0f;
		GemVertex[i][0].v = 0.0f;
		GemVertex[i][1].u = 15.0f / 75.0f;
		GemVertex[i][1].v = 0.0f;
		GemVertex[i][2].u = 0.0f / 75.0f;
		GemVertex[i][2].v = 1.0f;
		GemVertex[i][3].u = 15.0f / 75.0f;
		GemVertex[i][3].v = 1.0f;
	}
	
}
void InitTexture23()
{
	for (int i = 0; i < ITEMFEEDBACKMAX; i++)
	{
		TouchState[i] = false;
		ItemDisState[i] = true;
		//埵抲弶巒壔
		ItemFeedbackPosX[i] = GemPosX[i];
		ItemFeedbackPosY[i] = GemPosY[i];
		ItemFeedbackSizeX[i] = GemSizeX[i];
		ItemFeedbackSizeY[i] = GemSizeY[i];

		ItemFeedbackVertex[i][0].X = ItemFeedbackPosX[i] - ItemFeedbackSizeX[i] / 2;
		ItemFeedbackVertex[i][0].Y = ItemFeedbackPosY[i] - ItemFeedbackSizeY[i] / 2;
		ItemFeedbackVertex[i][0].Z = 0;
		ItemFeedbackVertex[i][1].X = ItemFeedbackPosX[i] + ItemFeedbackSizeX[i] / 2;
		ItemFeedbackVertex[i][1].Y = ItemFeedbackPosY[i] - ItemFeedbackSizeY[i] / 2;
		ItemFeedbackVertex[i][1].Z = 0;
		ItemFeedbackVertex[i][2].X = ItemFeedbackPosX[i] - ItemFeedbackSizeX[i] / 2;
		ItemFeedbackVertex[i][2].Y = ItemFeedbackPosY[i] + ItemFeedbackSizeY[i] / 2;
		ItemFeedbackVertex[i][2].Z = 0;
		ItemFeedbackVertex[i][3].X = ItemFeedbackPosX[i] + ItemFeedbackSizeX[i] / 2;
		ItemFeedbackVertex[i][3].Y = ItemFeedbackPosY[i] + ItemFeedbackSizeY[i] / 2;
		ItemFeedbackVertex[i][3].Z = 0;
		ItemFeedbackVertex[i][0].rhw = 1.0f;
		ItemFeedbackVertex[i][1].rhw = 1.0f;
		ItemFeedbackVertex[i][2].rhw = 1.0f;
		ItemFeedbackVertex[i][3].rhw = 1.0f;
		ItemFeedbackVertex[i][0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		ItemFeedbackVertex[i][1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		ItemFeedbackVertex[i][2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		ItemFeedbackVertex[i][3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		ItemFeedbackVertex[i][0].u = 0.0f;
		ItemFeedbackVertex[i][0].v = 0.0f;
		ItemFeedbackVertex[i][1].u = 1.0f;
		ItemFeedbackVertex[i][1].v = 0.0f;
		ItemFeedbackVertex[i][2].u = 0.0f;
		ItemFeedbackVertex[i][2].v = 1.0f;
		ItemFeedbackVertex[i][3].u = 1.0f;
		ItemFeedbackVertex[i][3].v = 1.0f;
	}

}
void InitTexture24()
{
	ArrowVertex[0].X = ArrowPosX - ArrowSizeX / 2;
	ArrowVertex[0].Y = ArrowPosY - ArrowSizeY / 2;
	ArrowVertex[0].Z = 0;
	ArrowVertex[1].X = ArrowPosX + ArrowSizeX / 2;
	ArrowVertex[1].Y = ArrowPosY - ArrowSizeY / 2;
	ArrowVertex[1].Z = 0;
	ArrowVertex[2].X = ArrowPosX - ArrowSizeX / 2;
	ArrowVertex[2].Y = ArrowPosY + ArrowSizeY / 2;
	ArrowVertex[2].Z = 0;
	ArrowVertex[3].X = ArrowPosX + ArrowSizeX / 2;
	ArrowVertex[3].Y = ArrowPosY + ArrowSizeY / 2;
	ArrowVertex[3].Z = 0;
	ArrowVertex[0].rhw = 1.0f;
	ArrowVertex[1].rhw = 1.0f;
	ArrowVertex[2].rhw = 1.0f;
	ArrowVertex[3].rhw = 1.0f;
	ArrowVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	ArrowVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	ArrowVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	ArrowVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	ArrowVertex[0].u = 0.0f;
	ArrowVertex[0].v = 0.0f;
	ArrowVertex[1].u = 1.0f;
	ArrowVertex[1].v = 0.0f;
	ArrowVertex[2].u = 0.0f;
	ArrowVertex[2].v = 1.0f;
	ArrowVertex[3].u = 1.0f;
	ArrowVertex[3].v = 1.0f;
}
void InitTexture25()
{
	BlackPicVertex[0].X = BlackPicPosX - BlackPicSizeX / 2;
	BlackPicVertex[0].Y = BlackPicPosY - BlackPicSizeY / 2;
	BlackPicVertex[0].Z = 0;
	BlackPicVertex[1].X = BlackPicPosX + BlackPicSizeX / 2;
	BlackPicVertex[1].Y = BlackPicPosY - BlackPicSizeY / 2;
	BlackPicVertex[1].Z = 0;
	BlackPicVertex[2].X = BlackPicPosX - BlackPicSizeX / 2;
	BlackPicVertex[2].Y = BlackPicPosY + BlackPicSizeY / 2;
	BlackPicVertex[2].Z = 0;
	BlackPicVertex[3].X = BlackPicPosX + BlackPicSizeX / 2;
	BlackPicVertex[3].Y = BlackPicPosY + BlackPicSizeY / 2;
	BlackPicVertex[3].Z = 0;
	BlackPicVertex[0].rhw = 1.0f;
	BlackPicVertex[1].rhw = 1.0f;
	BlackPicVertex[2].rhw = 1.0f;
	BlackPicVertex[3].rhw = 1.0f;
	BlackPicVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	BlackPicVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	BlackPicVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	BlackPicVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	BlackPicVertex[0].u = 0.0f;
	BlackPicVertex[0].v = 0.0f;
	BlackPicVertex[1].u = 1.0f;
	BlackPicVertex[1].v = 0.0f;
	BlackPicVertex[2].u = 0.0f;
	BlackPicVertex[2].v = 1.0f;
	BlackPicVertex[3].u = 1.0f;
	BlackPicVertex[3].v = 1.0f;
}
void InitTexture26()
{
	Sceen4Stage1SkyVertex[0].X = Sceen4Stage1SkyPosX - Sceen4Stage1SkySizeX / 2;
	Sceen4Stage1SkyVertex[0].Y = Sceen4Stage1SkyPosY - Sceen4Stage1SkySizeY / 2;
	Sceen4Stage1SkyVertex[0].Z = 0;
	Sceen4Stage1SkyVertex[1].X = Sceen4Stage1SkyPosX + Sceen4Stage1SkySizeX / 2;
	Sceen4Stage1SkyVertex[1].Y = Sceen4Stage1SkyPosY - Sceen4Stage1SkySizeY / 2;
	Sceen4Stage1SkyVertex[1].Z = 0;
	Sceen4Stage1SkyVertex[2].X = Sceen4Stage1SkyPosX - Sceen4Stage1SkySizeX / 2;
	Sceen4Stage1SkyVertex[2].Y = Sceen4Stage1SkyPosY + Sceen4Stage1SkySizeY / 2;
	Sceen4Stage1SkyVertex[2].Z = 0;
	Sceen4Stage1SkyVertex[3].X = Sceen4Stage1SkyPosX + Sceen4Stage1SkySizeX / 2;
	Sceen4Stage1SkyVertex[3].Y = Sceen4Stage1SkyPosY + Sceen4Stage1SkySizeY / 2;
	Sceen4Stage1SkyVertex[3].Z = 0;
	Sceen4Stage1SkyVertex[0].rhw = 1.0f;
	Sceen4Stage1SkyVertex[1].rhw = 1.0f;
	Sceen4Stage1SkyVertex[2].rhw = 1.0f;
	Sceen4Stage1SkyVertex[3].rhw = 1.0f;
	Sceen4Stage1SkyVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen4Stage1SkyVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen4Stage1SkyVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen4Stage1SkyVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen4Stage1SkyVertex[0].u = 0.0f;
	Sceen4Stage1SkyVertex[0].v = 0.0f;
	Sceen4Stage1SkyVertex[1].u = 1.0f;
	Sceen4Stage1SkyVertex[1].v = 0.0f;
	Sceen4Stage1SkyVertex[2].u = 0.0f;
	Sceen4Stage1SkyVertex[2].v = 1.0f;
	Sceen4Stage1SkyVertex[3].u = 1.0f;
	Sceen4Stage1SkyVertex[3].v = 1.0f;
}
void InitTexture27()
{
	Sceen4Stage1TileVertex[0].X = Sceen4Stage1TilePosX - Sceen4Stage1TileSizeX / 2;
	Sceen4Stage1TileVertex[0].Y = Sceen4Stage1TilePosY - Sceen4Stage1TileSizeY / 2;
	Sceen4Stage1TileVertex[0].Z = 0;
	Sceen4Stage1TileVertex[1].X = Sceen4Stage1TilePosX + Sceen4Stage1TileSizeX / 2;
	Sceen4Stage1TileVertex[1].Y = Sceen4Stage1TilePosY - Sceen4Stage1TileSizeY / 2;
	Sceen4Stage1TileVertex[1].Z = 0;
	Sceen4Stage1TileVertex[2].X = Sceen4Stage1TilePosX - Sceen4Stage1TileSizeX / 2;
	Sceen4Stage1TileVertex[2].Y = Sceen4Stage1TilePosY + Sceen4Stage1TileSizeY / 2;
	Sceen4Stage1TileVertex[2].Z = 0;
	Sceen4Stage1TileVertex[3].X =Sceen4Stage1TilePosX + Sceen4Stage1TileSizeX / 2;
	Sceen4Stage1TileVertex[3].Y =Sceen4Stage1TilePosY + Sceen4Stage1TileSizeY / 2;
	Sceen4Stage1TileVertex[3].Z = 0;
	Sceen4Stage1TileVertex[0].rhw = 1.0f;
	Sceen4Stage1TileVertex[1].rhw = 1.0f;
	Sceen4Stage1TileVertex[2].rhw = 1.0f;
	Sceen4Stage1TileVertex[3].rhw = 1.0f;
	Sceen4Stage1TileVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen4Stage1TileVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen4Stage1TileVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen4Stage1TileVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen4Stage1TileVertex[0].u = 0.0f;
	Sceen4Stage1TileVertex[0].v = 0.0f;
	Sceen4Stage1TileVertex[1].u = 1.0f;
	Sceen4Stage1TileVertex[1].v = 0.0f;
	Sceen4Stage1TileVertex[2].u = 0.0f;
	Sceen4Stage1TileVertex[2].v = 1.0f;
	Sceen4Stage1TileVertex[3].u = 1.0f;
	Sceen4Stage1TileVertex[3].v = 1.0f;
}
void InitTexture28()
{
	CharacterBoxVertex[0].X = CharacterBoxPosX - CharacterBoxSizeX / 2;
	CharacterBoxVertex[0].Y = CharacterBoxPosY - CharacterBoxSizeY / 2;
	CharacterBoxVertex[0].Z = 0;
	CharacterBoxVertex[1].X = CharacterBoxPosX + CharacterBoxSizeX / 2;
	CharacterBoxVertex[1].Y = CharacterBoxPosY - CharacterBoxSizeY / 2;
	CharacterBoxVertex[1].Z = 0;
	CharacterBoxVertex[2].X = CharacterBoxPosX - CharacterBoxSizeX / 2;
	CharacterBoxVertex[2].Y = CharacterBoxPosY + CharacterBoxSizeY / 2;
	CharacterBoxVertex[2].Z = 0;
	CharacterBoxVertex[3].X = CharacterBoxPosX + CharacterBoxSizeX / 2;
	CharacterBoxVertex[3].Y = CharacterBoxPosY + CharacterBoxSizeY / 2;
	CharacterBoxVertex[3].Z = 0;
	CharacterBoxVertex[0].rhw = 1.0f;
	CharacterBoxVertex[1].rhw = 1.0f;
	CharacterBoxVertex[2].rhw = 1.0f;
	CharacterBoxVertex[3].rhw = 1.0f;
	CharacterBoxVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	CharacterBoxVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	CharacterBoxVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	CharacterBoxVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	CharacterBoxVertex[0].u = 0.0f;
	CharacterBoxVertex[0].v = 0.0f;
	CharacterBoxVertex[1].u = 1.0f;
	CharacterBoxVertex[1].v = 0.0f;
	CharacterBoxVertex[2].u = 0.0f;
	CharacterBoxVertex[2].v = 1.0f;
	CharacterBoxVertex[3].u = 1.0f;
	CharacterBoxVertex[3].v = 1.0f;
}
void InitTexture29()
{
	for (int i = 0; i <DOORMAX; i++)
	{
		//位置大小初始化
		DoorPosX[i] = -1000;
		DoorPosY[i] = -1000;
		DoorSizeX[i] = 80;
		DoorSizeY[i] = 160;
		DoorCollisionState[i] = false;
		DoorAniState[i] = false;
		//顶点初始化
		DoorVertex[i][0].X = DoorPosX[i] - DoorSizeX[i] / 2;
		DoorVertex[i][0].Y = DoorPosY[i] - DoorSizeY[i] / 2;
		DoorVertex[i][0].Z = 0;
		DoorVertex[i][1].X = DoorPosX[i] + DoorSizeX[i] / 2;
		DoorVertex[i][1].Y = DoorPosY[i] - DoorSizeY[i] / 2;
		DoorVertex[i][1].Z = 0;
		DoorVertex[i][2].X = DoorPosX[i] - DoorSizeX[i] / 2;
		DoorVertex[i][2].Y = DoorPosY[i] + DoorSizeY[i] / 2;
		DoorVertex[i][2].Z = 0;
		DoorVertex[i][3].X = DoorPosX[i] + DoorSizeX[i] / 2;
		DoorVertex[i][3].Y = DoorPosY[i] + DoorSizeY[i] / 2;
		DoorVertex[i][3].Z = 0;
		DoorVertex[i][0].rhw = 1.0f;
		DoorVertex[i][1].rhw = 1.0f;
		DoorVertex[i][2].rhw = 1.0f;
		DoorVertex[i][3].rhw = 1.0f;
		DoorVertex[i][0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		DoorVertex[i][1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		DoorVertex[i][2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		DoorVertex[i][3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		DoorVertex[i][0].u = 0.0f;
		DoorVertex[i][0].v = 0.0f;
		DoorVertex[i][1].u = 1.0f;
		DoorVertex[i][1].v = 0.0f;
		DoorVertex[i][2].u = 0.0f;
		DoorVertex[i][2].v = 1.0f;
		DoorVertex[i][3].u = 1.0f;
		DoorVertex[i][3].v = 1.0f;
	}	
}
void InitTexture30()
{
	for (int i = 0; i < DOORMAX; i++)
	{
		//位置大小初始化
		DoorAnimationPosX[i] = DoorPosX[i];
		DoorAnimationPosY[i] = DoorPosY[i];
		DoorAnimationSizeX[i] = DoorSizeX[i];
		DoorAnimationSizeY[i] = DoorSizeY[i];
		//顶点初始化
		DoorAnimationVertex[i][0].X = DoorAnimationPosX[i] - DoorAnimationSizeX[i] / 2;
		DoorAnimationVertex[i][0].Y = DoorAnimationPosY[i] - DoorAnimationSizeY[i] / 2;
		DoorAnimationVertex[i][0].Z = 0;
		DoorAnimationVertex[i][1].X =DoorAnimationPosX[i] + DoorAnimationSizeX[i] / 2;
		DoorAnimationVertex[i][1].Y =DoorAnimationPosY[i] - DoorAnimationSizeY[i] / 2;
		DoorAnimationVertex[i][1].Z = 0;
		DoorAnimationVertex[i][2].X = DoorAnimationPosX[i] - DoorSizeX[i] / 2;
		DoorAnimationVertex[i][2].Y = DoorAnimationPosY[i] + DoorSizeY[i] / 2;
		DoorAnimationVertex[i][2].Z = 0;
		DoorAnimationVertex[i][3].X = DoorAnimationPosX[i] + DoorAnimationSizeX[i] / 2;
		DoorAnimationVertex[i][3].Y = DoorAnimationPosY[i] + DoorAnimationSizeY[i] / 2;
		DoorAnimationVertex[i][3].Z = 0;
		DoorAnimationVertex[i][0].rhw = 1.0f;
		DoorAnimationVertex[i][1].rhw = 1.0f;
		DoorAnimationVertex[i][2].rhw = 1.0f;
		DoorAnimationVertex[i][3].rhw = 1.0f;
		DoorAnimationVertex[i][0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		DoorAnimationVertex[i][1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		DoorAnimationVertex[i][2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		DoorAnimationVertex[i][3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		DoorAnimationVertex[i][0].u = 0.0f;
		DoorAnimationVertex[i][0].v = 0.0f;
		DoorAnimationVertex[i][1].u = 1.0f;
		DoorAnimationVertex[i][1].v = 0.0f;
		DoorAnimationVertex[i][2].u = 0.0f;
		DoorAnimationVertex[i][2].v = 1.0f;
		DoorAnimationVertex[i][3].u = 1.0f;
		DoorAnimationVertex[i][3].v = 1.0f;
	}
}
//Key
void InitTexture31()
{
	for (int i = 0; i < KEYMAX; i++)
	{
		//位置大小初始化
		KeyPosX[i] = -1000;
		KeyPosY[i] = -1000;
		KeySizeX[i] = 80;
		KeySizeY[i] = 80;
		//顶点初始化
		KeyVertex[i][0].X = KeyPosX[i] - KeySizeX[i] / 2;
		KeyVertex[i][0].Y = KeyPosY[i] - KeySizeY[i] / 2;
		KeyVertex[i][0].Z = 0;
		KeyVertex[i][1].X = KeyPosX[i] + KeySizeX[i] / 2;
		KeyVertex[i][1].Y = KeyPosY[i] - KeySizeY[i] / 2;
		KeyVertex[i][1].Z = 0;
		KeyVertex[i][2].X = KeyPosX[i] - KeySizeX[i] / 2;
		KeyVertex[i][2].Y = KeyPosY[i] + KeySizeY[i] / 2;
		KeyVertex[i][2].Z = 0;
		KeyVertex[i][3].X = KeyPosX[i] + KeySizeX[i] / 2;
		KeyVertex[i][3].Y = KeyPosY[i] + KeySizeY[i] / 2;
		KeyVertex[i][3].Z = 0;
		KeyVertex[i][0].rhw = 1.0f;
		KeyVertex[i][1].rhw = 1.0f;
		KeyVertex[i][2].rhw = 1.0f;
		KeyVertex[i][3].rhw = 1.0f;
		KeyVertex[i][0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		KeyVertex[i][1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		KeyVertex[i][2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		KeyVertex[i][3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		KeyVertex[i][0].u = 0.0f;
		KeyVertex[i][0].v = 0.0f;
		KeyVertex[i][1].u = 1.0f;
		KeyVertex[i][1].v = 0.0f;
		KeyVertex[i][2].u = 0.0f;
		KeyVertex[i][2].v = 1.0f;
		KeyVertex[i][3].u = 1.0f;
		KeyVertex[i][3].v = 1.0f;
	}
}
//Translucent
void InitTexture32()
{
	for (int i = 0; i < KEYMAX; i++)
	{
		//位置大小初始化
		TranslucentPosX[i] = -1000;
		TranslucentPosY[i] = -1000;
		TranslucentSizeX[i] = 80;
		TranslucentSizeY[i] = 80;
		//顶点初始化
		TranslucentVertex[i][0].X = TranslucentPosX[i] - TranslucentSizeX[i] / 2;
		TranslucentVertex[i][0].Y = TranslucentPosY[i] - TranslucentSizeY[i] / 2;
		TranslucentVertex[i][0].Z = 0;
		TranslucentVertex[i][1].X = TranslucentPosX[i] + TranslucentSizeX[i] / 2;
		TranslucentVertex[i][1].Y = TranslucentPosY[i] - TranslucentSizeY[i] / 2;
		TranslucentVertex[i][1].Z = 0;
		TranslucentVertex[i][2].X = TranslucentPosX[i] - TranslucentSizeX[i] / 2;
		TranslucentVertex[i][2].Y = TranslucentPosY[i] + TranslucentSizeY[i] / 2;
		TranslucentVertex[i][2].Z = 0;
		TranslucentVertex[i][3].X = TranslucentPosX[i] + TranslucentSizeX[i] / 2;
		TranslucentVertex[i][3].Y = TranslucentPosY[i] + TranslucentSizeY[i] / 2;
		TranslucentVertex[i][3].Z = 0;
		TranslucentVertex[i][0].rhw = 1.0f;
		TranslucentVertex[i][1].rhw = 1.0f;
		TranslucentVertex[i][2].rhw = 1.0f;
		TranslucentVertex[i][3].rhw = 1.0f;
		TranslucentVertex[i][0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		TranslucentVertex[i][1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		TranslucentVertex[i][2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		TranslucentVertex[i][3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		TranslucentVertex[i][0].u = 0.0f;
		TranslucentVertex[i][0].v = 0.0f;
		TranslucentVertex[i][1].u = 1.0f;
		TranslucentVertex[i][1].v = 0.0f;
		TranslucentVertex[i][2].u = 0.0f;
		TranslucentVertex[i][2].v = 1.0f;
		TranslucentVertex[i][3].u = 1.0f;
		TranslucentVertex[i][3].v = 1.0f;
	}
}
//W
void InitTexture33()
{
	WVertex[0].X = WPosX - WSizeX / 2;
	WVertex[0].Y = WPosY - WSizeY / 2;
	WVertex[0].Z = 0;
	WVertex[1].X = WPosX + WSizeX / 2;
	WVertex[1].Y = WPosY - WSizeY / 2;
	WVertex[1].Z = 0;
	WVertex[2].X = WPosX - WSizeX / 2;
	WVertex[2].Y = WPosY + WSizeY / 2;
	WVertex[2].Z = 0;
	WVertex[3].X = WPosX + WSizeX / 2;
	WVertex[3].Y = WPosY + WSizeY / 2;
	WVertex[3].Z = 0;
	WVertex[0].rhw = 1.0f;
	WVertex[1].rhw = 1.0f;
	WVertex[2].rhw = 1.0f;
	WVertex[3].rhw = 1.0f;
	WVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	WVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	WVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	WVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	WVertex[0].u = 0.0f;
	WVertex[0].v = 0.0f;
	WVertex[1].u = 1.0f;
	WVertex[1].v = 0.0f;
	WVertex[2].u = 0.0f;
	WVertex[2].v = 1.0f;
	WVertex[3].u = 1.0f;
	WVertex[3].v = 1.0f;
}
//A
void InitTexture34()
{
	AVertex[0].X = APosX - ASizeX / 2;
	AVertex[0].Y = APosY - ASizeY / 2;
	AVertex[0].Z = 0;
	AVertex[1].X = APosX + ASizeX / 2;
	AVertex[1].Y = APosY - ASizeY / 2;
	AVertex[1].Z = 0;
	AVertex[2].X = APosX - ASizeX / 2;
	AVertex[2].Y = APosY + ASizeY / 2;
	AVertex[2].Z = 0;
	AVertex[3].X = APosX + ASizeX / 2;
	AVertex[3].Y = APosY + ASizeY / 2;
	AVertex[3].Z = 0;
	AVertex[0].rhw = 1.0f;
	AVertex[1].rhw = 1.0f;
	AVertex[2].rhw = 1.0f;
	AVertex[3].rhw = 1.0f;
	AVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	AVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	AVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	AVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	AVertex[0].u = 0.0f;
	AVertex[0].v = 0.0f;
	AVertex[1].u = 1.0f;
	AVertex[1].v = 0.0f;
	AVertex[2].u = 0.0f;
	AVertex[2].v = 1.0f;
	AVertex[3].u = 1.0f;
	AVertex[3].v = 1.0f;
}
//S
void InitTexture35()
{
	SVertex[0].X = SPosX - SSizeX / 2;
	SVertex[0].Y = SPosY - SSizeY / 2;
	SVertex[0].Z = 0;
	SVertex[1].X = SPosX + SSizeX / 2;
	SVertex[1].Y = SPosY - SSizeY / 2;
	SVertex[1].Z = 0;
	SVertex[2].X = SPosX - SSizeX / 2;
	SVertex[2].Y = SPosY + SSizeY / 2;
	SVertex[2].Z = 0;
	SVertex[3].X = SPosX + SSizeX / 2;
	SVertex[3].Y = SPosY + SSizeY / 2;
	SVertex[3].Z = 0;
	SVertex[0].rhw = 1.0f;
	SVertex[1].rhw = 1.0f;
	SVertex[2].rhw = 1.0f;
	SVertex[3].rhw = 1.0f;
	SVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	SVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	SVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	SVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	SVertex[0].u = 0.0f;
	SVertex[0].v = 0.0f;
	SVertex[1].u = 1.0f;
	SVertex[1].v = 0.0f;
	SVertex[2].u = 0.0f;
	SVertex[2].v = 1.0f;
	SVertex[3].u = 1.0f;
	SVertex[3].v = 1.0f;
}
//D
void InitTexture36()
{
	DVertex[0].X = DPosX - DSizeX / 2;
	DVertex[0].Y = DPosY - DSizeY / 2;
	DVertex[0].Z = 0;
	DVertex[1].X = DPosX + DSizeX / 2;
	DVertex[1].Y = DPosY - DSizeY / 2;
	DVertex[1].Z = 0;
	DVertex[2].X = DPosX - DSizeX / 2;
	DVertex[2].Y = DPosY + DSizeY / 2;
	DVertex[2].Z = 0;
	DVertex[3].X = DPosX + DSizeX / 2;
	DVertex[3].Y = DPosY + DSizeY / 2;
	DVertex[3].Z = 0;
	DVertex[0].rhw = 1.0f;
	DVertex[1].rhw = 1.0f;
	DVertex[2].rhw = 1.0f;
	DVertex[3].rhw = 1.0f;
	DVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	DVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	DVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	DVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	DVertex[0].u = 0.0f;
	DVertex[0].v = 0.0f;
	DVertex[1].u = 1.0f;
	DVertex[1].v = 0.0f;
	DVertex[2].u = 0.0f;
	DVertex[2].v = 1.0f;
	DVertex[3].u = 1.0f;
	DVertex[3].v = 1.0f;
}
//Space
void InitTexture37()
{
	SpaceVertex[0].X = SpacePosX - SpaceSizeX / 2;
	SpaceVertex[0].Y = SpacePosY - SpaceSizeY / 2;
	SpaceVertex[0].Z = 0;
	SpaceVertex[1].X = SpacePosX + SpaceSizeX / 2;
	SpaceVertex[1].Y = SpacePosY - SpaceSizeY / 2;
	SpaceVertex[1].Z = 0;
	SpaceVertex[2].X = SpacePosX - SpaceSizeX / 2;
	SpaceVertex[2].Y = SpacePosY + SpaceSizeY / 2;
	SpaceVertex[2].Z = 0;
	SpaceVertex[3].X = SpacePosX + SpaceSizeX / 2;
	SpaceVertex[3].Y = SpacePosY + SpaceSizeY / 2;
	SpaceVertex[3].Z = 0;
	SpaceVertex[0].rhw = 1.0f;
	SpaceVertex[1].rhw = 1.0f;
	SpaceVertex[2].rhw = 1.0f;
	SpaceVertex[3].rhw = 1.0f;
	SpaceVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	SpaceVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	SpaceVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	SpaceVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	SpaceVertex[0].u = 0.0f;
	SpaceVertex[0].v = 0.0f;
	SpaceVertex[1].u = 1.0f;
	SpaceVertex[1].v = 0.0f;
	SpaceVertex[2].u = 0.0f;
	SpaceVertex[2].v = 1.0f;
	SpaceVertex[3].u = 1.0f;
	SpaceVertex[3].v = 1.0f;
}
//LoadingTitle
void InitTexture38()
{
	LoadingTitleVertex[0].X = LoadingTitlePosX - LoadingTitleSizeX / 2;
	LoadingTitleVertex[0].Y = LoadingTitlePosY - LoadingTitleSizeY / 2;
	LoadingTitleVertex[0].Z = 0;
	LoadingTitleVertex[1].X = LoadingTitlePosX + LoadingTitleSizeX / 2;
	LoadingTitleVertex[1].Y = LoadingTitlePosY - LoadingTitleSizeY / 2;
	LoadingTitleVertex[1].Z = 0;
	LoadingTitleVertex[2].X = LoadingTitlePosX - LoadingTitleSizeX / 2;
	LoadingTitleVertex[2].Y = LoadingTitlePosY + LoadingTitleSizeY / 2;
	LoadingTitleVertex[2].Z = 0;
	LoadingTitleVertex[3].X = LoadingTitlePosX + LoadingTitleSizeX / 2;
	LoadingTitleVertex[3].Y = LoadingTitlePosY + LoadingTitleSizeY / 2;
	LoadingTitleVertex[3].Z = 0;
	LoadingTitleVertex[0].rhw = 1.0f;
	LoadingTitleVertex[1].rhw = 1.0f;
	LoadingTitleVertex[2].rhw = 1.0f;
	LoadingTitleVertex[3].rhw = 1.0f;
	LoadingTitleVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	LoadingTitleVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	LoadingTitleVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	LoadingTitleVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	LoadingTitleVertex[0].u = 0.0f;
	LoadingTitleVertex[0].v = 0.0f;
	LoadingTitleVertex[1].u = 1.0f;
	LoadingTitleVertex[1].v = 0.0f;
	LoadingTitleVertex[2].u = 0.0f;
	LoadingTitleVertex[2].v = 1.0f;
	LoadingTitleVertex[3].u = 1.0f;
	LoadingTitleVertex[3].v = 1.0f;
}
//Stage1Title
void InitTexture39()
{
	Stage1TitleVertex[0].X = Stage1TitlePosX - Stage1TitleSizeX / 2;
	Stage1TitleVertex[0].Y = Stage1TitlePosY - Stage1TitleSizeY / 2;
	Stage1TitleVertex[0].Z = 0;
	Stage1TitleVertex[1].X = Stage1TitlePosX + Stage1TitleSizeX / 2;
	Stage1TitleVertex[1].Y = Stage1TitlePosY - Stage1TitleSizeY / 2;
	Stage1TitleVertex[1].Z = 0;
	Stage1TitleVertex[2].X = Stage1TitlePosX - Stage1TitleSizeX / 2;
	Stage1TitleVertex[2].Y = Stage1TitlePosY + Stage1TitleSizeY / 2;
	Stage1TitleVertex[2].Z = 0;
	Stage1TitleVertex[3].X = Stage1TitlePosX + Stage1TitleSizeX / 2;
	Stage1TitleVertex[3].Y = Stage1TitlePosY + Stage1TitleSizeY / 2;
	Stage1TitleVertex[3].Z = 0;
	Stage1TitleVertex[0].rhw = 1.0f;
	Stage1TitleVertex[1].rhw = 1.0f;
	Stage1TitleVertex[2].rhw = 1.0f;
	Stage1TitleVertex[3].rhw = 1.0f;
	Stage1TitleVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Stage1TitleVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Stage1TitleVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Stage1TitleVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Stage1TitleVertex[0].u = 0.0f;
	Stage1TitleVertex[0].v = 0.0f;
	Stage1TitleVertex[1].u = 1.0f;
	Stage1TitleVertex[1].v = 0.0f;
	Stage1TitleVertex[2].u = 0.0f;
	Stage1TitleVertex[2].v = 1.0f;
	Stage1TitleVertex[3].u = 1.0f;
	Stage1TitleVertex[3].v = 1.0f;
}
//TwiceJump
void InitTexture40()
{
	CharacterAVertex[0].X = CharacterAPosX - CharacterASizeX / 2;
	CharacterAVertex[0].Y = CharacterAPosY - CharacterASizeY / 2;
	CharacterAVertex[0].Z = 0;
	CharacterAVertex[1].X = CharacterAPosX + CharacterASizeX / 2;
	CharacterAVertex[1].Y = CharacterAPosY - CharacterASizeY / 2;
	CharacterAVertex[1].Z = 0;
	CharacterAVertex[2].X = CharacterAPosX - CharacterASizeX / 2;
	CharacterAVertex[2].Y = CharacterAPosY + CharacterASizeY / 2;
	CharacterAVertex[2].Z = 0;
	CharacterAVertex[3].X = CharacterAPosX + CharacterASizeX / 2;
	CharacterAVertex[3].Y = CharacterAPosY + CharacterASizeY / 2;
	CharacterAVertex[3].Z = 0;
	CharacterAVertex[0].rhw = 1.0f;
	CharacterAVertex[1].rhw = 1.0f;
	CharacterAVertex[2].rhw = 1.0f;
	CharacterAVertex[3].rhw = 1.0f;
	CharacterAVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	CharacterAVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	CharacterAVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	CharacterAVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	CharacterAVertex[0].u = 0.0f;
	CharacterAVertex[0].v = 0.0f;
	CharacterAVertex[1].u = 33.0f / 132.0f;
	CharacterAVertex[1].v = 0.0f;
	CharacterAVertex[2].u = 0.0f;
	CharacterAVertex[2].v = 32.0f / 32.0f;
	CharacterAVertex[3].u = 33.0f / 132.0f;
	CharacterAVertex[3].v = 32.0f / 32.0f;
}
void InitTexture41()
{
	for (int i = 0; i < CLOUDMAX; i++)
	{
		CloudPosX[i] = -1000;
		CloudPosY[i] = -1000;
		CloudSizeX[i] = 300;
		CloudSizeY[i] = 300;

		CloudVertex[i][0].X = CloudPosX[i] - CloudSizeX[i] / 2;
		CloudVertex[i][0].Y = CloudPosY[i] - CloudSizeY[i] / 2;
		CloudVertex[i][0].Z = 0;
		CloudVertex[i][1].X = CloudPosX[i] + CloudSizeX[i] / 2;
		CloudVertex[i][1].Y = CloudPosY[i] - CloudSizeY[i] / 2;
		CloudVertex[i][1].Z = 0;
		CloudVertex[i][2].X = CloudPosX[i] - CloudSizeX[i] / 2;
		CloudVertex[i][2].Y = CloudPosY[i] + CloudSizeY[i] / 2;
		CloudVertex[i][2].Z = 0;
		CloudVertex[i][3].X = CloudPosX[i] + CloudSizeX[i] / 2;
		CloudVertex[i][3].Y = CloudPosY[i] + CloudSizeY[i] / 2;
		CloudVertex[i][3].Z = 0;
		CloudVertex[i][0].rhw = 1.0f;
		CloudVertex[i][1].rhw = 1.0f;
		CloudVertex[i][2].rhw = 1.0f;
		CloudVertex[i][3].rhw = 1.0f;
		CloudVertex[i][0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		CloudVertex[i][1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		CloudVertex[i][2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		CloudVertex[i][3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		CloudVertex[i][0].u = 0.0f;
		CloudVertex[i][0].v = 0.0f;
		CloudVertex[i][1].u = 1.0f;
		CloudVertex[i][1].v = 0.0f;
		CloudVertex[i][2].u = 0.0f;
		CloudVertex[i][2].v = 1.0f;
		CloudVertex[i][3].u = 1.0f;
		CloudVertex[i][3].v = 1.0f;
	}
}
//NowLoading
void InitTexture42()
{
	NowLoadingVertex[0].X = NowLoadingPosX - NowLoadingSizeX / 2;
	NowLoadingVertex[0].Y = NowLoadingPosY - NowLoadingSizeY / 2;
	NowLoadingVertex[0].Z = 0;
	NowLoadingVertex[1].X = NowLoadingPosX + NowLoadingSizeX / 2;
	NowLoadingVertex[1].Y = NowLoadingPosY - NowLoadingSizeY / 2;
	NowLoadingVertex[1].Z = 0;
	NowLoadingVertex[2].X = NowLoadingPosX - NowLoadingSizeX / 2;
	NowLoadingVertex[2].Y = NowLoadingPosY + NowLoadingSizeY / 2;
	NowLoadingVertex[2].Z = 0;
	NowLoadingVertex[3].X = NowLoadingPosX + NowLoadingSizeX / 2;
	NowLoadingVertex[3].Y = NowLoadingPosY + NowLoadingSizeY / 2;
	NowLoadingVertex[3].Z = 0;
	NowLoadingVertex[0].rhw = 1.0f;
	NowLoadingVertex[1].rhw = 1.0f;
	NowLoadingVertex[2].rhw = 1.0f;
	NowLoadingVertex[3].rhw = 1.0f;
	NowLoadingVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	NowLoadingVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	NowLoadingVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	NowLoadingVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	NowLoadingVertex[0].u = 0.0f;
	NowLoadingVertex[0].v = 0.0f;
	NowLoadingVertex[1].u = 1.0f;
	NowLoadingVertex[1].v = 0.0f;
	NowLoadingVertex[2].u = 0.0f;
	NowLoadingVertex[2].v = 1.0f;
	NowLoadingVertex[3].u = 1.0f;
	NowLoadingVertex[3].v = 1.0f;
}
// GameOverTitle
void InitTexture43()
{
	GameOverTitleVertex[0].X = GameOverTitlePosX - GameOverTitleSizeX / 2;
	GameOverTitleVertex[0].Y = GameOverTitlePosY - GameOverTitleSizeY / 2;
	GameOverTitleVertex[0].Z = 0;
	GameOverTitleVertex[1].X = GameOverTitlePosX + GameOverTitleSizeX / 2;
	GameOverTitleVertex[1].Y = GameOverTitlePosY - GameOverTitleSizeY / 2;
	GameOverTitleVertex[1].Z = 0;
	GameOverTitleVertex[2].X = GameOverTitlePosX - GameOverTitleSizeX / 2;
	GameOverTitleVertex[2].Y = GameOverTitlePosY + GameOverTitleSizeY / 2;
	GameOverTitleVertex[2].Z = 0;
	GameOverTitleVertex[3].X = GameOverTitlePosX + GameOverTitleSizeX / 2;
	GameOverTitleVertex[3].Y = GameOverTitlePosY + GameOverTitleSizeY / 2;
	GameOverTitleVertex[3].Z = 0;
	GameOverTitleVertex[0].rhw = 1.0f;
	GameOverTitleVertex[1].rhw = 1.0f;
	GameOverTitleVertex[2].rhw = 1.0f;
	GameOverTitleVertex[3].rhw = 1.0f;
	GameOverTitleVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	GameOverTitleVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	GameOverTitleVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	GameOverTitleVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	GameOverTitleVertex[0].u = 0.0f;
	GameOverTitleVertex[0].v = 0.0f;
	GameOverTitleVertex[1].u = 1.0f;
	GameOverTitleVertex[1].v = 0.0f;
	GameOverTitleVertex[2].u = 0.0f;
	GameOverTitleVertex[2].v = 1.0f;
	GameOverTitleVertex[3].u = 1.0f;
	GameOverTitleVertex[3].v = 1.0f;
}

//RetryHighlight
void InitTexture44()
{
	RetryHighlightVertex[0].X = RetryHighlightPosX - RetryHighlightSizeX / 2;
	RetryHighlightVertex[0].Y = RetryHighlightPosY - RetryHighlightSizeY / 2;
	RetryHighlightVertex[0].Z = 0;
	RetryHighlightVertex[1].X = RetryHighlightPosX + RetryHighlightSizeX / 2;
	RetryHighlightVertex[1].Y = RetryHighlightPosY - RetryHighlightSizeY / 2;
	RetryHighlightVertex[1].Z = 0;
	RetryHighlightVertex[2].X = RetryHighlightPosX - RetryHighlightSizeX / 2;
	RetryHighlightVertex[2].Y = RetryHighlightPosY + RetryHighlightSizeY / 2;
	RetryHighlightVertex[2].Z = 0;
	RetryHighlightVertex[3].X = RetryHighlightPosX + RetryHighlightSizeX / 2;
	RetryHighlightVertex[3].Y = RetryHighlightPosY + RetryHighlightSizeY / 2;
	RetryHighlightVertex[3].Z = 0;
	RetryHighlightVertex[0].rhw = 1.0f;
	RetryHighlightVertex[1].rhw = 1.0f;
	RetryHighlightVertex[2].rhw = 1.0f;
	RetryHighlightVertex[3].rhw = 1.0f;
	RetryHighlightVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	RetryHighlightVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	RetryHighlightVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	RetryHighlightVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	RetryHighlightVertex[0].u = 0.0f;
	RetryHighlightVertex[0].v = 0.0f;
	RetryHighlightVertex[1].u = 1.0f;
	RetryHighlightVertex[1].v = 0.0f;
	RetryHighlightVertex[2].u = 0.0f;
	RetryHighlightVertex[2].v = 1.0f;
	RetryHighlightVertex[3].u = 1.0f;
	RetryHighlightVertex[3].v = 1.0f;
}
//RetryLowlight
void InitTexture45()
{
	RetryLowlightVertex[0].X = RetryLowlightPosX - RetryLowlightSizeX / 2;
	RetryLowlightVertex[0].Y = RetryLowlightPosY - RetryLowlightSizeY / 2;
	RetryLowlightVertex[0].Z = 0;
	RetryLowlightVertex[1].X = RetryLowlightPosX + RetryLowlightSizeX / 2;
	RetryLowlightVertex[1].Y = RetryLowlightPosY - RetryLowlightSizeY / 2;
	RetryLowlightVertex[1].Z = 0;
	RetryLowlightVertex[2].X = RetryLowlightPosX - RetryLowlightSizeX / 2;
	RetryLowlightVertex[2].Y = RetryLowlightPosY + RetryLowlightSizeY / 2;
	RetryLowlightVertex[2].Z = 0;
	RetryLowlightVertex[3].X = RetryLowlightPosX + RetryLowlightSizeX / 2;
	RetryLowlightVertex[3].Y = RetryLowlightPosY + RetryLowlightSizeY / 2;
	RetryLowlightVertex[3].Z = 0;
	RetryLowlightVertex[0].rhw = 1.0f;
	RetryLowlightVertex[1].rhw = 1.0f;
	RetryLowlightVertex[2].rhw = 1.0f;
	RetryLowlightVertex[3].rhw = 1.0f;
	RetryLowlightVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	RetryLowlightVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	RetryLowlightVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	RetryLowlightVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	RetryLowlightVertex[0].u = 0.0f;
	RetryLowlightVertex[0].v = 0.0f;
	RetryLowlightVertex[1].u = 1.0f;
	RetryLowlightVertex[1].v = 0.0f;
	RetryLowlightVertex[2].u = 0.0f;
	RetryLowlightVertex[2].v = 1.0f;
	RetryLowlightVertex[3].u = 1.0f;
	RetryLowlightVertex[3].v = 1.0f;
}
//StageSelectHighlight
void InitTexture46()
{
	StageSelectHighlightVertex[0].X = StageSelectHighlightPosX - StageSelectHighlightSizeX / 2;
	StageSelectHighlightVertex[0].Y = StageSelectHighlightPosY - StageSelectHighlightSizeY / 2;
	StageSelectHighlightVertex[0].Z = 0;
	StageSelectHighlightVertex[1].X = StageSelectHighlightPosX + StageSelectHighlightSizeX / 2;
	StageSelectHighlightVertex[1].Y = StageSelectHighlightPosY - StageSelectHighlightSizeY / 2;
	StageSelectHighlightVertex[1].Z = 0;
	StageSelectHighlightVertex[2].X = StageSelectHighlightPosX - StageSelectHighlightSizeX / 2;
	StageSelectHighlightVertex[2].Y = StageSelectHighlightPosY + StageSelectHighlightSizeY / 2;
	StageSelectHighlightVertex[2].Z = 0;
	StageSelectHighlightVertex[3].X = StageSelectHighlightPosX + StageSelectHighlightSizeX / 2;
	StageSelectHighlightVertex[3].Y = StageSelectHighlightPosY + StageSelectHighlightSizeY / 2;
	StageSelectHighlightVertex[3].Z = 0;
	StageSelectHighlightVertex[0].rhw = 1.0f;
	StageSelectHighlightVertex[1].rhw = 1.0f;
	StageSelectHighlightVertex[2].rhw = 1.0f;
	StageSelectHighlightVertex[3].rhw = 1.0f;
	StageSelectHighlightVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	StageSelectHighlightVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	StageSelectHighlightVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	StageSelectHighlightVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	StageSelectHighlightVertex[0].u = 0.0f;
	StageSelectHighlightVertex[0].v = 0.0f;
	StageSelectHighlightVertex[1].u = 1.0f;
	StageSelectHighlightVertex[1].v = 0.0f;
	StageSelectHighlightVertex[2].u = 0.0f;
	StageSelectHighlightVertex[2].v = 1.0f;
	StageSelectHighlightVertex[3].u = 1.0f;
	StageSelectHighlightVertex[3].v = 1.0f;
}
//StageSelectLowlight
void InitTexture47()
{
	StageSelectLowlightVertex[0].X = StageSelectLowlightPosX - StageSelectLowlightSizeX / 2;
	StageSelectLowlightVertex[0].Y = StageSelectLowlightPosY - StageSelectLowlightSizeY / 2;
	StageSelectLowlightVertex[0].Z = 0;
	StageSelectLowlightVertex[1].X = StageSelectLowlightPosX + StageSelectLowlightSizeX / 2;
	StageSelectLowlightVertex[1].Y = StageSelectLowlightPosY - StageSelectLowlightSizeY / 2;
	StageSelectLowlightVertex[1].Z = 0;
	StageSelectLowlightVertex[2].X = StageSelectLowlightPosX - StageSelectLowlightSizeX / 2;
	StageSelectLowlightVertex[2].Y = StageSelectLowlightPosY + StageSelectLowlightSizeY / 2;
	StageSelectLowlightVertex[2].Z = 0;
	StageSelectLowlightVertex[3].X = StageSelectLowlightPosX + StageSelectLowlightSizeX / 2;
	StageSelectLowlightVertex[3].Y = StageSelectLowlightPosY + StageSelectLowlightSizeY / 2;
	StageSelectLowlightVertex[3].Z = 0;
	StageSelectLowlightVertex[0].rhw = 1.0f;
	StageSelectLowlightVertex[1].rhw = 1.0f;
	StageSelectLowlightVertex[2].rhw = 1.0f;
	StageSelectLowlightVertex[3].rhw = 1.0f;
	StageSelectLowlightVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	StageSelectLowlightVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	StageSelectLowlightVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	StageSelectLowlightVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	StageSelectLowlightVertex[0].u = 0.0f;
	StageSelectLowlightVertex[0].v = 0.0f;
	StageSelectLowlightVertex[1].u = 1.0f;
	StageSelectLowlightVertex[1].v = 0.0f;
	StageSelectLowlightVertex[2].u = 0.0f;
	StageSelectLowlightVertex[2].v = 1.0f;
	StageSelectLowlightVertex[3].u = 1.0f;
	StageSelectLowlightVertex[3].v = 1.0f;
}
//Sceen81BgPic
void InitTexture48()
{
	Sceen81BgPicVertex[0].X = Sceen81BgPicPosX - Sceen81BgPicSizeX / 2;
	Sceen81BgPicVertex[0].Y = Sceen81BgPicPosY - Sceen81BgPicSizeY / 2;
	Sceen81BgPicVertex[0].Z = 0;
	Sceen81BgPicVertex[1].X = Sceen81BgPicPosX + Sceen81BgPicSizeX / 2;
	Sceen81BgPicVertex[1].Y = Sceen81BgPicPosY - Sceen81BgPicSizeY / 2;
	Sceen81BgPicVertex[1].Z = 0;
	Sceen81BgPicVertex[2].X = Sceen81BgPicPosX - Sceen81BgPicSizeX / 2;
	Sceen81BgPicVertex[2].Y = Sceen81BgPicPosY + Sceen81BgPicSizeY / 2;
	Sceen81BgPicVertex[2].Z = 0;
	Sceen81BgPicVertex[3].X = Sceen81BgPicPosX + Sceen81BgPicSizeX / 2;
	Sceen81BgPicVertex[3].Y = Sceen81BgPicPosY + Sceen81BgPicSizeY / 2;
	Sceen81BgPicVertex[3].Z = 0;
	Sceen81BgPicVertex[0].rhw = 1.0f;
	Sceen81BgPicVertex[1].rhw = 1.0f;
	Sceen81BgPicVertex[2].rhw = 1.0f;
	Sceen81BgPicVertex[3].rhw = 1.0f;
	Sceen81BgPicVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen81BgPicVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen81BgPicVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen81BgPicVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen81BgPicVertex[0].u = 0.0f;
	Sceen81BgPicVertex[0].v = 0.0f;
	Sceen81BgPicVertex[1].u = 1.0f;
	Sceen81BgPicVertex[1].v = 0.0f;
	Sceen81BgPicVertex[2].u = 0.0f;
	Sceen81BgPicVertex[2].v = 1.0f;
	Sceen81BgPicVertex[3].u = 1.0f;
	Sceen81BgPicVertex[3].v = 1.0f;
}
//LoadingIcon
void InitTexture49()
{
	LoadingIconVertex[0].X = LoadingIconPosX - LoadingIconSizeX / 2;
	LoadingIconVertex[0].Y = LoadingIconPosY - LoadingIconSizeY / 2;
	LoadingIconVertex[0].Z = 0;
	LoadingIconVertex[1].X = LoadingIconPosX + LoadingIconSizeX / 2;
	LoadingIconVertex[1].Y = LoadingIconPosY - LoadingIconSizeY / 2;
	LoadingIconVertex[1].Z = 0;
	LoadingIconVertex[2].X = LoadingIconPosX - LoadingIconSizeX / 2;
	LoadingIconVertex[2].Y = LoadingIconPosY + LoadingIconSizeY / 2;
	LoadingIconVertex[2].Z = 0;
	LoadingIconVertex[3].X = LoadingIconPosX + LoadingIconSizeX / 2;
	LoadingIconVertex[3].Y = LoadingIconPosY + LoadingIconSizeY / 2;
	LoadingIconVertex[3].Z = 0;
	LoadingIconVertex[0].rhw = 1.0f;
	LoadingIconVertex[1].rhw = 1.0f;
	LoadingIconVertex[2].rhw = 1.0f;
	LoadingIconVertex[3].rhw = 1.0f;
	LoadingIconVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	LoadingIconVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	LoadingIconVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	LoadingIconVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	LoadingIconVertex[1].u = 0.0f / 140.0f;
	LoadingIconVertex[1].v = 0.0f / 140.0f;
	LoadingIconVertex[0].u = 35.0f / 140.0f;
	LoadingIconVertex[0].v = 0.0f / 140.0f;
	LoadingIconVertex[3].u = 0.0f / 140.0f;
	LoadingIconVertex[3].v = 140.0f / 140.0f;
	LoadingIconVertex[2].u = 35.0f / 140.0f;
	LoadingIconVertex[2].v = 140.0f / 140.0f;
}
//Sceen5Tile
void InitTexture50()
{
	Sceen5TileVertex[0].X = Sceen5TilePosX - Sceen5TileSizeX / 2;
	Sceen5TileVertex[0].Y = Sceen5TilePosY - Sceen5TileSizeY / 2;
	Sceen5TileVertex[0].Z = 0;
	Sceen5TileVertex[1].X = Sceen5TilePosX + Sceen5TileSizeX / 2;
	Sceen5TileVertex[1].Y = Sceen5TilePosY - Sceen5TileSizeY / 2;
	Sceen5TileVertex[1].Z = 0;
	Sceen5TileVertex[2].X = Sceen5TilePosX - Sceen5TileSizeX / 2;
	Sceen5TileVertex[2].Y = Sceen5TilePosY + Sceen5TileSizeY / 2;
	Sceen5TileVertex[2].Z = 0;
	Sceen5TileVertex[3].X = Sceen5TilePosX + Sceen5TileSizeX / 2;
	Sceen5TileVertex[3].Y = Sceen5TilePosY + Sceen5TileSizeY / 2;
	Sceen5TileVertex[3].Z = 0;
	Sceen5TileVertex[0].rhw = 1.0f;
	Sceen5TileVertex[1].rhw = 1.0f;
	Sceen5TileVertex[2].rhw = 1.0f;
	Sceen5TileVertex[3].rhw = 1.0f;
	Sceen5TileVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen5TileVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen5TileVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen5TileVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen5TileVertex[0].u = 0.0f;
	Sceen5TileVertex[0].v = 0.0f;
	Sceen5TileVertex[1].u = 1.0f;
	Sceen5TileVertex[1].v = 0.0f;
	Sceen5TileVertex[2].u = 0.0f;
	Sceen5TileVertex[2].v = 1.0f;
	Sceen5TileVertex[3].u = 1.0f;
	Sceen5TileVertex[3].v = 1.0f;
}
//Sceen5Arrow
void InitTexture51()
{
	Sceen5ArrowVertex[0].X = Sceen5ArrowPosX - Sceen5ArrowSizeX / 2;
	Sceen5ArrowVertex[0].Y = Sceen5ArrowPosY - Sceen5ArrowSizeY / 2;
	Sceen5ArrowVertex[0].Z = 0;
	Sceen5ArrowVertex[1].X = Sceen5ArrowPosX + Sceen5ArrowSizeX / 2;
	Sceen5ArrowVertex[1].Y = Sceen5ArrowPosY - Sceen5ArrowSizeY / 2;
	Sceen5ArrowVertex[1].Z = 0;
	Sceen5ArrowVertex[2].X = Sceen5ArrowPosX - Sceen5ArrowSizeX / 2;
	Sceen5ArrowVertex[2].Y = Sceen5ArrowPosY + Sceen5ArrowSizeY / 2;
	Sceen5ArrowVertex[2].Z = 0;
	Sceen5ArrowVertex[3].X = Sceen5ArrowPosX + Sceen5ArrowSizeX / 2;
	Sceen5ArrowVertex[3].Y = Sceen5ArrowPosY + Sceen5ArrowSizeY / 2;
	Sceen5ArrowVertex[3].Z = 0;
	Sceen5ArrowVertex[0].rhw = 1.0f;
	Sceen5ArrowVertex[1].rhw = 1.0f;
	Sceen5ArrowVertex[2].rhw = 1.0f;
	Sceen5ArrowVertex[3].rhw = 1.0f;
	Sceen5ArrowVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen5ArrowVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen5ArrowVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen5ArrowVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen5ArrowVertex[0].u = 0.0f;
	Sceen5ArrowVertex[0].v = 0.0f;
	Sceen5ArrowVertex[1].u = 1.0f;
	Sceen5ArrowVertex[1].v = 0.0f;
	Sceen5ArrowVertex[2].u = 0.0f;
	Sceen5ArrowVertex[2].v = 1.0f;
	Sceen5ArrowVertex[3].u = 1.0f;
	Sceen5ArrowVertex[3].v = 1.0f;
}
//Spike
void InitTexture52()
{
	for (int i = 0; i < SPIKEMAX; i++)
	{
		SpikePosX[i] = -1000;
		SpikePosY[i] = -1000;
		SpikeSizeX[i] = 80;
		SpikeSizeY[i] = 160;

		SpikeVertex[i][0].X = SpikePosX[i] - SpikeSizeX[i] / 2;
		SpikeVertex[i][0].Y = SpikePosY[i] - SpikeSizeY[i] / 2;
		SpikeVertex[i][0].Z = 0;
		SpikeVertex[i][1].X = SpikePosX[i] + SpikeSizeX[i] / 2;
		SpikeVertex[i][1].Y = SpikePosY[i] - SpikeSizeY[i] / 2;
		SpikeVertex[i][1].Z = 0;
		SpikeVertex[i][2].X = SpikePosX[i] - SpikeSizeX[i] / 2;
		SpikeVertex[i][2].Y = SpikePosY[i] + SpikeSizeY[i] / 2;
		SpikeVertex[i][2].Z = 0;
		SpikeVertex[i][3].X = SpikePosX[i] + SpikeSizeX[i] / 2;
		SpikeVertex[i][3].Y = SpikePosY[i] + SpikeSizeY[i] / 2;
		SpikeVertex[i][3].Z = 0;
		SpikeVertex[i][0].rhw = 1.0f;
		SpikeVertex[i][1].rhw = 1.0f;
		SpikeVertex[i][2].rhw = 1.0f;
		SpikeVertex[i][3].rhw = 1.0f;
		SpikeVertex[i][0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		SpikeVertex[i][1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		SpikeVertex[i][2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		SpikeVertex[i][3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		SpikeVertex[i][0].u = 0.0f;
		SpikeVertex[i][0].v = 0.0f;
		SpikeVertex[i][1].u = 1.0f;
		SpikeVertex[i][1].v = 0.0f;
		SpikeVertex[i][2].u = 0.0f;
		SpikeVertex[i][2].v = 1.0f;
		SpikeVertex[i][3].u = 1.0f;
		SpikeVertex[i][3].v = 1.0f;
	}
	for (int i = 0; i < 22; i++)
	{
		SpikeMoveState[i] = false;//初始化状态
		SpikePosX[i] = 120 + 80 * i;
		SpikePosY[i] = 200;
		//顶点位置竵E?
		SpikeVertex[i][0].X = SpikePosX[i] - SpikeSizeX[i] / 2;
		SpikeVertex[i][0].Y = SpikePosY[i] - SpikeSizeY[i] / 2;
		SpikeVertex[i][1].X = SpikePosX[i] + SpikeSizeX[i] / 2;
		SpikeVertex[i][1].Y = SpikePosY[i] - SpikeSizeY[i] / 2;
		SpikeVertex[i][2].X = SpikePosX[i] - SpikeSizeX[i] / 2;
		SpikeVertex[i][2].Y = SpikePosY[i] + SpikeSizeY[i] / 2;
		SpikeVertex[i][3].X = SpikePosX[i] + SpikeSizeX[i] / 2;
		SpikeVertex[i][3].Y = SpikePosY[i] + SpikeSizeY[i] / 2;
	}
}

//Sceen6Tile
void InitTexture53()
{
	Sceen6TileVertex[0].X = Sceen6TilePosX - Sceen6TileSizeX / 2;
	Sceen6TileVertex[0].Y = Sceen6TilePosY - Sceen6TileSizeY / 2;
	Sceen6TileVertex[0].Z = 0;
	Sceen6TileVertex[1].X = Sceen6TilePosX + Sceen6TileSizeX / 2;
	Sceen6TileVertex[1].Y = Sceen6TilePosY - Sceen6TileSizeY / 2;
	Sceen6TileVertex[1].Z = 0;
	Sceen6TileVertex[2].X = Sceen6TilePosX - Sceen6TileSizeX / 2;
	Sceen6TileVertex[2].Y = Sceen6TilePosY + Sceen6TileSizeY / 2;
	Sceen6TileVertex[2].Z = 0;
	Sceen6TileVertex[3].X = Sceen6TilePosX + Sceen6TileSizeX / 2;
	Sceen6TileVertex[3].Y = Sceen6TilePosY + Sceen6TileSizeY / 2;
	Sceen6TileVertex[3].Z = 0;
	Sceen6TileVertex[0].rhw = 1.0f;
	Sceen6TileVertex[1].rhw = 1.0f;
	Sceen6TileVertex[2].rhw = 1.0f;
	Sceen6TileVertex[3].rhw = 1.0f;
	Sceen6TileVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen6TileVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen6TileVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen6TileVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen6TileVertex[0].u = 0.0f;
	Sceen6TileVertex[0].v = 0.0f;
	Sceen6TileVertex[1].u = 1.0f;
	Sceen6TileVertex[1].v = 0.0f;
	Sceen6TileVertex[2].u = 0.0f;
	Sceen6TileVertex[2].v = 1.0f;
	Sceen6TileVertex[3].u = 1.0f;
	Sceen6TileVertex[3].v = 1.0f;
}
//Laser
void InitTexture54()
{
	LaserVertex[0].X = LaserPosX - LaserSizeX / 2;
	LaserVertex[0].Y = LaserPosY - LaserSizeY / 2;
	LaserVertex[0].Z = 0;
	LaserVertex[1].X = LaserPosX + LaserSizeX / 2;
	LaserVertex[1].Y = LaserPosY - LaserSizeY / 2;
	LaserVertex[1].Z = 0;
	LaserVertex[2].X = LaserPosX - LaserSizeX / 2;
	LaserVertex[2].Y = LaserPosY + LaserSizeY / 2;
	LaserVertex[2].Z = 0;
	LaserVertex[3].X = LaserPosX + LaserSizeX / 2;
	LaserVertex[3].Y = LaserPosY + LaserSizeY / 2;
	LaserVertex[3].Z = 0;
	LaserVertex[0].rhw = 1.0f;
	LaserVertex[1].rhw = 1.0f;
	LaserVertex[2].rhw = 1.0f;
	LaserVertex[3].rhw = 1.0f;
	LaserVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	LaserVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	LaserVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	LaserVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	LaserVertex[0].u = 0.0f;
	LaserVertex[0].v = 0.0f;
	LaserVertex[1].u = 1.0f;
	LaserVertex[1].v = 0.0f;
	LaserVertex[2].u = 0.0f;
	LaserVertex[2].v = 1.0f;
	LaserVertex[3].u = 1.0f;
	LaserVertex[3].v = 1.0f;
}
//Sceen7Tile
void InitTexture55()
{
	Sceen7TileVertex[0].X = Sceen7TilePosX - Sceen7TileSizeX / 2;
	Sceen7TileVertex[0].Y = Sceen7TilePosY - Sceen7TileSizeY / 2;
	Sceen7TileVertex[0].Z = 0;
	Sceen7TileVertex[1].X = Sceen7TilePosX + Sceen7TileSizeX / 2;
	Sceen7TileVertex[1].Y = Sceen7TilePosY - Sceen7TileSizeY / 2;
	Sceen7TileVertex[1].Z = 0;
	Sceen7TileVertex[2].X = Sceen7TilePosX - Sceen7TileSizeX / 2;
	Sceen7TileVertex[2].Y = Sceen7TilePosY + Sceen7TileSizeY / 2;
	Sceen7TileVertex[2].Z = 0;
	Sceen7TileVertex[3].X = Sceen7TilePosX + Sceen7TileSizeX / 2;
	Sceen7TileVertex[3].Y = Sceen7TilePosY + Sceen7TileSizeY / 2;
	Sceen7TileVertex[3].Z = 0;
	Sceen7TileVertex[0].rhw = 1.0f;
	Sceen7TileVertex[1].rhw = 1.0f;
	Sceen7TileVertex[2].rhw = 1.0f;
	Sceen7TileVertex[3].rhw = 1.0f;
	Sceen7TileVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen7TileVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen7TileVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen7TileVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen7TileVertex[0].u = 0.0f;
	Sceen7TileVertex[0].v = 0.0f;
	Sceen7TileVertex[1].u = 1.0f;
	Sceen7TileVertex[1].v = 0.0f;
	Sceen7TileVertex[2].u = 0.0f;
	Sceen7TileVertex[2].v = 1.0f;
	Sceen7TileVertex[3].u = 1.0f;
	Sceen7TileVertex[3].v = 1.0f;
}
//Bullet
void InitTexture56()
{
	BulletVertex[0].X = BulletPosX - BulletSizeX / 2;
	BulletVertex[0].Y = BulletPosY - BulletSizeY / 2;
	BulletVertex[0].Z = 0;
	BulletVertex[1].X = BulletPosX + BulletSizeX / 2;
	BulletVertex[1].Y = BulletPosY - BulletSizeY / 2;
	BulletVertex[1].Z = 0;
	BulletVertex[2].X = BulletPosX - BulletSizeX / 2;
	BulletVertex[2].Y = BulletPosY + BulletSizeY / 2;
	BulletVertex[2].Z = 0;
	BulletVertex[3].X = BulletPosX + BulletSizeX / 2;
	BulletVertex[3].Y = BulletPosY + BulletSizeY / 2;
	BulletVertex[3].Z = 0;
	BulletVertex[0].rhw = 1.0f;
	BulletVertex[1].rhw = 1.0f;
	BulletVertex[2].rhw = 1.0f;
	BulletVertex[3].rhw = 1.0f;
	BulletVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	BulletVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	BulletVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	BulletVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	BulletVertex[0].u = 0.0f;
	BulletVertex[0].v = 0.0f;
	BulletVertex[1].u = 1.0f;
	BulletVertex[1].v = 0.0f;
	BulletVertex[2].u = 0.0f;
	BulletVertex[2].v = 1.0f;
	BulletVertex[3].u = 1.0f;
	BulletVertex[3].v = 1.0f;
}
//Sceen82BgPic
void InitTexture57()
{
	Sceen82BgPicVertex[0].X = Sceen82BgPicPosX - Sceen82BgPicSizeX / 2;
	Sceen82BgPicVertex[0].Y = Sceen82BgPicPosY - Sceen82BgPicSizeY / 2;
	Sceen82BgPicVertex[0].Z = 0;
	Sceen82BgPicVertex[1].X = Sceen82BgPicPosX + Sceen82BgPicSizeX / 2;
	Sceen82BgPicVertex[1].Y = Sceen82BgPicPosY - Sceen82BgPicSizeY / 2;
	Sceen82BgPicVertex[1].Z = 0;
	Sceen82BgPicVertex[2].X = Sceen82BgPicPosX - Sceen82BgPicSizeX / 2;
	Sceen82BgPicVertex[2].Y = Sceen82BgPicPosY + Sceen82BgPicSizeY / 2;
	Sceen82BgPicVertex[2].Z = 0;
	Sceen82BgPicVertex[3].X = Sceen82BgPicPosX + Sceen82BgPicSizeX / 2;
	Sceen82BgPicVertex[3].Y = Sceen82BgPicPosY + Sceen82BgPicSizeY / 2;
	Sceen82BgPicVertex[3].Z = 0;
	Sceen82BgPicVertex[0].rhw = 1.0f;
	Sceen82BgPicVertex[1].rhw = 1.0f;
	Sceen82BgPicVertex[2].rhw = 1.0f;
	Sceen82BgPicVertex[3].rhw = 1.0f;
	Sceen82BgPicVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen82BgPicVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen82BgPicVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen82BgPicVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen82BgPicVertex[0].u = 0.0f;
	Sceen82BgPicVertex[0].v = 0.0f;
	Sceen82BgPicVertex[1].u = 1.0f;
	Sceen82BgPicVertex[1].v = 0.0f;
	Sceen82BgPicVertex[2].u = 0.0f;
	Sceen82BgPicVertex[2].v = 1.0f;
	Sceen82BgPicVertex[3].u = 1.0f;
	Sceen82BgPicVertex[3].v = 1.0f;
}
//StageClearTitle
void InitTexture58()
{
	StageClearTitleVertex[0].X = StageClearTitlePosX - StageClearTitleSizeX / 2;
	StageClearTitleVertex[0].Y = StageClearTitlePosY - StageClearTitleSizeY / 2;
	StageClearTitleVertex[0].Z = 0;
	StageClearTitleVertex[1].X = StageClearTitlePosX + StageClearTitleSizeX / 2;
	StageClearTitleVertex[1].Y = StageClearTitlePosY - StageClearTitleSizeY / 2;
	StageClearTitleVertex[1].Z = 0;
	StageClearTitleVertex[2].X = StageClearTitlePosX - StageClearTitleSizeX / 2;
	StageClearTitleVertex[2].Y = StageClearTitlePosY + StageClearTitleSizeY / 2;
	StageClearTitleVertex[2].Z = 0;
	StageClearTitleVertex[3].X = StageClearTitlePosX + StageClearTitleSizeX / 2;
	StageClearTitleVertex[3].Y = StageClearTitlePosY + StageClearTitleSizeY / 2;
	StageClearTitleVertex[3].Z = 0;
	StageClearTitleVertex[0].rhw = 1.0f;
	StageClearTitleVertex[1].rhw = 1.0f;
	StageClearTitleVertex[2].rhw = 1.0f;
	StageClearTitleVertex[3].rhw = 1.0f;
	StageClearTitleVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	StageClearTitleVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	StageClearTitleVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	StageClearTitleVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	StageClearTitleVertex[0].u = 0.0f;
	StageClearTitleVertex[0].v = 0.0f;
	StageClearTitleVertex[1].u = 1.0f;
	StageClearTitleVertex[1].v = 0.0f;
	StageClearTitleVertex[2].u = 0.0f;
	StageClearTitleVertex[2].v = 1.0f;
	StageClearTitleVertex[3].u = 1.0f;
	StageClearTitleVertex[3].v = 1.0f;
}
//HeadBox
void InitTexture59()
{
	HeadBoxVertex[0].X = HeadBoxPosX - HeadBoxSizeX / 2;
	HeadBoxVertex[0].Y = HeadBoxPosY - HeadBoxSizeY / 2;
	HeadBoxVertex[0].Z = 0;
	HeadBoxVertex[1].X = HeadBoxPosX + HeadBoxSizeX / 2;
	HeadBoxVertex[1].Y = HeadBoxPosY - HeadBoxSizeY / 2;
	HeadBoxVertex[1].Z = 0;
	HeadBoxVertex[2].X = HeadBoxPosX - HeadBoxSizeX / 2;
	HeadBoxVertex[2].Y = HeadBoxPosY + HeadBoxSizeY / 2;
	HeadBoxVertex[2].Z = 0;
	HeadBoxVertex[3].X = HeadBoxPosX + HeadBoxSizeX / 2;
	HeadBoxVertex[3].Y = HeadBoxPosY + HeadBoxSizeY / 2;
	HeadBoxVertex[3].Z = 0;
	HeadBoxVertex[0].rhw = 1.0f;
	HeadBoxVertex[1].rhw = 1.0f;
	HeadBoxVertex[2].rhw = 1.0f;
	HeadBoxVertex[3].rhw = 1.0f;
	HeadBoxVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	HeadBoxVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	HeadBoxVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	HeadBoxVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	HeadBoxVertex[0].u = 0.0f;
	HeadBoxVertex[0].v = 0.0f;
	HeadBoxVertex[1].u = 1.0f;
	HeadBoxVertex[1].v = 0.0f;
	HeadBoxVertex[2].u = 0.0f;
	HeadBoxVertex[2].v = 1.0f;
	HeadBoxVertex[3].u = 1.0f;
	HeadBoxVertex[3].v = 1.0f;
}
//Sceen8Tile
void InitTexture60()
{
	Sceen8TileVertex[0].X = Sceen8TilePosX - Sceen8TileSizeX / 2;
	Sceen8TileVertex[0].Y = Sceen8TilePosY - Sceen8TileSizeY / 2;
	Sceen8TileVertex[0].Z = 0;
	Sceen8TileVertex[1].X = Sceen8TilePosX + Sceen8TileSizeX / 2;
	Sceen8TileVertex[1].Y = Sceen8TilePosY - Sceen8TileSizeY / 2;
	Sceen8TileVertex[1].Z = 0;
	Sceen8TileVertex[2].X = Sceen8TilePosX - Sceen8TileSizeX / 2;
	Sceen8TileVertex[2].Y = Sceen8TilePosY + Sceen8TileSizeY / 2;
	Sceen8TileVertex[2].Z = 0;
	Sceen8TileVertex[3].X = Sceen8TilePosX + Sceen8TileSizeX / 2;
	Sceen8TileVertex[3].Y = Sceen8TilePosY + Sceen8TileSizeY / 2;
	Sceen8TileVertex[3].Z = 0;
	Sceen8TileVertex[0].rhw = 1.0f;
	Sceen8TileVertex[1].rhw = 1.0f;
	Sceen8TileVertex[2].rhw = 1.0f;
	Sceen8TileVertex[3].rhw = 1.0f;
	Sceen8TileVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen8TileVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen8TileVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen8TileVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Sceen8TileVertex[0].u = 0.0f;
	Sceen8TileVertex[0].v = 0.0f;
	Sceen8TileVertex[1].u = 1.0f;
	Sceen8TileVertex[1].v = 0.0f;
	Sceen8TileVertex[2].u = 0.0f;
	Sceen8TileVertex[2].v = 1.0f;
	Sceen8TileVertex[3].u = 1.0f;
	Sceen8TileVertex[3].v = 1.0f;
}
//Stage2Title
void InitTexture61()
{
	Stage2TitleVertex[0].X = Stage2TitlePosX - Stage2TitleSizeX / 2;
	Stage2TitleVertex[0].Y = Stage2TitlePosY - Stage2TitleSizeY / 2;
	Stage2TitleVertex[0].Z = 0;
	Stage2TitleVertex[1].X = Stage2TitlePosX + Stage2TitleSizeX / 2;
	Stage2TitleVertex[1].Y = Stage2TitlePosY - Stage2TitleSizeY / 2;
	Stage2TitleVertex[1].Z = 0;
	Stage2TitleVertex[2].X = Stage2TitlePosX - Stage2TitleSizeX / 2;
	Stage2TitleVertex[2].Y = Stage2TitlePosY + Stage2TitleSizeY / 2;
	Stage2TitleVertex[2].Z = 0;
	Stage2TitleVertex[3].X = Stage2TitlePosX + Stage2TitleSizeX / 2;
	Stage2TitleVertex[3].Y = Stage2TitlePosY + Stage2TitleSizeY / 2;
	Stage2TitleVertex[3].Z = 0;
	Stage2TitleVertex[0].rhw = 1.0f;
	Stage2TitleVertex[1].rhw = 1.0f;
	Stage2TitleVertex[2].rhw = 1.0f;
	Stage2TitleVertex[3].rhw = 1.0f;
	Stage2TitleVertex[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Stage2TitleVertex[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Stage2TitleVertex[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Stage2TitleVertex[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	Stage2TitleVertex[0].u = 0.0f;
	Stage2TitleVertex[0].v = 0.0f;
	Stage2TitleVertex[1].u = 1.0f;
	Stage2TitleVertex[1].v = 0.0f;
	Stage2TitleVertex[2].u = 0.0f;
	Stage2TitleVertex[2].v = 1.0f;
	Stage2TitleVertex[3].u = 1.0f;
	Stage2TitleVertex[3].v = 1.0f;
}