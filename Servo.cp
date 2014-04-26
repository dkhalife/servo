#line 1 "C:/Users/Dan/Documents/PIC Projects/Servo/Servo.c"
double uart_rd;

void delay(int d){
 while(d--){
 Delay_us(1);
 }
}

void angle(unsigned int p){
 while(PORTD.F0 == 0){
 PORTC = 0xFF;
 delay(p);
 PORTC = 0x00;
 delay(2000 - p);
 }

 while(PORTD.F0 != 0);
}

void main() {
 TRISC = 0x00;
 UART1_Init(19200);
 Delay_ms(100);
 UART1_Write_Text("Ready");
 UART1_Write(10);
 UART1_Write(13);

 uart_rd = 150;
 while(1){
 while(!UART1_Data_Ready()){
 PORTC = 0xFF;
 delay(uart_rd);
 PORTC = 0x00;
 delay(2000 - uart_rd);
 }

 uart_rd = UART1_Read();
 uart_rd = (uart_rd / 255) * 300;

 UART1_Write(uart_rd);
 }
}
