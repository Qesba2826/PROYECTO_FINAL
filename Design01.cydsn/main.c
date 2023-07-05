/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "stdio.h"

#define CR 0x0D
#define CL 0x0A
#define Newline()   UART_PC_PutChar(CR);UART_PC_PutChar(CL);

// Función Clear para ASCII/ANSI
#define Clear()     UART_PC_PutString("\033[2J");UART_PC_PutString("\033c");

// Definición de variables
uint8  dato_PC_Rx;          // Variable para guardar el dato recibido por UART
char   data[100];           // Variable para definir el char que se envía por UART
uint8  var;                // Variable para almacenar el valor del registro
uint8  f_ADC = 0;          // Bandera para indicar final de conversión
uint8  S1_SR;               // Variable de la tasa de muestreo del primer sensor
uint8  S2_SR;               // Variable de la tasa de muestreo del segundo sensor
uint8  S1_datos_mem[20];       // Vector de datos
uint8  S2_datos_mem[20];       // Vector de datos 
uint8  S1_SR_mem[20];          // Vector de tasas de muestreo
uint8  S2_SR_mem[20];          // Vector de tasas de muestreo
uint8  n1_SR;                // Indica la última posición en el vector de tasas de muestreo históricas
uint8  n1_Dato;              // Indica la última posición en el vector de datos históricos
uint8  n2_SR;                // Indica la última posición en el vector de tasas de muestreo históricas
uint8  n2_Dato;              // Indica la última posición en el vector de datos históricos
float  th;
float  D;
float  YD;
uint8  Count_S1 = 0;
uint8  Count_S2 = 0;

//Interrupción por UART_PC
CY_ISR(ISR_PC){
    
}

//Interrupción por End Of Convertion del ADC
CY_ISR(ISR_ADC){
    var = ADC_SAR_1_GetResult8();
}

//Interrupción de un minuto
CY_ISR(ISR_S1){
    Count_S1++;
}

//Interrupción de diez minutos
CY_ISR(ISR_S2){
    Count_S2++;
}

//Muestra de datos
void display(uint8 vector[20], uint8 n){
    for(uint8 i=0;i<n;i++){
        Newline();
        sprintf(data,"%02d",i); // Formato
        UART_PC_PutString(data);
        UART_PC_PutString(". ");
        UART_PC_PutChar(vector[i]);
        Newline();
    }
}

//Toma de muestras
void Measure_OS(uint8 vector[20], uint8 n){
    ADC_SAR_1_StartConvert();
    
    while(ADC_SAR_1_IsEndConversion(ADC_SAR_1_WAIT_FOR_RESULT)){
    }
    
    if(n < 19){
        vector[n] = var;
        n++;
    }
    else{
        UART_PC_PutString("Memoria del sensor llena");
    }   
}

//Valores iniciales de la tasa de muestreo
void Sample_Rate_Init(){
    //Coloca las tres tasas de muestreo a 1 minuto
    S1_SR = 1;
    S2_SR = 1;
}

//Ajuste de la tasa de muestreo de una sola variable basada en su comportamiento
uint8 Adjust_Individual_Sample_Rate(uint8 vector_datos[1], uint8 vector_sample[1], uint8 sensor){
    uint8 SR_New = 0;
    D = abs(vector_datos[0]
    return SR_New;
    
}

//Ajuste de la tasa de muestreo de las variables dependientes
void Adjust_Dependent_Sample_Rate(){
}

//Configuración del Sleep mode adecuado
void Set_Sleep_Mode(){
}

void Set_Time(uint8 new_time){
    if(new_time < 10){
    }
    else{
        
    }
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    isr_PC_StartEx(ISR_PC);     //Habilita interrupción de UART_PC
    isr_ADC_StartEx(ISR_ADC);   //Habilita interrupción de ADC
    UART_PC_Start();            //Inicializa UART_PC
    ADC_SAR_1_Start();          //Inicializa ADC
    //Timer_1_Start();            //Inicializa el timer de un minuto
    //Timer_2_Start();            //Inicializa el timer de diez minutos
    AMux_1_Start();             //Inicializa el selector
    isr_S1_StartEx(ISR_S1);
    isr_S2_StartEx(ISR_S2);
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    AMux_1_Select(0);
    Measure_OS(S1_datos_mem, n1_Dato);
    for(;;)
    {
       /* Place your application code here. */
    }
}

/* [] END OF FILE */
