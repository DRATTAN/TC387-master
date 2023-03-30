/**
 * \file IfxFlash.h
 * \brief FLASH  basic functionality
 * \ingroup IfxLld_Flash
 *
 * \version iLLD_1_0_1_11_0
 * \copyright Copyright (c) 2019 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Use of this file is subject to the terms of use agreed between (i) you or 
 * the company in which ordinary course of business you are acting and (ii) 
 * Infineon Technologies AG or its licensees. If and as long as no such 
 * terms of use are agreed, use of this file is subject to following:


 * Boost Software License - Version 1.0 - August 17th, 2003

 * Permission is hereby granted, free of charge, to any person or 
 * organization obtaining a copy of the software and accompanying 
 * documentation covered by this license (the "Software") to use, reproduce,
 * display, distribute, execute, and transmit the Software, and to prepare
 * derivative works of the Software, and to permit third-parties to whom the 
 * Software is furnished to do so, all subject to the following:

 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE 
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.

 *
 *
 * \defgroup IfxLld_Flash_Std_Enumerations Enumerations
 * \ingroup IfxLld_Flash_Std
 * \defgroup IfxLld_Flash_Std_CommandSequence CommandSequence Functions
 * \ingroup IfxLld_Flash_Std
 */

#ifndef IFXFLAS_H
#define IFXFLAS_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxFlash_cfg.h"
#include "_Utilities/Ifx_Assert.h"
#include "IfxDmu_reg.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Flash_Std_Enumerations
 * \{ */
/** \} */

/** \addtogroup IfxLld_Flash_Std_CommandSequence
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Performs the "Clear Status" sequence. Operation and error flags are cleared.
 * \param flash selects the flash (PMU) module
 * \return None
 */
IFX_INLINE void IfxFlash_clearStatus(uint32 flash);

/** \brief Performs the sequence for entering program page mode
 * \param pageAddr pageAddr specifies the page being written - the command sequence will be varied accordingly
 * \return 0 on success, != 0 if invalid or not available page is selected
 *
 * Usage Example:
 * \code
 *
 * unsigned int pageAddr = IFXFLASH_DFLASH_START + page*IFXFLASH_DFLASH_PAGE_LENGTH;
 *
 * // enter page mode
 * IfxFlash_enterPageMode(pageAddr);
 *
 * \endcode
 *
 */
IFX_INLINE uint8 IfxFlash_enterPageMode(uint32 pageAddr);

/** \brief Performs the erase sequence for n  sectors in program or data flash
 * \param sectorAddr sector address
 * \param numSector the no.of sectors to be erased
 * \return None
 *
 * Usage Example:
 * \code
 *
 * // erase logical sectors of program flash
 *  IfxFlash_eraseMultipleSectors(pFlashTableLog[sector].start,2);
 *
 * \endcode
 *
 */
IFX_INLINE void IfxFlash_eraseMultipleSectors(uint32 sectorAddr, uint32 numSector);

/** \brief Performs the erase sequence for a sector in program or data flash.
 * \param sectorAddr sector address
 * \return None
 *
 * Usage Example:
 * \code
 *
 *
 * // erase all sectors of program flash
 * for(sector=0; sector<IFXFLASH_PFLASH_NO_OF_LOG_SECTORS; ++sector) {
 *   // get address from predefined table
 *   unsigned int sector_addr = pFlashTableLog[sector].start;
 *   // erase sector
 *  IfxFlash_eraseSector(sector_addr);
 * }
 *
 *
 * \endcode
 *
 */
IFX_INLINE void IfxFlash_eraseSector(uint32 sectorAddr);

/** \brief Performs the "Erase Verify" sequence for multiple sectors
 * \param sectorAddr sector address which should be verified
 * \param numSector no.of sectors to be operated on
 * \return None
 */
IFX_INLINE void IfxFlash_eraseVerifyMultipleSectors(uint32 sectorAddr, uint32 numSector);

/** \brief Performs the "Erase Verify" sequence
 * \param sectorAddr sector address which should be verified
 * \return None
 */
IFX_INLINE void IfxFlash_eraseVerifySector(uint32 sectorAddr);

/** \brief performs a load page sequence with a single 64bit access
 * \param pageAddr pageAddr start address of page which should be programmed
 * \param wordL Lower Address word
 * \param wordU Upper address word
 * \return None
 *
 * Usage Example:
 * \code
 *
 * // load 64bit into assembly buffer of program flash
 * IfxFlash_loadPage(IFXFLASH_PFLASH_START, 0x55555555, 0xaaaaaaaa);
 *
 * // load 64bit into assembly buffer of data flash
 * IfxFlash_loadPage(0XAF000000, 0x55555555, 0xaaaaaaaa);
 * \endcode
 *
 */
IFX_INLINE void IfxFlash_loadPage(uint32 pageAddr, uint32 wordL, uint32 wordU);

/** \brief performs a load page sequence with two 32bit accesses
 * \param pageAddr pageAddr start address of page which should be programmed
 * \param wordL Lower Address word
 * \param wordU Upper Address word
 * \return None
 *
 * Usage Example:
 * \code
 *
 * // load 2*32bit into assembly buffer of program flash
 * IfxFlash_loadPage2X32(IFXFLASH_PFLASH_START, 0x55555555, 0xaaaaaaaa);
 *
 * // load 2*32bit into assembly buffer of data flash
 * IfxFlash_loadPage2X32(0XAF000000, 0x55555555, 0xaaaaaaaa);
 * \endcode
 *
 */
IFX_INLINE void IfxFlash_loadPage2X32(uint32 pageAddr, uint32 wordL, uint32 wordU);

/** \brief reset to read mode
 * \param flash flash selects the flash (PMU) module
 * \return None
 *
 * Usage Example:
 * \code
 *
 * // reset to read mode
 *  IfxFlash_resetToRead(0);
 *
 * \endcode
 *
 */
IFX_INLINE void IfxFlash_resetToRead(uint32 flash);

/** \brief Performs the "Resume Protection" sequence
 * \param flash selects the flash (PMU) module
 * \return None
 */
IFX_INLINE void IfxFlash_resumeProtection(uint32 flash);

/** \brief Performs the "Suspend Resume" sequence for multiple sectors
 * \param sectorAddr sector address
 * \param numSector the no.of sectors  to be operated on
 * \return None
 */
IFX_INLINE void IfxFlash_suspendResumeMultipleSectors(uint32 sectorAddr, uint32 numSector);

/** \brief Performs the "Suspend Resume" sequence
 * \param sectorAddr sector address which should be resumed
 * \return None
 */
IFX_INLINE void IfxFlash_suspendResumeSector(uint32 sectorAddr);

/** \brief The function issues command sequence for User Content count.The result of this function is dependent on the difference of the number of logic 1 bits in the selected pages at the  erase-verify condition (N_dv) and at the selected control gate voltage (N_pv). Calling this function with different control gate voltages allows calculation of the Vth distribution
 * \param wordAddr word address
 * \return None
 */
IFX_INLINE void IfxFlash_userContentCount(uint32 wordAddr);

/** \brief The function issues command sequence for User Margin Count. The result of this function is the number of logic 1 bits in the selected pages at the selected reference current. Calling this function with different reference currents allows calculation of the cell current distribution.
 * \param wordAddr word address
 * \return None
 */
IFX_INLINE void IfxFlash_userMarginCount(uint32 wordAddr);

/** \brief The function issues command sequence for User Vth Count.The result of this function is the number of logic 1 bits in the selected pages at the selected control gate voltage. Calling this function with different control gate voltages allows calculation of the Vth distribution.
 * \param wordAddr word address
 * \return None
 */
IFX_INLINE void IfxFlash_userVthCount(uint32 wordAddr);

/** \brief Performs the "Verify Erased Block (page)" sequence. This command verifies if one page addressed by "PA" is correctly erased, i.e. contain 0 data and ECC bits
 * \param pageAddr page address which should be verified
 * \return None
 */
IFX_INLINE void IfxFlash_verifyErasedPage(uint32 pageAddr);

/** \brief Performs the "Verify Erased WL" sequence.This command verifies if one word line addressed by "WA" is correctly erased, i.e. contain 0 data and ECC bits
 * \param wordLineAddr word line address which should be verified
 * \return None
 */
IFX_INLINE void IfxFlash_verifyErasedWordLine(uint32 wordLineAddr);

/** \brief Polls the selected status flag in flash status register until it turns to 0
 * \param flash selects the flash (PMU) module
 * \param flashType selects the flash type
 * \return 0 on success, != 0 if invalid or not available page is selected
 *
 * Usage Example:
 * \code
 *
 * // wait until data flash 0 is unbusy
 *  IfxFlash_waitUnbusy(0, IfxFlash_FlashType_D0);
 *
 * \endcode
 *
 */
IFX_INLINE uint8 IfxFlash_waitUnbusy(uint32 flash, IfxFlash_FlashType flashType);

/** \brief Performs the "Write Burst" sequence, similar to write page but performs a burst transfer instead of page.Make sure the appropriate amount of data is loaded using load page command
 * \param pageAddr start address of page which should be programmed
 * \return None
 *
 * Usage Example:
 * \code
 *
 * // program the second page of the first sector of the Program Flash
 * IfxFlash_writeBurst(0xa0000100);
 *
 * \endcode
 *
 */
IFX_INLINE void IfxFlash_writeBurst(uint32 pageAddr);

/** \brief Performs the "Write Burst once" sequence. The command starts the programming process for an aligned group of pages as the normal "Write Burst" does. But before programming it checks if the pages are erased. If the page is not erased (allowing correctable errors) the command fails with PVER and EVER.
 * The command is only supported for PFlash. On sectors with "write-once" protection only this write command can be applied.
 * \param pageAddr start address of page which should be programmed
 * \return None
 *
 * Usage Example:
 * \code
 *
 * // program the second page of the first sector of the Program Flash
 * IfxFlash_writeBurstOnce(0xa0000100);
 *
 * \endcode
 *
 */
IFX_INLINE void IfxFlash_writeBurstOnce(uint32 pageAddr);

/** \brief Performs the "Write Page" sequence
 * \param pageAddr start address of page which should be programmed
 * \return None
 *
 * Usage Example:
 * \code
 *
 * // program the second page of the first sector of the Program Flash
 * IfxFlash_writePage(0xa0000100);
 *
 * \endcode
 *
 */
IFX_INLINE void IfxFlash_writePage(uint32 pageAddr);

/** \brief Performs the "Write Page Once" sequence, similar to write page but performs a program verify after writing.
 * \param pageAddr start address of page which should be programmed
 * \return None
 *
 * Usage Example:
 * \code
 *
 * // program the second page of the first sector of the Program Flash
 * IfxFlash_writePageOnce(0xa0000100);
 *
 * \endcode
 *
 */
IFX_INLINE void IfxFlash_writePageOnce(uint32 pageAddr);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief The password protection of the selected UCB (if this UCB offers this feature) is temporarily disabled. The command fails by setting PROER when any of the supplied PWs does not match. In this case until the next application reset all further calls of "Disable Protection" fail with PROER independent of the supplied password.
 * \param flash selects the flash (PMU) module
 * \param ucb selects the user configuration block (0 for UCB0, 1 for UCB1, 5 for UCB_HSMC)
 * \param password password pointer to an array of 8 words
 * \return None
 */
IFX_EXTERN void IfxFlash_disableWriteProtection(uint32 flash, IfxFlash_UcbType ucb, uint32 *password);

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief This function will wait till all the flash banks are out of busy state
 * \return Return 0 on success.Success means none of the flash banks are in busy state.
 */
IFX_INLINE boolean IfxFlash_waitUnbusyAll(void);

/** \brief Enter Flash Cranking Mode.
 * \return None
 */
IFX_INLINE void IfxFlash_enterCrankingMode(void);

/** \brief Exit Flash Cranking Mode.
 * \return None
 */
IFX_INLINE void IfxFlash_exitCrankingMode(void);

/**
 * \return None
 */
IFX_INLINE void IfxFlash_enterDemandMode(void);

/**
 * \return None
 */
IFX_INLINE void IfxFlash_exitDemandMode(void);

/**
 * \return None
 */
IFX_INLINE void IfxFlash_enterDynamicIdleMode(void);

/**
 * \return None
 */
IFX_INLINE void IfxFlash_exitDynamicIdleMode(void);

/** \brief Returns if Flash is in Cranking Mode.
 * TRUE - Flash is in Cranking Mode
 * FALSE - Flash is not in Cranking Mode
 * \return Returns if Flash is in Cranking mode or not
 * TRUE - Flash is in Cranking Mode
 * FALSE - Flash is not in Cranking Mode
 */
IFX_INLINE boolean IfxFlash_isCrankingMode(void);

/** \brief Returns if Flash is in Demand mode or not
 * TRUE - Flash is in Demand Mode
 * FALSE - Flash is not in Demand Mode
 * \return Returns if Flash is in Demand mode or not
 * TRUE - Flash is in Demand Mode
 * FALSE - Flash is not in Demand Mode
 */
IFX_INLINE boolean IfxFlash_isDemandMode(void);

/** \brief Returns if Flash is in Dynamic Idle mode or not
 * TRUE - Flash is in Dynamic Idle Mode
 * FALSE - Flash is not in Dynamic Idle Mode
 * \return Returns if Flash is in Dynamic Idle mode or not
 * TRUE - Flash is in Dynamic Idle Mode
 * FALSE - Flash is not in Dynamic Idle Mode
 */
IFX_INLINE boolean IfxFlash_isDynamicIdleMode(void);

/**
 * \param pageAddr start address of page which should be programmed
 * \return None
 */
IFX_INLINE void IfxFlash_replaceLogicalSector(uint32 pageAddr);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxFlash_clearStatus(uint32 flash)
{
    IFX_UNUSED_PARAMETER(flash);
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0x5554);

    *addr1 = 0xFA;

    __dsync();
}


IFX_INLINE uint8 IfxFlash_enterPageMode(uint32 pageAddr)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0x5554);

    if ((pageAddr & 0xff000000) == 0xa0000000)    // program flash
    {
        *addr1 = 0x50;
        return 0;
    }
    else if ((pageAddr & 0xff000000) == 0xaf000000)       // data flash
    {
        *addr1 = 0x5D;
        return 0;
    }

    __dsync();
    return 1; // invalid flash address
}


IFX_INLINE void IfxFlash_eraseMultipleSectors(uint32 sectorAddr, uint32 numSector)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa50);
    volatile uint32 *addr2 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa58);
    volatile uint32 *addr3 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);
    volatile uint32 *addr4 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);

    *addr1 = sectorAddr;
    *addr2 = numSector;
    *addr3 = 0x80;
    *addr4 = 0x50;

    __dsync();
}


IFX_INLINE void IfxFlash_eraseSector(uint32 sectorAddr)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa50);
    volatile uint32 *addr2 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa58);
    volatile uint32 *addr3 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);
    volatile uint32 *addr4 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);

    *addr1 = sectorAddr;
    *addr2 = 1;
    *addr3 = 0x80;
    *addr4 = 0x50;

    __dsync();
}


IFX_INLINE void IfxFlash_eraseVerifyMultipleSectors(uint32 sectorAddr, uint32 numSector)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa50);
    volatile uint32 *addr2 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa58);
    volatile uint32 *addr3 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);
    volatile uint32 *addr4 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);

    *addr1 = sectorAddr;
    *addr2 = numSector;
    *addr3 = 0x80;
    *addr4 = 0x5F;

    __dsync();
}


IFX_INLINE void IfxFlash_eraseVerifySector(uint32 sectorAddr)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa50);
    volatile uint32 *addr2 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa58);
    volatile uint32 *addr3 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);
    volatile uint32 *addr4 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);

    *addr1 = sectorAddr;
    *addr2 = 1;
    *addr3 = 0x80;
    *addr4 = 0x5F;

    __dsync();
}


IFX_INLINE void IfxFlash_loadPage(uint32 pageAddr, uint32 wordL, uint32 wordU)
{
    IFX_UNUSED_PARAMETER(pageAddr);
    uint64 *addr1 = (uint64 *)(IFXFLASH_CMD_BASE_ADDRESS | 0x55f0);

    __st64_lu(addr1, wordL, wordU);

    __dsync();
}


IFX_INLINE void IfxFlash_loadPage2X32(uint32 pageAddr, uint32 wordL, uint32 wordU)
{
    IFX_UNUSED_PARAMETER(pageAddr);

    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0x55f0);

    *addr1 = wordL;
    addr1++;
    *addr1 = wordU;

    __dsync();
}


IFX_INLINE void IfxFlash_resetToRead(uint32 flash)
{
    IFX_UNUSED_PARAMETER(flash);
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0x5554);
    *addr1 = 0xf0;

    __dsync();
}


IFX_INLINE void IfxFlash_resumeProtection(uint32 flash)
{
    IFX_UNUSED_PARAMETER(flash);

    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0x5554);

    *addr1 = 0xF5;

    __dsync();
}


IFX_INLINE void IfxFlash_suspendResumeMultipleSectors(uint32 sectorAddr, uint32 numSector)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa50);
    volatile uint32 *addr2 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa58);
    volatile uint32 *addr3 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);
    volatile uint32 *addr4 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);

    *addr1 = sectorAddr;
    *addr2 = numSector;
    *addr3 = 0x70;
    *addr4 = 0xCC;

    __dsync();
}


IFX_INLINE void IfxFlash_suspendResumeSector(uint32 sectorAddr)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa50);
    volatile uint32 *addr2 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa58);
    volatile uint32 *addr3 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);
    volatile uint32 *addr4 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);

    *addr1 = sectorAddr;
    *addr2 = 1;
    *addr3 = 0x70;
    *addr4 = 0xCC;

    __dsync();
}


IFX_INLINE void IfxFlash_userContentCount(uint32 wordAddr)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa50);
    volatile uint32 *addr2 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa58);
    volatile uint32 *addr3 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);
    volatile uint32 *addr4 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);

    *addr1 = wordAddr;
    *addr2 = 0x00;
    *addr3 = 0x60;
    *addr4 = 0x14;
    __dsync();
}


IFX_INLINE void IfxFlash_userMarginCount(uint32 wordAddr)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa50);
    volatile uint32 *addr2 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa58);
    volatile uint32 *addr3 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);
    volatile uint32 *addr4 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);

    *addr1 = wordAddr;
    *addr2 = 0x00;
    *addr3 = 0x60;
    *addr4 = 0x11;
    __dsync();
}


IFX_INLINE void IfxFlash_userVthCount(uint32 wordAddr)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa50);
    volatile uint32 *addr2 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa58);
    volatile uint32 *addr3 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);
    volatile uint32 *addr4 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);

    *addr1 = wordAddr;
    *addr2 = 0x00;
    *addr3 = 0x60;
    *addr4 = 0x12;
    __dsync();
}


IFX_INLINE void IfxFlash_verifyErasedPage(uint32 pageAddr)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa50);
    volatile uint32 *addr2 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa58);
    volatile uint32 *addr3 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);
    volatile uint32 *addr4 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);

    *addr1 = pageAddr;
    *addr2 = 00;
    *addr3 = 0x80;
    *addr4 = 0x56;

    __dsync();
}


IFX_INLINE void IfxFlash_verifyErasedWordLine(uint32 wordLineAddr)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa50);
    volatile uint32 *addr2 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa58);
    volatile uint32 *addr3 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);
    volatile uint32 *addr4 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);

    *addr1 = wordLineAddr;
    *addr2 = 00;
    *addr3 = 0x80;
    *addr4 = 0x58;

    __dsync();
}


IFX_INLINE uint8 IfxFlash_waitUnbusy(uint32 flash, IfxFlash_FlashType flashType)
{
    if (flash == 0)
    {
        while (DMU_HF_STATUS.U & (1 << flashType))
        {}
    }
    else
    {
        return 1;    /*invalid flash selected */
    }

    __dsync();
    return 0; /* finished */
}


IFX_INLINE void IfxFlash_writeBurst(uint32 pageAddr)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa50);
    volatile uint32 *addr2 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa58);
    volatile uint32 *addr3 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);
    volatile uint32 *addr4 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);

    *addr1 = pageAddr;
    *addr2 = 0x00;
    *addr3 = 0xa0;
    *addr4 = 0xa6;

    __dsync();
}


IFX_INLINE void IfxFlash_writeBurstOnce(uint32 pageAddr)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa50);
    volatile uint32 *addr2 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa58);
    volatile uint32 *addr3 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);
    volatile uint32 *addr4 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);

    *addr1 = pageAddr;
    *addr2 = 0x00;
    *addr3 = 0xa0;
    *addr4 = 0xa4;

    __dsync();
}


IFX_INLINE void IfxFlash_writePage(uint32 pageAddr)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa50);
    volatile uint32 *addr2 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa58);
    volatile uint32 *addr3 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);
    volatile uint32 *addr4 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);

    *addr1 = pageAddr;
    *addr2 = 0x00;
    *addr3 = 0xa0;
    *addr4 = 0xaa;

    __dsync();
}


IFX_INLINE void IfxFlash_writePageOnce(uint32 pageAddr)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa50);
    volatile uint32 *addr2 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa58);
    volatile uint32 *addr3 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);
    volatile uint32 *addr4 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);

    *addr1 = pageAddr;
    *addr2 = 0x00;
    *addr3 = 0xa0;
    *addr4 = 0xa8;

    __dsync();
}


IFX_INLINE boolean IfxFlash_waitUnbusyAll(void)
{
    while (DMU_HF_STATUS.U & 0x3FU)
    {}

    __dsync();
    return 0;
}


IFX_INLINE void IfxFlash_enterCrankingMode(void)
{
    DMU_HF_CCONTROL.B.CRANKING = 3U;
    __dsync();
}


IFX_INLINE void IfxFlash_exitCrankingMode(void)
{
    DMU_HF_CCONTROL.B.CRANKING = 0U;
    __dsync();
}


IFX_INLINE void IfxFlash_enterDemandMode(void)
{
    DMU_HF_PCONTROL.B.DEMAND = 3U;
    __dsync();
}


IFX_INLINE void IfxFlash_exitDemandMode(void)
{
    DMU_HF_PCONTROL.B.DEMAND = 0U;
    __dsync();
}


IFX_INLINE void IfxFlash_enterDynamicIdleMode(void)
{
    DMU_HF_PCONTROL.B.IDLE = 3U;
    __dsync();
}


IFX_INLINE void IfxFlash_exitDynamicIdleMode(void)
{
    DMU_HF_PCONTROL.B.IDLE = 0U;
    __dsync();
}


IFX_INLINE boolean IfxFlash_isCrankingMode(void)
{
    return (boolean)(DMU_HF_CCONTROL.B.CRANKING == 0x3U);
}


IFX_INLINE boolean IfxFlash_isDemandMode(void)
{
    return (boolean)(DMU_HF_PSTATUS.B.DEMAND == 1U);
}


IFX_INLINE boolean IfxFlash_isDynamicIdleMode(void)
{
    return (boolean)(DMU_HF_PSTATUS.B.IDLE == 1U);
}


IFX_INLINE void IfxFlash_replaceLogicalSector(uint32 pageAddr)
{
    volatile uint32 *addr1 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa50);
    volatile uint32 *addr2 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaa58);
    volatile uint32 *addr3 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);
    volatile uint32 *addr4 = (volatile uint32 *)(IFXFLASH_CMD_BASE_ADDRESS | 0xaaa8);

    *addr1 = pageAddr;
    *addr2 = 0x00;
    *addr3 = 0xa0;
    *addr4 = 0xac;

    __dsync();
}


#endif /* IFXFLAS_H */
