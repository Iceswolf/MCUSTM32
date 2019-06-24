/*
Esercizio 1:
  Accensione dei 4 led(led 3, led 4, led 5, led 6) della board utilizzando 
  un approccio a basso livello, tramite modifiche dei registri.

Input:
  Nessuno.

Output:
  Led 3
  Led 4
  Led 5
  Led 6.

Note:
  I registri GPIO_D_TYPE, GPIO_D_SPEED e GPIO_D_UDREG sono dichiarati ma
  lasciati ai valori di default.
*/

#define  Clock_AHB1_en     (unsigned int*)         (0x40023830)                 //RCC_AHB_EN (0x40023800+0x30)
#define  iopD_en           (unsigned int)          (1<<3)

#define  GPIO_D_MODER      (unsigned int*)         (0x40020c00)                 //(0x40020c00+0x0)     
#define  MODER15_30        (unsigned int)          (1<<30)                      //blu            
#define  MODER15_31        (unsigned int)          (1<<31)                      //blu             
#define  MODER15_28        (unsigned int)          (1<<28)                      //rosso
#define  MODER15_29        (unsigned int)          (1<<29)                      //rosso
#define  MODER15_27        (unsigned int)          (1<<27)                      //arancione
#define  MODER15_26        (unsigned int)          (1<<26)                      //arancione
#define  MODER15_25        (unsigned int)          (1<<25)                      //verde
#define  MODER15_24        (unsigned int)          (1<<24)                      //verde

#define  GPIO_D_TYPE      (unsigned int*)         (0x40020c04)                  //(0x40020c00+0x04) 
#define  TYPE_15          (unsigned int)          (1<<15)     

#define  GPIO_D_SPEED     (unsigned int*)         (0x40020c08)                  //(0x40020c00+0x08) 

#define  GPIO_D_UDREG     (unsigned int*)         (0x40020c0c)                  //(0x40020c00+0x0c) 

#define  GPIO_D_ODR       (unsigned int*)         (0x40020c14)                  //(0x40020c00+0x014) 
#define  TYPE_14          (unsigned int)          (1<<14)    
#define  TYPE_13          (unsigned int)          (1<<13) 
#define  TYPE_12          (unsigned int)          (1<<12) 

void main (void){
  unsigned int* puntatore;
  
  puntatore = Clock_AHB1_en;    //vado all'indirizzo del registro che contiene il clock
  *puntatore |= iopD_en;        // abilito il clock per la porta E
  
  puntatore = GPIO_D_MODER;     //vado all'indirizzo del registro che contiene il GPIOE
  *puntatore &= ~(MODER15_31);  //bit 31 a 0 e bit 30 a 1 modalità gp_o
  *puntatore |= (MODER15_30);
  *puntatore &= ~ (MODER15_29);
  *puntatore |= (MODER15_28);
  *puntatore &= ~ (MODER15_27);
  *puntatore |= (MODER15_26);
  *puntatore &= ~ (MODER15_25);
  *puntatore |= (MODER15_24);

  
   puntatore = GPIO_D_TYPE;     //vado all'indirizzo del registro che contiene l'info sul tipo di output di GPIOE
   *puntatore &= ~(TYPE_15);    //bit 15 a 0 tipo gp_o push_pull
   
   puntatore = GPIO_D_SPEED;    //vado all'indirizzo del registro che contiene l'info sulla velocità del clock
   *puntatore &= ~(MODER15_31); //bit 31 a 0 e bit 30 a 0 modalità lenta
   *puntatore &= ~(MODER15_30);
   
   puntatore = GPIO_D_UDREG;    //vado all'indirizzo del registro che contiene l'info sul pull dell'uscita
   *puntatore &= ~(MODER15_31); //bit 31 a 0 e bit 30 a 0 modalità no pull_up no pull_down
   *puntatore &= ~(MODER15_30);
   
   puntatore = GPIO_D_ODR;     //vado all'indirizzo del registro che contiene i dati da mandare in out
   *puntatore |= (TYPE_15);    //bit 15 a 1 per accendere il led
   *puntatore |= (TYPE_14); 
   *puntatore |= (TYPE_13); 
   *puntatore |= (TYPE_12);
   
   while(1){
   }
  
}
