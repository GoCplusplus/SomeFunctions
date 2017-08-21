
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
