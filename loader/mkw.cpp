#include "kamekLoader.h"

void loadIntoMKW();

struct loaderFunctionsEx {
	loaderFunctions base;
};

loaderFunctionsEx functions_p = {
	{(OSReport_t) 0x801A25D0,
	(OSFatal_t) 0x801A4EC4,
	(DVDConvertPathToEntrynum_t) 0x8015DF4C,
	(DVDFastOpen_t) 0x8015E254,
	(DVDReadPrio_t) 0x8015E834,
	(DVDClose_t) 0x8015E568,
	(sprintf_t) 0x80011A2C,
	(EGG_Heap_Alloc_t) 0x80229814,
	(EGG_Heap_Free_t) 0x80229B84,
    (int *) 0x802A4080}
};
loaderFunctionsEx functions_e = {
	{(OSReport_t) 0x801A2530,
	(OSFatal_t) 0x801A4E24,
	(DVDConvertPathToEntrynum_t) 0x8015DEAC,
	(DVDFastOpen_t) 0x8015E1B4,
	(DVDReadPrio_t) 0x8015E794,
	(DVDClose_t) 0x8015E4C8,
	(sprintf_t) 0x80010ECC,
	(EGG_Heap_Alloc_t) 0x80229490,
	(EGG_Heap_Free_t) 0x80229800,
    (int *) 0x8029fd00}
};
loaderFunctionsEx functions_j = {
	{(OSReport_t) 0x801A24F0,
	(OSFatal_t) 0x801A4DE4,
	(DVDConvertPathToEntrynum_t) 0x8015DE6C,
	(DVDFastOpen_t) 0x8015E174,
	(DVDReadPrio_t) 0x8015E754,
	(DVDClose_t) 0x8015E488,
	(sprintf_t) 0x80011950,
	(EGG_Heap_Alloc_t) 0x80229734,
	(EGG_Heap_Free_t) 0x80229AA4,
    (int *) 0x802a3a00}
};
loaderFunctionsEx functions_k = {
	{(OSReport_t) 0x801A292C,
	(OSFatal_t) 0x801A5220,
	(DVDConvertPathToEntrynum_t) 0x8015DFC4,
	(DVDFastOpen_t) 0x8015E2CC,
	(DVDReadPrio_t) 0x8015E8AC,
	(DVDClose_t) 0x8015E5E0,
	(sprintf_t) 0x80011A94,
	(EGG_Heap_Alloc_t) 0x80229B88,
	(EGG_Heap_Free_t) 0x80229EF8,
    (int *) 0x80292080}
};

void unknownVersion()
{
	// can't do much here!
	// we can't output a message on screen without a valid OSFatal addr
	for (;;);
}

void loadIntoMKW()
{
    int region = 0;
    
	switch (*((u16*)0x8000620A))
	{
		case 0x54A9: region = 'P'; break;
		case 0x5409: region = 'E'; break;
		case 0x53CD: region = 'J'; break;
		case 0x5511: region = 'K'; break;
		default: unknownVersion();
	}
    
	// choose functions
	loaderFunctions *funcs = NULL;
    int *heap = NULL;
	switch (region)
	{
		case 'P': funcs = &functions_p.base; break;
		case 'E': funcs = &functions_e.base; break;
		case 'J': funcs = &functions_j.base; break;
		case 'K': funcs = &functions_k.base; break;
	}

	char path[64];
	funcs->sprintf(path, "/bmc/%c.bin", region);
	loadKamekBinaryFromDisc(funcs, path);
    
    return;
};

