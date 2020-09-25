#ifndef LCD4BITSMODE_H
#define	LCD4BITSMODE_H


//------------------------------------------------------------------------------
//                                  INCLUDES                                  //
//------------------------------------------------------------------------------
#include <xc.h>


//------------------------------------------------------------------------------
// DEFINES
//------------------------------------------------------------------------------

// Pinos de IO para comunica��o com o LCD 16x2

#define PIN_LCDBIT0 LATBbits.LATB2
#define PIN_LCDBIT1 LATBbits.LATB3
#define PIN_LCDBIT2 LATBbits.LATB4
#define PIN_LCDBIT3 LATBbits.LATB5
#define PIN_LCDRS   LATEbits.LATE0
#define PIN_LCDRW   LATEbits.LATE1
#define PIN_LCDEN   LATEbits.LATE2


//------------------------------------------------------------------------------
// PROT�TIPOS DE FUN��ES P�BLICAS
//------------------------------------------------------------------------------

/**
 * Inicializa o display para opera��o. Deve ser chamada apenas uma vez.
 * 
 * @since 31/07/2017
 * 
 */
void hwConfigurarLcd(void);

/**
 * Escreve um �nico caracter no display na posi��o em que o cursor estiver.
 * 
 * @since 31/07/2017
 * 
 * @param ch Char para escrever no display.
 */
void lcdEscreverChar(char ch);

/**
 * Escreve um char no LCD na linha X coluna indicada.
 * 
 * @param ch Char para ser escrito no LCD>
 * @param line Linha para escrever o char.
 * @param col Coluna para posicionar o char.
 * 
 * @since 14/08/2017
 */
void lcdEscreverCharPosicao(unsigned char ch, unsigned char linha, unsigned char coluna);

/**
 * Escreve uma sequ�ncia de caracteres no display a partir da posi��o do cursor.
 * @since 31/07/2017
 * 
 * @param str String para escrever no LCD
 */

void lcdEscreverString(const char *str);

/**
 * Escreve uma sequ�ncia de caracteres no display a partir da linhaXcoluna informada.
 * 
 * @param string Texto para ser escrito no display LCD.
 * @param line Linha para escrever o texto.
 * @param col Coluna para posicionar o in�cio do texto.
 * 
 * @since 14/08/2017
 * 
 */

void lcdEscreverStringPosicao(const char *string, unsigned char linha, unsigned char coluna);


/**
 * Define a posi��o do cursor no display
 * @since 31/07/2017
 * 
 * @param line Linha para posicionar o cursor.
 * <p> Valores aceitos: <br>
 * 1 - Primeira linha <br>
 * 2 - segunda linha <br>
 * 
 * @param col Coluna para posicionar o cursor. <br>
 * <p> Valores aceitos: <br>
 *  1 - Primeira coluna <br>
 *  ... <br>
 *  16 - �ltima coluna <br>
 */
void lcdPosicionarCursor(unsigned char linha, unsigned char coluna);

/**
 * Apaga todo o texto exibido no LCD.
 * 
 * @since 01/08/2017
 */
void lcdLimparTela(void);

/**
 * Rotaciona o texto em 'n' posi��es para esquerda.
 * 
 * @since 01/08/2017
 * 
 * @param n Quantidade de deslocamentos
 */
void lcdDeslocarTextoEsquerda(unsigned char n);

/**
 * Rotaciona o texto em 'n' posi��es para direita.
 * 
 * @since 01/08/2017
 * 
 * @param n Quantidade de deslocamento
 */
void lcdDeslocarTextoDireita(unsigned char n);

//------------------------------------------------------------------------------
// PROT�TIPOS DE FUN��ES PRIVADAS
//------------------------------------------------------------------------------

/**
 * Envia um char para os pinos do display.
 * 
 * @since 01/08/2017
 * 
 * @param ch Char para ser enviado.
 */
static void escreverDados(unsigned char ch);

/**
 * D� um pulso no pino E do LCD.
 * 
 * @since 01/08/2017
 */
static void pulse(void);

/**
 * Escreve um comando no LCD.
 * 
 * @since 31/07/2017
 * 
 * @param cmd Comando para ser enviado ao LCD. Pode-se utilizar os defines
 * que come�am com LCD_CMD
 */
static void escreverComando(unsigned char cmd);

/**
 * Escreve uma sequ�ncia de caracteres no display a partir da linhaXcoluna informada.
 * 
 * @param int Texto para ser escrito no display LCD.
 * 
 * @since 23/11/2017
 * 
 */

void lcdEscreverInt(int data_value);
/**
 * Escreve valroes inteiro.
 * 
 * @param hex Texto para ser escrito no display LCD.
 * 
 * @since 10/12/2018
 * 
 */
void lcdEscreverIntPosicao(unsigned int x, unsigned char line, unsigned char col);
/**
 * Escreve uma sequ�ncia de caracteres no display a partir da linhaXcoluna informada.
 * 
 * @param float Texto para ser escrito no display LCD.
 * 
 * @since 23/11/2017
 * 
 */

void lcdEscreverFloat(float data_value);
/**
 * Escreve um valor em hexadecimal.
 * 
 * @param hex Texto para ser escrito no display LCD.
 * 
 * @since 10/12/2018
 * 
 */
void lcdEscreverHex(unsigned int x);
/**
 * Escreve valores em hexadecimal.
 * 
 * @param hex Texto para ser escrito no display LCD.
 * 
 * @since 10/12/2018
 * 
 */
void lcdEscreverHexPosicao(unsigned int x, unsigned char line, unsigned char col);


#endif	/* LCD_H */