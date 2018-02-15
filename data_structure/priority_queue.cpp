#include <iostream>
#include "priority_queue.h"
using namespace std;

int CHeapManager::Heap[ARRAY_MAX];

CHeapManager::CHeapManager()
{
	cout << "CHeapManager 생성자" << endl;
	m_nDataNumber = 0;
}

CHeapManager::~CHeapManager()
{
	cout << "CHeapManager 소멸자" << endl;
}

int CHeapManager::m_Start()
{
	int nChoice = 0;
	
	while (true) {
		std::cout << "1. 삽입, 2. 삭제, 3. 출력, 4. 종료" << endl;
		cin >> nChoice;
		
		switch (nChoice)
		{
		case eInsert:
		{
			m_Insert();
			break;
		}
		case eDel:
		{
			m_Delete();
			break;
		}
		case ePrint:
		{
			m_Print();
			break;
		}
		case eExit:
		{
			return eExit;
		}
		default:
			break;
		}
	}
}

int CHeapManager::m_ReturnParent(int nGetData)
{
	return (nGetData / 2);
}

int CHeapManager::m_ReturnLeft(int nGetData)
{
	return (nGetData * 2);
}

int CHeapManager::m_ReturnRight(int nGetData)
{
	return (nGetData * 2) + 1;
}

int CHeapManager::m_ReturnPreference(int nGetIndex)
{//우선순위 노드 반환
	//완전 이진 트리 특성상 왼쪽이 오른쪽보다 작은 값이 들어간다.(왼쪽부터 채워진다.)
	if (m_ReturnLeft(nGetIndex) > m_nDataNumber) {
		//왼쪽 노드에 자식이 존재하지 않으면
		//자식이 없다.
		return NULL;
	}
	else if (m_ReturnLeft(nGetIndex) == m_nDataNumber) {
		return m_ReturnLeft(nGetIndex);
	}
	else {
		if (Heap[m_ReturnLeft(nGetIndex)] > Heap[m_ReturnRight(nGetIndex)]) {
			return m_ReturnRight(nGetIndex);
		}
		else
			return m_ReturnLeft(nGetIndex);
	}
}


void CHeapManager::m_Insert()
{
	if (ARRAY_MAX <= m_nDataNumber) {
		cout << "가득 찼습니다" << endl;
	}
	else
	{
		int nIndex = m_nDataNumber + 1;
		int nData;
		cout << "정수를 입력해 주세요." << endl;
		cin >> nData;
		//정수의 숫자가 적을수록 우선순위가 높다는 가정

		while (nIndex != 1) {
			//새 노드 위치가 루프 노드까지 갈때까지 while 반복
			if (Heap[m_ReturnParent(nIndex)] > nData) {
				Heap[nIndex] = Heap[m_ReturnParent(nIndex)];
				nIndex = m_ReturnParent(nIndex);
			}
			else
				break;
		}
		Heap[nIndex] = nData;
		m_nDataNumber++;
	}
}

void CHeapManager::m_Delete()
{
	if (ARRAY_MIN >= m_nDataNumber) {
		cout << "비었습니다" << endl;
	}
	else
	{
		int nLastParentIndex = ARRAY_MIN + 1;
		int nLastNodeData = Heap[m_nDataNumber];
		int	nChildIndex;

		while(nChildIndex = m_ReturnPreference(nLastParentIndex)) {
			if (nLastNodeData <= Heap[nChildIndex]) {
				break;
			}
			else
			{
				Heap[nLastParentIndex] = Heap[nChildIndex];
				nLastParentIndex = nChildIndex;
			}
		}

		Heap[nLastParentIndex] = nLastNodeData;
		m_nDataNumber--;	
	}
}

void CHeapManager::m_Print()
{
	cout << m_nDataNumber << "개의 데이터를 저장 중" << endl;

	for (int i = 1; i <= m_nDataNumber; i++) {
		cout << i << "번째 : " << Heap[i] << endl;
	}

}