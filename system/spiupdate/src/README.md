# spi update write

write data to spi flash write data by blocks 
rewrite blocks only is diff

## USAGE

    [VARS] spiupdate OUT < INPUT_image

    gzip -dc VIM2.krescue.spi.img.gz | RATE=10 spiupdate /dev/mtdblock0  ; echo $?

## ARGS and VARS

+ NL   - progress new line
+ RATE - output rate
+ SIZE - output size
+ PROGRESS_FORMAT    - output progress format
+ PROGRESS_NO_HEADER - dont output progress header
+ OUT  - /dev/mtdblock0

## TESTS

    dd if=/dev/zero bs=4096 count=4096 > /tmp/spi_flash
    dd if=/dev/zero bs=4096 count=4096 | RATE=16 ./spiupdate /tmp/spi_flash ; echo $?
    dd if=/dev/zero bs=4096 count=4096 | RATE=16 NL=1 PROGRESS_FORMAT="%03d " PROGRESS_NO_HEADER=1 ./spiupdate /tmp/spi_flash ; echo $?

## GET && BUILD

    GCC=gcc make

## AUTHOR

\## hyphop ##

## LICENSE

    cat ./LICENSE