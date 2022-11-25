/* Genaric Z-80 Interupt handler */



int isr_08(void)
{


_asm
reti
_endasm
}


void isr_10(void)
{



_asm
reti
_endasm
}


void isr_18(void)
{
  
_asm
reti
_endasm  



reti
}

void isr_20(void)
{



_asm
reti
_endasm
}

void isr_28(void)
{



_asm
reti
_endasm
}



void isr_30(void)
{



_asm
reti
_endasm
}

void isr_38(void)
{



_asm
reti
_endasm
}


void isr_66(void) // NMI 
{



_asm
retn
_endasm
}
