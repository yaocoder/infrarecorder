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

#pragma once
#include <ckcore/types.hh>
#include <ckcore/exception.hh>

// Temporary typedef until all code moves to ckcore::Exception2
typedef ckcore::Exception2 ir_error;

ckcore::tstring GetExceptMsg(const std::exception &e);
void RethrowWithPrefix(const std::exception &e,const ckcore::tchar *szFormatStr,...);
ir_error CreateIrErrorFromHresult(HRESULT hRes,const ckcore::tchar *szPrefixFormatStr,...);
ir_error CreateIrInternalError(const ckcore::tchar *file,int line);