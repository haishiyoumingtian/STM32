#include "sram.h"	      

#define Bank1_SRAM3_ADDR    ((u32)(0x68000000))	
  						   
//��ʼ���ⲿSRAM
void FSMC_SRAM_Init(void)
{	
	FSMC_NORSRAMInitTypeDef  FSMC_NORSRAMInitStructure;
  FSMC_NORSRAMTimingInitTypeDef  readWriteTiming; 
	
	RCC_AHB3PeriphClockCmd(RCC_AHB3Periph_FSMC,ENABLE);//ʹ��FSMCʱ�� 
	

		  
 	readWriteTiming.FSMC_AddressSetupTime = 0x02;	 //��ַ����ʱ�䣨ADDSET��Ϊ1��HCLK 1/36M=27ns
  readWriteTiming.FSMC_AddressHoldTime = 0x08;	 //��ַ����ʱ�䣨ADDHLD��ģʽAδ�õ�	
  readWriteTiming.FSMC_DataSetupTime = 0x08;		 ////���ݱ���ʱ�䣨DATAST��Ϊ9��HCLK 6*9=54ns	 	 
  readWriteTiming.FSMC_BusTurnAroundDuration = 0x00;
  readWriteTiming.FSMC_CLKDivision = 0x00;
  readWriteTiming.FSMC_DataLatency = 0x00;
  readWriteTiming.FSMC_AccessMode = FSMC_AccessMode_B;	 //ģʽA 
 
  FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM3;
  FSMC_NORSRAMInitStructure.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable; 
  FSMC_NORSRAMInitStructure.FSMC_MemoryType =FSMC_MemoryType_NOR;// FSMC_MemoryType_SRAM;  //SRAM   
  FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_16b;//�洢�����ݿ��Ϊ16bit  
  FSMC_NORSRAMInitStructure.FSMC_BurstAccessMode =FSMC_BurstAccessMode_Disable;// FSMC_BurstAccessMode_Disable; 
  FSMC_NORSRAMInitStructure.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;
	FSMC_NORSRAMInitStructure.FSMC_AsynchronousWait=FSMC_AsynchronousWait_Disable;
  FSMC_NORSRAMInitStructure.FSMC_WrapMode = FSMC_WrapMode_Disable;   
  FSMC_NORSRAMInitStructure.FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;  
  FSMC_NORSRAMInitStructure.FSMC_WriteOperation = FSMC_WriteOperation_Enable;	//�洢��дʹ�� 
  FSMC_NORSRAMInitStructure.FSMC_WaitSignal = FSMC_WaitSignal_Disable;  
  FSMC_NORSRAMInitStructure.FSMC_ExtendedMode = FSMC_ExtendedMode_Disable; // ��дʹ����ͬ��ʱ��
  FSMC_NORSRAMInitStructure.FSMC_WriteBurst = FSMC_WriteBurst_Disable;  
  FSMC_NORSRAMInitStructure.FSMC_ReadWriteTimingStruct = &readWriteTiming;
  FSMC_NORSRAMInitStructure.FSMC_WriteTimingStruct = &readWriteTiming; //��дͬ��ʱ��

  FSMC_NORSRAMInit(&FSMC_NORSRAMInitStructure);  //��ʼ��FSMC����

 	FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM3, ENABLE);  // ʹ��BANK1����1										  
											
}
	  														  
//////��ָ����ַ(WriteAddr+Bank1_SRAM3_ADDR)��ʼ,����д��n���ֽ�.
//////pBuffer:�ֽ�ָ��
//////WriteAddr:Ҫд��ĵ�ַ
//////n:Ҫд����ֽ���
////void FSMC_SRAM_WriteBuffer(u8* pBuffer,u32 WriteAddr,u32 n)
////{
////	for(;n!=0;n--)  
////	{										    
////		*(vu8*)(Bank1_SRAM1_ADDR+WriteAddr)=*pBuffer;	  
////		WriteAddr++;
////		pBuffer++;
////	}   
////}																			    
//////��ָ����ַ((WriteAddr+Bank1_SRAM3_ADDR))��ʼ,��������n���ֽ�.
//////pBuffer:�ֽ�ָ��
//////ReadAddr:Ҫ��������ʼ��ַ
//////n:Ҫд����ֽ���
////void FSMC_SRAM_ReadBuffer(u8* pBuffer,u32 ReadAddr,u32 n)
////{
////	for(;n!=0;n--)  
////	{											    
////		*pBuffer++=*(vu8*)(Bank1_SRAM1_ADDR+ReadAddr);    
////		ReadAddr++;
////	}  
////} 
//// 
////void fsmc_sram_test(u16 x,u16 y)
////{  
////	u32 i=0;  	  
////	u8 temp=0;	   
////	u8 sval=0;	//�ڵ�ַ0����������	  				
////	//LCD_ShowString(x,y,239,y+16,16,"Ex Memory Test:   0KB"); 	
////	//ÿ��4K�ֽ�,д��һ������,�ܹ�д��256������,�պ���1M�ֽ�
////	for(i=0;i<1024*1024;i+=4096)
////	{
////		FSMC_SRAM_WriteBuffer(&temp,i,1);
////		temp++;
////	}
////	//���ζ���֮ǰд�������,����У��		  
//// 	for(i=0;i<1024*1024;i+=4096) 
////	{
////  		FSMC_SRAM_ReadBuffer(&temp,i,1);
////		if(i==0)sval=temp;
//// 		else if(temp<=sval)break;//�������������һ��Ҫ�ȵ�һ�ζ��������ݴ�.	   		   
////		//LCD_ShowxNum(x+15*8,y,(u16)(temp-sval+1)*4,4,16,0);//��ʾ�ڴ�����  
//// 	}					 
////}	








