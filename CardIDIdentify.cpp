#include <iostream>

bool IsValidCardID(const char* pInput)
{
	bool bSatisfy = false;
	if (!pInput)
		return bSatisfy;
	if (strlen(pInput) < 18)
		return false;

	// 判断身份证是否符合 1:18位 2:前17位一定位数字 最后一位为字母
	char* pBegin = (char*)pInput;
	while (*pBegin)
	{
		if (pBegin - pInput == 17) // 最后一位
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