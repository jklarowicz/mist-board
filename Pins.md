| **Pin No** | **Pin name** | **Description** |
|:-----------|:-------------|:----------------|
| 7          | LED          | FPGA LED output (second led), active low |
| 54-55      | CLOCK\_27[0..1] | 27Mhz clock inputs |
| 135, 137, 141-144 | VGA\_R[0..5] | 6 bit VGA output red channel |
| 115, 120-121, 125, 132-133 | VGA\_B[0..5] | 6 bit VGA output blue channel |
| 106, 110-114 | VGA\_G[0..5] | 6 bit VGA output green channel |
| 136        | VGA\_VS      | VGA vertical sync |
| 119        | VGA\_HS      | VGA horizontal sync |
| 65         | AUDIO\_L     | left audio PWM output |
| 80         | AUDIO\_R     | right audio PWM output |
| 46         | UART\_TX     | general purpose IO, currently used for MIDI out |
| 31         | UART\_RX     | general purpose IO, currently used for MIDI in |
| 105        | SPI\_DO      | Serial data output to ARM for serial peripheral interface (SPI) |
| 88         | SPI\_DI      | Serial data input from ARM for SPI |
| 126        | SPI\_SCK     | Serial clock from ARM for SPI |
| 127        | SPI\_SS2     | Second chip select from ARM for SPI |
| 91         | SPI\_SS3     | Third chip select from ARM for SPI |
| 90         | SPI\_SS4     | Fourth chip select from ARM for SPI |
| 13         | CONF\_DATA   | Config pin, dual use as fifth chip select from ARM for SPI |
| 49, 44, 42, 39, 4, 6, 8, 10, 11, 28, 50, 30, 32 | SDRAM\_A[0..12] | multiplexed SDRAM address input |
| 83, 79, 77-76, 72-71, 69-68, 86-87, 98-101, 103-104 | SDRAM\_DQ[0..15] | 16 bit SDRAM data bus |
| 58, 51     | SDRAM\_BA[0..1] | SDRAM bank address |
| 85         | SDRAM\_DQMH  | SDRAM high data mask |
| 67         | SDRAM\_DQML  | SDRAM low data mask |
| 60         | SDRAM\_nRAS  | SDRAM row select |
| 64         | SDRAM\_nCAS  | SDRAM column select |
| 66         | SDRAM\_nWE   | SDRAM write enable |
| 59         | SDRAM\_nCS   | SDRAM chip select |
| 33         | SDRAM\_CKE   | unused on boards >= 1.2, SDRAM clock enable on earlier boards |
| 43         | SDRAM\_CLK   | SDRAM clock     |