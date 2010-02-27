/*
 * InfraRecorder - CD/DVD burning software
 * Copyright (C) 2006-2009 Christian Kindahl
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "stdafx.h"
#include <comdef.h>
#include <ckcore/string.hh>
#include <ckcore/exception.hh>
#include "StringUtil.h"
#include "Exception.h"

/**
 * Returns the exception message of the given exception object. The function
 * tests if the exception is an ir_error and in that case returns its message.
 * @param [in] e The exception object.
 * @return The error message of the exception.
 */
ckcore::tstring GetExceptMsg(const std::exception &e)
{
	const ckcore::Exception2 *const pE2 = dynamic_cast<const ckcore::Exception2 *>(&e);

    if (pE2 != NULL)
		return pE2->message();

	return ckcore::string::ansi_to_auto<1024>(e.what());
}

/**
 * Rethrows the exception with a prefix message.
 * @param [in] e The exception to rethrow.
 * @param [in] szFormatStr The message format string.
 */
void RethrowWithPrefix(const std::exception &e,const ckcore::tchar *const szFormatStr,...)
{
    ckcore::tstring Msg;

	va_list args;
	va_start(args,szFormatStr);

	SlowFormatStrV(Msg,szFormatStr,args);

	va_end(args);

    const ckcore::tstring ErrMsg = GetExceptMsg(e);
    Msg.append(ErrMsg);

    throw ir_error(Msg.c_str());
}

ir_error CreateIrErrorFromHresult(const HRESULT hRes,const ckcore::tchar *const szPrefixFormatStr,...)
{
    ckcore::tstring Msg;

	if (szPrefixFormatStr != NULL)
	{
		va_list args;
		va_start(args,szPrefixFormatStr);

		SlowFormatStrV(Msg,szPrefixFormatStr,args);

		va_end(args);
	}

    const ckcore::tstring ErrMsg = _com_error(hRes).ErrorMessage();
    Msg.append(ErrMsg);

    return ir_error(Msg.c_str());
}

ir_error CreateIrInternalError(const tchar *file,int line)
{
	return ir_error(SlowFormatStr(_T("Internal error in %s at line %d."),file,line));
}