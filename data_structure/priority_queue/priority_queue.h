#pragma once

enum eMenu 
{
	eInsert = 1,
	eDel,
	ePrint,
	eExit
};

static const int ARRAY_MIN = 0;
static const int ARRAY_MAX = 10;

class CHeapManager
{
public:
	CHeapManager();
	~CHeapManager();

	int m_ReturnParent(int nGetData);	//부모반환
	int m_ReturnLeft(int nGetData);		//왼쪽반환
	int m_ReturnRight(int nGetData);	//오른쪽반환

	int m_ReturnPreference(int nGetIndex);	//좌, 우 중 우선 순위가 높은 쪽 반환

	int m_Start();

	void m_Insert();
	void m_Delete();
	void m_Print();

private:
	static int Heap[ARRAY_MAX];

	int m_nDataNumber;	//저장된 데이터 갯수
};