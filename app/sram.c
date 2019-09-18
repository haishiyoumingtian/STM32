#include "sram.h"	      

#define Bank1_SRAM3_ADDR    ((u32)(0x68000000))	
  						   
//初始化外部SRAM
void FSMC_SRAM_Init(void)
{	
	FSMC_NORSRAMInitTypeDef  FSMC_NORSRAMInitStructure;
  FSMC_NORSRAMTimingInitTypeDef  readWriteTiming; 
	
	RCC_AHB3PeriphClockCmd(RCC_AHB3Periph_FSMC,ENABLE);//使能FSMC时钟 
	

		  
 	readWriteTiming.FSMC_AddressSetupTime = 0x02;	 //地址建立时间（ADDSET）为1个HCLK 1/36M=27ns
  readWriteTiming.FSMC_AddressHoldTime = 0x08;	 //地址保持时间（ADDHLD）模式A未用到	
  readWriteTiming.FSMC_DataSetupTime = 0x08;		 ////数据保持时间（DATAST）为9个HCLK 6*9=54ns	 	 
  readWriteTiming.FSMC_BusTurnAroundDuration = 0x00;
  readWriteTiming.FSMC_CLKDivision = 0x00;
  readWriteTiming.FSMC_DataLatency = 0x00;
  readWriteTiming.FSMC_AccessMode = FSMC_AccessMode_B;	 //模式A 
 
  FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM3;
  FSMC_NORSRAMInitStructure.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable; 
  FSMC_NORSRAMInitStructure.FSMC_MemoryType =FSMC_MemoryType_NOR;// FSMC_MemoryType_SRAM;  //SRAM   
  FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_16b;//存储器数据宽度为16bit  
  FSMC_NORSRAMInitStructure.FSMC_BurstAccessMode =FSMC_BurstAccessMode_Disable;// FSMC_BurstAccessMode_Disable; 
  FSMC_NORSRAMInitStructure.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;
	FSMC_NORSRAMInitStructure.FSMC_AsynchronousWait=FSMC_AsynchronousWait_Disable;
  FSMC_NORSRAMInitStructure.FSMC_WrapMode = FSMC_WrapMode_Disable;   
  FSMC_NORSRAMInitStructure.FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;  
  FSMC_NORSRAMInitStructure.FSMC_WriteOperation = FSMC_WriteOperation_Enable;	//存储器写使能 
  FSMC_NORSRAMInitStructure.FSMC_WaitSignal = FSMC_WaitSignal_Disable;  
  FSMC_NORSRAMInitStructure.FSMC_ExtendedMode = FSMC_ExtendedMode_Disable; // 读写使用相同的时序
  FSMC_NORSRAMInitStructure.FSMC_WriteBurst = FSMC_WriteBurst_Disable;  
  FSMC_NORSRAMInitStructure.FSMC_ReadWriteTimingStruct = &readWriteTiming;
  FSMC_NORSRAMInitStructure.FSMC_WriteTimingStruct = &readWriteTiming; //读写同样时序

  FSMC_NORSRAMInit(&FSMC_NORSRAMInitStructure);  //初始化FSMC配置

 	FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM3, ENABLE);  // 使能BANK1区域1										  
											
}
	  														  
//////在指定地址(WriteAddr+Bank1_SRAM3_ADDR)开始,连续写入n个字节.
//////pBuffer:字节指针
//////WriteAddr:要写入的地址
//////n:要写入的字节数
////void FSMC_SRAM_WriteBuffer(u8* pBuffer,u32 WriteAddr,u32 n)
////{
////	for(;n!=0;n--)  
////	{										    
////		*(vu8*)(Bank1_SRAM1_ADDR+WriteAddr)=*pBuffer;	  
////		WriteAddr++;
////		pBuffer++;
////	}   
////}																			    
//////在指定地址((WriteAddr+Bank1_SRAM3_ADDR))开始,连续读出n个字节.
//////pBuffer:字节指针
//////ReadAddr:要读出的起始地址
//////n:要写入的字节数
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
////	u8 sval=0;	//在地址0读到的数据	  				
////	//LCD_ShowString(x,y,239,y+16,16,"Ex Memory Test:   0KB"); 	
////	//每隔4K字节,写入一个数据,总共写入256个数据,刚好是1M字节
////	for(i=0;i<1024*1024;i+=4096)
////	{
////		FSMC_SRAM_WriteBuffer(&temp,i,1);
////		temp++;
////	}
////	//依次读出之前写入的数据,进行校验		  
//// 	for(i=0;i<1024*1024;i+=4096) 
////	{
////  		FSMC_SRAM_ReadBuffer(&temp,i,1);
////		if(i==0)sval=temp;
//// 		else if(temp<=sval)break;//后面读出的数据一定要比第一次读到的数据大.	   		   
////		//LCD_ShowxNum(x+15*8,y,(u16)(temp-sval+1)*4,4,16,0);//显示内存容量  
//// 	}					 
////}	








