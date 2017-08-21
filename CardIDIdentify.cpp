
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
			if ((*pBegin >= 48 && *pBegin <= 57) || (*pBegin >= 65 && *pBegin <= 90) || (*pBegin >= 97 && *pBegin <= 122))
				bSatisfy = true;
		}
		else
		{
			if (!(*pBegin >= 48 && *pBegin <= 57))
				break;
		}
		pBegin++;
	}
	return bSatisfy;
}
