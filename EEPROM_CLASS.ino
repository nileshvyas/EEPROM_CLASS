/*****************************************************************************************************************************************************************
 *                                                                                                                                                               *
 *                                                    EEPROM READ AND WRITE DATA                                                                                 *
 *                                                                                                                                                               *
 *****************************************************************************************************************************************************************
  */
#include<EEPROM.h>

/************************************************************* GLOBAL VARIABLE DECLERATION *******************************************************************/

byte  FLOW_CONSTANT_1;
byte  FLOW_CONSTANT_2;
byte  COIN_PULSE_1;
byte  COIN_PULSE_5;
int   VOLUME_COIN_1;
int   VOLUME_COIN_5;
float TOTAL_VOLUME_DISPENCE;
float TOTAL_RECHARGE;
unsigned int  COLLECTION_CARD;
unsigned int  COLLECTION_COIN;
unsigned int  NUMBER_COIN_1;
unsigned int  NUMBER_COIN_5;

/*************************************************************<<<<< END OF GLOBAL VARIABLE DECLERATION >>>>>****************************************************/



/*************************************************** CLASS FOR SETTING PARAMETER IN CONTROLLER *************************************************************************/

class settingParameter
{
  byte flowConstant1,flowConstant2,coinPulse1,coinPulse5;
  int volumeCoin1,volumeCoin5;
  float totalVolumeDispence,TotalRecharge;
  unsigned int collectionCard,collectionCoin,numberCoin1,numberCoin5;
  public:
  settingParameter()  //Default constructor
  {
    flowConstant1=50;
    flowConstant2=50;
    coinPulse1=5;
    coinPulse5=10;
    volumeCoin1=500;
    volumeCoin5=1000;
    totalVolumeDispence=0;
    TotalRecharge=0;
    collectionCard=0;
    collectionCoin=0;
    numberCoin1=0;
    numberCoin5=0;
  }
  void getdata()
  {
    FLOW_CONSTANT_1=flowConstant1;
    FLOW_CONSTANT_2=flowConstant2;
    COIN_PULSE_1=coinPulse1;
    COIN_PULSE_5=coinPulse5;
    VOLUME_COIN_1=volumeCoin1;
    VOLUME_COIN_5=volumeCoin5;
    TOTAL_VOLUME_DISPENCE=totalVolumeDispence;
    TOTAL_RECHARGE=TotalRecharge;
    COLLECTION_CARD=collectionCard;
    COLLECTION_COIN=collectionCoin;
    NUMBER_COIN_1=numberCoin1;
    NUMBER_COIN_5=numberCoin5;
  }
  void setdata()
  {
    flowConstant1=FLOW_CONSTANT_1;
    flowConstant2=FLOW_CONSTANT_2;
    coinPulse1=COIN_PULSE_1;
    coinPulse5=COIN_PULSE_5;
    volumeCoin1=VOLUME_COIN_1;
    volumeCoin5=VOLUME_COIN_5;
    totalVolumeDispence=TOTAL_VOLUME_DISPENCE;
    TotalRecharge=TOTAL_RECHARGE;
    collectionCard=COLLECTION_CARD;
    collectionCoin=COLLECTION_COIN;
    numberCoin1=NUMBER_COIN_1;
    numberCoin5=NUMBER_COIN_5;
  }
}parameters;


/********************************************************************<<<<< END OF SETTING PARAMETER CLASS >>>>>******************************************/

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  if(0)
  {
    byte checkByte=0;
    EEPROM.write(0,checkByte);
  }
  checkEEPROM();

}

void loop() 
{
  // put your main code here, to run repeatedly:
  Serial.print("FLOW CONSTANT_1: ");
 Serial.println(FLOW_CONSTANT_1);
 delay(1000);
}

/************************************************************* FUNCTION FOR CHECK EEPROM DATA VARIABLE ************************************************************/

void checkEEPROM()
{
  int checkByteAddress=0;
  byte checkByte;
  int EEPROM_Address=0;
  checkByte=EEPROM.read(0);
  Serial.println(checkByte);
  if(checkByte!=1)
  {
    checkByte=1;
    EEPROM.write(checkByteAddress,checkByte);
    EEPROM_Address=checkByteAddress+sizeof(checkByte);
    EEPROM.put(EEPROM_Address,parameters);
    parameters.getdata();
    Serial.println("Data Write");
  }
  else
  {
    readParameter();
  }
}

/*************************************************************** END OF EEPROM CHECK FUNCTION ******************************************************************/

void readParameter()
{
  int EEPROM_Address=sizeof(byte);
  EEPROM.get(EEPROM_Address,parameters);
  parameters.getdata();
  //Serial.println(FLOW_CONSTANT_1);
  //Serial.println(VOLUME_COIN_1);
}
void writeParameter()
{
  int EEPROM_Address=sizeof(byte);
  parameters.setdata();
  EEPROM.put(EEPROM_Address, parameters);
}
