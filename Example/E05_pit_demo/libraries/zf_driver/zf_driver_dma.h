/*********************************************************************************************************************
* TC387 Opensourec Library ����TC387 ��Դ�⣩��һ�����ڹٷ� SDK �ӿڵĵ�������Դ��
* Copyright (c) 2022 SEEKFREE ��ɿƼ�
*
* ���ļ��� TC387 ��Դ���һ����
*
* TC387 ��Դ�� ���������
* �����Ը���������������ᷢ���� GPL��GNU General Public License���� GNUͨ�ù�������֤��������
* �� GPL �ĵ�3�棨�� GPL3.0������ѡ��ģ��κκ����İ汾�����·�����/���޸���
*
* ����Դ��ķ�����ϣ�����ܷ������ã�����δ�������κεı�֤
* ����û�������������Ի��ʺ��ض���;�ı�֤
* ����ϸ����μ� GPL
*
* ��Ӧ�����յ�����Դ���ͬʱ�յ�һ�� GPL �ĸ���
* ���û�У������<https://www.gnu.org/licenses/>
*
* ����ע����
* ����Դ��ʹ�� GPL3.0 ��Դ����֤Э�� ������������Ϊ���İ汾
* ��������Ӣ�İ��� libraries/doc �ļ����µ� GPL3_permission_statement.txt �ļ���
* ����֤������ libraries �ļ����� �����ļ����µ� LICENSE �ļ�
* ��ӭ��λʹ�ò����������� ���޸�����ʱ���뱣����ɿƼ��İ�Ȩ����������������
*
* �ļ�����          zf_driver_dma
* ��˾����          �ɶ���ɿƼ����޹�˾
* �汾��Ϣ          �鿴 libraries/doc �ļ����� version �ļ� �汾˵��
* ��������          ADS v1.8.0
* ����ƽ̨          TC387QP
* ��������          https://seekfree.taobao.com/
*
* �޸ļ�¼
* ����              ����                ��ע
* 2022-11-04       pudding            first version
********************************************************************************************************************/

#ifndef _zf_driver_dma_h_
#define _zf_driver_dma_h_

#include "IfxDma.h"
#include "zf_common_typedef.h"
#include "zf_driver_exti.h"

#define clear_dma_flag(dma_ch)                              (IfxDma_clearChannelInterrupt(&MODULE_DMA, dma_ch))

#define dma_set_destination(dma_ch, destination_addr)       (IfxDma_setChannelDestinationAddress(&MODULE_DMA, (dma_ch), (void *)IFXCPU_GLB_ADDR_DSPR(IfxCpu_getCoreId(), (destination_addr))))

//====================================================DMA ��������====================================================
uint8 dma_init      (IfxDma_ChannelId dma_ch, uint8 *source_addr, uint8 *destination_addr, exti_pin_enum eru_pin, exti_trigger_enum trigger, uint16 dma_count);
void  dma_disable   (IfxDma_ChannelId dma_ch);
void  dma_enable    (IfxDma_ChannelId dma_ch);
//====================================================DMA ��������====================================================

#endif