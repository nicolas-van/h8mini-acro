

#include "gd32f1x0.h"


#define offset 0x08007C00

int fmc_erasepage( void)
{
  FMC_Unlock();
  FMC_ClearBitState(FMC_FLAG_EOP | FMC_FLAG_WERR | FMC_FLAG_PERR );
	int test = FMC_ErasePage( (uint32_t)0x08007C00 );
  if ( test == FMC_WRPERR) printf( "FMC erase error");
	FMC_WaitReady(4000);
	FMC_Lock();
	return ( test == FMC_WRPERR);
}

int fmc_write( unsigned int address , int data)
{
 FMC_Unlock();
 FMC_ClearBitState(FMC_FLAG_EOP | FMC_FLAG_WERR | FMC_FLAG_PERR );
 int	test = FMC_ProgramWord( address + offset , data );
 FMC_WaitReady(4000);
 if ( test == FMC_BSY||test == FMC_WRPERR||test == FMC_PGERR||test == FMC_TIMEOUT_ERR	) printf( "FMC program error");	
 FMC_Lock();
 return ( test == FMC_WRPERR);
}

int fmc_read( unsigned int* address)
{
return (*address );
}









