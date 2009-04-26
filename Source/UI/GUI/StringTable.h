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

enum eStringTable
{
	GENERAL_ERROR = 0x0000,
	GENERAL_WARNING = 0x0001,
	GENERAL_INFORMATION = 0x0002,
	GENERAL_QUESTION = 0x0003,

	ERROR_REGISTRYWRITE = 0x0004,
	ERROR_FILEWRITE = 0x0005,
	ERROR_LOADSETTINGS = 0x0006,
	ERROR_AUDIOADDFOLDER = 0x0007,
	ERROR_LOADPROJECTXML = 0x0008,
	ERROR_LOADPROJECT = 0x0009,
	ERROR_PROJECTVERSION = 0x000a,
	ERROR_UNSUPCHARSET = 0x000b,
	ERROR_RELOADDRIVE = 0x000c,		// FIXME: Obsolete.
	ERROR_SECTOR = 0x000d,
	ERROR_COMMANDLINE = 0x000e,

	CONFIRM_AUTORUNENABLED = 0x000f,
	CONFIRM_WRITECANCEL = 0x0010,
	CONFIRM_REMOVEITEMS = 0x0011,
	CONFIRM_SAVEPROJECT = 0x0012,
	CONFIRM_CREATEMIXIMAGE = 0x0013,

	INIT_SCANBUS = 0x0014,
	INIT_LOADCAPABILITIES = 0x0015,
	INIT_LOADINFOEX = 0x0016,
	INIT_FOUNDDEVICES = 0x0017,
	INIT_DEVICECD = 0x0018,
	INIT_TRACK = 0x0019,

	FAILURE_SCANBUS = 0x001a,
	FAILURE_LOADCAP = 0x001b,
	FAILURE_LOADINFOEX = 0x001c,
	FAILURE_NORECORDERS = 0x001d,
	FAILURE_NODEVICES = 0x001e,
	FAILURE_CDRTOOLS = 0x001f,
	FAILURE_NOMEDIA = 0x0020,		// FIXME: Obsolete.
	FAILURE_UNSUPRW = 0x0021,
	FAILURE_ERASE = 0x0022,			// FIXME: Obsolete.
	FAILURE_BADSECTORSIZE = 0x0023,	// FIXME: Obsolete.
	FAILURE_WRITE = 0x0024,			// FIXME: Obsolete.
	FAILURE_UNSUPAUDIO = 0x0025,
	FAILURE_FILENOTFOUND = 0x0026,
	FAILURE_CREATECDTEXT = 0x0027,
	FAILURE_AUDIOCODING = 0x0028,	// FIXME: Obsolete.
	FAILURE_LOADDRIVE = 0x0029,		// FIXME: Obsolete.
	FAILURE_READSOURCEDISC = 0x002a,
	FAILURE_DEEPDIR = 0x002b,
	FAILURE_DVDSUPPORT = 0x002c,

	// Project properties.
	PROJECTPROP_TITLE = 0x002d,
	PROJECTPROP_ISOLEVEL1 = 0x002e,
	PROJECTPROP_ISOLEVEL2 = 0x002f,
	PROJECTPROP_ISOLEVEL3 = 0x0030,
	PROJECTPROP_MODE1 = 0x0031,
	PROJECTPROP_MODE2 = 0x0032,
	PROJECTPROP_TRACKPROP = 0x0033,

	// Container titles.
	TITLE_EXPLORERVIEW = 0x0034,
	TITLE_PROJECTVIEW = 0x0035,

	// Miscellaneous.
	MISC_MAXIMUM = 0x0036,
	MISC_NOTAVAILABLE = 0x0037,
	MISC_BURN = 0x0038,
	MISC_BURNCOMPILATION = 0x0039,
	MISC_NEWFOLDER = 0x003a,
	MISC_MINUTES = 0x003b,
	MISC_AUTODETECT = 0x003c,
	MISC_SPECIFYTRACKFOLDER = 0x003d,
	MISC_SPECIFYFOLDER = 0x003e,

	// Projects.
	PROJECT_DATA = 0x003f,
	PROJECT_AUDIO = 0x0040,
	PROJECT_MIXED = 0x0041,
	PROJECT_CONTENTS = 0x0042,

	// Properties.
	PROPERTIES_TITLE = 0x0043,
	PROPERTIES_DEVICELOC = 0x0044,

	// Advanced properties.
	ADVPROP_MODE2FORM1 = 0x0045,
	ADVPROP_MODE2FORM2 = 0x0046,
	ADVPROP_READDIGAUDIO = 0x0047,
	ADVPROP_READMULTSESSION = 0x0048,
	ADVPROP_READFIXPACKET = 0x0049,
	ADVPROP_READBARCODE = 0x004a,
	ADVPROP_READRWSUBCODE = 0x004b,
	ADVPROP_READRAWPWSC = 0x004c,
	ADVPROP_SIMULATION = 0x004d,
	ADVPROP_BUFRECORDING = 0x004e,
	ADVPROP_C2EP = 0x004f,
	ADVPROP_EJECTCDSS = 0x0050,
	ADVPROP_CHANGEDISCSIDE = 0x0051,
	ADVPROP_INDIVIDUALDP = 0x0052,
	ADVPROP_RETURNCDCN = 0x0053,
	ADVPROP_RETURNCDISRC = 0x0054,
	ADVPROP_DELIVCOMPOSITE = 0x0055,
	ADVPROP_PLAYAUDIOCD = 0x0056,
	ADVPROP_HASLESIC = 0x0057,
	ADVPROP_LMOPU = 0x0058,
	ADVPROP_ALLOWML = 0x0059,
	ADVPROP_RESTARTNSDARA = 0x005a,
	ADVPROP_RETURNRWSUBCODE = 0x005b,
	ADVPROP_INDIVIDUALVC = 0x005c,
	ADVPROP_INDEPENDENTMUTE = 0x005d,
	ADVPROP_DOPORT1 = 0x005e,
	ADVPROP_DOPORT2 = 0x005f,
	ADVPROP_DOSENDDIGDAT = 0x0060,
	ADVPROP_DOSETLRCK = 0x0061,
	ADVPROP_HASVALIDDATA = 0x0062,
	DEVICETYPE_CDREADER = 0x0063,
	DEVICETYPE_DVDREADER = 0x0064,
	DEVICETYPE_CDRECORDER = 0x0065,
	DEVICETYPE_DVDRECORDER = 0x0066,

	// Disc blanking.
	BLANKMODE_FULL = 0x0067,
	BLANKMODE_MINIMAL = 0x0068,
	BLANKMODE_UNCLOSE = 0x0069,
	BLANKMODE_SESSION = 0x006a,

	// Write methods.
	WRITEMODE_SAO = 0x006b,
	WRITEMODE_TAO = 0x006c,
	WRITEMODE_TAONOPREGAP = 0x006d,
	WRITEMODE_RAW96R = 0x006e,
	WRITEMODE_RAW16 = 0x006f,
	WRITEMODE_RAW96P = 0x0070,

	// Eject menu.
	EJECTMENU_NODRIVES = 0x0071,

	// Write modes.
	WRITEMODE_REAL = 0x0072,		// FIXME: Obsolete.
	WRITEMODE_SIMULATION = 0x0073,	// FIXME: Obsolete.

	// Column titles.
	COLUMN_TIME = 0x0074,
	COLUMN_EVENT = 0x0075,
	COLUMN_ID = 0x0076,
	COLUMN_VENDOR = 0x0077,
	COLUMN_IDENTIFICATION = 0x0078,
	COLUMN_REVISION = 0x0079,
	COLUMN_NAME = 0x007a,
	COLUMN_SIZE = 0x007b,
	COLUMN_TYPE = 0x007c,
	COLUMN_MODIFIED = 0x007d,
	COLUMN_PATH = 0x007e,
	COLUMN_TRACK = 0x007f,
	COLUMN_TITLE = 0x0080,
	COLUMN_LENGTH = 0x0081,
	COLUMN_LOCATION = 0x0082,
	COLUMN_ARTIST = 0x0083,
	COLUMN_ADDRESS = 0x0084,
	COLUMN_DESCRIPTION = 0x0085,
	COLUMN_EXTENSIONS = 0x0086,

	// Status dialog.
	PROGRESS_STATUS = 0x0087,
	PROGRESS_DEVICE = 0x0088,
	PROGRESS_TOTAL = 0x0089,
	PROGRESS_INIT = 0x008a,
	PROGRESS_DONE = 0x008b,			// FIXME: Obsolete.
	PROGRESS_CANCELED = 0x008c,
	PROGRESS_GRACETIME = 0x008d,	// FIXME: Obsolete.
	PROGRESS_BEGINERASE = 0x008e,
	PROGRESS_BEGINFIXATE = 0x008f,
	PROGRESS_BEGINWRITE = 0x0090,	// FIXME: Obsolete.
	PROGRESS_BEGINTRACK = 0x0091,	// FIXME: Obsolete.
	PROGRESS_BEGINDISCIMAGE = 0x0092,
	PROGRESS_IMAGEDEVICE = 0x0093,
	PROGRESS_BEGINREADTRACK = 0x0094,
	PROGRESS_BEGINSCANTRACK = 0x0095,
	PROGRESS_BEGINREADDISC = 0x0096,// FIXME: Obsolete.

	// Status strings.
	STATUS_ERASE = 0x0097,
	STATUS_WRITEDATA = 0x0098,		// FIXME: Obsolete.
	STATUS_WRITE = 0x0099,			// FIXME: Obsolete.
	STATUS_WRITEPREGAP = 0x009a,	// FIXME: Obsolete.
	STATUS_FILLBUFFER = 0x009b,		// FIXME: Obsolete.
	STATUS_FIXATE = 0x009c,			// FIXME: Obsolete.
	STATUS_WRITEIMAGE = 0x009d,
	STATUS_READTRACK = 0x009e,
	STATUS_SCANTRACK = 0x009f,
	STATUS_C2TOTAL = 0x00a0,
	STATUS_C2RATE = 0x00a1,
	STATUS_READDISC = 0x00a2,		// FIXME: Obsolete.

	// Status titles.
	STITLE_ERASE = 0x00a3,
	STITLE_BURNIMAGE = 0x00a4,
	STITLE_CREATEIMAGE = 0x00a5,
	STITLE_BURNCOMPILATION = 0x00a6,
	STITLE_FIXATE = 0x00a7,
	STITLE_READTRACK = 0x00a8,
	STITLE_SCANTRACK = 0x00a9,
	STITLE_COPYDISC = 0x00aa,

	// Sucess messages.
	SUCCESS_ERASE = 0x00ab,
	SUCCESS_WRITE = 0x00ac,		// FIXME: Obsolete.
	SUCCESS_FIXATE = 0x00ad,	// FIXME: Obsolete.
	SUCCESS_CREATEIMAGE = 0x00ae,
	SUCCESS_READTRACK = 0x00af,
	SUCCESS_SCANTRACK = 0x00b0,
	SUCCESS_READDISC = 0x00b1,	// FIXME: Obsolete.

	// Warning messages.
	WARNING_FIXATE = 0x00b2,	// FIXME: Obsolete.

	// Information messages.
	INFO_UNSUPERASEMODE = 0x00b3,// FIXME: Obsolete.
	INFO_ERASERETRY = 0x00b4,	// FIXME: Obsolete.

	// Property page titles.
	TITLE_GENERAL = 0x00b5,
	TITLE_ADVANCED = 0x00b6,
	TITLE_FIELDS = 0x00b7,
	TITLE_AUDIO = 0x00b8,
	TITLE_CONFIGURATION = 0x00b9,
	TITLE_LANGUAGE = 0x00ba,
	TITLE_SHELLEXT = 0x00bb,

	// Copy disc.
	COPYDISC_TITLE = 0x00bc,

	// Disc information.
	DISC_UNKNOWN = 0x00bd,
	DISC_SEQUENTIAL = 0x00be,
	DISC_RESTRICTEDOVERWRITE = 0x00bf,
	DISC_REVISION = 0x00c0,
	DISC_NOREGION = 0x00c1,
	DISC_BLANK = 0x00c2,
	DISC_INCOMPLETE = 0x00c3,
	DISC_FIXATED = 0x00c4,
	DISC_RANDOMACCESS = 0x00c5,
	DISC_EMPTY = 0x00c6,
	DISC_RESERVED = 0x00c7,
	DISC_COMPLETE = 0x00c8,
	DISC_NOT = 0x00c9,
	DISC_STATUS = 0x00ca,

	// Miscellaneous.
	WARNING_DISCSIZE = 0x00cb,		// FIXME: Obsolete.
	FAILURE_OPENSESSION = 0x00cc,	// FIXME: Obsolete.

	// Added version 0.40.
	ERROR_LOADCODECS = 0x00cd,
	PROGRESS_DECODETRACKS = 0x00ce,
	ERROR_NODECODER = 0x00cf,
	ERROR_WAVECODEC = 0x00d0,
	ERROR_CODECINIT = 0x00d1,
	ERROR_ENCODEDATA = 0x00d2,
	SUCCESS_DECODETRACK = 0x00d3,
	ERROR_TARGETFOLDER = 0x00d4,
	SUCCESS_ENCODETRACK = 0x00d5,
	PROGRESS_ENCODETRACK = 0x00d6,

	// Added version 0.41.
	ERROR_FIFOSIZE = 0x00d7,
	PROJECTPROP_ISOLEVEL4 = 0x00d8,
	WARNING_CLONEWRITEMETHOD = 0x00d9,
	TITLE_READ = 0x00da,
	MISC_AUTO = 0x00db,
	COPYIMAGE_TITLE = 0x00dc,
	INFO_COPYDISC = 0x00dd,
	INFO_RAWIMAGE = 0x00de,
	PROGRESS_BEGINESTIMAGESIZE = 0x00df,
	SUCCESS_ESTIMAGESIZE = 0x00e0,
	ERROR_ESTIMAGESIZE = 0x00e1,
	PROGRESS_ESTIMAGESIZE = 0x00e2,
	SPACEMETER_USED = 0x00e3,
	SPACEMETER_FREE = 0x00e4,
	ADVPROP_SAO = 0x00e5,
	ADVPROP_TAO = 0x00e6,
	ADVPROP_RAW96R = 0x00e7,
	ADVPROP_RAW16 = 0x00e8,
	ADVPROP_RAW96P = 0x00e9,
	INFO_WRITESPEED = 0x00ea,
	TITLE_BOOT = 0x00eb,
	ERROR_NUMBOOTIMAGES = 0x00ec,
	BOOTEMU_NONE = 0x00ed,
	BOOTEMU_FLOPPY = 0x00ee,
	BOOTEMU_HARDDISK = 0x00ef,
	COLUMN_EMULATION = 0x00f0,
	TITLE_EDITBOOTIMAGE = 0x00f1,

	// Added version 0.42.
	PROJECT_DVDVIDEO = 0x00f2,
	WARNING_OLDPROJECT = 0x00f3,
	MISC_SPECIFYDVDFOLDER = 0x00f4,
	ERROR_INVALIDDVDFOLDER = 0x00f5,
	FAILURE_WRITELEADIN = 0x00f6,	// FIXME: Obsolete.
	FAILURE_INITDRIVE = 0x00f7,		// FIXME: Obsolete.
	FAILURE_DVDRWDUMMY = 0x00f8,	// FIXME: Obsolete.
	PROGRESS_RELOADMEDIA = 0x00f9,
	STATUS_VERIFY = 0x00fa,
	SUCCESS_VERIFY = 0x00fb,
	FAILURE_VERIFY = 0x00fc,
	PROGRESS_BEGINVERIFY = 0x00fd,
	FAILURE_VERIFYNOFILE = 0x00fe,
	FAILURE_VERIFYREADERROR = 0x00ff,
	/*STRINGTABLE_PLACEHOLDER1 = 0x0100,
	STRINGTABLE_PLACEHOLDER2 = 0x0101,
	STRINGTABLE_PLACEHOLDER3 = 0x0102,*/

	// Added version 0.43.
	DRIVELETTER_TITLE = 0x0103,
	FORMATMODE_QUICK = 0x0104,
	FORMATMODE_FULL = 0x0105,
	MEDIA_INSERT = 0x0106,
	MEDIA_UNSUPPORTED = 0x0107,
	STATUS_FORMAT = 0x0108,
	STATUS_FORMATBKGND = 0x0109,
	STATUS_CLOSETRACK = 0x010a,
	PROGRESS_BEGINFORMAT = 0x010b,
	FAILURE_FORMAT = 0x010c,
	FAILURE_STOPBKGNDFORMAT = 0x010d,
	SUCCESS_FORMAT = 0x010e,

	// Added version 0.44.
	STATUS_REREADSECTOR = 0x010f,
	STATUS_READTRACK2 = 0x0110,
	ERROR_MOVESAMESRCDST = 0x0111,
	MISC_MODIFIED = 0x0112,
	ERROR_EXISTINGFILENAME = 0x0113,
	TBCUSTOMIZE_TEXTOPTIONS = 0x0114,
	TBCUSTOMIZE_ICONOPTIONS = 0x0115,
	TBCUSTOMIZE_SHOWTEXT = 0x0116,
	TBCUSTOMIZE_SHOWTEXTRIGHT = 0x0117,
	TBCUSTOMIZE_NOTEXT = 0x0118,
	TBCUSTOMIZE_ICONSMALL = 0x0119,
	TBCUSTOMIZE_ICONLARGE = 0x011a,
	TOOLBAR_OPEN = 0x011b,
	TOOLBAR_SAVE = 0x011c,
	TOOLBAR_PROJECTPROPERTIES = 0x011d,
	TOOLBAR_EXIT = 0x011e,
	TOOLBAR_BURNCOMPILATION = 0x011f,
	TOOLBAR_BURNIMAGE = 0x0120,
	TOOLBAR_COPY = 0x0121,
	TOOLBAR_TRACKS = 0x0122,
	TOOLBAR_ERASE = 0x0123,
	TOOLBAR_FIXATE = 0x0124,
	TOOLBAR_LOG = 0x0125,
	TOOLBAR_CONFIGURATION = 0x0126,
	TOOLBAR_DEVICES = 0x0127,
	TOOLBAR_HELP = 0x0128,
	TOOLBAR_ABOUT = 0x0129,
	ERROR_OPENDEVICE = 0x012a,
	MEDIA_INSERTBLANK = 0x012b,
	INFO_INSERTBLANK = 0x012c,
	INFO_INSERTSOURCE = 0x012d,
	WARNING_NOFIXATION = 0x012e,

	// Added version 0.45.
	INFO_RELOAD = 0x012f,
	PROGRESS_FAILED = 0x0130,
	FAILURE_CREATEIMAGE = 0x0131,
	TITLE_FILESYSTEM = 0x0132,
	ERROR_IMPORTSESSION = 0x0133,
	MISC_SESSION = 0x0134,
	MISC_TRACK = 0x0135,
	MISC_MODE = 0x0136,
	MISC_ERASENONEMPTY = 0x0137,
	WARNING_IMPORTFS = 0x0138,
	STITLE_VERIFYDISC = 0x0139,

	// Added version 0.46.
	ERROR_NUMCOPIES = 0x013a,
	INFO_NEXTCOPY = 0x013b,
	INFO_CREATECOPY = 0x013c,

	// Added version 0.47.
	ERROR_PROJECT_IMPORT = 0x013d,
	ERROR_PROJECT_IMPORT_FILE = 0x013e,

	// Added version 0.48.
	COLUMN_DRIVE = 0x013f
};

extern TCHAR *g_szStringTable[];