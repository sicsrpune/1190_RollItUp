/*
 * CGameManager.h
 *
 *  Created on: 16-Aug-2014
 *      Author: chaitany
 */

#ifndef CGAMEMANAGER_H_
#define CGAMEMANAGER_H_

class CGameManager {
public:

static CGameManager* Instance();
void LateInit();

float GetScaleX();
float GetScaleY();
float GetScaleFactor();

void SetUpScaleFactors();

void GetFileName(char *array, const int len, const char *name, const char *fileExt);

void RunScene(int scene);

private:

CGameManager(){}
//CGameManager(const CGameManager &);
CGameManager& operator=(const CGameManager &){ }



static CGameManager* _pInstance;

float _scaleX;
float _scaleY;
float _scaleFactor;
char *_extension;

};

#define GETSCALEX (CGameManager::Instance()->GetScaleX())
#define GETSCALEY (CGameManager::Instance()->GetScaleY())
#define GETSCALEFAC (CGameManager::Instance()->GetScaleFactor())

#define SCALEX(p) ((p) * GETSCALEX)
#define SCALEY(p) ((p) * GETSCALEY)

#define SCALEPOS(x,y) (Vec2(GETSCALEX*(x)*GETSCALEFAC,GETSCALEY*(y)*GETSCALEFAC))
#define SCALEFONT(p) (p * SCALEY * GETSCALEFAC)
#define GETFILENAME(a,l,n,e) \
	(CGameManager::Instance()->GetFileName(a,l,n,e))


#define SCALENODE_XY(n) \
n->setScaleX(GETSCALEX) \
		n->setScaleY(GETSCALEY)

#define SCALENODE_X(n) n->setScaleX(GETSCALEX)

#define SCALENODE_Y(n) n->setScale(GETSCALEY)


#endif /* CGAMEMANAGER_H_ */
