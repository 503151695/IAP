#ifndef  __IAPFUN_H__
#define  __IAPFUN_H__


//--��ҪӦ�ó��� ��Ӧ�޸�IROM1 : 0x0801 0000
//#define MAINAPP
//--����Ӧ�ó��� ��Ӧ�޸�IROM1 : 0x0806 0000
//#define SPAREAPP

#define	IAP_UPD_OK_ADDR													0x800FCF0	

void IAP_AddOffset(void);
void IAP_ProState(void);


#endif
