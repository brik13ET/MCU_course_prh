#include "keypad.h"
#include "displ.h"
#include <util/delay.h>

void KEYPAD_Init()
{
	KP_DDR |= KPA_MASK | KPB_MASK | KPC_MASK | KPD_MASK;
	KP_DDR &= ~(KP1_MASK | KP2_MASK | KP3_MASK);
}

key_t getkey()
{
	uint8_t maskc[] = {
            KP1_MASK,
            KP2_MASK,
            KP3_MASK
	};
	uint8_t maskr[] = {
            KPA_MASK,
            KPB_MASK,
            KPC_MASK,
            KPD_MASK
    };
	uint8_t i, j;
	for (i = 0; i < 4; i++)
	{
		KP_PORT &= ~(
            KPA_MASK |
            KPB_MASK |
            KPC_MASK |
            KPD_MASK
		);
		KP_PORT |= maskr[i];
		_delay_ms(17);
		for(j = 0; j < 3; j ++)
		{
			if (KP_PIN & maskc[j])
				return (key_t)(i * 3 + j);
			
		}
	}
    return k_none;
}

uint8_t getnum()
{
	uint8_t res = 0, end = 0;
	key_t inp = k_none;
	while (!end)
	{
		do{
			bcd_print(res);
			if (inp == k_none)
				inp = getkey();
			switch(inp)
			{
				case k_0:
					res *= 10;
					inp = k_none;
					break;
				case k_1:
				case k_2:
				case k_3:
				case k_4:
				case k_5:
				case k_6:
				case k_7:
				case k_8:
				case k_9:
					res *= 10;
					res += inp + 1;
					inp = k_none;
					break;
				case k_hash:
					res /= 10;
					inp = k_none;
					break;
				case k_star:
					end = !end;
					inp = k_none;
					break;
				case k_none:
					while( (inp = getkey()) && (inp == k_none)) bcd_print(res);
					break;
			}
			_delay_ms(100);
		}while (inp == k_star || inp == k_none);
	}
	return res;
}
