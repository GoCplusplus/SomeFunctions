#include <iostream>

bool IsValidCardID(const char* pInput)
{
	bool bSatisfy = false;
	if (!pInput)
		return bSatisfy;
	if (strlen(pInput) < 18)
		return false;

	// �ж����֤�Ƿ���� 1:18λ 2:ǰ17λһ��λ���� ���һλΪ��ĸ
	char* pBegin = (char*)pInput;
	while (*pBegin)
	{
		if (pBegin - pInput == 17) // ���һλ
		{
			if ((*pBegin >= 'A' && *pBegin <= 'Z') || (*pBegin >= '0' && *pBegin <= '9') || (*pBegin >= 'a' && *pBegin <= 'z'))
				bSatisfy = true;
		}
		else
		{
			if (!(*pBegin >= '0' && *pBegin <= '9'))
				break;
		}
		pBegin++;
	}
	return bSatisfy;
}

int main()
{
	bool bRet = IsValidCardID("a1250119720303517X");
	return 0;
}