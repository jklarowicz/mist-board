 /*
Copyright 2008, 2009 Jakub Bednarski

This file is part of Minimig

Minimig is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

Minimig is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "AT91SAM7S256.h"
#include "stdio.h"
#include "string.h"
#include "errors.h"
#include "hardware.h"
#include "fat.h"
#include "firmware.h"

#ifdef __GNUC__
#define __noinline
#endif

/* polynomial 0xEDB88320 */
const unsigned long crc32_table[256] =
{ 
    0x00000000, 0x77073096, 0xEE0E612C, 0x990951BA, 0x076DC419, 0x706AF48F, 0xE963A535, 0x9E6495A3,
    0x0EDB8832, 0x79DCB8A4, 0xE0D5E91E, 0x97D2D988, 0x09B64C2B, 0x7EB17CBD, 0xE7B82D07, 0x90BF1D91,
    0x1DB71064, 0x6AB020F2, 0xF3B97148, 0x84BE41DE, 0x1ADAD47D, 0x6DDDE4EB, 0xF4D4B551, 0x83D385C7,
    0x136C9856, 0x646BA8C0, 0xFD62F97A, 0x8A65C9EC, 0x14015C4F, 0x63066CD9, 0xFA0F3D63, 0x8D080DF5,
    0x3B6E20C8, 0x4C69105E, 0xD56041E4, 0xA2677172, 0x3C03E4D1, 0x4B04D447, 0xD20D85FD, 0xA50AB56B,
    0x35B5A8FA, 0x42B2986C, 0xDBBBC9D6, 0xACBCF940, 0x32D86CE3, 0x45DF5C75, 0xDCD60DCF, 0xABD13D59,
    0x26D930AC, 0x51DE003A, 0xC8D75180, 0xBFD06116, 0x21B4F4B5, 0x56B3C423, 0xCFBA9599, 0xB8BDA50F,
    0x2802B89E, 0x5F058808, 0xC60CD9B2, 0xB10BE924, 0x2F6F7C87, 0x58684C11, 0xC1611DAB, 0xB6662D3D,
    0x76DC4190, 0x01DB7106, 0x98D220BC, 0xEFD5102A, 0x71B18589, 0x06B6B51F, 0x9FBFE4A5, 0xE8B8D433,
    0x7807C9A2, 0x0F00F934, 0x9609A88E, 0xE10E9818, 0x7F6A0DBB, 0x086D3D2D, 0x91646C97, 0xE6635C01,
    0x6B6B51F4, 0x1C6C6162, 0x856530D8, 0xF262004E, 0x6C0695ED, 0x1B01A57B, 0x8208F4C1, 0xF50FC457,
    0x65B0D9C6, 0x12B7E950, 0x8BBEB8EA, 0xFCB9887C, 0x62DD1DDF, 0x15DA2D49, 0x8CD37CF3, 0xFBD44C65,
    0x4DB26158, 0x3AB551CE, 0xA3BC0074, 0xD4BB30E2, 0x4ADFA541, 0x3DD895D7, 0xA4D1C46D, 0xD3D6F4FB,
    0x4369E96A, 0x346ED9FC, 0xAD678846, 0xDA60B8D0, 0x44042D73, 0x33031DE5, 0xAA0A4C5F, 0xDD0D7CC9,
    0x5005713C, 0x270241AA, 0xBE0B1010, 0xC90C2086, 0x5768B525, 0x206F85B3, 0xB966D409, 0xCE61E49F,
    0x5EDEF90E, 0x29D9C998, 0xB0D09822, 0xC7D7A8B4, 0x59B33D17, 0x2EB40D81, 0xB7BD5C3B, 0xC0BA6CAD,
    0xEDB88320, 0x9ABFB3B6, 0x03B6E20C, 0x74B1D29A, 0xEAD54739, 0x9DD277AF, 0x04DB2615, 0x73DC1683,
    0xE3630B12, 0x94643B84, 0x0D6D6A3E, 0x7A6A5AA8, 0xE40ECF0B, 0x9309FF9D, 0x0A00AE27, 0x7D079EB1,
    0xF00F9344, 0x8708A3D2, 0x1E01F268, 0x6906C2FE, 0xF762575D, 0x806567CB, 0x196C3671, 0x6E6B06E7,
    0xFED41B76, 0x89D32BE0, 0x10DA7A5A, 0x67DD4ACC, 0xF9B9DF6F, 0x8EBEEFF9, 0x17B7BE43, 0x60B08ED5,
    0xD6D6A3E8, 0xA1D1937E, 0x38D8C2C4, 0x4FDFF252, 0xD1BB67F1, 0xA6BC5767, 0x3FB506DD, 0x48B2364B,
    0xD80D2BDA, 0xAF0A1B4C, 0x36034AF6, 0x41047A60, 0xDF60EFC3, 0xA867DF55, 0x316E8EEF, 0x4669BE79,
    0xCB61B38C, 0xBC66831A, 0x256FD2A0, 0x5268E236, 0xCC0C7795, 0xBB0B4703, 0x220216B9, 0x5505262F,
    0xC5BA3BBE, 0xB2BD0B28, 0x2BB45A92, 0x5CB36A04, 0xC2D7FFA7, 0xB5D0CF31, 0x2CD99E8B, 0x5BDEAE1D,
    0x9B64C2B0, 0xEC63F226, 0x756AA39C, 0x026D930A, 0x9C0906A9, 0xEB0E363F, 0x72076785, 0x05005713,
    0x95BF4A82, 0xE2B87A14, 0x7BB12BAE, 0x0CB61B38, 0x92D28E9B, 0xE5D5BE0D, 0x7CDCEFB7, 0x0BDBDF21,
    0x86D3D2D4, 0xF1D4E242, 0x68DDB3F8, 0x1FDA836E, 0x81BE16CD, 0xF6B9265B, 0x6FB077E1, 0x18B74777,
    0x88085AE6, 0xFF0F6A70, 0x66063BCA, 0x11010B5C, 0x8F659EFF, 0xF862AE69, 0x616BFFD3, 0x166CCF45,
    0xA00AE278, 0xD70DD2EE, 0x4E048354, 0x3903B3C2, 0xA7672661, 0xD06016F7, 0x4969474D, 0x3E6E77DB,
    0xAED16A4A, 0xD9D65ADC, 0x40DF0B66, 0x37D83BF0, 0xA9BCAE53, 0xDEBB9EC5, 0x47B2CF7F, 0x30B5FFE9,
    0xBDBDF21C, 0xCABAC28A, 0x53B39330, 0x24B4A3A6, 0xBAD03605, 0xCDD70693, 0x54DE5729, 0x23D967BF,
    0xB3667A2E, 0xC4614AB8, 0x5D681B02, 0x2A6F2B94, 0xB40BBE37, 0xC30C8EA1, 0x5A05DF1B, 0x2D02EF8D
};

// Initial CRC value is -1 (0xFFFFFFFF)
// Final CRC value is bitwise negation of the last calculated value
unsigned long CalculateCRC32(unsigned long crc, unsigned char *pBuffer, unsigned long nSize)
{
    while (nSize--)
        crc = crc32_table[(unsigned char)crc ^ *pBuffer++] ^ crc >> 8;

    return crc;  
}

unsigned char CheckFirmware(fileTYPE *file, char *name)
{
    UPGRADE *pUpgrade = (UPGRADE*)sector_buffer;
    unsigned long crc;
    unsigned long size;
    unsigned long rom_size;
    unsigned long rom_crc;
    unsigned long read_size;

    Error = ERROR_FILE_NOT_FOUND;
    if (FileOpen(file, name))
    {
        Error = ERROR_INVALID_DATA;
        iprintf("Upgrade file size     : %lu\r", file->size);
        iprintf("Upgrade header size   : %lu\r", (unsigned long)sizeof(UPGRADE));

        if (file->size >= sizeof(UPGRADE))
        {
            FileRead(file, sector_buffer);
            crc = ~CalculateCRC32(-1, sector_buffer, sizeof(UPGRADE) - 4);
            iprintf("Upgrade ROM size      : %lu\r", pUpgrade->rom.size);
            iprintf("Upgrade header CRC    : %08lX\r", pUpgrade->crc);
            iprintf("Calculated header CRC : %08lX\r", crc);
            if (pUpgrade->crc == crc)
            {
                if (strncmp((const char*)pUpgrade->id, "MNMGUPG", 7) == 0 && pUpgrade->id[7] == 0)
                {
                    if (pUpgrade->rom.size == file->size - sizeof(UPGRADE))
                    {
                        rom_size = pUpgrade->rom.size;
                        rom_crc = pUpgrade->rom.crc;

                        crc = -1; // initial CRC32 value
                        size = rom_size;
                        while (size)
                        {
                            if (size > 512)
                               read_size = 512;
                            else
                               read_size = size;

                            FileNextSector(file);
                            FileRead(file, sector_buffer);
                            crc = CalculateCRC32(crc, sector_buffer, read_size);
                            size -= read_size;
                        }
                        iprintf("Calculated ROM CRC    : %08lX\r", ~crc);
                        iprintf("ROM CRC from header   : %08lX\r", rom_crc);
                        if (~crc == rom_crc)
                        { // upgrade file CRC is OK so go back to the beginning of the file
                            FileSeek(file, 0, SEEK_SET);
                            Error = ERROR_NONE;
                            return 1;
                        }
                        else iprintf("ROM CRC mismatch! from header: %08lX, calculated: %08lX\r", rom_crc, ~crc);
                    }
                    else iprintf("ROM size mismatch! from header: %lu, from file: %lu\r", pUpgrade->rom.size, file->size-sizeof(UPGRADE));
                }
                else iprintf("Invalid upgrade file header!\r");
            }
            else iprintf("Header CRC mismatch! from header: %08lX, calculated: %08lX\r", pUpgrade->crc, crc);
        }
        else iprintf("Upgrade file size too small: %lu\r", file->size);
    }
    else iprintf("Cannot open firmware file!\r");
    return 0;
}

char *GetFirmwareVersion(fileTYPE *file, char *name) {
  static char v[16];

  if ((!FileOpen(file, name) || file->size < sizeof(UPGRADE))) 
    return NULL;

  FileRead(file, sector_buffer);
  strncpy(v, ((UPGRADE*)sector_buffer)->version, 16);
  v[15] = 0;

  return v;
}

// enable some nasty hacks to prevent gcc calling memset/memcpy during flash as these
// are library functions placed in flash and thus must not be called while flash is being
// overwritten
#define GCC_OPTIMZES_TOO_MUCH

#pragma section_code_init
RAMFUNC __noinline void WriteFirmware(fileTYPE *file, char *name)
{
    unsigned long read_size;
    unsigned long i;
    unsigned long k;
    unsigned long page;
    unsigned long *pSrc;
    unsigned long *pDst;
    unsigned long size;

    // All interrupts have to be disabled.
    asm volatile ("mrs r12, CPSR; orr r12, r12, #0xC0; msr CPSR_c, r12"
        : /* No outputs */
        : /* No inputs */
        : "r12", "cc");

    // Since the file may have changed in the meantime, it needs to be
    // opened again...
    if (!FileOpen(file, name)) 
        return;

    size = file->size - sizeof(UPGRADE);
    page = 0;
    pDst = 0;

    *AT91C_MC_FMR = 48 << 16 | FWS << 8; // MCLK cycles in 1us
    for (i = 0; i < 16; i++)
        if (*AT91C_MC_FSR & 1 << 16 + i)
        { // page is locked
            while (!(*AT91C_MC_FSR & AT91C_MC_FRDY));  // wait for ready
            *AT91C_MC_FCR = 0x5A << 24 | i << 6 + 8 | AT91C_MC_FCMD_UNLOCK; // unlock page
            while (!(*AT91C_MC_FSR & AT91C_MC_FRDY));  // wait for ready
        }

    *AT91C_MC_FMR = 72 << 16 | FWS << 8; // MCLK cycles in 1.5us

    while (size)
    {
        if (size > 512)
	    read_size = 512;
        else
	    read_size = size;

        // On _any_ error the upgrade will fail :-(
        // then the firmware needs to be upgraded by another way!
        FileNextSector(file); 
        FileRead(file, sector_buffer);

#ifndef GCC_OPTIMZES_TOO_MUCH  // the latest gcc 4.8.0 calls memset for this
	// it doesn't hurt to not do this at all

        // fill the rest of buffer
	for (i = read_size; i < 512; i++)
	  sector_buffer[i] = 0xFF;
#endif

        // programming time: 13.2 ms per disk sector (512B)
        pSrc = (unsigned long*)sector_buffer;
        k = 2;
        while (k--)
        {
 		DISKLED_ON;

#ifndef GCC_OPTIMZES_TOO_MUCH  // the latest gcc 4.8.0 calls memcpy for this
		i = 256 / 4;
		while (i--)
		  *pDst++ = *pSrc++;
#else
		i = 256 / 8;
		while (i--) {
		  *pDst++ = *pSrc++;
		  *pDst++ = *pSrc++;
		}

#if 0
		  *pDst++ = *pSrc++; *pDst++ = *pSrc++; *pDst++ = *pSrc++; *pDst++ = *pSrc++;
		  *pDst++ = *pSrc++; *pDst++ = *pSrc++; *pDst++ = *pSrc++; *pDst++ = *pSrc++;
		  *pDst++ = *pSrc++; *pDst++ = *pSrc++; *pDst++ = *pSrc++; *pDst++ = *pSrc++;
		  *pDst++ = *pSrc++; *pDst++ = *pSrc++; *pDst++ = *pSrc++; *pDst++ = *pSrc++;

		  *pDst++ = *pSrc++; *pDst++ = *pSrc++; *pDst++ = *pSrc++; *pDst++ = *pSrc++;
		  *pDst++ = *pSrc++; *pDst++ = *pSrc++; *pDst++ = *pSrc++; *pDst++ = *pSrc++;
		  *pDst++ = *pSrc++; *pDst++ = *pSrc++; *pDst++ = *pSrc++; *pDst++ = *pSrc++;
		  *pDst++ = *pSrc++; *pDst++ = *pSrc++; *pDst++ = *pSrc++; *pDst++ = *pSrc++;

		  *pDst++ = *pSrc++; *pDst++ = *pSrc++; *pDst++ = *pSrc++; *pDst++ = *pSrc++;
		  *pDst++ = *pSrc++; *pDst++ = *pSrc++; *pDst++ = *pSrc++; *pDst++ = *pSrc++;
		  *pDst++ = *pSrc++; *pDst++ = *pSrc++; *pDst++ = *pSrc++; *pDst++ = *pSrc++;
		  *pDst++ = *pSrc++; *pDst++ = *pSrc++; *pDst++ = *pSrc++; *pDst++ = *pSrc++;

		  *pDst++ = *pSrc++; *pDst++ = *pSrc++; *pDst++ = *pSrc++; *pDst++ = *pSrc++;
		  *pDst++ = *pSrc++; *pDst++ = *pSrc++; *pDst++ = *pSrc++; *pDst++ = *pSrc++;
		  *pDst++ = *pSrc++; *pDst++ = *pSrc++; *pDst++ = *pSrc++; *pDst++ = *pSrc++;
		  *pDst++ = *pSrc++; *pDst++ = *pSrc++; *pDst++ = *pSrc++; *pDst++ = *pSrc++;
#endif
#endif

		DISKLED_OFF;

                while (!(*AT91C_MC_FSR & AT91C_MC_FRDY));  // wait for ready
                *AT91C_MC_FCR = 0x5A << 24 | page << 8 | AT91C_MC_FCMD_START_PROG; // key: 0x5A
                while (!(*AT91C_MC_FSR & AT91C_MC_FRDY));  // wait for ready
                page++;
        }

        size -= read_size;
    }

    *AT91C_RSTC_RCR = 0xA5 << 24 | AT91C_RSTC_PERRST | AT91C_RSTC_PROCRST; // restart
    for(;;);
}
#pragma section_no_code_init

