#pragma once

#include <stdio.h>

#include "../__Common/Type.h"
#include "../__Common/Define.h"
#include "FmtTypes.h"
#include "IChannel.h"

namespace fmt_internal
{
	class CFileWritter : public core::IChannel
	{
	private:
		std::tstring	m_strFilename;
		FILE*			m_pFile;

	public:
						CFileWritter(std::tstring strFilename);
						~CFileWritter(void);

		bool			CheckValidity(std::tstring& refStrErrMsg);

	private:
		size_t			OnAccess(void* pData, size_t tDataSize);
	};
}

