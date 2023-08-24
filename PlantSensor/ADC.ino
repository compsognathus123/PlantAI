#define HSPI_CLK 1000000 // 1 MHz

SPIClass hspi;


boolean initADC()
{
  hspi = new SPIClass(HSPI);
  pinMode(HSPI_CS, OUTPUT);
  hspi.begin(HSPI_CLK, HSPI_MISO, HSPI_MOSI, HSPI_CS);
  
}


void spiCommand(SPIClass *spi, byte data) {
  //use it as you would the regular arduino SPI API
  spi->beginTransaction(SPISettings(HSPI_CLK, MSBFIRST, SPI_MODE0));
  digitalWrite(spi->pinSS(), LOW); //pull SS slow to prep other end for transfer
  spi->transfer(data);
  digitalWrite(spi->pinSS(), HIGH); //pull ss high to signify end of data transfer
  spi->endTransaction();
}
