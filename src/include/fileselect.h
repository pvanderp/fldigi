// ----------------------------------------------------------------------------
// Copyright (C) 2014
//              David Freese, W1HKJ
//
// This file is part of fldigi
//
// fldigi is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// fldigi is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// ----------------------------------------------------------------------------

#ifndef FILESELECT_H
#define FILESELECT_H

#include <config.h>

#if (FLDIGI_FLTK_API_MAJOR == 1 && FLDIGI_FLTK_API_MINOR < 3) || (FLARQ_FLTK_API_MAJOR == 1 && FLARQ_FLTK_API_MINOR < 3)
class Fl_Native_File_Chooser;

class FSEL
{
public:
	static void create(void);
	static void destroy(void);
	static const char* select(const char* title, const char* filter, const char* def = 0, int* fsel = 0);
	static const char* saveas(const char* title, const char* filter, const char* def = 0, int* fsel = 0);
	static const char* dir_select(const char* title, const char* filter, const char* def = 0);
	~FSEL();
private:
	FSEL();
	FSEL(const FSEL&);
	FSEL& operator=(const FSEL&);

	const char* get_file(void);
#if FSEL_THREAD
	static void* thread_func(void* arg);
#endif
private:
	static FSEL* inst;
#ifdef __APPLE__
	MAC_chooser* chooser;
#else
	Fl_Native_File_Chooser* chooser;
#endif
	int result;
};

#else // API >=1.3.0

namespace FSEL {

	void create(void);
	void destroy(void);
	const char* select(const char* title, const char* filter, const char* def = 0, int *fsel = NULL);
	const char* saveas(const char* title, const char* filter, const char* def = 0, int *fsel = NULL);
	const char* dir_select(const char* title, const char* filter, const char* def = 0);

}

#endif // API < 1.3.0

#endif // FILESELECT_H
